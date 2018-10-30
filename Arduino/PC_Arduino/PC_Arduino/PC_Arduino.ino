const int motor = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() >0){
    char MotorState = Serial.read(); //read the value

    if (MotorState == '1'){
      digitalWrite(motor, HIGH);
    }
    if (MotorState == '0'){
      digitalWrite(motor, LOW);
    }
  
  }
}
