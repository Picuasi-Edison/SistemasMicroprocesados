

/*
Realizar un sistema que tenga tres funciones:
- La primera es realizar la sucesión fibonazi de los primeros 20 números vistos en una LCD cada 2 segundos.
- La segunda es una serie geométrica de los primeros 40 números cada 1 segundo en una LCD. *
- La tercera una serie exponencial cada 4 segundos de los primeros 30 números vistos en una LCD.
Cuando termine cada una de estas actividades, debe reiniciar el sistema para el desarrollo de la siguiente.

*/

#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MsTimer2.h>
#include <avr/wdt.h>

int funcion;
int limite;
long fnum1=0, fnum2=1, fnum3;
float gnum1=0, gnum2=0.002, gnum3=2; //gnum1-> resultado, gnum2-> valor inicial, gnum3->razon de aumento
float enum1=1,enum2=1,enum3=3;  //enum1-> , enum2-> , enum3->;
int segundos=0;
//LiquidCrystal lcd(36, 35, 34, 33, 32, 31); //declara y asigna los pines del lcd
LiquidCrystal lcd(13,12,11,10,9,8); //declara y asigna los pines del lcd
void setup() {
wdt_disable();
Serial.begin(9600);
lcd.begin(16,2);
//EEPROM.write(0,1);  //almacena la funcion
funcion=EEPROM.read(0);
MsTimer2::set(1000,reloj);
MsTimer2::start();
if(EEPROM.read(0)==0){
  Serial.println("serie de FIBONACCI");
  }
if(EEPROM.read(0)==1){
  Serial.println("serie de Geometrica");
  }
if(EEPROM.read(0)==2){
  Serial.println("serie de Exponencial");
  }
}

void loop() {

}

void reloj(){
  segundos++;
  lcd.clear();
  lcd.setCursor(13,0);
  lcd.print(segundos);
  
/////////////////////////////////////////SERIE DE FIBONACI///////////////////////////////
  if(EEPROM.read(0)==0){
    lcd.setCursor(0,0);
    lcd.print("FIBONACCI");
    if(segundos%2==0&&limite<20){
      limite++;      
            fnum3=fnum1+fnum2;
            fnum1=fnum2;
            fnum2=fnum3;
            Serial.print("serie ");
            Serial.print(limite);
            Serial.print(" :");
            Serial.println(fnum3);
            lcd.setCursor(0,1);
            lcd.print(fnum3);
      }
            lcd.setCursor(0,1);
            lcd.print(fnum3);
      if(limite==20){
        Serial.println("cambia a 2");
        EEPROM.update(0,1);
        limite=0;
        wdt_enable(WDTO_30MS);
        }
        
    }
//////////////////////////////////////SERIE GEOMETRICA///////////////////////////////////
  if(EEPROM.read(0)==1){
    lcd.setCursor(0,0);
    lcd.print("GEOMETRICA");
    if(limite<40){
      limite++;

/*
            if(limite==1){
            gnum1= gnum2*(((1-pow(gnum3,limite)))/(1-gnum3));
            }else{
              gnum1= gnum2*(((1-pow(gnum3,limite)))/(1-gnum3));
              }
*/

//gnum1=gnum1+gnum2;
//gnum2=gnum2*gnum3;

            gnum1=gnum2*pow(gnum3,limite-1);
              
            Serial.print("serie ");
            Serial.print(limite);
            Serial.print(" :");
            Serial.println(gnum1,3);
            lcd.setCursor(0,1);
            lcd.print(gnum1,3);
      }
            lcd.setCursor(0,1);
            lcd.print(gnum1,3);
      if(limite==40){
        Serial.println("cambia a 3");
        EEPROM.update(0,2);
        limite=0;
        wdt_enable(WDTO_30MS);
        }
        
    }
/////////////////////////////////////SERIE EXPONENCIAL///////////////////////////////////
  if(EEPROM.read(0)==2){
    lcd.setCursor(0,0);
    lcd.print("EXPONENCIAL");
    if(segundos%4==0&&limite<30){
      limite++;
            enum1=enum1*enum3/limite;
            enum2=enum2+enum1;
            Serial.print("serie ");
            Serial.print(limite);
            Serial.print(" :");
            Serial.println(enum2,10);
            
            lcd.setCursor(0,1);
            lcd.print(enum2,10);
      }
            lcd.setCursor(0,1);
            lcd.print(enum2,10);
      if(limite==30){
        
        Serial.println("cambia a 1");
        EEPROM.update(0,0);
        limite=0;
        wdt_enable(WDTO_30MS);
        }
        
    }
//////////////////////////////////////////////////////////////////////////////////////////
  }
