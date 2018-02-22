int led_1=4 ;
void setup() {
  // initialize digital pin led_1 as an output. 
  pinMode ( led_1, OUTPUT ) ;
}
// the loop function runs over and over again forever 
void loop () {
  digitalWrite (led_1, HIGH );
  delay ( 1200 ) ;
  digitalWrite ( led_1 , LOW );
  delay (1200) ; 
}

