#include "keyboard.h"

Keyboard::Keyboard(){
  for(int i=0; i<8; i++){
    buf[i] = 0;
  }
}

void Keyboard::releaseKey(){ //釋放按鈕
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}

void Keyboard::clickPrtScn(){ //按PrtSrc
  buf[2] = 70;
  Serial.write(buf, 8);
  delay(100);
  releaseKey();
}

void Keyboard::clickF12(){ //按F12
  buf[2] = 69;
  Serial.write(buf, 8);
  releaseKey();
}

void Keyboard::clickF10(){ //按F12
  buf[2] = 67;
  Serial.write(buf, 8);
  releaseKey();
}

void Keyboard::clickF9(){ //按F12
  buf[2] = 66;
  Serial.write(buf, 8);
  releaseKey();
}