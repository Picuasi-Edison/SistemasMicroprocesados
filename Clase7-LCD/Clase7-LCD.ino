#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);
char vector[6]={'M','i','c','r','o','s'};
float datocad;
float voltaje;
int i=0,on;
void setup() {
lcd.begin(16,2);
attachInterrupt(0,ON,LOW);
}

void loop() {
/*==============================================*/
/*
lcd.setCursor(4,0); //(columna,fila)
lcd.print("MICROS");
delay(200);
lcd.clear();
delay(200);
*/

/*==============================================*/
/*
for(int j=0;j<16;j++){
  
for(int i=0;i<6;i++){
  lcd.setCursor(i+j,0);
  lcd.print(vector[i]);
  delay(100);
  lcd.setCursor(i+j,0);
  lcd.print('*'); //va borrando el dato
  delay(100);
  }
  lcd.clear();
  delay(100);
}
*/

/*==============================================*/

if(i==1){
  datocad=analogRead(0);
  voltaje=(datocad*5)/1023;

if(datocad<1000){
  
  lcd.setCursor(8,0);//debido a que se sobreescribe el 
                     //dato borramos con esta linea de codigo
  lcd.print(' ');
  }
lcd.setCursor(0,0);
lcd.print("CAD:");
lcd.setCursor(5,0);
lcd.print((int) datocad); //el int combierte a entero el float
lcd.setCursor(0,1);
lcd.print("VOL:");
lcd.setCursor(5,1);
lcd.print(voltaje);
}else{
  lcd.clear();
  }
}
void ON(){
  i=1-i;
  }
