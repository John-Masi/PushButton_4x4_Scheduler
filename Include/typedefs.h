#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <stdint.h>
#include "pins.h"

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSSR;
    volatile uint32_t r;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO_Typedef;

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t reserved0[9];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t reserved1;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
} RCC_Typedef;

typedef struct {
	volatile uint32_t ISER0[7];
} NVIC_Typedef;

typedef struct {
	volatile uint32_t r[2];
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
} SYSCFG_Typedef;

typedef struct {
	volatile uint32_t KR;
	volatile uint32_t PR;
	volatile uint32_t RLR;
	volatile uint32_t SR;
} IWDG_Typedef;

typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t r[2];
	volatile uint32_t FSTR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_Typedef;

// STREAM 5 & 6 FOR USART2 TX/RX
typedef struct {
	volatile uint32_t r[2];

} DMA_Typedef;

typedef struct {
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
} USART_Typedef;

typedef struct {

} RTC_Typedef;

#define RCC ((RCC_Typedef *)0X40023800)
#define NVIC ((NVIC_Typedef*)0xE000E100)
#define SYSCFG ((SYSCFG_Typedef *)0x40013800)
#define IWDG ((IWDG_Typedef *)0x40003000)
#define EXTI ((EXTI_Typedef *)0x40013C00)
#define DMA1 ((DMA_Typedef*)0x40026000)
#define USART2 ((USART_Typedef *)0x40004400)
#define RTC ((RTC_Typedef*)0x40002800)
#define GPIOD ((GPIO_Typedef*)0x40020C00)


void EXTI_INIT(void);
void CLK_INIT(void);
void USART2_INIT(void);
void DMA1_INIT(void);

#endif
