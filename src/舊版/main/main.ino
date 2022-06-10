//#include <avr/wdt.h>
#include "keyboard.h"

Keyboard keyboard;

void setup(){
  Serial.begin(9600);
  //wdt_enable(WDTO_2S); 
}

void loop() {
  int val0 = analogRead(0);
  int val1 = analogRead(1);
  int val2 = analogRead(2);
  
  if(val0 > 500){
    delay(random(100, 500));
    //Serial.println("val0: ");
    keyboard.clickPrtScn();
    keyboard.clickF12();
  }

  if(val1 > 500){
    delay(random(100, 500));
    //Serial.println("val1: ");
    keyboard.clickF10();
  }

  if(val2 > 500){
    delay(random(100, 500));
    //Serial.println("val2:");
    keyboard.clickF9();
  }
}
