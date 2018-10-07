import processing.serial.*;

Serial myPort;

float xPos;
float yPos;



void setup(){
  size(400,400);
  background(240);
  println(Serial.list());
  xPos = width/2.0;
  yPos = height/2.0;
  
  String portName = Serial.list()[11];
  myPort = new Serial(this, portName, 9600);
  
}

void draw(){
  fill(34);
  ellipse(xPos, yPos, 10,10);

} 

void serialEvent ( Serial myPort){
  
}
