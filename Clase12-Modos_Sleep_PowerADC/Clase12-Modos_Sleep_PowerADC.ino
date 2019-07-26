#include <avr/power.h>
#include <avr/sleep.h>

int i;
void setup() {
Serial.begin(9600);
attachInterrupt(0,on,LOW);
}

void loop() {
Serial.println(analogRead(0));
delay(20);
}

void on(){
i=1-i;

if(i==1){
  power_adc_disable();
  power_usart0_disable();
  }else{
    power_adc_enable();
    power_usart0_enable();
    }
  
  }
