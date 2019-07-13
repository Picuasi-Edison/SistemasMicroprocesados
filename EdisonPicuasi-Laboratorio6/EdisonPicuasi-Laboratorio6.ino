//Edison Picuasi
//SISTEMA DOMOTICO
/*
Estimados estudiantes: Realizar un sistema domótico que cuente 
con un sistema de alarma y sistema de luces autónomas, con sistema 
de ingreso por contraseña y almacenamiento de eventos en EEPROM 
(si se desconecta de la batería el sistema debe recordar si algún evento sucedió)
*/

#include <LiquidCrystal.h>
#include <TimerOne.h>
#include <MsTimer2.h>
#include <EEPROM.h>
#include <Keypad.h>

LiquidCrystal lcd(36,35,34,33,32,31); //declara y asigna los pines del lcd

const byte filas = 4; //4 filas
const byte columnas = 4; //4 columnas
String cifra;
char customKey;

//crear la variable y asignar los caracteres de ingreso
char teclado[filas][columnas] = {
  {'1','2','3','/'},
  {'4','5','6','*'},
  {'7','8','9','-'},
  {'C','0','=','+'}
};
byte rowPins[filas] = {29,28,27,26}; //asignamos los pines para las filas
byte colPins[columnas] = {25,24,23,22}; //asignamos los pines para las comunas

Keypad customKeypad = Keypad( makeKeymap(teclado), rowPins, colPins, filas, columnas); 

int hora, minuto, segundo;
int ahora, aminuto;
int opcion,presion=5,contpass=0;

char pass [4]={'1','2','3','4'};  //variable contrasena predfinida
char verpass[4];  //variable ingreso de contrasena

void setup() {
Serial.begin(9600);
lcd.begin(16,2);
pinMode(4,OUTPUT);//led 1
pinMode(5,OUTPUT);//led 2
pinMode(6,OUTPUT);//led 3
pinMode(7,OUTPUT);//led 4
/*
for(int i=0;i<20;i++){
  EEPROM.write(i,0);
  }
*/
segundo=EEPROM.read(0);
minuto=EEPROM.read(1);
hora=EEPROM.read(2);
aminuto=EEPROM.read(3);
ahora=EEPROM.read(4);

Timer1.initialize(1000000);
Timer1.attachInterrupt(reloj);
MsTimer2::set(1000,cronometro);
MsTimer2::start();
attachInterrupt(2,menu,FALLING);

}

void loop() {
customKey = customKeypad.getKey();  //almacena el dato ingresado por teclado
if(opcion==1){
  if(customKey){
    verpass[contpass]=customKey; //almacena el dato ingresado en cada posicion
    
    contpass++; //aumenta contador
    presion++;
    lcd.setCursor(presion,1);
    lcd.print('*');
    Serial.println(customKey);
  }

  if(contpass==4){

      if(verpass[0]==pass[0]&&verpass[1]==pass[1]&&
       verpass[2]==pass[2]&&verpass[3]==pass[3]){
        //lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Correcto    ");

        contpass=0;
        presion=5;
                
        }else{
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Incorrecto");

          contpass=0;
          presion=5;
          }
      
      
      }
}

if(opcion==2){
  
  
  
  
  
  }

}
void reloj (){
  if(segundo<59){
  segundo++;
  }else{
    segundo=0;
    EEPROM.update(0,segundo);
    if(minuto<59){
      minuto++;
      EEPROM.update(1,minuto);
      }else{
        minuto=0;
      EEPROM.update(1,minuto);
        if(hora<12){
          hora++;
          EEPROM.update(2,hora);
          }else{
            hora=0;
            EEPROM.update(2,hora);
            }
        }
    }
     
 if(opcion==0){
     
     if(segundo<10){ //comprueba el valor
    lcd.clear();  //limpia el lcd
    lcd.setCursor(9,0); //posiciona el cursor
    lcd.print(':'); //Imprime mensaje
    lcd.setCursor(10,0);  //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(11,0);  //posiciona el cursor
    lcd.print(segundo); //Imprime mensaje
    }else{
      lcd.clear();  //limpia el lcd
      lcd.setCursor(9,0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(10,0);  //posiciona el cursor
      lcd.print(segundo); //Imprime mensaje
      
      }
   if(minuto<10){ //comprueba el valor
    lcd.setCursor(6,0); //posiciona el cursor
    lcd.print(':'); //Imprime mensaje
    lcd.setCursor(7,0); //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(8,0); //posiciona el cursor
    lcd.print(minuto);  //Imprime mensaje
    }else{
      lcd.setCursor(6,0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(7,0); //posiciona el cursor
      lcd.print(minuto);  //Imprime mensaje
      }
    if(hora<10){  //comprueba el valor
    lcd.setCursor(4,0); //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(5,0); //posiciona el cursor
    lcd.print(hora);  //Imprime mensaje
    }else{
      lcd.setCursor(4,0); //posiciona el cursor
      lcd.print(hora);  //Imprime mensaje
      }

}
  
  }
void cronometro(){
  
  
  }

void menu (){
  opcion++;
  switch(opcion){
    case 1:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter Password");
    break;
    case 2:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Light System");
    break;
    case 3:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Event List");
    break;
    default:
    opcion=0;
    
    }

  }
