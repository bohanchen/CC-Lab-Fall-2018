/*
  Blink
*/
int led = 13;
int button = 2;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); //how fast arduino talk to the protocal 
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(button) == HIGH){
    Serial.println("ON");
    digitalWrite(led, HIGH);
  } else {
    Serial.println("OFF");
    digitalWrite(led, LOW);
  }


//=====This is the blink code======
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  //Serial.println("ON");
//  Serial.println(digitalRead(button));
//  delay(1000);                       // wait for a second
//  
//  digitalWrite(LED_BUILTIN, LOW);// turn the LED off by making the voltage LOW
//  //Serial.println("OFF");
//  Serial.println(digitalRead(button));
//  delay(1000);                       // wait for a second
}
