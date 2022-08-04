#define LIMIT 600000

#include "place.h"
#include "mouse.h"

Place place;
Mouse mouse;

unsigned long pre_potion;

void recall();
void hp();

void setup()
{
    Serial.begin(9600);

    pre_potion = 0;
}

int trigger_count = 0;
void loop()
{
    bool be_attacked = ( analogRead(0) > 500 ? true : false );   // A25 遭受敵人攻擊了
    bool hp_not_enough = ( analogRead(1) > 500 ? true : false );   // A26 體力不足了
    bool need_potion = ( analogRead(2) > 500 ? true : false );   // A27 需要補充藥水

    bool trigger = ( digitalRead(7) ? 0 : 1 );   // 聽聲音瞬間觸發

    if(trigger){
      trigger_count ++;
    }
    if(trigger_count == 2){
      recall();
      trigger_count = 0;
    }

    if( be_attacked ){

        // 回程並購買藥水        
        buy_supply();
        delay(random(150, 1250));

        // 改圖
        place.execute(place.DO_CHANGE_PLACE);
    }

    if( hp_not_enough ){
        hp(); // 按鍵7 的強效藥水 
    }


    unsigned long current_time = millis();

    if( need_potion ){
        //Serial.println(pre_time);
        //Serial.println(current_time);
        if(current_time - pre_potion > LIMIT || pre_potion == 0){ // 10 分鐘以上

          buy_supply();
          delay(random(750, 1250));
          place.execute(place.DO_NOT_CHANGE_PLACE);

          pre_potion = current_time;
        }else{ // 停止
          buy_supply();

          pre_potion = current_time;
        }
    }
}

void recall(){
  
  mouse.click(4); // 中鍵
  delay(200);
  mouse.click(4); // 中鍵

}

void hp(){
  mouse.reset_mouse();
  delay(200);
  mouse.move(107, 60, 30);
  mouse.click(1);
  delay(100);
  mouse.click(1);
  mouse.move(-30, -30, 30);
  
}

void buy_supply(){
  mouse.reset_mouse();
  delay(200);
  //mouse.move(0, 3, 30);
  //mouse.click(4); // 中鍵
  //mouse.click(4); // 中鍵
  mouse.move(111, 60, 30); //回捲110,60
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
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);
  mouse.click(1);

  delay(2000);
  mouse.move(-1, -49, 30); //小地圖..110,11
  delay(1500);
  mouse.click(1);


  mouse.move(-95, 3, 30); //領地15,14
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(0, 12, 30); //古魯丁領地15,26
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(-4, 14, 30); //肯特村莊11,40
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(99, 21, 30); //傳送110,61
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(-48, -23, 30); //確定...62,38
  delay(random(1000, 1200));
  mouse.click(1);
  
  
  delay(12000);
  mouse.move(45, 13, 30); //指標按鈕107,51
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(-40, -18, 30);//商人67,33
  mouse.click(1);

  
  delay(random(1000, 1200));
  mouse.move(4, 0, 30);//移動71,33
  mouse.click(1);

  delay(10000);
  
  delay(random(1000, 1200));
  mouse.move(32, 28, 30); //自動購買103,61
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(7, 0, 30); //全部購買110,61
  delay(random(1000, 1200));
  mouse.click(1);
  
  delay(random(1000, 1200));
  mouse.move(5, -57, 30); //結束視窗115,4
  delay(random(1000, 1200));
  mouse.click(1);
}
