import processing.serial.*; //import library for a serial communiation

Serial myPort;    //define name of the serial communication

PImage bg;      // add the background img

void setup(){
  size(500,500);
  bg = loadImage("icon.png");
 
  String portName[] = Serial.list(); //check the port name
  println(portName[9]);
  
  myPort = new Serial(this, portName[9], 9600);
}


void draw(){
  background(bg);
  if (mousePressed && (mouseButton == LEFT)){
    println("left pressed");
    myPort.write('1');
  }
  
  if(mousePressed && (mouseButton == RIGHT)){
    myPort.write('2');
    println("right pressed");
  }
}
