/*
DEBER 7

Realice un sistema reloj con alarma almacenada en la EEPROM.

*/

#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <TimerOne.h>
#include <MsTimer2.h>


LiquidCrystal lcd(13,12,11,10,9,8); //declara y asigna los pines del lcd

int segundo, minuto, hora;
int aminuto,ahora;
int opcion,estado;
String CX;
String pass="ok";
String msg;
void setup() {
Serial.begin(9600);
lcd.begin(16,2);
segundo=EEPROM.read(0);
minuto=EEPROM.read(1);
hora=EEPROM.read(2);
aminuto=EEPROM.read(3);
ahora=EEPROM.read(4);
pinMode(7,OUTPUT);
Serial.print("Minuto: ");
Serial.println(EEPROM.read(3));
Serial.print("Hora: ");
Serial.println(EEPROM.read(4));

/*
for(int i=0;i<7;i++){
  EEPROM.write(i,0);
 }
 
*/
MsTimer2::set(1000,reloj);
MsTimer2::start();
attachInterrupt(0,curser,FALLING);
attachInterrupt(1,modificar,FALLING);
}

void loop() {
if(Serial.available()>0){
    CX=Serial.readString(); //alamcena el dato
  Serial.println(CX); //imprime el dato ingresado
  if(CX.equals(pass)){  //comprueba si el dato es igual a la contrasena
  opcion++; //incrementa variable
    }
  }

  switch(opcion){ //comprueba el variable
    case 0:
    msg="ALARMA OFF"; //almacena dato
    break;
    case 1:
    msg="ALARMA ON";  //almacana el dato
    break;
    default:
    opcion=0; //inicializa variable
    }

if(opcion==1){
  
  if(EEPROM.read(1)==EEPROM.read(3)&&EEPROM.read(2)==EEPROM.read(4)){
    
    digitalWrite(7,HIGH);
    }
  }else{
    
    digitalWrite(7,LOW);
    
    }

  
}

void reloj (){
  
if(segundo<59){
  segundo++;
  }else{
    segundo=0;
    if(minuto<59){
      minuto++;
      EEPROM.update(1,minuto);
      }else{
        EEPROM.update(1,minuto);
        minuto=0;
        if(hora<24){
          hora++;
          EEPROM.update(2,hora);
          }else{
            EEPROM.update(2,hora);
            hora=0;
            }
        }
    }

     if(segundo<10){ //comprueba el valor
    lcd.clear();  //limpia el lcd
    lcd.setCursor(9,0); //posiciona el cursor
    lcd.print(':'); //Imprime mensaje
    lcd.setCursor(10,0);  //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(11,0);  //posiciona el cursor
    lcd.print(segundo); //Imprime mensaje
    lcd.setCursor(0,1); //posiciona el cursor
    lcd.print(msg); //Imprime mensaje
    }else{
      lcd.clear();  //limpia el lcd
      lcd.setCursor(9,0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(10,0);  //posiciona el cursor
      lcd.print(segundo); //Imprime mensaje
      lcd.setCursor(0,1); //posiciona el cursor
      lcd.print(msg); //Imprime mensaje
      
      }
   if(minuto<10){ //comprueba el valor
    lcd.setCursor(6,0); //posiciona el cursor
    lcd.print(':'); //Imprime mensaje
    lcd.setCursor(7,0); //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(8,0); //posiciona el cursor
    lcd.print(minuto);  //Imprime mensaje
    lcd.setCursor(0,1); //posiciona el cursor
    lcd.print(msg); //Imprime mensaje
    }else{
      lcd.setCursor(6,0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(7,0); //posiciona el cursor
      lcd.print(minuto);  //Imprime mensaje
      lcd.setCursor(0,1); //posiciona el cursor
      lcd.print(msg); //Imprime mensaje
      }
    if(hora<10){  //comprueba el valor
    lcd.setCursor(4,0); //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(5,0); //posiciona el cursor
    lcd.print(hora);  //Imprime mensaje
    lcd.setCursor(0,1); //posiciona el cursor
    lcd.print(msg); //Imprime mensaje
    }else{
      lcd.setCursor(4,0); //posiciona el cursor
      lcd.print(hora);  //Imprime mensaje
      lcd.setCursor(0,1); //posiciona el cursor
      lcd.print(msg); //Imprime mensaje
      }
}

void curser(){
  estado++;
switch(estado){
  case 1:
  Serial.println("Alarma minuto");
  break;

  case 2:
  Serial.println("Alarma hora");
  break;
  default:
  estado=0;
  }
  }

void modificar(){
if(estado==1){
  if(aminuto<59){
    
    aminuto++;
      Serial.println(aminuto);
      EEPROM.update(3,aminuto);
    }else{
      aminuto=0;
      Serial.println(aminuto);
      EEPROM.update(3,aminuto);
      }
  }

if(estado==2){
  
 if(ahora<24){
    
    ahora++;
      Serial.println(ahora);
      EEPROM.update(4,ahora);
    }else{
      ahora=0;
      Serial.println(ahora);
      EEPROM.update(4,ahora);
      }
  }
}
