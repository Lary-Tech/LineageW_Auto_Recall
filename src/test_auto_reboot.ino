//多久之後重新設定
unsigned long RESET_TIME = 180;

//記錄開始時間
unsigned long start_time = millis();

//定義重新開機
void(* resetFunc) (void) = 0;

void setup() {
  // 開著預設燈號
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
}

void loop() {
  // 現在時間
  unsigned long current_time = millis();

  // start_time > current_time 代表連續執行超過50天 start_time 歸 0
  // current_time - start_time 為執行時間 如果大於設定的 RESET_TIME 也要重製
  if(start_time > current_time || current_time - start_time >= RESET_TIME*1000){
    // 以防萬一在初始化一次
    start_time = millis();
    // 重置
    resetFunc();
  }

  delay(1);
}