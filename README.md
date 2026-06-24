# Phase 4 — Tactile Feedback Integration and Tactile Interaction Reality

A five-day learning structure aligned with the XJTLU course schedule. The theme of Phase 4 is **tactile feedback integration** and **tactile interaction reality**: students connect screen menus, touch feedback, wireless commands, motors, servos, and car behavior so digital decisions become physical, touchable interaction.

## Theme

**Tactile Feedback Integration and Tactile Interaction Reality**

In this phase, interaction becomes physical:

- Screens, buttons, and touch modules form user input surfaces.
- LEDs, buzzers, vibration motors, servos, and motors provide feedback users can see, hear, feel, and observe.
- Bluetooth/Wi-Fi commands and AI pathfinding logic are translated into real movement and tactile interaction.

## Learning path

| Day | Topic | Outcome |
| --- | --- | --- |
| Day 1 | Screen layout and touch menu control | Design screen layouts, understand touch feedback, and build a touch menu control prototype |
| Day 2 | Bluetooth/Wi-Fi communication and light control | Design communication commands and build Bluetooth light control, with Wi-Fi as an extension |
| Day 3 | Car motor and servo control | Test motors and servos, then build a car motion program |
| Day 4 | Bluetooth remote car and AI-assisted motor decisions | Control car motors through Bluetooth and design AI-assisted motor decision rules |
| Day 5 | AI pathfinding car | Map AI tags, sensor states, or classification labels to motor/servo responses for intelligent pathfinding |

## Folder structure

```text
phase4/
├─ day1-screen-touch-menu/
├─ day2-bluetooth-wifi-light-control/
├─ day3-car-motor-servo-control/
├─ day4-bluetooth-remote-car/
├─ day5-ai-pathfinding-car/
├─ outputs/
└─ resources/
```

## Student submissions

Students can submit lab results in the `outputs/` folder.

Recommended structure:

```text
outputs/lesson1/team-01/
outputs/lesson2/team-01/
outputs/lesson3/team-01/
outputs/lesson4/team-01/
outputs/lesson5/team-01/
```

Each submission should include final Arduino code, a short lab report, and photos or screenshots if available.

## Suggested board and hardware

Examples are written for ESP32-S3 / Arduino-style boards. For Bluetooth and Wi-Fi control, ESP32-based boards are recommended. For touch menu control, use a separate touchscreen module if the kit screen does not support touch.

## Course connection

Phase 3 focuses on environmental perception and Edge AI. Phase 4 continues into advanced AI and multi-sensor development: interfaces, wireless control, motors, servos, and intelligent car behavior.

## Reference / 自学平台

- [FunKit 自学平台](https://funkit.eetree.cn/)
---

## 中文说明

这是智能硬件 Phase 4 的五天课程资料，主题是 **触觉反馈集成，触觉交互现实**。课程重点是把屏幕、触摸、灯光、蜂鸣器、震动、电机、舵机和小车运动整合起来，让数字指令变成可触摸、可感知、可执行的真实交互。

课程内容包括屏幕布局与触摸菜单、蓝牙/Wi-Fi 通信控制、电机与舵机、小车远程控制、AI 智能寻路。

注意：课程安排中提到套件屏幕本身不带触摸功能，如需完成触摸反馈和触摸菜单，需要单独触摸屏模块。若没有触摸屏，可以用按钮或串口命令模拟菜单交互。

最终项目主线为智能寻路小车，语音控制小车可作为拓展方向。
