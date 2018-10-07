import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;

import processing.serial.*;  

Minim minim;
AudioPlayer player;
AudioPlayer player2;


Serial myPort;  
String data="" ;
int IntData;
PFont  myFont; 

//int counter = 0;

void setup(){
  size(1280,720); // size of processing window
  background(0);// setting background color to black
  printArray(Serial.list());
  String portName = Serial.list()[13];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
  
  minim = new Minim(this);
  player = minim.loadFile("Nebula.mp3");
  player2 = minim.loadFile("drump1.mp3");

  //player2.play();

}


void draw() {
  background(220);
  textAlign(CENTER);
  fill(0);
  text(data,width/2+35,700);
  textSize(20);
  
  fill(#4B5DCE);
  text("Distance :      cm", width/2,700);
  noFill();
  stroke(#4B5DCE);  
  //println("the distance is "+data);
  
  //int i = int(data);
  strokeWeight(4);
  stroke(90,49,5);
  for(int i = 0; i < player2.bufferSize() - 1; i++){
    float x1 = map( i, 0, player2.bufferSize(), 0, width );
    float x2 = map( i+1, 0, player2.bufferSize(), 0, width );
    line( x1, 150 + player2.left.get(i)*50, x2, 150 + player.left.get(i+1)*50 );
    line( x1, 550 + player2.right.get(i)*50, x2, 550 + player.right.get(i+1)*50 );
  }
  
  float posx = map(player2.position(), 0, player2.length(), 0, width);
  stroke(26,83,92);
  line(posx, 0, posx, height);
  
  
  while (myPort.available() >0){
     if (data != null) {
      int val=Integer.parseInt(data);
      //println(data);
      
      println(val);
      if (val>90 & player.isPlaying()){
        player2.pause();
        //player.play();
      }
      else if (val<70 & val>0){
        player2.rewind();
        //delay(200);
        player2.play();
        //counter = 1;
        //println("the counter is "+counter);
      } 
    }
  } //end while loop
  
}


void serialEvent(Serial myPort) {
 
  data=myPort.readStringUntil('\n').trim();
  
  
}

void keyPressed()
{
  if ( player.isPlaying() )
  {
    player.pause();
  }
  // if the player is at the end of the file,
  // we have to rewind it before telling it to play again
  else if ( player.position() == player.length() )
  {
    player.rewind();
    player.play();
  }
  else
  {
    player.play();
  }
}
