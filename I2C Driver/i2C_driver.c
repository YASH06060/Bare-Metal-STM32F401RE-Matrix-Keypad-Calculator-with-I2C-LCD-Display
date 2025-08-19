#include "i2c_driver.h"

void I2C_EnableClock(I2C_Regs_t *I2Cx, uint8_t en_dis) {
    if(en_dis == ENABLED) {
        if(I2Cx == I2C1) RCC->APB1ENR |= (1 << 21);
        else if(I2Cx == I2C2) RCC->APB1ENR |= (1 << 22);
        else if(I2Cx == I2C3) RCC->APB1ENR |= (1 << 23);
    } else {
        if(I2Cx == I2C1) RCC->APB1ENR &= ~(1 << 21);
        else if(I2Cx == I2C2) RCC->APB1ENR &= ~(1 << 22);
        else if(I2Cx == I2C3) RCC->APB1ENR &= ~(1 << 23);
    }
}

void I2C_Init(I2C_Regs_t *I2Cx, I2C_Config_t *config) {
    I2Cx->CR2 = 16; // 16MHz
    I2Cx->CCR = (16000/(2*config->clockSpeed));
    I2Cx->TRISE = 17;
    I2Cx->CR1 = 0x0001; // Enable
}

void I2C_MasterTransmit(I2C_Regs_t *I2Cx, uint8_t address, uint8_t *data, uint16_t len) {
    I2Cx->CR1 |= (1 << 8); // START
    while(!(I2Cx->SR1 & (1 << 0)));
    I2Cx->DR = address << 1;
    while(!(I2Cx->SR1 & (1 << 1)));
    volatile uint32_t tmp = I2Cx->SR1 | I2Cx->SR2;
    for(uint16_t i=0; i<len; i++) {
        while(!(I2Cx->SR1 & (1 << 7)));
        I2Cx->DR = data[i];
    }
    while(!(I2Cx->SR1 & (1 << 2)));
    I2Cx->CR1 |= (1 << 9); // STOP
}

void I2C_WriteByte(I2C_Regs_t *I2Cx, uint8_t address, uint8_t data) {
    I2C_MasterTransmit(I2Cx, address, &data, 1);
}

void I2C_MasterReceive(I2C_Regs_t *I2Cx, uint8_t address, uint8_t *buffer, uint16_t len) {
    
}
