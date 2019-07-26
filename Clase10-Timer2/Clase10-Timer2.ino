//Cuando se trabaja con timers los servos quedan inhabilitados
//Timer2

/*
MsTimer2::set(1000,rutina);
MsTimer2::start();
MsTimer2::stop();
MsTimer2::restart();
*/

//EEPROM
/*
EEPROM.write(dir,dato); dir-> posicion de la memoria
                        dato->  byte
EEPROM.read(dir);
EEPROM.update(dir,dato);
EEPROM.put(dir,dato);
EEPROM.get(dir,var);  var->variable de lectura
EEPROM.length();

*/

#include <MsTimer2.h>
#include <EEPROM.h>


int i=0,j=0;
void setup() {
Serial.begin(9600);
MsTimer2::set(1000,cont2);
//attachInterrupt(0,on,FALLING);
  attachInterrupt(0,eeprom,LOW);
  i=EEPROM.read(1);
/*
EEPROM.write(1,0);
Serial.println(EEPROM.read(1));
*/

//lectura y escritura de datos en EEPROM
/*
for(;i<EEPROM.length();i++){
  Serial.print(i);
  Serial.print(';');
  Serial.println(EEPROM.read(i));
  //BORRAR Datos en EEPROM
  //EEPROM.write(i,0);
  //Serial.println(EEPROM.read(i));
  }
*/
}

void loop() {
}
////////////////////////////TIMER2/////////////////////////
void cont2(){
i++;
EEPROM.update(1,i);
Serial.println(EEPROM.read(1));
}
////////////////////////////////////////////////////////////
/*
void on(){
j=1-j;
if(j==1){
  i=0;
  MsTimer2::stop();
}else{
  MsTimer2::start();
  }
}
*/
/////////////////////////////////////////////////////////////
////////////////////////EEPROM///////////////////////////////
void eeprom(){
  j=1-j;
if(j==1){
  Serial.println("Se detuvo");
  MsTimer2::stop();
  }else{
  Serial.println("inicia");
  MsTimer2::start();
  }
  
  
  }
