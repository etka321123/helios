#ifndef IO_H
#define IO_H

#include "stm32f4xx.h"

typedef enum {
    IO_LOW = 0,
    IO_HIGH = 1
} IO_State;

typedef enum {
    IO_LED_ORANGE = 0, // PD13
    IO_LED_GREEN,      // PD12
    IO_LED_RED,        // PD14
    IO_LED_BLUE,       // PD15
    IO_LED_MAX
} IO_Index;

void IO_Init(void);  // Tüm LED’leri init eder
void IO_Write(IO_Index idx, IO_State state);
void IO_Toggle(IO_Index idx);
IO_State IO_Read(IO_Index idx);

#endif