#include <ld3320.h>

//定義一個語音辨識對
VoiceRecognition Voice;

//定義重新開機
void(* resetFunc) (void) = 0;

//記錄開始時間
unsigned long start_time = 0;

//多久之後重新設定
unsigned long RESET_TIME = 180;

//定義寫入按鍵
uint8_t buf[8] = { 0 };
void clickF12();
void releaseKey();

void setup(){
  //開機完成亮燈
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  Serial.begin(9600);  
  
  // 初始化 ld3320
  Voice.init(MIC);                                
  Voice.addCommand("zao shou di ren gong chi le", 0); 
  Voice.micVol(100);      
  Voice.voiceMaxLength(22);              
  Voice.start();

  start_time = millis()
}


void loop() {
  // 如果 read 到 0
  switch(Voice.read())
  {
    case 0:
      clickF12();
      break;   
    default:
      unsigned long current_time = millis();
      // start_time > current_time 代表連續執行超過50天 start_time 歸 0
      // current_time - start_time 為執行時間 如果大於設定的 RESET_TIME 也要重製
      if(start_time > current_time || current_time - start_time >= RESET_TIME*1000){
          //重置時暗掉
          digitalWrite(13, LOW)
          // 重置
          resetFunc();
      }
      break;
  }
}

void clickF12(){
  //按下按鈕
  buf[2] = 69;
  Serial.write(buf, 8);
  
  //持續 1s
  delay(1000);
  
  releaseKey();
}

void releaseKey(){
  //釋放按鈕
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}
