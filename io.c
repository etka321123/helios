#include "io.h"

static const IO_t io_table[IO_MAX] = {
    [IO_LED_ORANGE] = { GPIOD, 13 },
};

void IO_Init(IO_Index idx) {
    if (idx >= IO_MAX) return;

    IO_t io = io_table[idx];

    // Clock enable
    if (io.port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (io.port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (io.port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (io.port == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    // Pin as output
    io.port->MODER &= ~(0x3 << (io.pin * 2));
    io.port->MODER |=  (0x1 << (io.pin * 2));
}

void IO_Write(IO_Index idx, IO_State state) {
    if (idx >= IO_MAX) return;

    IO_t io = io_table[idx];

    if (state == IO_HIGH)
        io.port->ODR |= (1 << io.pin);
    else
        io.port->ODR &= ~(1 << io.pin);
}

void IO_Toggle(IO_Index idx) {
    if (idx >= IO_MAX) return;

    IO_t io = io_table[idx];
    io.port->ODR ^= (1 << io.pin);
}

IO_State IO_Read(IO_Index idx) {
    if (idx >= IO_MAX) return IO_LOW;

    IO_t io = io_table[idx];
    return (io.port->IDR & (1 << io.pin)) ? IO_HIGH : IO_LOW;
}