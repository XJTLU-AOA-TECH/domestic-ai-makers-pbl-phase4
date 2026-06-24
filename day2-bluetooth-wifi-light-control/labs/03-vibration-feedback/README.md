# Lab 03 — Vibration Feedback

## Goal

Use a vibration motor to provide haptic feedback.

## Wiring

Use a transistor or driver module for the vibration motor.

- Driver input → GPIO 5
- Motor power → external power or module VCC
- GND → common GND

Do not power a motor directly from a GPIO pin.

## Expected result

The vibration motor turns on briefly, then stops.

## Challenge

Create short vibration, long vibration, and double vibration patterns.
---

## 中文说明

本实验使用震动马达提供触觉反馈。注意不要直接用 GPIO 给马达供电，应使用驱动模块或三极管电路。
