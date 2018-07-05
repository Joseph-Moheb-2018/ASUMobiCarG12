/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */
const int motorA1 = 6;    //motor A positive (+) pin to pin 6 (PWM) (from L298 module!)
const int motorA2 = 9;        //motor A negative (-) pin to pin 9 (PWM)
const int motorB1 = 10;   //motor B positive (+) pin to pin 10 (PWM)
const int motorB2 = 11; //motor B negative (-) pin to pin 11 (PWM)
int ticks_R= 8;
int ticks_L = 12;
int no=0;
int Last_State = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  // make the pushbutton's pin an input:
  pinMode(ticks_R, INPUT);
  pinMode(ticks_L, INPUT);
}

void forward() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(3, 70);
  analogWrite(5, 75);
   
}

void backward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(3, 70);
  analogWrite(5, 75);
}

void left() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(3, 0);
  analogWrite(5, 180);
}

void right() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
   analogWrite(3, 70);
   analogWrite(5, 0);
}

void stop() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
 
  // read the input pin:
 int x= digitalRead(ticks_R);
  //int y = digitalRead(ticks_L);
  if((x==1) && (x!=Last_State)){
    no++;
    }
    Last_State = x;
  
  Serial.println(no);
  delay(1);

 if (no <70){   
  forward();
  } 
else if ( (no>=70) && (no<115) )  {
  left();
  }
else if ((no>=115) && (no<175)  ){
  forward();
  }
else if ((no>=175)&&(no<220)) 
  {
    left();
  }
else if ((no>=220) && (no<290))    
{
  forward();
}
else if ((no>=290)  && (no<335))
{
  left();
  }
else if((no>=335)  &&  (no<395))
{
  forward();
  }
  
  else {
    stop();
    }
}



