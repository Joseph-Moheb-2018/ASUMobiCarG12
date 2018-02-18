int redled=5;
int yellowled=6;
int greenled=7;
int blueled=4;
int i;
void setup() {
  pinMode(redled, OUTPUT);
  pinMode(yellowled,OUTPUT );
  pinMode(greenled,OUTPUT);
  pinMode(blueled,OUTPUT);

}

void loop() {
for(i=1;i=i+1;i=15){
  digitalWrite(redled, HIGH);
delay(1000);
 digitalWrite(redled, LOW);
 digitalWrite(yellowled, HIGH);
delay(1000);
 digitalWrite(yellowled, LOW);
 digitalWrite(greenled, HIGH);
delay(1000);
 digitalWrite(greenled, LOW);
 digitalWrite(blueled,HIGH);
 delay(1000);
 digitalWrite(blueled,LOW);
  digitalWrite(blueled,HIGH);
 delay(1000);
 digitalWrite(blueled,LOW);
digitalWrite(greenled, HIGH);
delay(1000);
 digitalWrite(greenled, LOW);
  digitalWrite(yellowled, HIGH);
delay(1000);
 digitalWrite(yellowled, LOW);
 digitalWrite(redled, HIGH);
delay(1000);
 digitalWrite(redled, LOW);
 delay(1000);
 }
}
