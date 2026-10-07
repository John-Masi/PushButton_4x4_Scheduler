#include "../Include/keypad.h"

int keypad_event = 0;
static const char keymap[4][4] = {
	    {' ', ' ', ' ', ' '},
	    {' ', '^', '^', ' '},
	    {' ', '<', '>', ' '},
	    {' ', ' ', ' ', ' '}
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

	CLEAR_BIT(GPIOA->MODER,(9 * 2)); // pin for wired test led
	CLEAR_BIT(GPIOA->MODER,(0 * 2));
	CLEAR_BIT(GPIOA->MODER,(1 * 2));
	CLEAR_BIT(GPIOA->MODER,(4 * 2));
	CLEAR_BIT(GPIOA->MODER,(10 * 2));

	SET_BIT(GPIOA->MODER,(0 * 2));
	SET_BIT(GPIOA->MODER,(1 * 2));
	SET_BIT(GPIOA->MODER,(4 * 2));
	SET_BIT(GPIOA->MODER,(10 * 2));

	CLEAR_BIT(GPIOA->MODER,(5 * 2));
	CLEAR_BIT(GPIOA->MODER,(6 * 2));
	CLEAR_BIT(GPIOA->MODER,(7 * 2));
	CLEAR_BIT(GPIOA->MODER,(8 * 2));

	CLEAR_BIT(GPIOA->PUPDR,(5 * 2));
	SET_BIT(GPIOA->PUPDR,(5 * 2));

    CLEAR_BIT(GPIOA->PUPDR,(6 * 2));
    SET_BIT(GPIOA->PUPDR,(7 * 2));

    CLEAR_BIT(GPIOA->PUPDR,(7 * 2));
    SET_BIT(GPIOA->PUPDR,(7 * 2));

    CLEAR_BIT(GPIOA->PUPDR,(8 * 2));
    SET_BIT(GPIOA->PUPDR,(8 * 2));
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
