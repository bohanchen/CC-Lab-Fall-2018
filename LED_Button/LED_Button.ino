//name each led
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;

int button = 7;
int value;

boolean buttonUp = true;
boolean state = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  pinMode(button, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  value = digitalRead(button);
  //Serial.println(value);
  if (value != HIGH && buttonUp == true){
    state = !state;
   
    buttonUp = false;
    
  } 
  else if (value == HIGH && buttonUp != true){
    
    buttonUp = true;
  }
  
  Serial.println(state);
  if (state){
    ODD();
  } else{
    EVEN();
  }  
}

void ODD(){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW); //HIGH IS ON
    digitalWrite(led3, HIGH); //HIGH IS ON
    digitalWrite(led4, LOW); //HIGH IS ON
    digitalWrite(led5, HIGH); //HIGH IS ON
    digitalWrite(led6, LOW); //HIGH IS ON
}

void EVEN(){
    digitalWrite(led1, LOW); //HIGH IS ON
    digitalWrite(led2, HIGH); //HIGH IS ON
    digitalWrite(led3, LOW); //HIGH IS ON
    digitalWrite(led4, HIGH); //HIGH IS ON
    digitalWrite(led5, LOW); //HIGH IS ON
    digitalWrite(led6, HIGH); //HIGH IS ON
}
