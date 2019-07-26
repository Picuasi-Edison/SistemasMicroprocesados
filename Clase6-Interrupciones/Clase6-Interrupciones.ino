/*
COnfiguracion de interrupciones
attachInterrpt(pin de interrupcion, subrutina, modo);
              pin interrupcion-->#interrupcion, pin de la interrupcion
              digitalpinINterrupt(pin);

              subrutina--> void metodo()
              modo-->LOW,RISING,FALLING
*/

int led_red=12;
int led_green=13;
int inter=2;
int on=0;
volatile byte stado=LOW;
void setup() {
Serial.begin(9600);
pinMode(led_red,OUTPUT);
pinMode(led_green,OUTPUT);
pinMode(inter,INPUT);
attachInterrupt(digitalPinToInterrupt(inter),INTER,LOW);

}

void loop() {
if(on==1){  
digitalWrite(led_green,HIGH);
delay(400);
digitalWrite(led_green,LOW);
delay(400);
digitalWrite(led_red,stado);
delay(400);
digitalWrite(led_red,stado);
delay(400);
  
}
}

void INTER(){
//stado=!stado;
 on=1-on; 
  
  }
