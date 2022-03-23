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

void loop()
{
    reset_mouse();
    change_place();
    delay(5000);
}

void change_place(){
  delay(100);
  mouse(40, 70, 10);
  click(4);
  click(1);
  mouse(18, 12, 10);
  click(1);
}

void reset_mouse(){
  mouseReport.x = -64;
  mouseReport.y = -64;
  mouseReport.buttons = 0;
  
  for (int i = 0; i < 100; i++) {
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
