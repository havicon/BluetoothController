#include <SoftwareSerial.h>
#define StringMaxLength 32
SoftwareSerial BT(10, 11);
const int motorA = 6;
const int motorB = 7;
const int PWM_motAB = 3;
const int motorC = 8;
const int motorD = 9;
const int PWM_motCD = 5;
char data[StringMaxLength];
int counter = 0;
void setup() {
  BT.begin(9600);
  pinMode(motorA,OUTPUT); //信号用ピン
  pinMode(motorB,OUTPUT); //信号用ピン
  pinMode(motorC,OUTPUT); //信号用ピン
  pinMode(motorD,OUTPUT); //信号用ピン
}
void loop() {
 if(BT.available()) {
   data[counter] = BT.read();
   counter++;
   if(data[counter] == '\0' || counter == StringMaxLength) {
     data[counter] == '\0';
     BT.println("Hi from Arduino ");
     BT.println(data);
     counter = 0;
   }
 }
}
