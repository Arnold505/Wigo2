#include <Ubidots_Arduino_GPRS.h>
#include <Ubidots_FONA.h>

#include <UbidotsArduino.h>
#include <WiFi101.h>
#include <SPI.h>
#define TRIGGER1 1
#define ECHO1    0

#define TRIGGER2 6
#define ECHO2    5

int cont=0;
 
// NodeMCU Pin D1 > TRIGGER | Pin D2 > ECHO
 
void setup() {
 
  Serial.begin (9600);
  pinMode(TRIGGER1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIGGER2, OUTPUT);
  pinMode(ECHO2, INPUT);

}
 
void loop() {
 
  long duration1, distance1;
  long duration2, distance2;
  
  digitalWrite(TRIGGER1, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER1, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER1, LOW);
  duration1 = pulseIn(ECHO1, HIGH);
  distance1 = duration1/58;
  
//PRIMER SENSOR ULTRASONICO

  digitalWrite(TRIGGER2, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER2, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER2, LOW);
  duration2 = pulseIn(ECHO2, HIGH);
  distance2 = duration2/58;

 if(distance1<6){
      cont++;
      Serial.println(cont);
      delay(1000);
 }
    else if (distance2<6){
      cont--;
      Serial.println(cont);
      delay(1000);
      }
      Serial.println(cont);
      delay(1000);
}
