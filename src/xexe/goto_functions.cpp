#include <Arduino.h>
#include "mouse.h"

void marked_locations(int place){ //<<<<<<<<<<<<祝瞬
  Mouse mouse;
  mouse.reset_mouse();
  delay(random(300, 700));
  mouse.move(113, 11, 30); //記憶位置
  delay(random(100, 200));
  mouse.click(1);
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(-98, 16 + 3*place, 30); //選擇記憶座標順序原座標(15, 27 , 30)
  delay(random(750, 1250));
  mouse.click(1);


  delay(random(300, 700));
  mouse.move(3, 4 - 3*place, 30);//點按傳送原座標(3, 4, 30)
  delay(random(750, 1250));
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(108, 42, 30); //自動練功原座標(111, 46, 30)
  delay(1250);
  mouse.click(1);
  delay(random(300, 700));
  mouse.move(-30, -30, 30);
}

void Favorites_Tag1(int place){ //<<<<<<<<<<<<書籤
  Mouse mouse;
  mouse.reset_mouse();
  mouse.move(110, 11, 30); //小地圖原座標
  delay(random(500, 700));
  mouse.click(1);
  mouse.click(1);

  delay(2000);
  mouse.move(-95, 7, 30); //點書籤原座標(15, 18 ,30)
  delay(random(500, 700));
  mouse.click(1);

  // 選圖
  delay(random(500, 700));
  mouse.move(0, 4 + 3*place, 30); //選擇書籤順序原座標(15, 22 ,30)
  delay(random(500, 700));
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(95, 39 - 3*place, 30); //金幣傳送原座標(110, 61 ,30)
  delay(random(300, 700));
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(-48, -23, 30); //確認原座標(62, 38 ,30)
  delay(random(300, 700));
  mouse.click(1);

  mouse.reset_mouse();
  delay(random(300, 700)); //<<<<<<<<<<<<<<<
  mouse.move(111, 46, 30); //自動練功
  delay(1250);
  mouse.click(1);
  delay(500);
  mouse.move(-30, -30, 30);
}

void Favorites_Tag2(int place){ //<<<<<<<<<<<<書籤+標誌
  Mouse mouse;
  mouse.reset_mouse();
  mouse.move(110, 11, 30); //小地圖原座標
  delay(random(500, 700));
  mouse.click(1);
  mouse.click(1);

  delay(2000);
  mouse.move(-95, 7, 30); //點書籤原座標(15, 18 ,30)
  delay(random(500, 700));
  mouse.click(1);

  // 選圖
  delay(random(500, 700));
  mouse.move(0, 4 + 3*place, 30); //選擇書籤順序原座標(15, 22 ,30)
  delay(random(500, 700));
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(95, 39 - 3*place, 30); //金幣傳送原座標(110, 61 ,30)
  delay(random(300, 700));
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(-48, -23, 30); //確認原座標(62, 38 ,30)
  delay(random(300, 700));
  mouse.click(1);

  delay(1500);
  mouse.move(48, -27, 30); //小地圖原座標(110, 11 ,30)
  delay(random(100, 200));
  mouse.click(1);

  mouse.move(-99, 25, 30); //點標誌原座標(11, 36 ,30)
  delay(random(100, 200));
  mouse.click(1);


  mouse.move(4, 3 + 3*place, 30); //選擇標誌順序原座標(15, 39, 30)
  delay(random(100, 200));
  mouse.click(1);
  delay(random(1000, 2000));
  mouse.click(1);


  mouse.move(50, -4 - 3*place, 30); //移動原座標(65, 35, 30)
  delay(random(100, 200));
  mouse.click(1);
}

void parkEarth(int place){ //<<<<<<<<<<<<<<<<<<<<<<  1 <= place <= 3
  Mouse mouse;
  mouse.reset_mouse();
  delay(random(300, 700)); 
  mouse.move(114, 4, 30); //列表圖案
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(-9, 11, 30); //列表圖案原座標(105, 15, 30)
  delay(100);
  mouse.click(1);
  
  delay(random(300, 700)); 
  mouse.move(-90, -6, 30); //選擇世界地圖原座標(15, 9, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(6, 27, 30); //選樂園原座標(21, 36, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(41, 2, 30); //確定原座標(62, 38, 30)
  delay(100);
  mouse.click(1);
  delay(12000);

  delay(random(300, 700));
  mouse.move(48, -27, 30); //點地圖原座標(110, 11, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(-40, 25, 30); // 往上拉原座標(70, 36, 30)
  delay(random(750, 1250));
  mouse.slide(0, -5, 30); //原座標(70, 31, 30)
  delay(500);

  mouse.reset_mouse();
  delay(random(300, 700)); 
  mouse.move(62, 22, 30); //地屬性門口原座標(62, 22, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(8, 0, 30); //自動移動原座標(70, 22, 30)
  delay(100);
  mouse.click(1);
  delay(7000);

  delay(random(300, 700)); 
  mouse.move(43, 29, 30); //按進入原座標(113, 51, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(-51, -13, 30); //確定原座標(62, 38, 30)
  delay(100);
  mouse.click(1);
  delay(2000);

  /*設定特定地區
  mouse.reset_mouse();
  delay(random(300, 700)); 
  mouse.move(57, 25, 30); //特定地區"地屬性"原座標
  delay(100);
  mouse.click(1);
  mouse.move(8, 0, 30); //自動移動原座標
  delay(100);
  mouse.click(1);
  delay(50000);*/

  mouse.reset_mouse();
  delay(random(300, 700)); //<<<<<<<<<<<<<<<
  mouse.move(111, 46, 30); //自動練功
  delay(1250);
  mouse.click(1);
  delay(500);
  mouse.move(-30, -30, 30);
}

void parkWind(int place){ //<<<<<<<<<<<<<<<<<<<<<<  1 <= place <= 3
  Mouse mouse;
  mouse.reset_mouse();
  delay(random(300, 700)); 
  mouse.move(114, 4, 30); //列表圖案原座標
  delay(100);
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(-9, 11, 30); //地監原座標(105, 15, 30)
  delay(100);
  mouse.click(1);
  
  delay(random(300, 700)); 
  mouse.move(-90, -6, 30); //選擇世界地圖原座標(15, 9, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(6, 27, 30); //選樂園原座標(21, 36, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(41, 2, 30); //確定原座標(62, 38, 30)
  delay(100);
  mouse.click(1);
  delay(12000);

  delay(random(300, 700));
  mouse.move(48, -27, 30); //點地圖原座標(110, 11, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(-40, 25, 30); // 往上拉原座標(70, 36, 30)
  delay(random(750, 1250));
  mouse.slide(0, -5, 30); //原座標(70, 31, 30)
  delay(500);

  mouse.reset_mouse();
  delay(random(300, 700)); 
  mouse.move(62, 35, 30); //風屬性門口原座標(62, 35, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(8, 0, 30); //自動移動原(70, 35, 30)
  delay(100);
  mouse.click(1);
  delay(7000);

  delay(random(300, 700)); 
  mouse.move(43, 16, 30); //按進入原座標(113, 51, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(-51, -13, 30); //確定原座標(62, 38, 30)
  delay(100);
  mouse.click(1);
  delay(2000);
  
/*設定特定地區
  mouse.reset_mouse();
  delay(random(300, 700)); 
  mouse.move(57, 4, 30); //特定地區"風屬性王區"原座標
  delay(100);
  mouse.click(1);
  mouse.move(8, 0, 30); //自動移動原座標
  delay(100);
  mouse.click(1);
  delay(50000);*/
  
  mouse.reset_mouse();
  delay(random(300, 700)); //<<<<<<<<<<<<<<<
  mouse.move(111, 46, 30); //自動練功
  delay(1250);
  mouse.click(1);
  delay(500);
  mouse.move(-30, -30, 30);
}

void TowerOfInsolence(int place){ //<<<<<<<<<<<<<<<<<<<<<<  1 <= place <= 3
  Mouse mouse;
  mouse.reset_mouse();
  delay(random(300, 700)); 
  mouse.move(114, 4, 30); //列表圖案
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(-9, 11, 30); //列表圖案原座標(105, 15, 30)
  delay(100);
  mouse.click(1);
  
  delay(random(300, 700)); 
  mouse.move(-90, -6, 30); //選擇世界地圖原座標(15, 9, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(-4, 27, 30); //選傲塔原座標(11, 36, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700)); 
  mouse.move(51, 2, 30); //確定原座標(62, 38, 30)
  delay(100);
  mouse.click(1);
  delay(12000);

  delay(random(300, 700));
  mouse.move(48, -27, 30); //點地圖原座標(110, 11, 30)
  delay(100);
  mouse.click(1);

  delay(random(300, 700));
  mouse.move(-40, 25, 30); // 往上拉原座標(70, 36, 30)
  delay(random(750, 1250));
  mouse.slide(0, -5, 30); //原座標(70, 31, 30)
  delay(500);

  mouse.reset_mouse();
  delay(random(300, 700)); 
  mouse.move(55, 30, 30); //傲塔1F入口原座標(55, 30, 30)
  delay(100);
  mouse.click(1);
  delay(1000);
  mouse.move(8, 0, 30); //自動移動原座標(63, 30, 30)
  delay(100);
  mouse.click(1);
  delay(5000);
  mouse.click(1);
  delay(random(300, 700)); 
  
  delay(random(300, 700)); 
  mouse.move(50, 21, 30); //按進入原座標(113, 51, 30)
  delay(1000);
  mouse.click(1);
  delay(1000);

  delay(random(300, 700)); 
  mouse.move(-51, -13, 30); //確定原座標(62, 38, 30)
  delay(1000);
  mouse.click(1);
  delay(500);

/*設定特定地區
  mouse.reset_mouse();
  delay(random(300, 700)); 
  mouse.move(85, 30, 30); //特定位置原座標
  delay(100);
  mouse.click(1);
  delay(random(300, 700));

  mouse.move(8, 0, 30); //自動移動原座標
  delay(100);
  mouse.click(1);
  delay(1000);*/

  mouse.reset_mouse();
  delay(random(300, 700)); //<<<<<<<<<<<<<<<
  mouse.move(111, 46, 30); //自動練功
  delay(1250);
  mouse.click(1);
  delay(500);
  mouse.move(-30, -30, 30);
}


void Aden1_3F(int place){ //<<<<<<<<<<<<<<<<<<<<<<  1 <= place <= 3
  Mouse mouse;
  mouse.reset_mouse();
  delay(random(300, 700)); // 點按叫出儲存的東西
  mouse.move(114, 4, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);

  mouse.reset_mouse();

  delay(random(300, 700)); // 選擇地監選項
  mouse.move(110, 15, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(random(300, 700)); 
  mouse.move(15, 35, 30); //選擇龍谷地監 *改
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(random(300, 700));
  mouse.move(72, 24 + 4*place, 30); // 選幾層
  delay(random(750, 1250));
  mouse.click(1);

  mouse.reset_mouse();

  
  delay(random(300, 700));
  mouse.move(62, 38, 30); //確認 
  delay(1250);
  mouse.click(1);
}

void Dragon_Vally_Dungeon1_3F(int place){ //<<<<<<<<<<<<<<<<<<<<<< 1 <= place <= 3
  Mouse mouse;
  mouse.reset_mouse();
  delay(random(300, 700)); // 點按叫出儲存的東西
  mouse.move(114, 4, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);

  mouse.reset_mouse();

  delay(random(300, 700)); // 選擇地監選項
  mouse.move(110, 15, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(random(300, 700)); 
  mouse.move(110, 35, 30); //選擇龍谷地監 *改
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(random(300, 700));
  mouse.move(72, 24 + 4*place, 30); // 選幾層
  delay(random(750, 1250));
  mouse.click(1);

  mouse.reset_mouse();

  
  delay(random(300, 700));
  mouse.move(62, 38, 30); //確認 
  delay(1250);
  mouse.click(1);
  
  
}

void Dragon_Vally_Dungeon4_6F(int place){ //<<<<<<<<<<<<<<<<<<<<<< 4 <= place <= 6
  Mouse mouse;
  mouse.reset_mouse();
  delay(random(300, 700)); // 點按叫出儲存的東西
  mouse.move(114, 4, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);

  mouse.reset_mouse();

  delay(random(300, 700)); // 選擇地監選項
  mouse.move(110, 15, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(random(300, 700)); 
  mouse.move(110, 35, 30); //選擇龍谷地監 *改
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(random(300, 700));
  mouse.move(70, 36, 30); // 往上拉
  delay(random(750, 1250));
  
  mouse.slide(0, -5, 30);
  
  delay(random(300, 700));
  
  mouse.reset_mouse();
  
  delay(random(300, 700));
  mouse.move(72, 34 + 4*place, 30); // 選幾層
  delay(random(750, 1250));
  mouse.click(1);
  
  mouse.reset_mouse();

  
  delay(random(300, 700));
  mouse.move(62, 38, 30); //確認 
  delay(1250);
  mouse.click(1);
  
}

void Dragon_Vally_Dungeon5_7F(int place){ //<<<<<<<<<<<<<<<<<<<<<<
  Mouse mouse;
  mouse.reset_mouse();
  delay(random(300, 700)); // 點按叫出儲存的東西
  mouse.move(114, 4, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);

  mouse.reset_mouse();

  delay(random(300, 700)); // 選擇地監選項
  mouse.move(110, 15, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();
  
  delay(random(300, 700)); 
  mouse.move(110, 35, 30); //選擇龍谷地監 *改
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(random(300, 700));
  mouse.move(70, 36, 30); // 往上拉
  delay(random(750, 1250));
  
  mouse.slide(0, -5, 30);
  
  delay(random(300, 700));
  
  mouse.reset_mouse();
  
  delay(random(300, 700));
  mouse.move(72, 39 + 4*place, 30); // 選幾層
  delay(random(750, 1250));
  mouse.click(1);
  
  mouse.reset_mouse();

  
  delay(random(300, 700));
  mouse.move(62, 38, 30); //確認 
  delay(1250);
  mouse.click(1);
  
  
}

void Gludio5_7F(int place){ //<<<<<<<<<<<<<<<<<<<<<<
  Mouse mouse;
  mouse.reset_mouse();
  delay(random(300, 700)); // 點按叫出儲存的東西
  mouse.move(114, 4, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);

  mouse.reset_mouse();

  delay(random(300, 700)); // 選擇地監選項
  mouse.move(110, 15, 30); //列表圖案
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(random(300, 700)); 
  mouse.move(62, 38, 30); //選古丁谷地監 *改
  delay(random(100, 200));
  mouse.click(1);
  
  mouse.reset_mouse();

  delay(random(300, 700));
  mouse.move(70, 36, 30); // 往上拉
  delay(random(750, 1250));
  
  mouse.slide(0, -5, 30);
  
  delay(random(300, 700));
  
  mouse.reset_mouse();
  
  delay(random(300, 700));
  mouse.move(72, 39 + 4*place, 30); // 選幾層
  delay(random(750, 1250));
  mouse.click(1);
  
  mouse.reset_mouse();
  delay(random(300, 700));
  mouse.move(62, 38, 30); //確認 
  delay(1250);
  mouse.click(1);
  
  
}
