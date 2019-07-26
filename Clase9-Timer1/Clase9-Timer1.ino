
/*
 * Sistema de alarma cpn las siguientes funciones
 -Valida la contraseña de 4 digitos por CX Serial
 -Valida el tamaño de la contraseña ingresada
 - Si la contraseña ingresada es correcta el sistema se activa en 20 segundos
 - La alarma solo puede activarse si los todos los sensores estan apagados
 - el sistema tien edos modos: alarma y luces secuenciales para simular presencia
 
*/


#include <LiquidCrystal.h>
#include <MsTimer2.h>
#include <TimerOne.h>

LiquidCrystal lcd(13,12,11,10,9,8); //declara y asigna los pines del lcd


int funcion=0;
boolean validar;
String  CX;
String pass="1234";
int tam;
int contador;
int alarma;
void setup() {
pinMode(7,INPUT);//switch 1
pinMode(6,INPUT); //switch 2
pinMode(5,OUTPUT); //buzzer
pinMode(4,OUTPUT);//led
Serial.begin(9600);
lcd.begin(16,2);
attachInterrupt(1,funcionamiento,LOW);
Timer1.initialize(500000);
Timer1.attachInterrupt(conteo);
Timer1.stop();
lcd.setCursor(0,0);
lcd.print("Sistema OFF");
}

void loop() {
if(funcion==1){
  if(Serial.available()>0){
  CX=Serial.readString();
  if(CX.length()!=4){
    lcd.setCursor(0,1);
    lcd.print("PSW INVALIDO");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("               ");
    }else{
      validar=CX.equals(pass);
      if(validar==true){
        lcd.setCursor(0,1);
        lcd.print("PSW VALIDO");
        delay(1000);
        lcd.setCursor(0,1);
        lcd.print("               ");
        Timer1.start();
        alarma=0;
        }else{  
        lcd.setCursor(0,1);
        lcd.print("PSW INVALIDO");
        delay(1000);
        lcd.setCursor(0,1);
        lcd.print("               ");
          }
      }
  }
  }

}

void conteo(){
  
  if(contador<20){
    contador++;
    lcd.setCursor(0,1);
    lcd.print(20-contador);

    if(contador>10){
      lcd.setCursor(1,1);
      lcd.print(' ');
      }
    if(contador==20){
      lcd.setCursor(0,1);
      lcd.print("            " );
      if(digitalRead(7)==HIGH&&digitalRead(6)==HIGH){
        lcd.setCursor(0,1);
        lcd.print("CASA SEGURA");
        alarma=1;
        }
      }else{
        
        lcd.print("SENSOR SIN ON");
        delay(1000);
        lcd.print("Reinicia conteo");
        contador=0;
        }
    }
if(alarma==1){
  if(digitalRead(7)==LOW&&digitalRead(6)==LOW){
   digitalWrite(5,HIGH);
    }
  }else{
    digitalWrite(5,LOW);
    } 
  }

void funcionamiento (){
  switch(funcion){
    
    case 0:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ingrese PSW");
    funcion++;
    break;

    case 1:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Luces ON");
    funcion++;
    break;

    case 2:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sistema OFF");
    funcion=0;
    break;
    }
  }
