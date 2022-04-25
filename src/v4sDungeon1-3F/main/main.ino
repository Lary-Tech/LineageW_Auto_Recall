#define LIMIT 600000

struct {
    uint8_t buttons;
    int8_t x;
    int8_t y;
    int8_t wheel;   /* Not yet implemented */
} mouseReport;
 
uint8_t nullReport[4] = { 0, 0, 0, 0 };

int count_place = 2;
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

    pre_potion = 0;
}

Mouse mouse;

void loop()
{
    bool be_attacked = ( analogRead(0) > 500 ? true : false );   // A25 遭受敵人攻擊了
    bool hp_not_enough = ( analogRead(1) > 500 ? true : false );   // A26 體力不足了
    bool need_potion = ( analogRead(2) > 500 ? true : false );   // A27 需要補充藥水
<<<<<<< HEAD:src/v5s/v5s.ino
    
    if( be_attacked || hp_not_enough || need_potion )
      mouse.reset_mouse();
=======
>>>>>>> V4sDragon1F-3F:src/v4sDungeon1-3F/main/main.ino

    if( be_attacked ){
        // 回程並購買藥水
        recall();
        delay(random(150, 1250));
        buy_supply();
<<<<<<< HEAD:src/v5s/v5s.ino
        delay(random(750, 1250));
        mouse.reset_mouse();
        delay(random(750, 1250));
        change_place_DroganValley3F();
        delay(random(750, 1250));
=======
        delay(random(150, 1250));

        // 改圖
        change_place(count_place);
        count_place = count_place + 1;
        if(count_place > 2)
          count_place = 0;
>>>>>>> V4sDragon1F-3F:src/v4sDungeon1-3F/main/main.ino
    }

    if( hp_not_enough ){
        hp(); // 按鍵7 的強效藥水 
    }

    unsigned long current_time = millis();

    if( need_potion ){
<<<<<<< HEAD:src/v5s/v5s.ino
        delay(random(100, 500));
        //Serial.println("val2:");
        recall();
        delay(random(750, 1250));
        mouse.reset_mouse();
        delay(random(750, 1250));
        buy_supply();
        delay(random(750, 1250));
        mouse.reset_mouse();
        delay(random(750, 1250));
        change_place_DroganValley3F();
        delay(random(750, 1250));
=======
        //Serial.println(pre_time);
        //Serial.println(current_time);
        if(current_time - pre_potion > LIMIT || pre_potion == 0){ // 10 分鐘以上
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
>>>>>>> V4sDragon1F-3F:src/v4sDungeon1-3F/main/main.ino
    }
}

void recall(){
<<<<<<< HEAD:src/v5s/v5s.ino
  delay(100);
  mouse.mouse(0, 3, 30);
  mouse.click(4); // 中鍵
  mouse.click(4); // 中鍵
  
=======
  reset_mouse();
  mouse(0, 3, 30);
  click(4); // 中鍵
  click(4); // 中鍵
>>>>>>> V4sDragon1F-3F:src/v4sDungeon1-3F/main/main.ino
}

void hp(){
  mouse.reset_mouse();
  delay(1000);
  mouse.mouse(107, 60, 30);
  mouse.click(1);
  delay(100);
  mouse.click(1);
}

void buy_supply(){
  mouse.reset_mouse();
  delay(100);
  mouse.mouse(110, 60, 30); //回捲
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  delay(2000);
  
  mouse.reset_mouse();
  
  delay(1000);
  mouse.mouse(107, 51, 30); //指標按鈕
  delay(2000);
  mouse.click(1);

  mouse.reset_mouse();
  
  delay(1000);
  mouse.mouse(67, 33, 30);//商人
  mouse.click(1);

  mouse.reset_mouse();
  
  delay(1000);
  mouse.mouse(71, 33, 30);//移動
  mouse.click(1);

  mouse.reset_mouse();

  delay(15000);
  
  delay(1000);
  mouse.mouse(103, 61, 30); //自動購買
  delay(1000);
  mouse.click(1);

  mouse.reset_mouse();
  
  delay(1000);
  mouse.mouse(110, 61, 30); //全部購買
  delay(1000);
  mouse.click(1);

  mouse.reset_mouse();
  
  delay(1000);
  mouse.mouse(115, 4, 30); //結束視窗
  delay(1000);
  mouse.click(1);
}

void change_place(int place){ //<<<<<<<<<<<<<<<<<<<<<<
  reset_mouse();
  delay(1000); // 點按叫出儲存的東西
<<<<<<< HEAD:src/v5s/v5s.ino
  mouse.mouse(113, 11, 30); //列表圖案
  delay(1250);
  mouse.click(1);
=======
  mouse(114, 4, 30); //列表圖案
  delay(100);
  click(1);
>>>>>>> V4sDragon1F-3F:src/v4sDungeon1-3F/main/main.ino

  mouse.reset_mouse();

<<<<<<< HEAD:src/v5s/v5s.ino
  delay(1000);
  mouse.mouse(110, 15, 30); //選擇地監選項
  delay(1250);
  mouse.click(1);

  mouse.reset_mouse();
  
  delay(1000);
  mouse.mouse(110, 30, 30); //選擇龍谷地監 *改
  delay(1250);
  mouse.click(1);

  mouse.reset_mouse();

  delay(1000);
  mouse.mouse(72, 33, 30); //飛3F  *改
  delay(1250);
  mouse.click(1);
=======
  delay(1000); // 選擇地監選項
  mouse(110, 15, 30); //列表圖案
  delay(100);
  click(1);
  
  reset_mouse();

  delay(1000); 
  mouse(110, 35, 30); //選擇龍谷地監 *改
  delay(100);
  click(1);
  
  reset_mouse();

  delay(1000);
  mouse(72, 24 + 4*count_place, 30); // 選幾層
  delay(random(750, 1250));
  click(1);
>>>>>>> V4sDragon1F-3F:src/v4sDungeon1-3F/main/main.ino

  mouse.reset_mouse();

  
  delay(1000);
  mouse.mouse(62, 38, 30); //確認 
  delay(1250);
<<<<<<< HEAD:src/v5s/v5s.ino
  mouse.click(1);

  mouse.reset_mouse();

  delay(1000);
  mouse.mouse(111, 46, 30); //自動練功
  delay(1250);
  mouse.click(1);
=======
  click(1);
  
  reset_mouse();

  delay(1000); //<<<<<<<<<<<<<<<
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
>>>>>>> V4sDragon1F-3F:src/v4sDungeon1-3F/main/main.ino
}
