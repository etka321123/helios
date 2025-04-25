#include "stm32f4xx.h" //CMSIS "Core + Device" Support
#include <stdint.h>
#include "io.h"

void delay(volatile uint32_t t) {
    while (t--);
}

void delay_1s(void) {
    delay(4000000); // Yaklasik 1 saniye @16MHz
}

void init()
{
  IO_Init();
}

void main()
{
  init();
  
  while (1) {
      for (IO_Index i = IO_LED_ORANGE; i < IO_LED_MAX; i++) {
            IO_Write(i, IO_HIGH);  
            delay_1s();
            IO_Write(i, IO_LOW);    // LED’i söndür
            delay_1s();
        }
    }
  
}
