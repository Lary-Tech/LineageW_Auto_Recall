#include "../h/mouse.h"

void setup()
{
    Serial.begin(9600);
}

int c = 0;

Mouse mouse;

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
      mouse.reset_mouse();

    if( be_attacked ){
        delay(random(100, 500));
        //Serial.println("val0: ");
        recall();
        delay(100);
        buy_supply();
        delay(random(750, 1250));
        mouse.reset_mouse();
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
        mouse.reset_mouse();
        delay(random(750, 1250));
        buy_supply();
        delay(random(750, 1250));
        mouse.reset_mouse();
        delay(random(750, 1250));
        change_place_DroganValley3F();
        delay(random(750, 1250));
    }
}

void recall(){
  delay(100);
  mouse.mouse(0, 3, 30);
  mouse.click(4); // 中鍵
  mouse.click(4); // 中鍵
  
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

void change_place_DroganValley3F(){
  delay(1000); // 點按叫出儲存的東西
  mouse.mouse(113, 11, 30); //列表圖案
  delay(1250);
  mouse.click(1);

  mouse.reset_mouse();

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

  mouse.reset_mouse();

  delay(1000);
  mouse.mouse(62, 38, 30); //確認 
  delay(1250);
  mouse.click(1);

  mouse.reset_mouse();

  delay(1000);
  mouse.mouse(111, 46, 30); //自動練功
  delay(1250);
  mouse.click(1);
}
