void setup() {
  // put your setup code here, to run once:

}

void loop() {
 //case 'L':
        // turn left
      {   
       motor_right.run(FORWARD);  
       motor_left.run(RELEASE);
      
    
       Serial.println("Rotate Left\n");//display message for test purposes
       incomingByte='*';}
     break;
     
     case '1':
        // Put what you like in here - for example - change the motor speeds
      { speed_left = speed_min; // set both motors to minimum speed
       speed_right = speed_min;
       Serial.println("Speed 1\n");//display message for test purposes
       incomingByte='*';}
     break;
     
    case '2':
        // Put what you like in here - for example - turn on some LED lights on the car
      { 
       Serial.println("Lights on\n");//display message for test purposes
       
       //why not use the motor sheild's spre motors - M3 and M4  - to turn lights on and off
       //you would need to define M3/4 in your program setup, and a few extra veriables to hold values
       //then FORWARD and BACKWARD would send a voltage one way then the other through the M3 and M4 terminals as you require
       
       incomingByte='*';}
     break;        
  }
}
//-----------------------------------------------------------------------------------------------------------------------

}
