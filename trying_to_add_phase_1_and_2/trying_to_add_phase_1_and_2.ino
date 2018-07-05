
#include "Ultrasonic.h"
#include <SoftwareSerial.h>

int incomingByte = 0;
const int motorA1 = 6;    //motor A positive (+) pin to pin 6 (PWM) (from L298 module!)
const int motorA2 = 9;        //motor A negative (-) pin to pin 9 (PWM)
const int motorB1 = 10;   //motor B positive (+) pin to pin 10 (PWM)
const int motorB2 = 11; //motor B negative (-) pin to pin 11 (PWM)
//const int T = 71;
int pushButton = 12;
Ultrasonic ultrasonic(A4 , A5); //Create Ultrsonic object ultrasonic(trig pin,echo pin)

int distance;         //Variable to store distance from an object



void setup()
{

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(pushButton, INPUT);

  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);

}

void loop()
{
 int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  distance = ultrasonic.Ranging(CM); //Tip: Use 'CM' for centimeters or 'INC' for inches
  
//do{
  if (distance > 10)
  {




    if (Serial.available() > 0) {
      // read the incoming byte:
      incomingByte = Serial.read();
      Serial.println((char)incomingByte);
      stop();
    }
    switch (incomingByte)
    {    
      case 'S':
        // stop all motors
        { stop();
        }

        break;

      case 'F':
        // turn it on going forward
        { forward();

          Serial.println("Forward\n");//display message for test purposes when connected to a serial monitor
        }
        break;

      case 'B':
        // turn it on going backward
        { backward();
          Serial.println("Backward\n");//display message for test purposes when connected to a serial monitor
        }
        break;

      case 'R':
        // turn right
        { right();
          Serial.println("Rotate Right\n");//display message for test purposes
        }
        break;


      case 'L':
        // turn left
        {
          left();
        }
        break;

    }
  }
  else {
    stop();
  }
//}while(buttonState=0);
do{
if(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == LOW)
 {
   digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
   analogWrite(3, 80);
  analogWrite(5, 80);
 }
  else if(digitalRead(2) == LOW && digitalRead(7) == HIGH && digitalRead(4) == HIGH)
 {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
   analogWrite(3, 80);
   analogWrite(5, 0);
  delay(300);
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == HIGH)
  {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(3, 0);
  analogWrite(5, 80);
  delay(300);
  }
}while (buttonState=1);*/
} 

void forward() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
   analogWrite(3, 255);
  analogWrite(5, 255);
  
}

void backward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(3, 255);
  analogWrite(5, 255);
}

void left() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(3, 0);
  analogWrite(5, 255);
}

void right() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
   analogWrite(3, 255);
   analogWrite(5, 0);
}

void stop() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}



