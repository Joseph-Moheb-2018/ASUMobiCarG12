

const int motorA1 = 6;    //motor A positive (+) pin to pin 6 (PWM) (from L298 module!)
const int motorA2 = 9;        //motor A negative (-) pin to pin 9 (PWM)
const int motorB1 = 10;   //motor B positive (+) pin to pin 10 (PWM)
const int motorB2 = 11; //motor B negative (-) pin to pin 11 (PWM)
int ticks_R= 8;
int ticks_L= 12;
int no=0;
int no2=0;
int Last_State = 0;
int Last_State2 = 0;
int y=0;
int x=0;

void setup() {

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(ticks_R, INPUT);
  pinMode(ticks_L, INPUT);
  Serial.begin(9600);
}

void Circle() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(3,100);
  analogWrite(5, 190);
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







void loop() {
  // put your main code here, to run repeatedly:
  x= digitalRead(ticks_R);
  y = digitalRead(ticks_L);
 if((x==1) && (x!=Last_State)){
    no++;
    }
    Last_State = x;
 if((y==1) && (y!=Last_State2)){
    no2++;
    }
    Last_State2=y;
    Serial.println(no);
    Serial.println(no2);
     if (no <70){   
  forward();
  } 
else if ( (no>=70) && (no<113) )  {
  left();
  }
  
else if ((no>=113) && (no<173)  ){
  forward();
  }
else if ((no>=173)&&(no<216)) 
  {
    left();
  }
else if ((no>=216) && (no<286))    
{
  forward();
}
else if ((no>=286)  && (no<327))
{
  left();
  }
else if((no>=327)  &&  (no<387))
{
  forward();
  }
else if (no>=387)  
{
  Circle();
  }
}
