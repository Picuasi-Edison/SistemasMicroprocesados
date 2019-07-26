/*
  MODOS SLEEP Y AHORRO DE BATERIA
  El consumo del arduido se encuentra entre 100 a 500 mA
  El ahorro de bateria es hasta 10 mA
  Librerias:
            avr/sleep.h
            avr/power.h

  Configuracion:
            set_sleep_mode(modo):
            modo->  SLEEP_MODE_IDLE
                    SLEEP_MODE_ADC
                    SLEEP_MODE_PWR_SAVE
                    SLEEP_MODE_STANDBY
                    SLEEP_MODE_PWR_DOWN
                    
            sleep_enable();
            sleep_disable();

            power_xx_disable();
            power_xx_enable();

            xx: adc
                timer0
                lcd
                timer1
                usart
                all
            

*/

#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <EEPROM.h>
int dato;
void on (void); //se hace esto para estructurar dde forma mas adecuada el programa se
                //emplea en un lenguaje c mas puro

void setup() {
EEPROM.write(0,0);
Serial.begin(9600);
Serial.println("SETUP");
if(dato==0){
  set_sleep_mode(SLEEP_MODE_STANDBY);
  sleep_enable();
  EEPROM.write(0,1);
  wdt_enable(WDTO_8S);
  }else{
    sleep_disable();
    EEPROM.write(0,0);
    wdt_enable(WDTO_1S);
    }


}

void loop() {
if(dato==0){
  sleep_mode(); //entra a dormir
  delay(20);
  Serial.println("ME DESPERTE"); //contar el tiempo que el sistema permanece encendido
  }else{
    delay(20);
    Serial.println("ME DORMI");
    }
}
