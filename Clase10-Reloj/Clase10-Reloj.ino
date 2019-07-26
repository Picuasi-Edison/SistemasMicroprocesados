#include <TimerOne.h>
#include <MsTimer2.h>
#include <EEPROM.h>
//posicion 0->segundero
//posicion 1->minutero
//posicion 2->horero
//reloj

int segundero;
int minutero;
int horero;
int i=0;
void setup() {
Serial.begin(9600);  
/*EEPROM.write(0,0);
EEPROM.write(1,0);
EEPROM.write(2,0);
Serial.println(EEPROM.read(0));
Serial.println(EEPROM.read(1));
Serial.println(EEPROM.read(2));*/
MsTimer2::set(100,reloj);
MsTimer2::start();
Timer1.initialize(1000000);
Timer1.attachInterrupt(backup);
segundero=EEPROM.read(0);
minutero=EEPROM.read(1);
horero=EEPROM.read(2);
}

void loop() {

}

void reloj(){
if(segundero<59){
  segundero++;
  }else{
    segundero=0;
    if(minutero<59){
      minutero++;
      }else{
        minutero=0;
        if(horero<12){
          horero++;
          }else{
            horero=0;
            }
        }
    }
 Serial.print(horero);
 Serial.print(':'); 
  Serial.print(minutero);
  Serial.print(':'); 
   Serial.println(segundero);   
}
void backup(){
  i++;
  if(i==5){
    Serial.println("Backup");
    EEPROM.write(0,segundero);
    EEPROM.write(1,minutero);
    EEPROM.write(2,horero);
    }
  }
