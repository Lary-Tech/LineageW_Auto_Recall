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
}

/* Move the mouse in a clockwise square every 5 seconds */
void loop()
{
    int ind;
    delay(1000);
 
    mouseReport.buttons = 0;
    mouseReport.x = 0;
    mouseReport.y = 0;
    mouseReport.wheel = 0;

    // reset
    mouseReport.x = -64;
    mouseReport.y = -64;
    mouseReport.buttons = 0;
    for (ind = 0; ind < 100; ind++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }

    /*
    // Go to 祝瞬 約1780 150
    mouseReport.x = 50;
    mouseReport.y = 0;
    mouseReport.buttons = 0;
    for (ind = 0; ind < 71; ind++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }
    mouseReport.x = 0;
    mouseReport.y = 50;
    mouseReport.buttons = 0;
    for (ind = 0; ind < 6; ind++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }
    mouseReport.buttons = 1;
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);

    delay(1000);
    */
    
    // reset
    mouseReport.x = -64;
    mouseReport.y = -64;
    mouseReport.buttons = 0;
    for (ind = 0; ind < 100; ind++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }
    
    // Go to 選地圖 約200 330
    mouseReport.x = 10;
    mouseReport.y = 0;
    mouseReport.buttons = 0;
    for (ind = 0; ind < 40; ind++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }
    mouseReport.x = 0;
    mouseReport.y = 10;
    mouseReport.buttons = 0;
    for (ind = 0; ind < 70; ind++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }
    
    mouseReport.buttons = 4;
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);
    mouseReport.buttons = 0;
    
    mouseReport.buttons = 1;
    Serial.write((uint8_t *) &mouseReport, 4);
    Serial.write((uint8_t *) &nullReport, 4);

    delay(1000);

    // reset
    mouseReport.x = -64;
    mouseReport.y = -64;
    mouseReport.buttons = 0;
    for (ind = 0; ind < 100; ind++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }

    // Go to 飛 約342 404
    mouseReport.x = 10;
    mouseReport.y = 0;
    mouseReport.buttons = 0;
    for (ind = 0; ind <67; ind++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }
    mouseReport.x = 0;
    mouseReport.y = 10;
    mouseReport.buttons = 0;
    for (ind = 0; ind < 87; ind++) {
      Serial.write((uint8_t *) &mouseReport, 4);
      Serial.write((uint8_t *) &nullReport, 4);
    }
    //mouseReport.buttons = 1;
    //Serial.write((uint8_t *) &mouseReport, 4);
    //Serial.write((uint8_t *) &nullReport, 4);

    delay(1000);

    /*
    // Going up
    mouseReport.x = 0;
    mouseReport.y = -2;
    for (ind = 0; ind < 20; ind++) {
      Serial.write((uint8_t *)&mouseReport, 4);
    Serial.write((uint8_t *)&nullReport, 4);
    }

    // Going right
    mouseReport.x = 2;
    mouseReport.y = 0;
    for (ind = 0; ind < 20; ind++) {
    Serial.write((uint8_t *)&mouseReport, 4);
    Serial.write((uint8_t *)&nullReport, 4);
    }

    // Going down
    mouseReport.x = 0;
    mouseReport.y = 2;
    for (ind = 0; ind < 20; ind++) {
    Serial.write((uint8_t *)&mouseReport, 4);
    Serial.write((uint8_t *)&nullReport, 4);
    }
    */
}
