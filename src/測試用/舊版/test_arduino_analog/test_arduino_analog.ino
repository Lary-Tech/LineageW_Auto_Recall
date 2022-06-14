#include <Arduino.h>

void setup() {
  Serial.begin(9600);

  pinMode(7, INPUT);
}

void loop() {
  int be_attacked    = analogRead(0);
  int hp_not_enough  = analogRead(1);
  int need_potion    = analogRead(2);
  int en_be_attacked = analogRead(3);
  int en_need_potion = analogRead(4);

  int trigger = digitalRead(7);
  Serial.println(trigger);
  if(trigger != 1){
    delay(3000);
  }
//  String myString = "be_attack: ";
//  Serial.println(myString + be_attacked);
//
//  myString = "hp_not_enough: ";
//  Serial.println(myString + hp_not_enough);
//  
//  myString = "need_potion: ";
//  Serial.println(myString + need_potion);
//
//  myString = "en_be_attacked: ";
//  Serial.println(myString + en_be_attacked);
//
//  myString = "en_need_potion: ";
//  Serial.println(myString + en_need_potion);

  Serial.println("==============================================");

//  delay(1000);
}
