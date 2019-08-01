
/*

SISTEMAS MICROPROCESADOS

EDISON PICUASI

EXAMEN


*/
////////////////////////////////////////EJERCICIO 1////////////////////////////////////////////
/*

Actividad: Guarde el menor dato del conversor analogo digital y almacene en la EEPROM, 
reinicie el sistema y compare con las nuevas lecturas del CAD. Si es menor al almacenado,
guardelo en la EEPROM, encienda un led e imprima por serial hasta una nueva comparacion.

*/



#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MsTimer2.h>
#include <avr/wdt.h>
LiquidCrystal lcd(13,12,11,10,9,8);

int bt1,estado;
double cad;
void setup() {
wdt_disable();
Serial.begin(9600);
lcd.begin(16,2);
pinMode(7,OUTPUT);  //led1
pinMode(6,OUTPUT);  //led2
MsTimer2::set(1000,contador);
MsTimer2::start();
//cad=analogRead(A0)/4;
//EEPROM.update(0,cad);
Serial.println("Inicia Sistema"); 
Serial.println(EEPROM.read(0));
}

void loop() {

}
void contador(){
  cad=analogRead(A0)/4;
if(cad<EEPROM.read(0)){
  EEPROM.update(0,cad);
  Serial.println("Menor");
  Serial.println(EEPROM.read(0));
  digitalWrite(7,HIGH);
  delay(200);
  MsTimer2::stop();
  Serial.println("Inicia Watchdog en 4S");  
  wdt_enable(WDTO_4S);
  }else{
    Serial.println("Mayor");
    }
}


////////////////////////////////////////EJERCICIO 2////////////////////////////////////////////
/*
Actividad: Ingrese el tiempo de configuracion separado por comas del timer 1 y 2 y activelos
por interrupcion, encienda leds para verificar el tiempo de cada uno.
*/



/*


#include <MsTimer2.h>
#include <TimerOne.h>


int conteo1,conteo2;
int on1,on2;
int analog1,analog2;
String CX,dato1,dato2;
void setup() {
Serial.begin(9600);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
attachInterrupt(0,Tiempo1,FALLING);
attachInterrupt(1,Tiempo2,FALLING);
Serial.println("Ingrese los tiempos para el Timer1 y Timer2 separados por una coma.");
Serial.println("EJEMPLO: 10000,100");
}

void loop() {

if(Serial.available()>0){
CX=Serial.readString();
  dato1=CX.substring(0,CX.indexOf(","));
  
  Serial.println("");
  Serial.print("Timepo 1: ");
  Serial.println(dato1);
  dato2=CX.substring(CX.indexOf(",")+1,CX.length());
  Serial.print("Timepo 2: ");
  Serial.println(dato2);
  analog1=dato1.toInt();
  analog2=dato2.toInt();
}

}

void Tiempo1(){
  on1=1-on1;
    Serial.print("b1: "); 
  Serial.println(on1);
  if(on1==1){
    Timer1.initialize(analog1);
    Timer1.attachInterrupt(Time1);
    Timer1.start();
    }else{
      Timer1.stop();
      }
  }

void Tiempo2(){
  on2=1-on2;
  Serial.print("b2: "); 
  Serial.println(on2);
  if(on2==1){
    MsTimer2::set(analog2,Time2);
    MsTimer2::start();
    }else{
      MsTimer2::stop();
      }
  }
void Time1(){
if(on1==1){
conteo1++;
Serial.print("Timer1: ");
Serial.println(conteo1);
if(conteo1%2==0){
  digitalWrite(6,HIGH);
  }else{
      digitalWrite(6,LOW);
    }
}
  }
void Time2(){
  if(on2==1){
  conteo2++;
  Serial.print("Timer2: ");
  Serial.println(conteo2);
  if(conteo2%2==0){
  digitalWrite(7,HIGH);
  }else{
      digitalWrite(7,LOW);
    }
  }
  }



*/
