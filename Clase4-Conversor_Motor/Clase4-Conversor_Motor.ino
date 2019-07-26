/*
Controlar velocidad del motor
*Mediante potenciometro
*
*Recicbir los datos de un conversor analogico y 
*enviarlo por una senal analogica

analogRead(pin);  0-1023
analogWrite(pin); 0-1023

*/
#include <Servo.h>
Servo servo1; 

//variables

int conversor;
int pwm=9;
int movservo;
int y;
int ant;
String dato;
int limite;



void setup() {
Serial.begin(9600);//Habilitar CX
pinMode(pwm,OUTPUT);
servo1.attach(10);
Serial.println("Ingrese un Limite: ");

}

void loop() {
/*movimiento con el potenciometro*/  

/*
conversor=analogRead(0)/4;
analogWrite(pwm,conversor);
delay(15);

servo1.write(10);
delay(500);
servo1.write(170);
delay(500);
*/


/*Lectura en comunicacion Serial*/


movservo=analogRead(1);//recibo dato del conversor
y=map(movservo,0,1023,0,180);//regla de 3 compuesta
if(Serial.available()>0){



  
  dato=Serial.readString();
  //Serial.println(dato);//comprueba que si existe dato eco
  limite=dato.toInt();//combierte el String en int

  if(y<limite){
    
    if(ant!=y){//condicion de impresion solo si el dato cambia
  Serial.print("Angulo: ");
  Serial.println(y);//Se puede imprimir en HEX DEC BIN
  ant=y;//adquiere el nuevo dato
  }
servo1.write(y);//movimiento de servo de 0 a 180
delay(15);
    }else{
      Serial.println("Limite Superado");
      }
  
  }






/*Movimiento con la funcion map y potenciometro*/
/*
movservo=analogRead(1);//recibo dato del conversor
y=map(movservo,0,1023,0,180);//regla de 3 compuesta

servo1.write(y);//movimiento de servo de 0 a 180
delay(15);

  if(ant!=y){//condicion de impresion solo si el dato cambia
  Serial.print("Angulo: ");
  Serial.println(y);//Se puede imprimir en HEX DEC BIN
  ant=y;//adquiere el nuevo dato
  }
*/
}
