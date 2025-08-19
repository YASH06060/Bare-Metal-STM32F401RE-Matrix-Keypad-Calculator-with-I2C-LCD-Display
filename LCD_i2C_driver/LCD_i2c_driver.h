#include "i2c_driver.h"

#define LCD_ADDR        0x27  

void LCD_I2C_Init(I2C_Regs_t *I2Cx, uint8_t address);
void LCD_I2C_SendCmd(I2C_Regs_t *I2Cx, uint8_t address, uint8_t cmd);
void LCD_I2C_SendData(I2C_Regs_t *I2Cx, uint8_t address, uint8_t data);
void LCD_I2C_Print(I2C_Regs_t *I2Cx, uint8_t address, const char *str);
