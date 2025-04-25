#include "io.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} IO_t;

static const IO_t io_table[IO_LED_MAX] = {
    [IO_LED_ORANGE] = { GPIOD, 13 },
    [IO_LED_GREEN]  = { GPIOD, 12 },
    [IO_LED_RED]    = { GPIOD, 14 },
    [IO_LED_BLUE]   = { GPIOD, 15 },
};

void IO_Init(void) {
    // GPIOD clock aktif et
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    for (int i = 0; i < IO_LED_MAX; i++) {
        IO_t io = io_table[i];

        // Pin'i output moda al
        io.port->MODER &= ~(0x3 << (io.pin * 2));
        io.port->MODER |=  (0x1 << (io.pin * 2));
    }
}

void IO_Write(IO_Index idx, IO_State state) {
    if (idx >= IO_LED_MAX) return;

    IO_t io = io_table[idx];
    if (state == IO_HIGH)
        io.port->ODR |= (1 << io.pin);
    else
        io.port->ODR &= ~(1 << io.pin);
}

void IO_Toggle(IO_Index idx) {
    if (idx >= IO_LED_MAX) return;

    IO_t io = io_table[idx];
    io.port->ODR ^= (1 << io.pin);
}

IO_State IO_Read(IO_Index idx) {
    if (idx >= IO_LED_MAX) return IO_LOW;

    IO_t io = io_table[idx];
    return (io.port->IDR & (1 << io.pin)) ? IO_HIGH : IO_LOW;
}