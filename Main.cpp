#include <Arduino.h>
int electrode = 35;
void setup(){
    Serial.begin(115200);
    pinMode(electrode,INPUT);
    
}

void loop(){
    float readings = analogRead(electrode);
    Serial.println(readings);
    delay(200);
}