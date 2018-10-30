#include <Servo.h>
Servo servo;
const int ledPin = 13;


void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() >0){
     char incomingByte = Serial.read();
     if(incomingByte == '1'){
      digitalWrite(ledPin, HIGH);
      servo.write(180);

     }
     
     if (incomingByte == '2'){
      digitalWrite(ledPin, LOW);
      servo.write(0);
     }
  }
}
