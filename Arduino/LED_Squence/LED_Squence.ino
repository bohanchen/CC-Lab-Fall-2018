//name each led
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;
int led8 = 6;
int led9 = 5;
int led10 = 4;
int led11 = 3;

int button = 0;
int value;



void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);

  pinMode(button, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  value = digitalRead(button);
  if (value == HIGH){
      digitalWrite(led1, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led2, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led3, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led4, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led5, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led6, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led7, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led8, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led9, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led10, HIGH); //HIGH IS ON
      delay(200);
      digitalWrite(led11, HIGH); //HIGH IS ON
      delay(200);
   }

   else if(value == LOW) {
      digitalWrite(led1, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led2, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led3, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led4, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led5, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led6, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led7, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led8, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led9, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led10, LOW); //LOW IS OFF
      delay(300);
      digitalWrite(led11, LOW); //LOW IS OFF
      delay(300);
      
   }

}
