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
        reset_mouse();
        change_place();
    }

    if( hp_not_enough ){
        delay(random(100, 500));
        //Serial.println("val1: ");
        hp(); // 按鍵6 的強效藥水 
    }

    if( need_potion ){
        delay(random(100, 500));
        //Serial.println("val2:");
        recall();
        reset_mouse();
        buy_supply();
        reset_mouse();
        change_place();
    }
}

void recall(){
  delay(100);
  mouse(60, 60, 30);
  click(4); // 中鍵
}

void hp(){
  delay(100);
  mouse(105, 60, 30);
  click(1);
}

void buy_supply(){
  delay(100);
  mouse(115, 60, 30);
  //click(1);
  delay(100);
  mouse(-5, -8, 30);
  click(1);
  delay(100);
  mouse(-40, -18, 30);
  click(1);
  delay(100);
  mouse(4, 0, 30);
  click(1);

  delay(10000);
  
  delay(random(100, 500));
  mouse(33, 28, 30);
  click(1);
  
  delay(100);
  mouse(10, 0, 30);
  click(1);
  delay(100);
  mouse(0, -57, 30);
  click(1);
}

void change_place(){
  delay(100); // 點按叫出儲存的東西
  mouse(117, 10, 30);
  click(1);

  reset_mouse();

  delay(100);
  mouse(40, 70, 10);
  click(1);
  
  delay(100);
  
  mouse(14, 9, 10);
  click(1);

  delay(1000);

  mouse(93, 18, 30);
  click(1);
}

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

    delay(100);
}

void wheel(int8_t wh){
    mouseReport.wheel = wh;
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);
    
    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;

    delay(100);
}