//name each led
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;

int button = 7;
int value;

boolean buttonUp = true; //flag to control the button
boolean state = false; //flag to check the state of LED

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
  if (value != HIGH && buttonUp == true){ //the button is not pushed
    state = !state; //reverse the state of led
    buttonUp = false; //set flag to false
    
  }
  else if (value == HIGH && buttonUp != true){ //the button is pushed
    buttonUp = true; // set flag back
  }
  
  Serial.println(state);
  if (state){
    ODD();
  } else{
    EVEN();
  }  
}

void ODD(){
    //Turn on odd number led (1,3,5)
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW); 
    digitalWrite(led3, HIGH); 
    digitalWrite(led4, LOW); 
    digitalWrite(led5, HIGH); 
    digitalWrite(led6, LOW); 
}

void EVEN(){
    //Turn on even number led (2,4,6)
    digitalWrite(led1, LOW); //HIGH IS ON
    digitalWrite(led2, HIGH); //HIGH IS ON
    digitalWrite(led3, LOW); //HIGH IS ON
    digitalWrite(led4, HIGH); //HIGH IS ON
    digitalWrite(led5, LOW); //HIGH IS ON
    digitalWrite(led6, HIGH); //HIGH IS ON
}
