/*

July 7/7/2021

By Eng.Odai Farhat.

Project_Electronics_Bluetooth-and-Ultrasonic-HC-with-6-Motors.

Define a start for each engine.

Programming three coordinated arm movements robot arms.

*/

#include <Servo.h>

// char inputByte; //Bluetooth
Servo servo1,servo2,servo3,servo4,servo5,servo6;

int trigPin = 9;
int echoPin = 8;

long distance;
long duration;
 
void setup() 
{
 /*  Serial.begin(9600);//Bluetooth
 pinMode(13,OUTPUT);
  */
 
  servo1.attach(7); 
  servo2.attach(6); 
  servo3.attach(5); 
  servo4.attach(4); 
  servo5.attach(3); 
  servo6.attach(2); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
}
 
void loop() {
  
 /* while(Serial.available()>0){   //Bluetooth
  inputByte= Serial.read();
  Serial.println(inputByte);
  if (inputByte=='Z'){
  digitalWrite(13,HIGH);
  }
  else if (inputByte=='z'){
  digitalWrite(13,LOW);
  } 
  }
  */
  
  
  ultra();
   servo1.write(0);
   servo2.write(0);
   servo3.write(0);
   servo4.write(0);
   servo5.write(0);
   servo6.write(0);
  
  if(distance <= 10){
    servo1.write(60);
    servo2.write(60);
    servo3.write(60);
    servo4.write(60);
    servo5.write(60);
    servo6.write(60);
    delay(3000);
  }
    if(distance <= 9){
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
    servo5.write(90);
    servo6.write(90);
    delay(2000);
  }
    if(distance <= 8){
    servo1.write(120);
    servo2.write(120);
    servo3.write(120);
    servo4.write(120);
    servo5.write(120);
    servo6.write(120);
    delay(1000);
  }
    if(distance <= 5){
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
    servo4.write(0);
    servo5.write(0);
    servo6.write(0);
    delay(2000);
  }
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }
