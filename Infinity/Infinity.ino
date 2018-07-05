
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
void stop() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
void loop() {
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
    

    if(no<220)
    {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(3,65);
  analogWrite(5, 245);
    }
    else if((no>=220) && (no<410))
    {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(3,175);
  analogWrite(5, 60);
      }
      
   else if((no>=410) && (no<555))
    {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(3,65);
  analogWrite(5, 245);
    }
    else {
      stop();
      }
}
