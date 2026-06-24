# Troubleshooting Guide

## Purpose

Use this guide when a lab does not work as expected. Debug one module at a time before combining modules.

---

## General debugging order

1. Check power.
2. Check GND connection.
3. Check pin numbers in code.
4. Test one module only.
5. Open Serial Monitor.
6. Reduce speed or simplify the code.
7. Only combine modules after each part works alone.

---

## Common problems

| Problem | Possible cause | Fix |
| --- | --- | --- |
| Code cannot upload | Wrong board or port | Select correct board and serial port, reconnect USB |
| Serial Monitor shows nothing | Wrong baud rate | Set Serial Monitor to 115200 |
| Button logic is reversed | `INPUT_PULLUP` is used | Remember: pressed usually means `LOW` |
| Touch sensor triggers repeatedly | No debounce or threshold too sensitive | Add debounce time or adjust touch threshold |
| LED does not light | Wrong pin or LED direction | Check pin, GND, resistor, LED polarity |
| Buzzer silent | Wrong pin or passive/active buzzer mismatch | Check wiring and try `tone()` or digital output depending on buzzer type |
| Vibration motor does not move | No driver or insufficient power | Use driver/transistor module and external power if needed |
| Servo shakes | Power is not stable | Use proper servo power and common GND |
| Touchscreen coordinates are wrong | Rotation or calibration mismatch | Calibrate touch and check screen rotation |
| Motor does not move | No motor power or no common GND | Check battery, driver power, shared GND |
| Motor direction is reversed | Motor wires reversed | Swap motor wires or change direction logic |
| Car spins in place | One motor direction is wrong | Fix left/right motor direction first |
| Bluetooth cannot connect | Phone/app/library mismatch | Try another app, check ESP32 Bluetooth support, or use Wi-Fi control |
| Wi-Fi does not connect | Wrong SSID/password or weak signal | Check credentials locally, do not commit them, move closer to router |
| Web page does not open | Phone not on same network or wrong IP | Check Serial Monitor IP and same Wi-Fi network |
| Auto mode behaves incorrectly | Sensor value is wrong | Print raw sensor data before action decisions |

---

## Wireless control notes

- Do not commit real Wi-Fi passwords to GitHub.
- Test car actions with wheels lifted before wireless control.
- Add a stop command and use it often.
- Keep speed low in early tests.

---

## 中文说明

本文件用于帮助学生排查实验问题。调试时不要一开始就运行完整项目，应该先检查供电、共地、引脚号，再逐个模块测试。

蓝牙和 Wi-Fi 控制小车时，必须先确认小车动作函数本身正常。第一次测试时请把轮子架空，并保留停止命令，避免小车突然移动。

不要把真实 Wi-Fi 密码提交到 GitHub。
