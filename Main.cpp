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

//Findings show conducivity is present, as the 00.0 variable will go to a 4095.00 limit when pressed against something