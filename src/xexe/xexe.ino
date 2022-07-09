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

    delay(3000);

    pre_potion = 0;
}

int trigger_count = 0;
int change_place_delay = 0;
int DELAY_TIME = 20000;
void loop()
{
    bool be_attacked = ( analogRead(0) > 500 ? true : false );   // A25 遭受敵人攻擊了
    bool hp_not_enough = ( analogRead(1) > 500 ? true : false );   // A26 體力不足了
    bool need_potion = ( analogRead(2) > 500 ? true : false );   // A27 需要補充藥水
    bool en_be_attacked = ( analogRead(3) > 500 ? true : false ); // B0 English 遭受敵人攻擊
    bool en_need_potion = ( analogRead(4) > 500 ? true : false );   // B1 English 需要補充藥水
    bool en_hp_not_enough = ( analogRead(5) > 500 ? true : false );   // B2 English 體力不足了

    bool trigger = ( digitalRead(7) ? 0 : 1 );   // 聽聲音瞬間觸發

    if(change_place_delay >= 100){
      change_place_delay --;
    }else if(change_place_delay != 0){
      // 自動
      mouse.reset_mouse();

      delay(1000); //<<<<<<<<<
      mouse.move(111, 46, 30); //自動練功
      delay(1250);
      mouse.click(1);
      delay(500);
      mouse.move(-30, -30, 30);

      change_place_delay = 0;
    }else if(change_place_delay < 0){
      change_place_delay = 0;
    }

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

        //查看是否需要等待
        if( place.isWait() ){
          change_place_delay = DELAY_TIME;
        } else {
          change_place_delay = 100;
        } 
    }

    if( hp_not_enough || en_hp_not_enough ){
        hp(); // 按鍵7 的強效藥水 
        change_place_delay = 0;
    }

    if(en_be_attacked ){
        teleport_scroll(); 
        change_place_delay = 0;
    }

    unsigned long current_time = millis();

    if( need_potion || en_need_potion ){
        //Serial.println(pre_time);
        //Serial.println(current_time);
        if(current_time - pre_potion > LIMIT || pre_potion == 0){ // 10 分鐘以上

          buy_supply();
          delay(random(750, 1250));
          place.execute(place.DO_NOT_CHANGE_PLACE);

          pre_potion = current_time;

          //查看是否需要等待
          if( place.isWait() ){
            change_place_delay = DELAY_TIME;
          } else {
            change_place_delay = 100;
          } 
        }else{ // 停止
          buy_supply();

          pre_potion = current_time;

          change_place_delay = 0;
        }
    }

    delay(1);
}

void recall(){
  
  mouse.click(4); // 中鍵
  mouse.click(4); // 中鍵

}

void teleport_scroll(){
  mouse.reset_mouse();
  mouse.move(0, 3, 30);
  mouse.click(4); // 中鍵
  mouse.click(4); // 中鍵
  mouse.move(62, 38, 30);
}

void hp(){
  mouse.reset_mouse();
  delay(1000);
  mouse.move(107, 60, 30);
  mouse.click(1);
  delay(100);
  mouse.click(1);
  mouse.move(-30, -30, 30);
  
}

void buy_supply(){
  mouse.reset_mouse();
  delay(100);
  mouse.move(110, 60, 30); //回捲
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
  mouse.move(107, 51, 30); //指標按鈕
  delay(2000);
  mouse.click(1);

  mouse.reset_mouse();
  
  delay(1000);
  mouse.move(67, 33, 30);//商人
  mouse.click(1);

  mouse.reset_mouse();
  
  delay(1000);
  mouse.move(71, 33, 30);//移動
  mouse.click(1);

  mouse.reset_mouse();

  delay(15000);
  
  delay(1000);
  mouse.move(103, 61, 30); //自動購買
  delay(1000);
  mouse.click(1);

  mouse.reset_mouse();
  
  delay(1000);
  mouse.move(110, 61, 30); //全部購買
  delay(1000);
  mouse.click(1);

  mouse.reset_mouse();
  
  delay(1000);
  mouse.move(115, 4, 30); //結束視窗
  delay(1000);
  mouse.click(1);
}
