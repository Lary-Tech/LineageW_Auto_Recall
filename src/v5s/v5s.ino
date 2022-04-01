struct {
    uint8_t buttons;
    int8_t x;
    int8_t y;
    int8_t wheel;   /* Not yet implemented */
} mouseReport;
 
uint8_t nullReport[4] = { 0, 0, 0, 0 };

void setup()
{
    Serial.begin(9600);
 
    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;
}

int c = 0;

void loop()
{
    //int val0 = analogRead(0);
    //int val1 = analogRead(1);
    //int val2 = analogRead(2);

    //Serial.println(val0);
    //Serial.println(val1);
    //Serial.println(val2);

    bool be_attacked = ( analogRead(0) > 500 ? true : false );   // A25 遭受敵人攻擊了
    bool hp_not_enough = ( analogRead(1) > 500 ? true : false );   // A26 體力不足了
    bool need_potion = ( analogRead(2) > 500 ? true : false );   // A27 需要補充藥水
    
    if( be_attacked || hp_not_enough || need_potion )
      reset_mouse();

    if( be_attacked ){
        delay(random(100, 500));
        //Serial.println("val0: ");
        recall();
        delay(100);
        buy_supply();
        delay(random(750, 1250));
        reset_mouse();
        delay(random(750, 1250));
        change_place_DroganValley3F();
        delay(random(750, 1250));
    }

    if( hp_not_enough ){
        delay(100);
        //Serial.println("val1: ");
        hp(); // 按鍵7 的強效藥水或治癒術
       
    }

    if( need_potion ){
        delay(random(100, 500));
        //Serial.println("val2:");
        recall();
        delay(random(750, 1250));
        reset_mouse();
        delay(random(750, 1250));
        buy_supply();
        delay(random(750, 1250));
        reset_mouse();
        delay(random(750, 1250));
        change_place_DroganValley3F();
        delay(random(750, 1250));
    }
}

void recall(){
  delay(100);
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

void change_place_DroganValley3F(){
  delay(1000); // 點按叫出儲存的東西
  mouse(114, 4, 30); //列表圖案
  delay(1250);
  click(1);

  reset_mouse();

  delay(1000);
  mouse(110, 15, 30); //選擇地監選項
  delay(1250);
  click(1);

  reset_mouse();
  
  delay(1000);
  mouse(110, 30, 30); //選擇龍谷地監 *改
  delay(1250);
  click(1);

  reset_mouse();

  delay(1000);
  mouse(72, 33, 30); //飛3F  *改
  delay(1250);
  click(1);

  reset_mouse();

  delay(1000);
  mouse(62, 38, 30); //確認 
  delay(1250);
  click(1);

  reset_mouse();

  delay(1000);
  mouse(111, 46, 30); //自動練功
  delay(1250);
  click(1);
}
/*void change_place(){
  delay(1000); // 點按叫出儲存的東西
  mouse(117, 10, 30);
  delay(random(750, 1250));
  click(1);

  reset_mouse();

  delay(1000);
  mouse(40, 70, 10);
  delay(random(750, 1250));
  click(1);
  
  delay(1000);
  
  mouse(14, 9, 10);
  delay(random(750, 1250));
  click(1);

  delay(1000);

  mouse(93, 18, 30);
  delay(random(750, 1250));
  click(1);
}
*/
void reset_mouse(){
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
