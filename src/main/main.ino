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
  int val = analogRead(0);
  //Serial.println(val);
  
  if(val > 11){
    clickPrtScn();
    clickF12();
    delay(1000);
  }
  
  unsigned long current_time = millis();
  // start_time > current_time 代表連續執行超過50天 start_time 歸 0
  // current_time - start_time 為執行時間 如果大於設定的 RESET_TIME 也要重製
  if(start_time > current_time || current_time - start_time >= RESET_TIME*1000){
      // 重置
      resetFunc();
  }
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
