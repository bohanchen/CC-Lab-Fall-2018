//led light on with the distance getting closer
//Buzzer also get a warning light
//Joystick controls the lightness of the led

int triggerPin = 9;
int echoPin = 10;
int buzzer = 11;
int ledPin = 13;

//int redPin = 4;
int greenPin = 5;
int bluePin = 3;

const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1;

int YPIN; //declaring YPIN an integer for later
int XPIN;


long duration;
int distance;
int safeDistance;

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(redPin, OUTPUT); // declares RGB LED as an output
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
  
}

void setColor(int red, int green, int blue){
  analogWrite(redPin, red); 
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void loop() {
  //trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  //read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  //get the distance
  distance = (duration*0.034)/2;
  //
  if(distance <= 5){
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, HIGH);
    tone(buzzer,4000,1000);

   } else{
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
   }

   Serial.println("Distance: ");
   Serial.println(distance);
  int YPIN = analogRead(Y_pin);  //sets the number thats comes out of analogRead(Y_pin); equal to a new variable
  int XPIN = analogRead(X_pin);

  Serial.print("X-axis:");
  Serial.print(analogRead(X_pin));
  Serial.print("  ");
  Serial.print("Y-axis:");
  Serial.println(analogRead(Y_pin));
  
  if(YPIN == 0) {setColor(100, 80, 0); 
    delay(100);
  }else {
    setColor(0, 0, 0);
  }
  
  if(YPIN == 1023) {
    setColor(225, 0, 225); 
    delay(100);
  }else {
    setColor(0, 0, 0);}
    
  if(XPIN == 0) {
    setColor(0, 0, 225); 
    delay(100);
  }else {
    setColor(0, 0, 0);
  }

  if(XPIN == 1023) {
    setColor(0, 225, 0); 
    delay(100);
  }else {
    setColor(0, 0, 0);
  }
 
}
