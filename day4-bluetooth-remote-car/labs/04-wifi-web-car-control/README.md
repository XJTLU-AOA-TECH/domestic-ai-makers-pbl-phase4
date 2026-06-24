# Lab 04 — Wi-Fi Web Car Control

## Goal

Control the car from a phone browser through Wi-Fi.

The ESP32 creates a small web server with buttons:

```text
[Forward]
[Left] [Stop] [Right]
[Backward]
```

## Setup

1. Change `WIFI_SSID` and `WIFI_PASSWORD` in the code.
2. Upload the code.
3. Open Serial Monitor to find the ESP32 IP address.
4. Open the IP address in a phone or computer browser on the same Wi-Fi.

## Important

Do not commit real Wi-Fi passwords to GitHub.

## Expected result

Clicking a web button sends a command to the car.

## Challenge

Add speed buttons or a Manual/Auto mode button.
---

## 中文说明

本实验使用 Wi-Fi 网页控制小车。ESP32 提供一个简单网页，手机浏览器打开后可以点击按钮控制小车。

注意：不要把真实 Wi-Fi 密码提交到 GitHub。
