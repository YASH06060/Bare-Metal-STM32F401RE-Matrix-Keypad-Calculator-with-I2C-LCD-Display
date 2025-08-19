#include "lcd_i2c.h"
#include <stdint.h>
#include <string.h>

#define LCD_BACKLIGHT   0x08
#define LCD_EN          0x04
#define LCD_RW          0x02
#define LCD_RS          0x01

static void LCD_I2C_send_half(I2C_Regs_t *I2Cx, uint8_t address, uint8_t data) {
    I2C_WriteByte(I2Cx, address, data | LCD_BACKLIGHT | LCD_EN);
    for(volatile int i=0; i<50; i++);
    I2C_WriteByte(I2Cx, address, (data | LCD_BACKLIGHT) & ~LCD_EN);
    for(volatile int i=0; i<50; i++);
}

static void LCD_I2C_send_byte(I2C_Regs_t *I2Cx, uint8_t address, uint8_t val, uint8_t mode) {
    uint8_t high = (val & 0xF0) | mode;
    uint8_t low = ((val << 4) & 0xF0) | mode;
    LCD_I2C_send_half(I2Cx, address, high);
    LCD_I2C_send_half(I2Cx, address, low);
}

void LCD_I2C_SendCmd(I2C_Regs_t *I2Cx, uint8_t address, uint8_t cmd) {
    LCD_I2C_send_byte(I2Cx, address, cmd, 0x00);
}

void LCD_I2C_SendData(I2C_Regs_t *I2Cx, uint8_t address, uint8_t data) {
    LCD_I2C_send_byte(I2Cx, address, data, LCD_RS);
}

void LCD_I2C_Init(I2C_Regs_t *I2Cx, uint8_t address) {
    for(volatile int i=0; i<50000; i++);
    LCD_I2C_SendCmd(I2Cx, address, 0x33);
    LCD_I2C_SendCmd(I2Cx, address, 0x32);
    LCD_I2C_SendCmd(I2Cx, address, 0x28);
    LCD_I2C_SendCmd(I2Cx, address, 0x0C);
    LCD_I2C_SendCmd(I2Cx, address, 0x06);
    LCD_I2C_SendCmd(I2Cx, address, 0x01);
    for(volatile int i=0; i<5000; i++);
}

void LCD_I2C_Print(I2C_Regs_t *I2Cx, uint8_t address, const char *str) {
    while(*str) {
        LCD_I2C_SendData(I2Cx, address, *str++);
    }
}
