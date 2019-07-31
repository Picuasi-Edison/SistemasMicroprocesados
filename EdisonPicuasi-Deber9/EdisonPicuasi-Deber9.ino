/*
 * 
SISTEMAS MICROPROCESADOS
Edison Picuasi

Actividad: Realizar un sistema que permita en intervalos de tiempo (puede ser cada 2 segundos)
establecidos dormir al sistema y levantarse para lecturas de un conversor análogo digital. 
Toma la lectura, la envía por comunicación serial y se vuelve a dormir.
*
*/

#include <LowPower.h>
#include <LiquidCrystal.h>
#include <MsTimer2.h>

LiquidCrystal lcd(13,12,11,10,9,8); //declara y asigna los pines del lcd

float cad; //variable de almacenamiento cad
void setup(){
  lcd.begin(16,2);  //inicia lcd
  Serial.begin(9600); //inicia la CX Serial
  Serial.println("Sistema Activo"); //imprime mensaje por CX serial
  delay(50);  //detiene el sistema para que se imprima el mensaje de forma correcta
  }
void  loop(void){
  cad=analogRead(A0); //lee el dato del cad
  Serial.println(cad);  //imprime el valor de cad
  lcd.clear();  //limpia LCD
  lcd.setCursor(0,0); //Posiciona cursor
  lcd.print("V. CAD: ");  //imprime mensaje en la LCD
  lcd.setCursor(9,0); //Posiciona cursor
  lcd.print(cad); //imprime mensaje en la LCD
  delay(50);  //detiene el sistema para que se imprima el mensaje de forma correcta
  dormir(); //llama al metodo
  }
void dormir(){
  Serial.println("Sistema entra en suspension por 8S");//imprime mensaje por CX Serial
  delay(50);  //detiene el sistema para que se imprima el mensaje de forma correcta
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);//el sistema dormira por 8 segundos
  }
