#ifndef PINS_H
#define PINS_H

#define BIT(x) (1UL << (x))
#define GPIO_CLR(X) (3 << (X))
#define ALT_FUNC(x) (2UL << (x))

#define CLEAR_BIT(REG,X) ((REG) &= ~(GPIO_CLR(X)))
#define SET_BIT(REG,X) ((REG)|= BIT(X))

#define AFR_MSK(X,COL) (Y << (X * 4))
#define CLEAR_AFR(REG,X) ((REG) &= ~(BIT(X)))
#define SET_AFR(REG,X) ((REG)|= ALT_FUNC(X))

// RCC PINS
#define GPIOAEN 0
#define USART2EN 17
#define SYSCFGEN 14
#define DMA1EN 21

// KEYPAD PINS
#define ROW0 0
#define ROW1 1
#define ROW2 2
#define ROW3 3
#define COL0 5
#define COL1 6
#define COL2 7
#define COL3 8

// EXTI PIN
#define EXTI9_5_INDX 23

// USART PINS
#define UEN 13
#define TXEIE 7
#define TCIE 6
#define RE 2
#define TE 3
#define DMAR 6
#define DMAT 7

// DMA PINS

#endif


