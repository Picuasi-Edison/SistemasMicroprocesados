//Timer 1
/*
TIMER 1
*#include <TimerOne.h>

configuracion


timer1.attachInterrupt();

timer1.stop();
timer1.start();
timer1.restart();

*/
#include <TimerOne.h>

int cont=0;
int on=0;
void setup() {
Serial.begin(9600);
Timer1.initialize(1000000);
Timer1.attachInterrupt(contador);
attachInterrupt(0,inicio,HIGH);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
digitalWrite(8,HIGH);
delay(3000);
digitalWrite(8,LOW);
delay(3000);
}

void contador(){
  
  
  cont++;
  Serial.println(cont);
  if(cont==10){
    
    digitalWrite(9,HIGH);
    
    }
  if(cont==15){
    
    digitalWrite(10,HIGH);
    }
    if(cont==18){
    
    digitalWrite(9,LOW);
    digitalWrite(11,LOW);
    }
      if(cont==24){
    
    digitalWrite(11,LOW);
    }
    if(cont==30){
    
    digitalWrite(10,LOW);
    cont=0;
    }
  }

void inicio(){
  on=1-on;
  if(on==1){
    
    Timer1.stop();
    
    }else{
      
          Timer1.start();
      }
  
  
  }
