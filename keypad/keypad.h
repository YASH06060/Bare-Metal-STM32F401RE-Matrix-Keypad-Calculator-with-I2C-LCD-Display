#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f401re.h"
#include "Gpio_driver.h"

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

void Keypad_Init(void);
char Keypad_GetKey(void);

#endif
