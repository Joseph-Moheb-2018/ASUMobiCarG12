#define LED 13
#define PB 3
bool state = 0 , blinking=0;
float Time = 0 , dtime=0;
bool pushed=LOW;
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(PB,INPUT);


}

void loop()
{
  pushed=digitalRead(PB);
Time=millis();
while(pushed==HIGH)
{
  pushed=digitalRead(PB);
dtime=millis()-Time;
if(dtime>4999)
{blinking=!blinking; //reverse the blinking state
}
  } 
  if(!blinking)pushed=HIGH; 
if (pushed==HIGH&&state==0&&blinking==0)
  {
    state=state+1;
    digitalWrite(LED,state);
  }
  else if (pushed==HIGH&&state==1&&blinking==0)
  {
    state=state-1;
    digitalWrite(LED,state);
    
  }
  else if (blinking)
  {
    analogWrite(LED,1);
    }
  
