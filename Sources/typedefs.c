#include "../Include/typedefs.h"

void EXTI_INIT(void) {
	//SYSCFG->EXTICR2 |= (0b0000 << 4);
	//SYSCFG->EXTICR2 |= (0b0000 << 8);
	//SYSCFG->EXTICR2 |= (0b0000 << 12);
	//SYSCFG->EXTICR3 |= (0b0000 << 0);


	SYSCFG->EXTICR2 &= ~(0xF << 4);
	SYSCFG->EXTICR2 &= ~(0xF << 8);
	SYSCFG->EXTICR2 &= ~(0xF << 12);
	SYSCFG->EXTICR3 &= ~(0xF << 0);


	EXTI->IMR |= (1 << COL0);
	EXTI->IMR |= (1 << COL1);
	EXTI->IMR |= (1 << COL2);
	EXTI->IMR |= (1 << COL3);

	EXTI->FSTR |= (1 << COL0);
	EXTI->FSTR |= (1 << COL1);
	EXTI->FSTR |= (1 << COL2);
	EXTI->FSTR |= (1 << COL3);

	EXTI->PR = (1 << COL0);
	EXTI->PR = (1 << COL1);
	EXTI->PR = (1 << COL2);
	EXTI->PR = (1 << COL3);

	NVIC->ISER0[0] |= (1 << 23);
}

void CLK_INIT(void) {
	RCC->AHB1ENR |= (1 << 0);
	RCC->AHB1ENR |= (1 << DMA1EN);
	RCC->APB1ENR |= (1 << USART2EN);
	RCC->APB2ENR |= (1 << SYSCFGEN);
}

void USART2_INIT(void) {

}

void DMA1_INIT(void) {

}
