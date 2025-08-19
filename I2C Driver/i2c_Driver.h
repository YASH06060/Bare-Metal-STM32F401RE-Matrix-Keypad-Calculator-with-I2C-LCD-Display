#include "stm32f401re.h"

typedef struct {
    uint32_t clockSpeed;
    uint8_t dutyCycle;
    uint8_t ownAddress;
    uint8_t ackEnable;
} I2C_Config_t;

void I2C_EnableClock(I2C_Regs_t *I2Cx, uint8_t en_dis);
void I2C_Init(I2C_Regs_t *I2Cx, I2C_Config_t *config);
void I2C_MasterTransmit(I2C_Regs_t *I2Cx, uint8_t address, uint8_t *data, uint16_t len);
void I2C_WriteByte(I2C_Regs_t *I2Cx, uint8_t address, uint8_t data);
void I2C_MasterReceive(I2C_Regs_t *I2Cx, uint8_t address, uint8_t *buffer, uint16_t len);
