/*

 1. Insertar librerias
 # include <libreria.h>

 2. Declaracion de variables
 int dato;
 float dato;
 char dato;
 String dato;
 
 unsigned int dato; 64000 datos positivos
 long int dato; 16 bits
 long long int; 32 bits
 
*/

/*
void setup() {
// corre 1 sola vez cuando se inicia el sistema
// configuracion del sistema
}

void loop() {
//while(1)
//ciclo de repeticion infinita
}
*/

/*
CONFIGURACION DE PUERTOS COMO SALIDA
*
*setup
*pinMode(pin,HIGH/LOW);
                      pin 0>13
*void loop

*/
int leds[6]={8,9,10,11,12,13};
int i=0;
int j=0;
void setup(){
pinMode(7,OUTPUT);  
pinMode(8,OUTPUT); 

for(; i<6;i++){
  pinMode(leds[i],OUTPUT);
  } 
  i=0;
  }

void loop(){
/*
for(int i;i<9;i++){
  
digitalWrite(7,HIGH);
delay(300); 
digitalWrite(7,LOW);
delay(300); 
digitalWrite(8,HIGH);
delay(300); 
digitalWrite(8,LOW);
delay(300);
}

*/
//Se enciende desde el led 0 hasta el led 5(led#6)
for(;i<6;i++){
digitalWrite(leds[i],HIGH);
delay(300); 
digitalWrite(leds[i],LOW);
delay(300); 
}
// se enciende desde el led 5(led#6) y va desendiendo hasta el led 0
for(i=4;i>0;i--){
digitalWrite(leds[i],HIGH);
delay(300); 
digitalWrite(leds[i],LOW);
delay(300); 
  
  }


for(j=0;j<6;j++){
digitalWrite(leds[j],HIGH);
delay(300); 
digitalWrite(leds[j],LOW);
delay(300); 
for(i=j+1;i<6;i++)
digitalWrite(leds[i],HIGH);
delay(300); 
digitalWrite(leds[i],LOW);
delay(300); 
  }
}
  //random(5,10);
