# Lab 01 — Single Motor Test

## Goal

Test one DC motor using a motor driver.

## Wiring

Example for one motor channel:

- IN1 → GPIO 7
- IN2 → GPIO 8
- PWM → GPIO 9
- Motor power → external battery or motor power supply
- GND → common GND

## Expected result

The motor rotates forward, stops, rotates backward, and stops again.

## Challenge

Change the speed value and observe how the motor changes.
---

## 中文说明

本实验测试一个直流电机。注意电机必须通过电机驱动模块供电和控制，不能直接接 GPIO。
