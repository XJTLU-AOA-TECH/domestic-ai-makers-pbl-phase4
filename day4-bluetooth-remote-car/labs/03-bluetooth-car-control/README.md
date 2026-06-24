# Lab 03 — Bluetooth Car Control

## Goal

Control the car using Bluetooth commands.

A phone or computer sends one-character commands:

```text
F → forward
B → backward
L → turn left
R → turn right
S → stop
```

## Important

This example uses ESP32 Bluetooth Classic. Some phones or boards may require BLE instead. If Bluetooth Classic is not available, use the Wi-Fi web control lab.

## Expected result

When the ESP32 receives a command, the car performs the matching action.

## Challenge

Add a speed command, such as `1`, `2`, `3` for low, medium, and high speed.
---

## 中文说明

本实验使用蓝牙控制小车。手机或电脑发送 `F/B/L/R/S` 字符，小车执行前进、后退、左转、右转、停止。

注意：不同手机和开发板对蓝牙支持不同。如果经典蓝牙不可用，可以使用下一节 Wi-Fi 网页控制。
