#include "../Include/keypad.h"

int keypad_event = 0;
static const char keymap[4][4] = {
	    {'1', '2', '3', 'A'},
	    {'4', '5', '6', 'B'},
	    {'7', '8', '9', 'C'},
	    {'*', '0', '#', 'D'}
};

void rowsHigh(void) {
	GPIOA->BSSR = 0x0F;
}

static const uint8_t row_pins[4] = {0, 1, 4, 10};

void activate_row(uint8_t row)
{
    rowsHigh();
    GPIOA->BSSR = (1 << (row_pins[row] + 16));
}

void rowsLow(void)
{
    GPIOA->BSSR = (0x0F << 16);
}

void KEYPAD_INIT(void) {
	GPIOA->MODER &= ~(3 << (0 * 2));
	GPIOA->MODER &= ~(3 << (1 * 2));
	GPIOA->MODER &= ~(3 << (4 * 2));
	GPIOA->MODER &= ~(3 << (10 * 2));
	GPIOA->MODER &= ~(3 << (9 * 2));

	GPIOA->MODER |= (1 << (0 * 2));
	GPIOA->MODER |= (1 << (1 * 2));
	GPIOA->MODER |= (1 << (4 * 2));
	GPIOA->MODER |= (1 << (10 * 2));
	GPIOA->MODER |= (1 << (9 * 2));

    GPIOA->MODER &= ~(3 << (5 * 2));
    GPIOA->MODER &= ~(3 << (6 * 2));
    GPIOA->MODER &= ~(3 << (7 * 2));
    GPIOA->MODER &= ~(3 << (8 * 2));

    GPIOA->PUPDR &= ~(3 << (5 * 2));
    GPIOA->PUPDR |=  (1 << (5 * 2));

    GPIOA->PUPDR &= ~(3 << (6 * 2));
    GPIOA->PUPDR |=  (1 << (6 * 2));

    GPIOA->PUPDR &= ~(3 << (7 * 2));
    GPIOA->PUPDR |=  (1 << (7 * 2));

    GPIOA->PUPDR &= ~(3 << (8 * 2));
    GPIOA->PUPDR |=  (1 << (8 * 2));
    rowsLow();
}

char Keypad_Scan(void)
{
    for (uint8_t row = 0; row < 4; row++)
    {
        activate_row(row);

        uint32_t columns = GPIOA->IDR;

        for (uint8_t col = 0; col < 4; col++)
        {
            if (!(columns & (1U << (col + 5))))
            {
                rowsLow();
                return keymap[row][col];
            }
        }
    }

    rowsLow();
    return 0;
}

void KeyPad_Task(void) {
	char key = Keypad_Scan();

	if(key) {
		GPIOA->ODR |= (1 << 9);
	}
}
