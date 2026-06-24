# Pin Map Template

## Purpose

Before uploading code, fill in this table with the real pins used by your board and wiring.

## Day 1 screen and touch menu

| Function | Example pin | Your pin |
| --- | --- | --- |
| OLED / screen SDA | Board SDA |  |
| OLED / screen SCL | Board SCL |  |
| Button fallback | GPIO 0 |  |
| Touch input / touchscreen IRQ | Board-specific |  |

## Day 2 Bluetooth/Wi-Fi light control

| Function | Example pin | Your pin |
| --- | --- | --- |
| LED output | GPIO 2 |  |
| LED strip DIN | GPIO 8 |  |
| Optional buzzer | GPIO 4 |  |

## Day 3 car motor and servo control

| Function | Example pin | Your pin |
| --- | --- | --- |
| Left motor IN1 | GPIO 7 |  |
| Left motor IN2 | GPIO 8 |  |
| Left motor PWM | GPIO 9 |  |
| Right motor IN1 | GPIO 11 |  |
| Right motor IN2 | GPIO 12 |  |
| Right motor PWM | GPIO 13 |  |
| Servo signal | GPIO 10 |  |

## Day 4 Bluetooth remote car

Use the same motor pins as Day 3.

| Function | Example pin | Your pin |
| --- | --- | --- |
| Bluetooth car status LED | GPIO 2 |  |
| Optional web-control status output |  |  |

## Day 5 AI pathfinding car

| Function | Example pin | Your pin |
| --- | --- | --- |
| Ultrasonic TRIG | GPIO 5 |  |
| Ultrasonic ECHO | GPIO 6 |  |
| Servo scan signal | GPIO 10 |  |
| Optional AI label input |  |  |
| Optional feedback output |  |  |

## Power notes

| Module | Voltage | Notes |
| --- | --- | --- |
| Development board | USB / 5V | Depends on board |
| Touchscreen | Board-specific | Check display documentation |
| LED strip | 5V often required | Use external power for many LEDs |
| Servo | 5V recommended | May need external power |
| DC motors | Battery / external power | Use motor driver |
| Ultrasonic sensor | 3.3V or 5V | Check ECHO voltage before connecting to ESP32 |

## 中文说明

上传代码前，请先填写本引脚表。很多实验失败不是代码问题，而是代码中的引脚号和实际接线不一致。

特别注意：电机、舵机、灯带等执行器可能需要外部电源；电机驱动模块、开发板、传感器必须共地。
