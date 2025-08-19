# Bare-Metal STM32F401RE Matrix Keypad Calculator with I2C LCD Display

## Overview

This project implements a simple calculator on the STM32F401RE microcontroller using **bare-metal programming** (no HAL or RTOS) from scratch.  
User input is taken via a **4x4 matrix keypad** connected through GPIO pins, and the output/display is shown on an **I2C LCD** module using a custom-built I2C driver.

## Features

- Custom low-level GPIO and I2C drivers developed from scratch.
- Matrix keypad scanning for numerical and operator input.
- Basic arithmetic operations: addition, subtraction, multiplication, and division.
- Real-time display of input and results on a 16x2 character LCD via I2C.
- Fully bare-metal approach offers deep understanding of STM32 peripherals.

## Hardware Used

- STM32F401RE Nucleo or similar STM32F4 series MCU board.
- 4x4 matrix keypad connected to GPIO pins (example pins: PA0-PA3 as rows, PA4-PA7 as columns).
- 16x2 LCD with I2C backpack (e.g., PCF8574 I2C expander module).
- Pull-up resistors on keypad columns and I2C bus as needed.

## Software Components

- **stm32f401re.h:** Register definitions for GPIO, RCC, I2C peripherals.
- **GPIO Driver:** Custom GPIO driver for pin initialization, mode setting, and I/O.
- **I2C Driver:** Simple blocking I2C master driver.
- **LCD Driver:** 4-bit LCD communication over I2C protocol.
- **Keypad Driver:** Matrix keypad scan with debounce.
- **Main Application:** Calculator logic handling keypad input, parsing, calculation, and display update.

## Usage Instructions

1. Connect the keypad rows and columns to configured GPIO pins (default PA0-PA7).
2. Connect the I2C LCD module via SDA and SCL lines (default I2C1 pins PB6/PB7).
3. Compile the project in your preferred toolchain (e.g., STM32CubeIDE, Makefile).
4. Flash the firmware to the STM32F401RE board.
5. Use the keypad to input numbers and operators (+, -, *, /).
6. Press '=' to compute and display results on the LCD.
7. 'C' or '#' clears the input.

## Notes

- The code uses blocking polling for I2C and keypad scanning for simplicity.
- Timing and debounce delays are implemented with simple software loops.




## Author

Yash Gour - Embedded Systems Enthusiast

---

