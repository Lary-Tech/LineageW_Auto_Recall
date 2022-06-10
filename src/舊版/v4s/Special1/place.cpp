#include "place.h"
#include "mouse.h"

Place::Place(){
  insert_place(&v4sLocations, 1);

  insert_place(&v4sDungeon5_7F, 7);
}

Place::~Place(){
}

void Place::execute(change_flag flag){
  int i = count_place;
  void(*func)(int) = place_array[i].func;
  int arg = place_array[i].arg;

  func(arg);

  if(flag == DO_CHANGE_PLACE){
    count_place++;
    
    if(count_place >= n_place){
      count_place = 0;
    }
  }
}

void Place::execute(int i){
  void(*func)(int) = place_array[i].func;
  int arg = place_array[i].arg;

  func(arg);
}

void Place::insert_place(void(*func)(int), int arg){
  int n = n_place;
  place_array[n].func = func;
  place_array[n].arg = arg;

  n_place = n + 1;
}

/*把多出來的 function 寫在下面*/
void v4sLocations(int place){ //>>>>>>>>>>>>> 1 <= place <= 3
  Mouse mouse;
  mouse.reset_mouse();
  delay(1000); // 點按叫出儲存的東西
  mouse.move(113, 11, 30); //列表圖案
  delay(100);
  click(1);
  click(1);

  // 選圖
  mouse.reset_mouse();
  delay(1000);
  mouse.move(15, 27 + 3*count_place, 30);
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

void v4sDungeon5_7F(int place){ //<<<<<<<<<<<<<<<<<<<<<< 5 <= place <= 7
  Mouse mouse;
  mouse.reset_mouse();
  delay(1000); // 點按叫出儲存的東西
  mouse(114, 4, 30); //列表圖案
  delay(100);
  click(1);

  reset_mouse();

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
  mouse(70, 36, 30); // 往上拉
  delay(random(750, 1250));
  
  mouseReport.buttons = 1;
  mouseReport.x = 0;
  mouseReport.y = -5;
  for (int i = 0; i < 30; i++) {
    uint8_t tmpReport[4] = { 1, 0, 0, 0 };
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &tmpReport, 4);
  }

  mouseReport.buttons = 0;
  mouseReport.x = 0;
  mouseReport.y = 0;
  
  delay(500);
  
  reset_mouse();
  
  delay(1000);
  mouse(72, 39 + 4*place, 30); // 選幾層
  delay(random(750, 1250));
  click(1);
  
  reset_mouse();

  
  delay(1000);
  mouse(62, 38, 30); //確認 
  delay(1250);
  click(1);
  
  reset_mouse();

  delay(1000); //<<<<<<<<<<<<<<<
  
  // 自動
  reset_mouse();

  delay(1000);
  mouse(111, 46, 30); //自動練功
  delay(1250);
  click(1);
}