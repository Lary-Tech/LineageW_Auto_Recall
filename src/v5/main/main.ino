struct {
    uint8_t buttons;
    int8_t x;
    int8_t y;
    int8_t wheel;   /* Not yet implemented */
} mouseReport;
 
uint8_t nullReport[4] = { 0, 0, 0, 0 };

int count_place = 4;
unsigned long pre_potion;

void recall();
void hp();
void change_place(int);

void setup()
{
    Serial.begin(9600);
 
    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;

    pre_potion = millis();
}

void loop()
{
    bool be_attacked = ( analogRead(0) > 500 ? true : false );   // A25 遭受敵人攻擊了
    bool hp_not_enough = ( analogRead(1) > 500 ? true : false );   // A26 體力不足了
    bool need_potion = ( analogRead(2) > 500 ? true : false );   // A27 需要補充藥水

    if( be_attacked ){
        // 回程並購買藥水
        recall();
        delay(random(150, 1250));
        buy_supply();
        delay(random(150, 1250));

        // 改圖
        change_place(count_place);
        count_place = count_place + 1;
        if(count_place > 2)
          count_place = 0;
    }

    if( hp_not_enough ){
        hp(); // 按鍵7 的強效藥水 
    }

    unsigned long current_time = millis();

    if( need_potion ){
        if(current_time - pre_potion > 10 * 60 * 1000){ // 10 分鐘以上
          recall();
          delay(random(750, 1250));
          buy_supply();
          delay(random(750, 1250));
          change_place(count_place);

          pre_potion = current_time;
        }else{ // 停止
          recall();

          pre_potion = current_time;
        }
    }
}

void recall(){
  reset_mouse();
  mouse(0, 3, 30);
  click(4); // 中鍵
  click(4); // 中鍵
}

void hp(){
  reset_mouse();
  delay(1000);
  mouse(107, 60, 30);
  click(1);
  delay(100);
  click(1);
}

void buy_supply(){
  reset_mouse();
  delay(100);
  mouse(110, 60, 30); //回捲
  click(1);
  click(1);
  click(1);
  click(1);
  click(1);
  click(1);
  click(1);
  click(1);
  click(1);
  click(1);
  click(1);
  click(1);
  delay(2000);
  
  reset_mouse();
  
  delay(1000);
  mouse(107, 51, 30); //指標按鈕
  delay(2000);
  click(1);

  reset_mouse();
  
  delay(1000);
  mouse(67, 33, 30);//商人
  click(1);

  reset_mouse();
  
  delay(1000);
  mouse(71, 33, 30);//移動
  click(1);

  reset_mouse();

  delay(15000);
  
  delay(1000);
  mouse(103, 61, 30); //自動購買
  delay(1000);
  click(1);

  reset_mouse();
  
  delay(1000);
  mouse(110, 61, 30); //全部購買
  delay(1000);
  click(1);

  reset_mouse();
  
  delay(1000);
  mouse(115, 4, 30); //結束視窗
  delay(1000);
  click(1);
}

void change_place(int place){
  reset_mouse();
  delay(1000); // 點按叫出儲存的東西
  mouse(113, 11, 30); //列表圖案
  delay(100);
  click(1);
  click(1);

  // 選圖
  reset_mouse();
  delay(1000);
  mouse(15, 27 + 3*count_place, 30);
  delay(random(750, 1250));
  click(1);


  delay(1000);
  
  // 點按傳送
  mouse(3, 4, 30);
  delay(random(750, 1250));
  click(1);
  delay(1000);

  // 自動
  reset_mouse();

  delay(1000);
  mouse(111, 46, 30); //自動練功
  delay(1250);
  click(1);
}

void reset_mouse(){
  mouseReport.x = -120;
  mouseReport.y = -120;
  mouseReport.buttons = 0;
  
  for (int i = 0; i < 70; i++) {
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);
  }

  mouseReport.buttons = 0;
  mouseReport.x = 0;
  mouseReport.y = 0;
  mouseReport.wheel = 0;
}

void mouse(int8_t x, int8_t y, int t){    
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

void click(uint8_t cl){
    mouseReport.buttons = cl;
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);
    
    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;

    delay(500);
}

void wheel(int8_t wh){
    mouseReport.wheel = wh;
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);
    
    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;

    delay(500);
}
