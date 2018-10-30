int motor = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<255; i++){
    analogWrite(motor, i);
    delay(5);
  }
  for(int i = 255; i>0; i--){
  analogWrite(motor, i);
  delay(5);
}

}
