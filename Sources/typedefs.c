#include "../Include/typedefs.h"

void EXTI_INIT(void) {
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
	RCC->AHB1ENR |= (1 << 2);
	RCC->AHB1ENR |= (1 << DMA1EN);
	RCC->APB1ENR |= (1 << 18);
	RCC->APB2ENR |= (1 << SYSCFGEN);
	RCC->APB2ENR |= (1 << 4);
}

void DMA1_INIT(void) {

	DMA1->S5CR |= CHSEL;
	DMA1->S5CR |= MBURST;
	DMA1->S5CR |= PL;
	DMA1->S5CR |= MSIZE;
	DMA1->S5M0AR = USART1->DR;

}

void USART1_INIT(void) {

	GPIOA->MODER &= ~(3 << (2 * 9));
	GPIOA->MODER &= ~(3 << (2 * 10));

	GPIOA->MODER |= (2 << (2 * 9));
	GPIOA->MODER |= (2 << (2 * 10));

	GPIOA->AFRH &= ~(0xF << (4 * 1));
	GPIOA->AFRH &= ~(0xF << (4 * 2));

	GPIOA->AFRH |= (7 << (4 * 1));
	GPIOA->AFRH |= (7 << (4 * 2));

	USART1->BRR = 0x008B;
	USART1->CR1 |= (1 << RE);
	USART1->CR1 |= (1 << TE);
	USART1->CR1 |= (1 << UEN);
}
