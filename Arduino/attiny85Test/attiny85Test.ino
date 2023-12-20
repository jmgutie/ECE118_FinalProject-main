// Servo8Bit Example code
// Ilya Brutman

#include "Servo8Bit.h"

//void delay(uint16_t milliseconds);  //forward declaration to the delay function

int led = 1; // blink 'digital' pin 1 - AKA the built in red LED
int esc = 0;
#define SWITCH 2

Servo8Bit myServo;  //create a servo object.
                        //a maximum of five servo objects can be created

void setup() {          
  myServo.attach(esc);  //attach the servo to pin PB1
  pinMode(led, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);

  digitalWrite(led, LOW);
  myServo.write(45);
  delay(7000);
  digitalWrite(led, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  if (! digitalRead(SWITCH)) {  // if the button is pressed
    myServo.write(85); 
    delay(100);
  } else {
    myServo.write(45);
    delay(100);
  }    
}
