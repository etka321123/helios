#include "stm32f4xx.h" //CMSIS "Core + Device" Support
#include <stdint.h>
#include "io.h"

#define LED_PIN 13

void delay(volatile uint32_t time) {
    while (time--) {
        // NOP wait for one cycle.
        __NOP();
    }
}

void init()
{
  IO_Init(IO_LED_ORANGE); 
}

void main()
{
  init();
  
  while (1) {
        IO_Write(IO_LED_ORANGE, IO_HIGH);
        delay(5000000);
        IO_Write(IO_LED_ORANGE, IO_LOW);
        delay(5000000);
    }
  
}
