#include <Arduino.h>
#include "mouse.h"

Mouse::Mouse(){
    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;
}

Mouse::~Mouse(){
}

void Mouse::reset_mouse(){
  mouseReport.x = -120;
  mouseReport.y = -120;
  mouseReport.buttons = 0;
  
  for (int i = 0; i < 50; i++) {
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);
  }

  mouseReport.buttons = 0;
  mouseReport.x = 0;
  mouseReport.y = 0;
  mouseReport.wheel = 0;
}

void Mouse::move(int8_t x, int8_t y, int t){    
    mouseReport.x = x;
    mouseReport.y = y;
    mouseReport.buttons = 0;
    for (int i = 0; i < t; i++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }

    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;

    delay(100);
}

void Mouse::click(uint8_t cl){
    mouseReport.buttons = cl;
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);
    
    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;

    delay(500);
}

void Mouse::slide(int8_t x, int8_t y, int t){
  mouseReport.buttons = 1;
  mouseReport.x = x;
  mouseReport.y = y;
  for (int i = 0; i < t; i++) {
    uint8_t tmpReport[4] = { 1, 0, 0, 0 };
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &tmpReport, 4);
  }

  mouseReport.buttons = 0;
  mouseReport.x = 0;
  mouseReport.y = 0;
}

void Mouse::wheel(uint8_t wh){
    mouseReport.wheel = wh;
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);
    
    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;

    delay(500);
}
