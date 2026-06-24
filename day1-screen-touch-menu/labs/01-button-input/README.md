# Lab 01 — Button Input

## Goal

Read a button and use it to control an LED.

## Wiring

- LED → GPIO 2 through resistor
- Button one side → GPIO 0
- Button other side → GND

This example uses `INPUT_PULLUP`, so pressed usually means `LOW`.

## Expected result

Press the button and the LED turns on. Release the button and the LED turns off.

## Challenge

Reverse the logic: LED is on when the button is not pressed.
---

## 中文说明

本实验使用按钮控制 LED。因为代码使用 `INPUT_PULLUP`，按钮按下时通常读到 `LOW`。
