#include <Arduino.h>
#include "mouse.h"

void Aden1_3F(int place){ //<<<<<<<<<<<<<<<<<<<<<<  1 <= place <= 3
  Mouse mouse;
  mouse.reset_mouse();
  delay(1000); // 點按叫出儲存的東西
  mouse.move(114, 4, 30); //列表圖案
  delay(100);
  mouse.click(1);

  mouse.reset_mouse();

  delay(1000); // 選擇地監選項
  mouse.move(110, 15, 30); //列表圖案
  delay(100);
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(1000); 
  mouse.move(15, 35, 30); //選擇龍谷地監 *改
  delay(100);
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(1000);
  mouse.move(72, 24 + 4*place, 30); // 選幾層
  delay(random(750, 1250));
  mouse.click(1);

  mouse.reset_mouse();

  
  delay(1000);
  mouse.move(62, 38, 30); //確認 
  delay(1250);
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(1000); //<<<<<<<<<<<<<<<
  mouse.move(111, 46, 30); //自動練功
  delay(1250);
  mouse.click(1);
}