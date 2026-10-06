#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>
#include "typedefs.h"

#define GPIOA ((GPIO_Typedef *)0x40020000)

// PA0 - PA3 for rows
// PA5 - PA8 for columns

void rowsHigh(void);
void activate_row(uint8_t row);
void KEYPAD_INIT(void);
char Keypad_Scan(void);
void KeyPad_Task(void);

#endif



