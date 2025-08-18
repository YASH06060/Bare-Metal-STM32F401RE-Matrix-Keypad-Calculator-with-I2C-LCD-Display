/*
 * stm32f401xx_gpio_driver_mod.c
 * Modified GPIO driver source for STM32F401RE bare-metal
 */

#include "stm32f401re.h"
#include "Gpio_driverl.h"

void GPIO_EnableClock(GPIO_Regs_t *GPIOx, uint8_t en_dis) {
    if(en_dis == ENABLED) {
        if(GPIOx == GPIOA) RCC->AHB1ENR |= (1 << 0);
        else if(GPIOx == GPIOB) RCC->AHB1ENR |= (1 << 1);
        else if(GPIOx == GPIOC) RCC->AHB1ENR |= (1 << 2);
        else if(GPIOx == GPIOD) RCC->AHB1ENR |= (1 << 3);
        else if(GPIOx == GPIOE) RCC->AHB1ENR |= (1 << 4);
        else if(GPIOx == GPIOH) RCC->AHB1ENR |= (1 << 7);
    } else {
        if(GPIOx == GPIOA) RCC->AHB1ENR &= ~(1 << 0);
        else if(GPIOx == GPIOB) RCC->AHB1ENR &= ~(1 << 1);
        else if(GPIOx == GPIOC) RCC->AHB1ENR &= ~(1 << 2);
        else if(GPIOx == GPIOD) RCC->AHB1ENR &= ~(1 << 3);
        else if(GPIOx == GPIOE) RCC->AHB1ENR &= ~(1 << 4);
        else if(GPIOx == GPIOH) RCC->AHB1ENR &= ~(1 << 7);
    }
}

void GPIO_Init(GPIO_Handle_Mod_t *handle) {
    uint32_t temp = 0;
    uint8_t pin = handle->config.pinNumber;

    // Configure mode
    temp = (handle->config.mode << (pin * 2));
    handle->port->MODER &= ~(0x3 << (pin * 2));
    handle->port->MODER |= temp;

    // Configure output type
    temp = (handle->config.outputType << pin);
    handle->port->OTYPER &= ~(0x1 << pin);
    handle->port->OTYPER |= temp;

    // Configure speed
    temp = (handle->config.speed << (pin * 2));
    handle->port->OSPEEDR &= ~(0x3 << (pin * 2));
    handle->port->OSPEEDR |= temp;

    // Configure pull-up/pull-down
    temp = (handle->config.pull << (pin * 2));
    handle->port->PUPDR &= ~(0x3 << (pin * 2));
    handle->port->PUPDR |= temp;

    // Configure alternate function
    if(handle->config.mode == GPIO_MODE_ALTFN) {
        uint8_t afrIndex = pin / 8;
        uint8_t afrPos = (pin % 8) * 4;
        handle->port->AFRL = (afrIndex == 0) ? handle->port->AFRL & ~(0xF << afrPos) : handle->port->AFRH & ~(0xF << afrPos);
        if(afrIndex == 0)
            handle->port->AFRL |= (handle->config.altFuncSel << afrPos);
        else
            handle->port->AFRH |= (handle->config.altFuncSel << afrPos);
    }
}

void GPIO_DeInit(GPIO_Regs_t *GPIOx) {
    if(GPIOx == GPIOA) { RCC->AHB1RSTR |= (1 << 0); RCC->AHB1RSTR &= ~(1 << 0); }
    else if(GPIOx == GPIOB) { RCC->AHB1RSTR |= (1 << 1); RCC->AHB1RSTR &= ~(1 << 1); }
    else if(GPIOx == GPIOC) { RCC->AHB1RSTR |= (1 << 2); RCC->AHB1RSTR &= ~(1 << 2); }
    else if(GPIOx == GPIOD) { RCC->AHB1RSTR |= (1 << 3); RCC->AHB1RSTR &= ~(1 << 3); }
    else if(GPIOx == GPIOE) { RCC->AHB1RSTR |= (1 << 4); RCC->AHB1RSTR &= ~(1 << 4); }
    else if(GPIOx == GPIOH) { RCC->AHB1RSTR |= (1 << 7); RCC->AHB1RSTR &= ~(1 << 7); }
}

uint8_t GPIO_ReadPin(GPIO_Regs_t *GPIOx, uint8_t pin) {
    return ((GPIOx->IDR >> pin) & 0x1);
}

uint16_t GPIO_ReadPort(GPIO_Regs_t *GPIOx) {
    return ((uint16_t) GPIOx->IDR);
}

void GPIO_WritePin(GPIO_Regs_t *GPIOx, uint8_t pin, uint8_t val) {
    if(val == GPIO_PIN_SET)
        GPIOx->ODR |= (1 << pin);
    else
        GPIOx->ODR &= ~(1 << pin);
}

void GPIO_WritePort(GPIO_Regs_t *GPIOx, uint16_t val) {
    GPIOx->ODR = val;
}

void GPIO_TogglePin(GPIO_Regs_t *GPIOx, uint8_t pin) {
    GPIOx->ODR ^= (1 << pin);
}
