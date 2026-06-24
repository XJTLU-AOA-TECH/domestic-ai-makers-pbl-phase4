# Hardware List

## Day 1

- ESP32-S3 / Arduino-compatible development board
- USB cable
- Screen/OLED display module
- Separate touchscreen module if real touch input is required
- Button module or touch sensor module as fallback input
- Breadboard and jumper wires

## Day 2

- ESP32-based development board with Bluetooth and Wi-Fi
- LED module, RGB LED, or LED strip for light control
- Optional buzzer or vibration motor for feedback
- Phone or computer for Bluetooth / Wi-Fi testing
- USB cable and jumper wires

## Day 3

- ESP32-S3 / Arduino-compatible development board
- Two-wheel car chassis
- 2 DC motors
- Motor driver module, such as TB6612 or L298N
- Servo motor
- Battery pack or external motor power supply
- Jumper wires, screws, brackets, and cable ties

## Day 4

- ESP32-based development board with Bluetooth and Wi-Fi
- Smart car chassis from Day 3
- 2 DC motors and motor driver
- Optional servo for direction or sensor mount
- Phone or computer for Bluetooth remote control
- Optional Wi-Fi network for browser control

## Day 5

Use a combination of previous modules:

- ESP32-based development board
- Smart car chassis and motor driver
- Servo motor
- Ultrasonic ranging sensor
- Optional AI tag / label source, such as visual classification, audio classification, or manually simulated labels
- Optional OLED, LED, buzzer, or touchscreen for feedback
- Battery pack or external power supply

## Common wiring notes

- Always connect GND between the board and modules.
- Do not power motors directly from GPIO pins.
- Use a motor driver for DC motors and a suitable driver/transistor for vibration motors.
- Check whether modules require 3.3V or 5V.
- Start motor tests with wheels lifted.
- The kit screen may not support touch; use a separate touchscreen module or simulate touch with buttons.
- Do not commit real Wi-Fi credentials to GitHub.
---

## 中文说明

本文件列出了 Phase 4 五天课程所需的硬件材料。Phase 4 已根据课程安排调整为：Day 1 屏幕布局与触摸菜单，Day 2 蓝牙/Wi-Fi 灯光控制，Day 3 小车电机和舵机控制，Day 4 蓝牙遥控小车，Day 5 AI 智能寻路小车。

实际接线时请根据自己的开发板和模块调整引脚号。电机、震动马达等执行器不要直接接 GPIO，应使用驱动模块。无线控制实验不要把真实 Wi-Fi 密码提交到仓库。
