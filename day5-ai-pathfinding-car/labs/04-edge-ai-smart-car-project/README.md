# Lab 04 — Edge AI Smart Car Project

## Goal

Build a final smart car project that combines interaction, wireless control, sensing, and Edge AI-style decision logic.

## Project idea

The smart car has two modes:

1. Manual mode: user controls the car through Bluetooth, Wi-Fi, or touchscreen.
2. Auto mode: the car reads sensors and makes local decisions.

## Edge AI concept

For this beginner project, Edge AI can be implemented at three levels:

| Level | Method | Example |
| --- | --- | --- |
| Basic | Rule-based decision | If distance is close, stop |
| Standard | Weighted score | Risk score combines distance, sound, and mode |
| Advanced | Lightweight model concept | A local model classifies state as safe/warning/danger |

## Requirements

Your final project should:

1. Include at least one manual control method.
2. Include at least one automatic decision rule.
3. Control car movement safely.
4. Provide feedback through Serial, LED, buzzer, OLED, or screen.
5. Explain why local decision-making is useful.

## Challenge

Add visual or audio input from Phase 3 as part of the automatic decision.
---

## 中文说明

本实验是 Phase 4 的最终项目。学生需要把手动控制、自动控制、传感器输入和边缘 AI 决策思想结合起来。

边缘 AI 在这里强调“本地决策”：设备不一定要把数据上传到云端，而是在开发板本地根据输入判断下一步动作。
