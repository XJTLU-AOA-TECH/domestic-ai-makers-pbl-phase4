# Lab 02 — Touch Toggle

## Goal

Use a touch input to toggle a device state.

Touch once to turn the state on. Touch again to turn it off.

## Wiring

Use a touch sensor module or capacitive touch pin:

- Touch sensor VCC → 3.3V
- Touch sensor GND → GND
- Touch sensor OUT → GPIO 4
- LED → GPIO 2

## Expected result

Each touch changes the LED state.

## Challenge

Print the current mode name, such as `Mode: ON` or `Mode: OFF`.
---

## 中文说明

本实验使用触摸输入切换状态。触摸一次打开，再触摸一次关闭，帮助学生理解状态机和交互逻辑。
