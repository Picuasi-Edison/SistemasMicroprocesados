//Edison Picuasi
//Deber 6 (Timer One)
//Descripcion
/*
Estimados estudiantes: Realizar un programa de seguridad domótica que permita 
encender las luces de un domicilio de 5 habitaciones de forma aleatoria solo en 
horario nocturno. 
El sistema se activa al ingresar una contraseña por comunicación serial.
*/

#include <EEPROM.h>
#include <MsTimer2.h>
#include <TimerOne.h>
#include <LiquidCrystal.h>

//variables
int hora, minuto,segundo; //variables de almacenamiento
String CX;  //variable almacenamiento dato por CX
String msg; //variable almacenamiento estado
String pass="admin";  //variable de validacion contrasena
int opcion; //variable de estado
//long randnum; //variable 
LiquidCrystal lcd(13,12,11,10,9,8); //declara y asigna los pines del lcd
void setup() {
pinMode(7,OUTPUT);  //Configuracion led 1 como salida
pinMode(6,OUTPUT);  //Configuracion led 2 como salida
pinMode(5,OUTPUT);  //Configuracion led 3 como salida
pinMode(4,OUTPUT);  //Configuracion led 4 como salida
pinMode(3,OUTPUT);  //Configuracion led 5 como salida
Serial.begin(9600); //inicializa CX Serial
lcd.begin(16,2);  //inicializa lcd
segundo=EEPROM.read(0); //lea dato en la celda 0 de la memoria EEPROM
minuto=EEPROM.read(1);  //lea dato en la celda 1 de la memoria EEPROM
hora=EEPROM.read(2);  //lea dato en la celda 2 de la memoria EEPROM
Timer1.initialize(10000); //inicializa y configura el timer 1
Timer1.attachInterrupt(reloj);  //configura la interrupcion del timer

}

void loop() {
if(Serial.available()>0){ //comprueba si existe datos en la cx
  CX=Serial.readString(); //alamcena el dato
  Serial.println(CX); //imprime el dato ingresado
  if(CX.equals(pass)){  //comprueba si el dato es igual a la contrasena
  opcion++; //incrementa variable
    }
  }

  switch(opcion){ //comprueba el variable
    case 0:
    msg="SYSTEM OFF"; //almacena dato
    break;
    case 1:
    msg="SYSTEM ON";  //almacana el dato
    break;
    default:
    opcion=0; //inicializa variable
    }
    
if(opcion==1){  //comprueba si la variable es igual a 1
if(hora>6&&hora<10){  //comprueba y establece un limite de comparacion
  
  digitalWrite(random(3,8),HIGH); //enciende los leds
  delay(100); //detiene 
  }
}
if(hora<6){ //comprueba si la variable es menor a 6
  
    digitalWrite(3,LOW);  //apaga los leds
    digitalWrite(4,LOW);  //apaga los leds
    digitalWrite(5,LOW);  //apaga los leds
    digitalWrite(6,LOW);  //apaga los leds
    digitalWrite(7,LOW);  //apaga los leds
    delay(100); //detiene
  }

  
}

void reloj(){
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
  if(segundo<10){
    lcd.clear();
    lcd.setCursor(9,0);
    lcd.print(':');
    lcd.setCursor(10,0);
    lcd.print('0');
    lcd.setCursor(11,0);
    lcd.print(segundo);
    lcd.setCursor(0,1);
    lcd.print(msg);
    }else{
      lcd.clear();
      lcd.setCursor(9,0);
      lcd.print(':');
      lcd.setCursor(10,0);
      lcd.print(segundo);
      lcd.setCursor(0,1);
      lcd.print(msg);
      
      }
   if(minuto<10){
    lcd.setCursor(6,0);
    lcd.print(':');
    lcd.setCursor(7,0);
    lcd.print('0');
    lcd.setCursor(8,0);
    lcd.print(minuto);
    lcd.setCursor(0,1);
    lcd.print(msg);
    }else{
      lcd.setCursor(6,0);
      lcd.print(':');
      lcd.setCursor(7,0);
      lcd.print(minuto);
      lcd.setCursor(0,1);
      lcd.print(msg);
      }
    if(hora<10){
    lcd.setCursor(4,0);
    lcd.print('0');
    lcd.setCursor(5,0);
    lcd.print(hora);
    lcd.setCursor(0,1);
    lcd.print(msg);
    }else{
      lcd.setCursor(4,0);
      lcd.print(hora);
      lcd.setCursor(0,1);
      lcd.print(msg);
      }
}
