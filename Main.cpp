#include <Arduino.h>
int electrode1 = 35;
int electrode2 = 34;
int buzzer = 17;
void setup(){
    Serial.begin(115200);
    pinMode(electrode1,INPUT);
    pinMode(electrode2,INPUT);
    pinMode(buzzer,OUTPUT);
    
}
   
void loop(){
    float readings1 = analogRead(electrode1);
    float readings2 = analogRead(electrode2);
    Serial.println(readings1);
    Serial.println(" ");
    Serial.println(readings2);

    if (readings1>=2100 && readings2 >= 2150){
      digitalWrite(buzzer,HIGH);
      
    }

    else{
      digitalWrite(buzzer,LOW);
    }
   
}