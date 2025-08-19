#include "stm32f401re.h"

typedef struct {
    uint8_t pinNumber;
    uint8_t mode;
    uint8_t speed;
    uint8_t outputType;
    uint8_t pull;
    uint8_t altFuncSel;
} GPIO_Config_Mod_t;

typedef struct {
    GPIO_Regs_t *port;
    GPIO_Config_Mod_t config;
} GPIO_Handle_Mod_t;

// Modes, types, speeds, pulls
#define GPIO_MODE_IN      0
#define GPIO_MODE_OUT     1
#define GPIO_MODE_ALTFN   2
#define GPIO_MODE_ANALOG  3

#define GPIO_OT_PP        0
#define GPIO_OT_OD        1

#define GPIO_SPEED_LOW    0
#define GPIO_SPEED_MED    1
#define GPIO_SPEED_HIGH   2
#define GPIO_SPEED_VHIGH  3

#define GPIO_NO_PULL      0
#define GPIO_PULL_UP      1
#define GPIO_PULL_DOWN    2

#define GPIO_PIN_SET      1
#define GPIO_PIN_RESET    0

void GPIO_EnableClock(GPIO_Regs_t *GPIOx, uint8_t en_dis);
void GPIO_Init(GPIO_Handle_Mod_t *handle);
void GPIO_DeInit(GPIO_Regs_t *GPIOx);
uint8_t GPIO_ReadPin(GPIO_Regs_t *GPIOx, uint8_t pin);
uint16_t GPIO_ReadPort(GPIO_Regs_t *GPIOx);
void GPIO_WritePin(GPIO_Regs_t *GPIOx, uint8_t pin, uint8_t val);
void GPIO_WritePort(GPIO_Regs_t *GPIOx, uint16_t val);
void GPIO_TogglePin(GPIO_Regs_t *GPIOx, uint8_t pin);
