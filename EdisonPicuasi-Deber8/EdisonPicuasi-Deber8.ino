

/*
Sistemas Microprocesados
Edison Picuasi
Deber 8 - WATCH DOG

ACTIVIDAD:
Estimados estudiantes: Realizar un programa que reinicie el sistema al tener la hora 00:10:50. 
Cuando vuelva a funcionar, deberá empezar con la hora 00:11:10. Es proceso se observa en una LCD.
*/
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MsTimer2.h>
#include <avr/wdt.h>
#include <avr/sleep.h>

LiquidCrystal lcd(13,12,11,10,9,8); //declara y asigna los pines del lcd

int hora, minuto, segundo;  //variables reloj

ISR(WDT_vect) 
  {
  wdt_disable();  // disable watchdog
  }

void myWatchdogEnable(const byte interval) 
  {  
  MCUSR = 0;                          
  WDTCSR |= 0b00011000;              
  WDTCSR =  0b01000000 | interval;    

  wdt_reset();
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);  
  sleep_mode();            // now goes to Sleep and waits for the interrupt
  } 


void setup() {
//wdt_disable();
  lcd.begin(16,2);
  Serial.begin(9600);
/*
EEPROM.write(0,0);
EEPROM.write(1,0);
EEPROM.write(2,0);
*/
  segundo = EEPROM.read(0);
  minuto = EEPROM.read(1);
  hora = EEPROM.read(2);

  MsTimer2::set(1000,reloj);
  MsTimer2::start();

}

void loop() {
if(EEPROM.read(2)==0&&EEPROM.read(1)==11&&segundo==25){
  Serial.println("Reinicia Sistema");

//  myWatchdogEnable (0b100001);  // 8 seconds
//  myWatchdogEnable (0b100001);  // 8 seconds
  myWatchdogEnable (0b100000);  // 4 seconds

  }
}

void reloj () {
  if (segundo < 59) {
    segundo++;
    if(segundo%10==0){
      EEPROM.update(0, segundo);
      Serial.println("backup");
      }
  } else {
    segundo = 0;
    EEPROM.update(0, segundo);
    if (minuto < 59) {
      minuto++;
      EEPROM.update(1, minuto);
    } else {
      minuto = 0;
      EEPROM.update(1, minuto);
      if (hora < 23) {
        hora++;
        EEPROM.update(2, hora);
      } else {
        hora = 0;
        EEPROM.update(2, hora);
      }
    }
  }

    if (segundo < 10) { //comprueba el valor
      lcd.clear();  //limpia el lcd
      lcd.setCursor(9, 0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(10, 0); //posiciona el cursor
      lcd.print('0'); //Imprime mensaje
      lcd.setCursor(11, 0); //posiciona el cursor
      lcd.print(segundo); //Imprime mensaje
    } else {
      lcd.clear();  //limpia el lcd
      lcd.setCursor(9, 0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(10, 0); //posiciona el cursor
      lcd.print(segundo); //Imprime mensaje

    }
    if (minuto < 10) { //comprueba el valor
      lcd.setCursor(6, 0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(7, 0); //posiciona el cursor
      lcd.print('0'); //Imprime mensaje
      lcd.setCursor(8, 0); //posiciona el cursor
      lcd.print(minuto);  //Imprime mensaje
    } else {
      lcd.setCursor(6, 0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(7, 0); //posiciona el cursor
      lcd.print(minuto);  //Imprime mensaje
    }
    if (hora < 10) { //comprueba el valor
      lcd.setCursor(4, 0); //posiciona el cursor
      lcd.print('0'); //Imprime mensaje
      lcd.setCursor(5, 0); //posiciona el cursor
      lcd.print(hora);  //Imprime mensaje
    } else {
      lcd.setCursor(4, 0); //posiciona el cursor
      lcd.print(hora);  //Imprime mensaje
    }


}
