#include "keypad.h"

// Adjust for your wiring: PA0–PA3 as rows, PA4–PA7 as columns
const uint8_t rowPins[KEYPAD_ROWS] = {0, 1, 2, 3};
const uint8_t colPins[KEYPAD_COLS] = {4, 5, 6, 7};

const char keymap[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

void Keypad_Init(void) {
    GPIO_EnableClock(GPIOA, ENABLED);
    for(int i=0; i<KEYPAD_ROWS; i++) {
        GPIO_Handle_Mod_t rowHandle = {GPIOA, {rowPins[i], GPIO_MODE_OUT, GPIO_SPEED_LOW, GPIO_OT_PP, GPIO_NO_PULL, 0}};
        GPIO_Init(&rowHandle);
        GPIO_WritePin(GPIOA, rowPins[i], GPIO_PIN_SET);
    }
    for(int j=0; j<KEYPAD_COLS; j++) {
        GPIO_Handle_Mod_t colHandle = {GPIOA, {colPins[j], GPIO_MODE_IN, GPIO_SPEED_LOW, GPIO_OT_PP, GPIO_PULL_UP, 0}};
        GPIO_Init(&colHandle);
    }
}

char Keypad_GetKey(void) {
    for(int i=0; i<KEYPAD_ROWS; i++) {
        GPIO_WritePin(GPIOA, rowPins[i], GPIO_PIN_RESET);
        for(int j=0; j<KEYPAD_COLS; j++) {
            if(GPIO_ReadPin(GPIOA, colPins[j]) == 0) {
                for(volatile int k=0; k<1000; k++);
                if(GPIO_ReadPin(GPIOA, colPins[j]) == 0) {
                    GPIO_WritePin(GPIOA, rowPins[i], GPIO_PIN_SET);
                    return keymap[i][j];
                }
            }
        }
        GPIO_WritePin(GPIOA, rowPins[i], GPIO_PIN_SET);
    }
    return 0;
}
