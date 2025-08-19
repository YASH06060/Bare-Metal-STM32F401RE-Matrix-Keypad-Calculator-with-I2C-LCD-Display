#include "stm32f401re.h"
#include "i2c_driver.h"
#include "lcd_i2c.h"
#include "Gpio_driver.h"
#include "keypad.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    I2C_Config_t i2c_cfg = {100, 0, 0x00, 1};
    I2C_EnableClock(I2C1, ENABLED);
    I2C_Init(I2C1, &i2c_cfg);

    LCD_I2C_Init(I2C1, LCD_ADDR);
    LCD_I2C_SendCmd(I2C1, LCD_ADDR, 0x01);
    LCD_I2C_Print(I2C1, LCD_ADDR, "STM32 Calc");

    Keypad_Init();

    char input[17] = {0};
    int input_pos = 0;
    int num1 = 0, num2 = 0, result = 0;
    char op = 0;
    int state = 0;

    while(1) {
        char key = Keypad_GetKey();
        if(key) {
            if((key >= '0' && key <= '9')) {
                if(state == 0 || state == 2) {
                    if(input_pos < 16) {
                        input[input_pos++] = key;
                        input[input_pos] = 0;
                        LCD_I2C_SendCmd(I2C1, LCD_ADDR, 0x01);
                        LCD_I2C_Print(I2C1, LCD_ADDR, input);
                    }
                }
            } else if(key == '+' || key == '-' || key == '*' || key == '/') {
                if(state == 0 && input_pos > 0) {
                    num1 = atoi(input);
                    op = key;
                    input[input_pos++] = key;
                    input[input_pos] = 0;
                    LCD_I2C_SendCmd(I2C1, LCD_ADDR, 0x01);
                    LCD_I2C_Print(I2C1, LCD_ADDR, input);
                    state = 2;
                }
            } else if(key == '=') {
                if(state == 2 && input_pos > 0) {
                    char *ptr = strchr(input, op);
                    if(ptr) {
                        num2 = atoi(ptr + 1);
                        switch(op) {
                            case '+': result = num1 + num2; break;
                            case '-': result = num1 - num2; break;
                            case '*': result = num1 * num2; break;
                            case '/': result = num2 ? num1 / num2 : 0; break;
                        }
                        char res_str[17];
                        snprintf(res_str, 17, "%d", result);
                        LCD_I2C_SendCmd(I2C1, LCD_ADDR, 0x01);
                        LCD_I2C_Print(I2C1, LCD_ADDR, res_str);
                        strcpy(input, res_str);
                        input_pos = strlen(res_str);
                        state = 0;
                    }
                }
            } else if(key == 'C' || key == '#') {
                memset(input, 0, sizeof(input));
                input_pos = 0;
                num1 = num2 = result = 0;
                op = 0; state = 0;
                LCD_I2C_SendCmd(I2C1, LCD_ADDR, 0x01);
            }
            for(volatile int d=0; d<50000; d++);
        }
    }
}
