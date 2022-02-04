#define RESET_TIME 180                         // 定義幾秒之後 reset

//記錄開始時間
unsigned long start_time = millis();

//定義重新開機
void(* resetFunc) (void) = 0;

void setup() {
  pinMode(13, OUTPUT);    // sets the digital pin 13 as output
  digitalWrite(13, HIGH); // sets the digital pin 13 on
}

void loop() {
  unsigned long current_time = millis();
  
  // start_time > current_time 代表連續執行超過50天 start_time 歸 0
  // current_time - start_time 為執行時間 如果大於設定的 RESET_TIME 也要重製
  if(start_time > current_time || current_time - start_time >= RESET_TIME*1000){
    // 重置
    resetFunc();
    // 以防萬一在初始化一次
    start_time = millis();
  }

  delay(1);
}