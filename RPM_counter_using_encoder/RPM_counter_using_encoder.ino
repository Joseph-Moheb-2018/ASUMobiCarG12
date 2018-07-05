/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int ticks_R= 8;
int ticks_L = 12;
int no=0;
int Last_State = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(ticks_R, INPUT);
  pinMode(ticks_L, INPUT);
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
}



