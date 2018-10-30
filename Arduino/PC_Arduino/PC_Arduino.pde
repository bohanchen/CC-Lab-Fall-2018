import processing.serial.*; //import library for a serial communiation

Serial myPort;    //define name of the serial communication

PImage bg;      // add the background img

void setup(){
  size(500,500);
  bg = loadImage("fan.png");
  String portName[] = Serial.list(); //check the port name
  println(portName);
  
  myPort = new Serial(this, "/dev/cu.usbmodem141241", 9600);
}


void draw(){
  background(bg);
  if (mousePressed && (mouseButton == LEFT)){
    myPort.write('1');
  }
  
  if(mousePressed && (mouseButton == RIGHT)){
    myPort.write('0');
  }
  
  if (keyPressed){
    if (key == 'r' || key == 'R'){
      myPort.write('r');
    }
    
    if (key == 'b' || key == 'B'){
      myPort.write('B');
    }
  }
}
