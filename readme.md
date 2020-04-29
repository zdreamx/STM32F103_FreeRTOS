# [English](readme_en.md) 

# 标准STM32F103 FreeRTOS工程模板

## 背景

快速STM32F103R6 FreeRTOS工程模板

许多同学因FreeRTOS移植问题迟迟无法上手FreeRTOS,本工程提供一个已经移植并配置的FreeRTOS工程模板,可以快速开始进入FreeRTOS的编程,模板工程提供最基本的LED闪烁任务。工程代码基于当时最新的HAL库和FreeRTOS版本,CMSIS基于Keil(MDK)的运行库。同时工程可以使用最新的ARM COMPILER 6编译。

本工程包含以下内容:
1. FreeRTOS v10.3.1
2. HAL Lib v1.1.4(HAL FW 1.8.0)

## 工程软件和编译器

1. MDK-ARM v5.29
2. arm compiler v6

## 使用说明

下载最新release版本,解压缩后运行USER->STM32F103_FreeRTOS.uvprojx,工程支持软件仿真.

目录路径不要包含非ASCII码字符

## 作者

[@zdreamx](https://github.com/zdreamx)

## 使用许可

随便用
