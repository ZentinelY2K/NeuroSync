#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "ZentinelY2K";
const char* password = "M8!rTz#4qLpX92vB2i#x";


WiFiUDP udp;

const char* host = "10.239.224.76"; // your laptop IP
const int port = 1234;

char incomingPacket[255];

int electrode1 = 35;
int electrode2 = 34;
int buzzer = 17;

void setup(){
    Serial.begin(115200);
    pinMode(electrode1,INPUT);
    pinMode(electrode2,INPUT);
    pinMode(buzzer,OUTPUT);
    
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500); //wait for connection
  }
  udp.begin(port);
  
  Serial.println("IP Address:");
  Serial.println(WiFi.localIP());


}

bool thinking_left_hand = false;
bool rhinking_right_hand = false;

void loop(){
    int packetSize = udp.parsePacket();

    float readings1 = analogRead(electrode1);
    float readings2 = analogRead(electrode2);

 
    if (packetSize) {
    int len = udp.read(incomingPacket, 255);
    if (len > 0) incomingPacket[len] = 0;
    String msg = String(incomingPacket);
    Serial.println(msg);
    if(msg == "True"){
      thinking_left_hand = true;
      
    }
  }
  if (thinking_left_hand==true){
      udp.beginPacket();
      udp.println("A" + String(electrode1));
      udp.endPacket();
      

      udp.beginPacket();
      udp.println("B" + String(electrode2));
      udp.endPacket();

   }
  
      //Serial.println(readings2);
     
    

    /*if (readings1>=2100 && readings2 >= 2150){
      digitalWrite(buzzer,HIGH);
      
    }

    else{
      digitalWrite(buzzer,LOW);
    }*/
  
   
    
}
//