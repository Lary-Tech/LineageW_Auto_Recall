#define LIMIT 600000

#include "place.h"
#include "placeEnglish.h"
#include "mouse.h"

Place place;
PlaceEnglish placeEnglish;
Mouse mouse;

unsigned long pre_potion;

void teleport();
void hp();

void setup()
{
    Serial.begin(9600);

    delay(3000);

    pre_potion = 0;
}

int trigger_count = 0;
int change_place_delay = 0;
long long int DELAY_TIME = 20000; //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<行走秒數
void loop()
{
    bool be_attacked = ( analogRead(0) > 500 ? true : false );   // A25 遭受敵人攻擊了
    bool hp_not_enough = ( analogRead(1) > 500 ? true : false );   // A26 體力不足了
    bool need_potion = ( analogRead(2) > 500 ? true : false );   // A27 需要補充藥水
    bool en_be_attacked = ( analogRead(3) > 500 ? true : false ); // B0 English 遭受敵人攻擊
    bool en_need_potion = ( analogRead(4) > 500 ? true : false );   // B1 English 需要補充藥水
    bool en_hp_not_enough = ( analogRead(5) > 500 ? true : false );   // B2 English 體力不足了

    bool trigger = ( digitalRead(7) ? 0 : 1 );   // 聽聲音瞬間觸發

    if(change_place_delay >= 100){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<自動行走等待
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

    if(trigger){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<一刀飛
      trigger_count ++;
    }
    if(trigger_count == 2){
      teleport();
      trigger_count = 0;
    }

    if( be_attacked ){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<中文被攻擊

        // 回程並購買藥水
        recall();        
        buy_supply();
        //stash_keeper();
        receive_mail();
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

    if( en_be_attacked ){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<英文被攻擊

        // 回程並購買藥水
        recall();          
        buy_supply();
        //stash_keeper();
        receive_mail();
        delay(random(150, 1250));

        // 改圖
        placeEnglish.execute(placeEnglish.DO_CHANGE_PLACEEnglish);

        //查看是否需要等待
        if( place.isWait() ){
          change_place_delay = DELAY_TIME;
        } else {
          change_place_delay = 100;
        } 
    }

    if( hp_not_enough ){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<中文體力不足

        // 回程並購買藥水
        recall();          
        buy_supply();
        //stash_keeper();
        receive_mail();
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

    if( en_hp_not_enough ){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<英文體力不足

        // 回程並購買藥水
        recall();          
        buy_supply();
        //stash_keeper();
        receive_mail();
        delay(random(150, 1250));

        // 改圖
        placeEnglish.execute(placeEnglish.DO_CHANGE_PLACEEnglish);

        //查看是否需要等待
        if( place.isWait() ){
          change_place_delay = DELAY_TIME;
        } else {
          change_place_delay = 100;
        } 
    }

    if( en_need_potion ){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<英文藥水不足

        // 回程並購買藥水
        recall();          
        buy_supply();
        //stash_keeper();
        receive_mail();
        delay(random(150, 1250));

        // 改圖
        placeEnglish.execute(placeEnglish.DO_CHANGE_PLACEEnglish);

        //查看是否需要等待
        if( place.isWait() ){
          change_place_delay = DELAY_TIME;
        } else {
          change_place_delay = 100;
        } 
    }
    
 
    unsigned long current_time = millis();

    if( need_potion ){  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<中文藥水不足
        //Serial.println(pre_time);
        //Serial.println(current_time);
        if(current_time - pre_potion > LIMIT || pre_potion == 0){ // 10 分鐘以上
          recall();  
          buy_supply();
          //stash_keeper();
          receive_mail();
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
          recall();  
          buy_supply();

          pre_potion = current_time;

          change_place_delay = 0;
        }
    }

    delay(1);
}

void teleport(){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<使用滑鼠中鍵2次
  
  mouse.click(4); // 中鍵
  delay(200);
  mouse.click(4); // 中鍵

}

void hp(){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<使用熱鍵2次
  mouse.reset_mouse();
  delay(1000);
  mouse.move(107, 60, 30);
  mouse.click(1);
  delay(100);
  mouse.click(1);
  mouse.move(-30, -30, 30);
  
}

void recall(){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<緊急回村，飛肯特
  mouse.reset_mouse();
  delay(200);
  mouse.move(111, 60, 30); //回捲
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
  
  delay(1000);
  mouse.move(-1, -49, 30); //小地圖原座標(110, 11 ,30)
  delay(1000);
  mouse.click(1);


  mouse.move(-95, 3, 30); //領地原座標(15, 14 ,30)
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(0, 12, 30); //古魯丁領地原座標(15, 26 ,30)
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(-4, 14, 30); //肯特村莊原座標(11, 40 ,30))
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(99, 21, 30); //傳送原座標(110, 61 ,30)
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(-48, -23, 30); //確定原座標(62, 38 ,30)
  delay(random(1000, 1200));
  mouse.click(1);
  delay(12000);
}
void buy_supply(){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<雜貨商購買補給品
  
  mouse.reset_mouse();
  mouse.move(107, 51, 30); //指標按鈕
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(-40, -18, 30);//商人原座標(67, 33 ,30)
  mouse.click(1);

  
  delay(random(1000, 1200));
  mouse.move(4, 0, 30);//移動原座標(71, 33 ,30)
  mouse.click(1);

  delay(10000);
  
  delay(random(1000, 1200));
  mouse.move(32, 28, 30); //自動購買原座標(103, 61 ,30)
  delay(random(1000, 1200));
  mouse.click(1);

  delay(random(1000, 1200));
  mouse.move(7, 0, 30); //全部購買原座標(110, 61 ,30)
  delay(random(1000, 1200));
  mouse.click(1);
  
  delay(random(1000, 1200));
  mouse.move(5, -57, 30); //結束視窗原座標(115, 4 ,30)
  delay(random(1000, 1200));
  mouse.click(1);
}

void stash_keeper(){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<倉庫領勇水
  mouse.reset_mouse();
  delay(1000);
  mouse.move(107, 51, 30); //指標按鈕
  delay(1000);
  mouse.click(1);
  
  delay(1000);
  mouse.move(-56, -18, 30);//倉庫原座標(51, 33, 30)
  mouse.click(1);
  
  delay(1000);
  mouse.move(-4, 0, 30);//移動***原座標(47, 33, 30)
  mouse.click(1);
  delay(8000);

  mouse.move(56, 28, 30); //自動存放原座標(103, 61, 30)
  delay(1000);
  mouse.click(1);
  
  delay(1000);
  mouse.move(7, 0, 30); //全部存放原座標(110, 61, 30)
  delay(1000);
  mouse.click(1);

  delay(1000);
  mouse.move(-105, -47, 30); //選第一個物品原座標(5, 14, 30)
  delay(1000);
  mouse.click(1);
  
  delay(1000);
  mouse.move(43, 47, 30); //選30個原座標(48, 61, 30)
  delay(200);
  mouse.click(1);
  delay(200);
  mouse.click(1);
  delay(200);
  mouse.click(1);
  delay(200);
    
  delay(1000);
  mouse.move(62, 0, 30); //全部領取原座標(110, 61, 30)
  delay(1000);
  mouse.click(1);
    
  delay(1000);
  mouse.move(5, -57, 30); //結束視窗原座標(115, 4, 30)
  delay(1000);
  mouse.click(1);
}

void receive_mail(){ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<自動領信
  mouse.reset_mouse();
  delay(1000); // 
  mouse.move(114, 4, 30); //列表圖案
  delay(1000);
  mouse.click(1);

  delay(1000); // 
  mouse.move(-4, 21, 30); //選擇信件選項原座標(110, 25, 30)
  delay(1000);
  mouse.click(1);
  
  delay(1000); 
  mouse.move(-26, 36, 30); //系統 全部領取原座標(84, 61, 30)
  delay(100);
  mouse.click(1);

  delay(1000); 
  mouse.move(-22, -17, 30); //確定原座標(62, 44, 30)
  delay(1000);
  mouse.click(1);

  delay(1000); 
  mouse.move(-24, -37, 30); //點商人原座標(38, 7, 30)
  delay(1000);
  mouse.click(1);

  delay(1000); 
  mouse.move(46, 54, 30); //商人 全部領取原座標(84, 61, 30)
  delay(1000);
  mouse.click(1);

  delay(1000); 
  mouse.move(-22, -17, 30); //確定原座標(62, 44, 30)
  delay(1000);
  mouse.click(1);
  
  delay(1000);
  mouse.move(53, -40, 30); //結束視窗原座標(115, 4, 30)
  delay(1000);
  mouse.click(1);
}
