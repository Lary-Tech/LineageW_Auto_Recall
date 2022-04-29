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
  mouse.reset_mouse();
}

void Drageon1_3F(int place){ //<<<<<<<<<<<<<<<<<<<<<< 1 <= place <= 3
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
  mouse.move(110, 35, 30); //選擇龍谷地監 *改
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
  mouse.reset_mouse();
}

void Drageon4_6F(int place){ //<<<<<<<<<<<<<<<<<<<<<< 4 <= place <= 6
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
  mouse.move(110, 35, 30); //選擇龍谷地監 *改
  delay(100);
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(1000);
  mouse.move(70, 36, 30); // 往上拉
  delay(random(750, 1250));
  
  mouse.slide(0, -5, 30);
  
  delay(500);
  
  mouse.reset_mouse();
  
  delay(1000);
  mouse.move(72, 34 + 4*place, 30); // 選幾層
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
  mouse.reset_mouse();
}

void Drageon5_7F(int place){ //<<<<<<<<<<<<<<<<<<<<<<
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
  mouse.move(110, 35, 30); //選擇龍谷地監 *改
  delay(100);
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(1000);
  mouse.move(70, 36, 30); // 往上拉
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
  
  mouse.reset_mouse();
  
  delay(1000);
  mouse.move(72, 39 + 4*place, 30); // 選幾層
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
  mouse.reset_mouse();
}

void Gludio5_7F(int place){ //<<<<<<<<<<<<<<<<<<<<<<
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
  mouse.move(62, 38, 30); //選古丁谷地監 *改
  delay(100);
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(1000);
  mouse.move(70, 36, 30); // 往上拉
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
  
  mouse.reset_mouse();
  
  delay(1000);
  mouse.move(72, 39 + 4*place, 30); // 選幾層
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
  mouse.reset_mouse();
}

void marked_locations(int place){ //<<<<<<<<<<<<
  Mouse mouse;
  mouse.reset_mouse();
  delay(1000); // 點按叫出儲存的東西
  mouse.move(113, 11, 30); //列表圖案
  delay(100);
  mouse.click(1);
  mouse.click(1);

  // 選圖
  mouse.reset_mouse();
  delay(1000);
  mouse.move(15, 27 + 3*place, 30);
  delay(random(750, 1250));
  mouse.click(1);


  delay(1000);
  
  // 點按傳送
  mouse.move(3, 4, 30);
  delay(random(750, 1250));
  mouse.click(1);
  delay(1000);

  // 自動
  mouse.reset_mouse();

  delay(1000); //<<<<<<<<<
  mouse.move(111, 46, 30); //自動練功
  delay(1250);
  mouse.click(1);
  mouse.reset_mouse();
}
  
