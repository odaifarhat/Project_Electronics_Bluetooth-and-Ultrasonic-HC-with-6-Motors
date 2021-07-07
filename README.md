# Project_Electronics_Bluetooth-and-Ultrasonic-HC-with-6-Motors
Moving the robot’s arms three coordinated movements to welcome when a person approaches a certain distance and a signal will be sent to the iPad to open the screen through Bluetooth, at 10 cm the arms will be moved up and at 9 cm the arms will be moved forward and at 8 cm the arms will be joined and at 5 cm The arms will return down to the origin.

# Component List:

Arduino Uno R3.

Arduino Uno R3. // I used the second Arduino instead of the bluetooth to illustrate the connection only. The bluetooth segment is not present in the simulation.

Breadboard.

Wires.

Servo Motors.

Ultrasonic.

# Circuit connection steps:

Step_1, Connect from arduino ground and power (5v) Breadboard.

Step_2, Connect ServoMotorsLeft pin signal (1 & 2 & 3) to digtal(pwm) in arduino pin 5 & 6 & 7.

Step_3, Step_3, Connect ServoMotorsRight pin signal (4 & 5 & 6) to digtal(pwm) in arduino pin 2 & 3 & 4 .

Step_4, Connect the Ultrasonic TRIG and ECHO to digtal(pwm) in arduino pin 8 & 9.

Step_5, Connect the Bluetooth TX & RX to digtal(pwm) in arduino pin RX & TX.


# SCHEMATICS

schematic representation:

![Bluetooth and Ultrasonic HC with 6 motors](https://user-images.githubusercontent.com/56201060/124808458-a4890200-df67-11eb-8f3f-0013cd57954f.png)


# Code:


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

