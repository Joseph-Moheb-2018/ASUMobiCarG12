//speed of motors betwen 0 and 255, if you like you can change it
int pwm_speedA = 150;
int pwm_speedB = 145;
char command; 
const int motorA1 = 6;    //motor A positive (+) pin to pin 6 (PWM) (from L298 module!)
const int motorA2 = 9;        //motor A negative (-) pin to pin 9 (PWM)
const int motorB1 = 10;   //motor B positive (+) pin to pin 10 (PWM)
const int motorB2 = 11; //motor B negative (-) pin to pin 11 (PWM)
void setup() {
Serial.begin(9600);
  //pins for motor controller
 pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);

}

void loop() {
  

 if(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == LOW)
 {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(3, 80);
  analogWrite(5, 80);
 }
  else if(digitalRead(2) == LOW && digitalRead(7) == HIGH && digitalRead(4) == HIGH)
 {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
   analogWrite(5, 80);
   analogWrite(3, 0);
  delay(300);
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == HIGH)
  {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(5, 0);
  analogWrite(3, 80);
  delay(300);
  }
}




