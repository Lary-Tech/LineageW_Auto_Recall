void setup()
{
    Serial.begin(9600);

    pinMode(7, INPUT); 
}

int count = 0;
void loop(){
    bool be_attacked = ( analogRead(0) > 500 ? true : false );   // A25 遭受敵人攻擊了
    bool hp_not_enough = ( analogRead(1) > 500 ? true : false );   // A26 體力不足了
    bool need_potion = ( analogRead(2) > 500 ? true : false );   // A27 需要補充藥水
    bool en_be_attacked = ( analogRead(3) > 500 ? true : false ); // B0 English 遭受敵人攻擊
    bool en_need_potion = ( analogRead(4) > 500 ? true : false );   // B1 English 需要補充藥水
    bool en_hp_not_enough = ( analogRead(5) > 500 ? true : false );   // B2 English 體力不足了
    // bool trigger = digitalRead(7);   // 聽聲音瞬間觸發
    int trigger = analogRead(5);

    Serial.println(trigger);
    if(trigger < 500){
      delay(500);
      count ++;
    }

    Serial.println(count);
    
}
