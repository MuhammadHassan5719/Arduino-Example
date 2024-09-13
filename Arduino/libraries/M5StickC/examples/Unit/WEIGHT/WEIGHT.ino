/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5StickC sample source code
*                          配套  M5StickC 示例源代码
* Visit for more information: https://docs.m5stack.com/en/core/m5stickc
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/core/m5stickc
*
* Product:  Weight.
* Date: 2021/8/20
*******************************************************************************
  Please connect to Port,Use WEIGHT Unit to read the analog value returned by
the pressure sensor, convert it into intuitive weight data and send it to
M5Core,Press ButtonA to calibrate 请连接端口,使用WEIGHT
Unit读取压力传感器返回的模拟值，将其转换为直观的重量数据，发送到M5Core，按下按钮A进行校准
*/

#include <M5StickC.h>

#include "HX711.h"

// HX711 related pin Settings.  HX711 相关引脚设置
#define LOADCELL_DOUT_PIN 33
#define LOADCELL_SCK_PIN  32

HX711 scale;
const long LOADCELL_OFFSET  = 50682624;
const long LOADCELL_DIVIDER = 5895655;

void setup() {
    M5.begin();             // Init M5StickC.  初始化M5StickC
    M5.Lcd.setRotation(3);  // Rotating display.  旋转显示屏
    M5.Lcd.setCursor(0, 0);  // Set the cursor at (0,0).  将光标设置在(0,0)处
    M5.Lcd.print("Weight Unit\nBtnA to reset");
    scale.begin(
        LOADCELL_DOUT_PIN,
        LOADCELL_SCK_PIN);  // Initialize library with data output pin, clock
                            // input pin and gain factor.
                            // 初始化库的数据输出引脚，时钟输入引脚和增益因子。
    scale.set_scale(
        LOADCELL_DIVIDER);  // set the SCALE value this value is used to convert
                            // the raw data to measure units.
                            // 设置SCALE值,该值用于将原始数据转换为度量单位
    scale.set_offset(LOADCELL_OFFSET);  // Set the tare weight.  设置皮重
    scale.set_scale(61.2f);  // this value is obtained by calibrating the scale
                             // with known weights; see the README for details.
                             // 这个值是通过校正已知权重的刻度而得到的
    scale.tare();  // reset the scale to 0.  将比例重置为0
}

void loop() {
    M5.update();
    if (M5.BtnA.wasPressed()) {  // If button A is pressed.  如果按键A按下
        scale.set_offset(LOADCELL_OFFSET + scale.read());
        scale.set_scale(61.2f);
        scale.tare();
    }
    static int weight = scale.get_units(5);
    M5.Lcd.fillRect(75, 40, 80, 30, BLACK);
    M5.Lcd.setCursor(30, 40);
    M5.Lcd.printf("Weight:%1d g", weight);
    delay(200);
}