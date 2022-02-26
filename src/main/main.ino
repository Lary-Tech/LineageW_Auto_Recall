//定義重新開機
void(* resetFunc) (void) = 0;

//記錄開始時間
unsigned long start_time = 0;

//多久之後重新設定
unsigned long RESET_TIME = 8;

//定義寫入按鍵
uint8_t buf[8] = { 0 };
void clickPrtScn();
void clickF12();
void releaseKey();

void setup(){
  Serial.begin(9600);
  start_time = millis();

  pinMode(13, OUTPUT);
  while(analogRead(0) > 10){
    digitalWrite(13, HIGH);
  }
  digitalWrite(13, LOW);
}

void loop() {
  int val0 = analogRead(0);
  int val1 = analogRead(1);
  int val2 = analogRead(2);
  
  Serial.println("V: ");
  Serial.println(val0);
  Serial.println(val1);
  Serial.println(val2);

  if(val0 > 10 || val1 > 10 || val2 > 10){
    delay(3000);
  }
  
  delay(100);
}

void clickPrtScn(){
  digitalWrite(13, HIGH);
  //按下按鈕
  buf[2] = 70;
  Serial.write(buf, 8);
  
  //持續 0.1s
  delay(100);
  releaseKey();
  digitalWrite(13, LOW);
}

void clickF12(){
  digitalWrite(13, HIGH);
  //按下按鈕
  buf[2] = 69;
  Serial.write(buf, 8);
  
  //持續 0.1s
  delay(100);
  releaseKey();
  digitalWrite(13, LOW);
}

void releaseKey(){
  //釋放按鈕
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}
