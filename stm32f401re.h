/*
 * stm32f401re_mod.h
 * Modified low-level definition header for STM32F401RE
 */

#ifndef INC_STM32F401RE_H_
#define INC_STM32F401RE_H_

#include <stdint.h>

#define FLASH_BASE 0x08000000U
#define SRAM1_BASE 0x20000000U
#define ROM_BASE   0x1FFF0000U

#define PERIPH_BASE 0x40000000U
#define AHB1_BASE   0x40020000U
#define APB1_BASE   PERIPH_BASE
#define APB2_BASE   0x40010000U

// GPIO Base Addresses
#define GPIOA_BASE (AHB1_BASE + 0x0000U)
#define GPIOB_BASE (AHB1_BASE + 0x0400U)
#define GPIOC_BASE (AHB1_BASE + 0x0800U)
#define GPIOD_BASE (AHB1_BASE + 0x0C00U)
#define GPIOE_BASE (AHB1_BASE + 0x1000U)
#define GPIOH_BASE (AHB1_BASE + 0x1C00U)

// RCC Base Address
#define RCC_BASE   (AHB1_BASE + 0x3800U)

// GPIO register structure
typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO_Regs_t;

// RCC register structure
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    uint32_t RESERVED0[2];
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    uint32_t RESERVED2[2];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t RESERVED3[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    uint32_t RESERVED4[2];
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t RESERVED5[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t RESERVED6[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    uint32_t RESERVED7;
    volatile uint32_t DCKCFGR;
} RCC_Regs_t;

// Peripheral pointers
#define GPIOA ((GPIO_Regs_t *) GPIOA_BASE)
#define GPIOB ((GPIO_Regs_t *) GPIOB_BASE)
#define GPIOC ((GPIO_Regs_t *) GPIOC_BASE)
#define GPIOD ((GPIO_Regs_t *) GPIOD_BASE)
#define GPIOE ((GPIO_Regs_t *) GPIOE_BASE)
#define GPIOH ((GPIO_Regs_t *) GPIOH_BASE)

#define RCC   ((RCC_Regs_t *) RCC_BASE)

#define ENABLED  1
#define DISABLED 0

#endif /* INC_STM32F401RE_MOD_H_ */
