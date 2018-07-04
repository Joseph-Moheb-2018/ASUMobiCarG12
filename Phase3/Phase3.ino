/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

int left_encoder_pin=12;
int right_encoder_pin = 8;
int left_encoder=0;
int right_encoder = 0;
int ticks = 0;
unsigned long time_unit=0;
int prev_right_ticks=0;
int prev_left_ticks=0;
int right_ticks=0;
int left_ticks=0;
int R=.067; //units in m
int L=.130; //in m 
int m_per_tick=0;
int pi =22/7;
int d_right=0;
int d_left=0;
int d_center=0;
int phi=0;
int theta =0;
int theta_new =0;
int theta_dt=0;
int x=0;
int y=0;
int x_new=0;
int y_new=0;
int x_dt=0;
int y_dt=0;
int ttt=100;
void setup() {
  Serial.begin(9600);
  pinMode(left_encoder_pin, INPUT);
  pinMode(right_encoder_pin, INPUT);
}


void loop() {
  time_unit= millis();
  m_per_tick = (2*pi*R)/20;  // 20 is the number of ticks in one revolution in our encoder 
   
  
    if (time_unit == ttt ){
              ttt= ttt+100;
  
   prev_right_ticks =  prev_right_ticks;
   prev_left_ticks = prev_left_ticks;
   Serial.print("X=");
   Serial.println(x);
   Serial.print("Y=");
   Serial.println(y);
   Serial.print("theta=");
   Serial.println(theta);
   Serial.print("prev_right_ticks");
   Serial.println(prev_right_ticks);
   Serial.print("prev_left_ticks");
   Serial.println(prev_left_ticks);
   Serial.print("left_ticks");
   Serial.println(left_ticks);
   Serial.print("right_ticks");
   Serial.println(right_ticks);
   
   left_encoder = digitalRead(left_encoder_pin);
   right_encoder = digitalRead(right_encoder_pin);
   delay(1);  
   if(right_encoder==1){
                               right_ticks ++;
                              }               
         if(left_encoder==1){
                               left_ticks ++ ; 
                               }
             
            
                           // variable to store the ticks in the begining
            
    
            d_right = (right_ticks - prev_right_ticks)*m_per_tick;
            d_left = (left_ticks-prev_left_ticks)*m_per_tick;
            d_center = (d_right + d_left)/2;
            phi = (d_right - d_left)/L;
            
            x_dt = d_center*cos(theta);
            y_dt = d_center*sin(theta);
            theta_dt = phi;
                        
            theta_new = theta + theta_dt;
            x_new = x + x_dt;
            y_new = y + y_dt;  
           prev_right_ticks = right_ticks;
           prev_left_ticks = left_ticks;
           
            
 // delay(1);        // delay in between reads for stability    
       
    }

}


