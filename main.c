#include "stm32f4xx.h" //CMSIS "Core + Device" Support
#include <stdint.h>
#define LED_PIN 13

void delay(volatile uint32_t time) {
    while (time--) {
        // NOP wait for one cycle.
        __NOP();
    }
}

void init()
{
  //Enabled GPIOD Clock
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
  // Drive pin 13 on gpio d port   
  GPIOD->MODER &= ~(0x3 << (LED_PIN * 2)); // Clear
  GPIOD->MODER |=  (0x1 << (LED_PIN * 2)); // 01: General purpose output
  GPIOD->OTYPER &= ~(1 << LED_PIN);       // Push-pull
  GPIOD->OSPEEDR |=  (0x3 << (LED_PIN*2)); // High speed
  GPIOD->PUPDR   &= ~(0x3 << (LED_PIN*2)); // No pull-up, pull-down    
}

void main()
{
  init();
  
  while(1) {
    // Enable (PD13 = 1)
    GPIOD->ODR |= (1 << LED_PIN);

    delay(5600000);
    
    // Disable (PD13 = 0)
    GPIOD->ODR &= ~(1 << LED_PIN); 
    
    delay(5600000);
  }
  
}
