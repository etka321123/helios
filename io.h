#ifndef IO_H
#define IO_H

#include "stm32f4xx.h"

typedef enum {
    IO_LOW = 0,
    IO_HIGH = 1
} IO_State;

typedef enum {
    IO_LED_ORANGE = 0,
    //IO_LED_GREEN,
    //IO_LED_RED,
    //IO_LED_BLUE,
    IO_MAX
} IO_Index;

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} IO_t;

void IO_Init(IO_Index idx);
void IO_Write(IO_Index idx, IO_State state);
void IO_Toggle(IO_Index idx);
IO_State IO_Read(IO_Index idx);

#endif