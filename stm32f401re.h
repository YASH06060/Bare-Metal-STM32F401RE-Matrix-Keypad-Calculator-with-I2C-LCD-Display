

#include <stdint.h>

#define FLASH_BASE      0x08000000U
#define SRAM1_BASE      0x20000000U
#define ROM_BASE        0x1FFF0000U
#define PERIPH_BASE     0x40000000U
#define AHB1_BASE       0x40020000U
#define APB1_BASE       PERIPH_BASE
#define APB2_BASE       0x40010000U

// GPIO base addresses
#define GPIOA_BASE      (AHB1_BASE + 0x0000U)
#define GPIOB_BASE      (AHB1_BASE + 0x0400U)
#define GPIOC_BASE      (AHB1_BASE + 0x0800U)
#define GPIOD_BASE      (AHB1_BASE + 0x0C00U)
#define GPIOE_BASE      (AHB1_BASE + 0x1000U)
#define GPIOH_BASE      (AHB1_BASE + 0x1C00U)

// RCC base address
#define RCC_BASE        (AHB1_BASE + 0x3800U)

// I2C base addresses
#define I2C1_BASE       (APB1_BASE + 0x5400U)
#define I2C2_BASE       (APB1_BASE + 0x5800U)
#define I2C3_BASE       (APB1_BASE + 0x5C00U)

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
    uint32_t RESERVED1[1];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    uint32_t RESERVED2[1];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t RESERVED3[1];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    uint32_t RESERVED4[1];
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t RESERVED5[1];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t RESERVED6[1];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    uint32_t RESERVED7;
    volatile uint32_t DCKCFGR;
} RCC_Regs_t;

// I2C register structure
typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t OAR1;
    volatile uint32_t OAR2;
    volatile uint32_t DR;
    volatile uint32_t SR1;
    volatile uint32_t SR2;
    volatile uint32_t CCR;
    volatile uint32_t TRISE;
    volatile uint32_t FLTR;
} I2C_Regs_t;

// Peripheral pointers
#define GPIOA   ((GPIO_Regs_t *) GPIOA_BASE)
#define GPIOB   ((GPIO_Regs_t *) GPIOB_BASE)
#define GPIOC   ((GPIO_Regs_t *) GPIOC_BASE)
#define GPIOD   ((GPIO_Regs_t *) GPIOD_BASE)
#define GPIOE   ((GPIO_Regs_t *) GPIOE_BASE)
#define GPIOH   ((GPIO_Regs_t *) GPIOH_BASE)
#define RCC     ((RCC_Regs_t *) RCC_BASE)
#define I2C1    ((I2C_Regs_t *) I2C1_BASE)
#define I2C2    ((I2C_Regs_t *) I2C2_BASE)
#define I2C3    ((I2C_Regs_t *) I2C3_BASE)

#define ENABLED 1
#define DISABLED 0


