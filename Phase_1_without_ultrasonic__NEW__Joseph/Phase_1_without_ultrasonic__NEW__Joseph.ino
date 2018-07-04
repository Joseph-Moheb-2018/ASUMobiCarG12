
#include <SoftwareSerial.h>

int incomingByte = 0;
const int motorA1 = 6;    //motor A positive (+) pin to pin 6 (PWM) (from L298 module!)
const int motorA2 = 9;        //motor A negative (-) pin to pin 9 (PWM)
const int motorB1 = 10;   //motor B positive (+) pin to pin 10 (PWM)
const int motorB2 = 11; //motor B negative (-) pin to pin 11 (PWM)



void setup()
{

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
 Serial.begin(9600);

}

void loop()
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
     else{
      stop();
      }
   
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



