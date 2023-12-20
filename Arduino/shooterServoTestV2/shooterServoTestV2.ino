
#include<Servo.h>

Servo esc;

void setup() {
  // put your setup code here, to run once:
  esc.attach(9); // 9 on arduino Uno, 
  esc.write(45); // 95
  //delay(4000);
  //esc.write(180);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(7000);
  esc.write(75);
}

//#include <Servo.h>
//
//Servo servo1;  // create servo object to control a servo
//Servo servo2;  // create servo object to control a servo
//
//void setup() {
////nothing here
//  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
//  servo2.attach(5);  // attaches the servo on pin 9 to the servo object
//}
//
//void loop()
//{
//  servo1.write(180);
//  delay (1000);   // wait for a second
//  servo1.write(90);
//  delay (1000);   // wait for a second
//
//  servo2.write(90);
//  delay (1000);   // wait for a second
//  servo2.write(180);
//  delay (1000);   // wait for a second
//}
