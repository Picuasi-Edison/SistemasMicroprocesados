/*
DEBER 7

Realice un sistema reloj con alarma almacenada en la EEPROM.

*/

#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <TimerOne.h>
#include <MsTimer2.h>


LiquidCrystal lcd(13,12,11,10,9,8); //declara y asigna los pines del lcd

int segundo, minuto, hora;  //variables minuto hora y segundo para el reloj
int aminuto,ahora;  //variable minuto y hora para la alarma
int opcion,estado;  //variable de monitoreo
String CX;  //variable de validacion contrasena
String pass="ok"; //variable contrasena
String msg; //variable para el mensaje
void setup() {
Serial.begin(9600); //inicializa CX Serial
lcd.begin(16,2);  //inicializa lcd
segundo=EEPROM.read(0); //almacena el dato de la memoria EEPROM en la variable
minuto=EEPROM.read(1);  //almacena el dato de la memoria EEPROM en la variable
hora=EEPROM.read(2);  //almacena el dato de la memoria EEPROM en la variable
aminuto=EEPROM.read(3); //almacena el dato de la memoria EEPROM en la variable
ahora=EEPROM.read(4); //almacena el dato de la memoria EEPROM en la variable
pinMode(7,OUTPUT);  //configura pin del buzzer
Serial.print("Minuto: "); //imprime el mensaje por CX
Serial.println(EEPROM.read(3));   //lee el dato almacenado en EEPROM
Serial.print("Hora: "); //imprime por CX el mensaje
Serial.println(EEPROM.read(4)); //lee el dato almacenado en EEPROM

/*
 * proceso para borrar datos en la memoria EEPROM
for(int i=0;i<7;i++){
  EEPROM.write(i,0);
 }
 
*/
MsTimer2::set(1000,reloj);  //configura y establece el tiempo
MsTimer2::start();  //inicia el timer
attachInterrupt(0,curser,FALLING);  //configuracion interrupcion
attachInterrupt(1,modificar,FALLING); //configuracion interrupcion
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
  
  if(EEPROM.read(1)==EEPROM.read(3)&&EEPROM.read(2)==EEPROM.read(4)){ //verifica si las variables de la alarma y reloj es igual
    
    digitalWrite(7,HIGH);//Buzzer
    }
  }else{
    
    digitalWrite(7,LOW);//Buzzer
    
    }

  
}

void reloj (){
  
if(segundo<59){ //comprueba si el valor de segundo es menor a 59
  segundo++;  //incrementa variable
  }else{
    segundo=0;  //reinicia variable
    if(minuto<59){  //comprueba si el valor de minuto es menor a 59
      minuto++; //incrementa variable
      EEPROM.update(1,minuto);  //almacena el dato en la memoria EEPROM
      }else{
        EEPROM.update(1,minuto);  //almacena el dato en la memoria EEPROM
        minuto=0; //reinicia variable
        if(hora<24){  //comprueba si el valor de hora es menor a 24
          hora++; //incrementa variable
          EEPROM.update(2,hora);  //almacena el dato en la memoria EEPROM
          }else{
            EEPROM.update(2,hora);  //almacena el dato en la memoria EEPROM
            hora=0; //reinicia variable
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
  estado++; //incrementa variable
switch(estado){
  case 1:
  Serial.println("Alarma minuto");  //imprime el mensaje por CX Serial
  break;

  case 2:
  Serial.println("Alarma hora");  //Imprime el mensaje por CX serial
  break;
  default:
  estado=0; //reinicia la variable
  }
  }

void modificar(){
if(estado==1){  //verifica el estado actual
  if(aminuto<59){ //verifica si la variable es menor a 59
    aminuto++;  //incrementa la variable
      Serial.println(aminuto);  //Imprime por CX serial
      EEPROM.update(3,aminuto); //almacena el dato en la EEPROM
    }else{
      aminuto=0;  //reinicia variable
      Serial.println(aminuto);  //Imprime por CX serial
      EEPROM.update(3,aminuto); //almacena el dato en la EEPROM
      }
  }

if(estado==2){  //verifica el estado actual
  
 if(ahora<24){  //verifica si la variable es menor a 24
    
    ahora++;  //incrementa la variable
      Serial.println(ahora);  //Imprime por CX serial
      EEPROM.update(4,ahora); //almacena el dato en la EEPROM
    }else{
      ahora=0;
      Serial.println(ahora);  //Imprime por CX serial
      EEPROM.update(4,ahora); //almacena el dato en la EEPROM
      }
  }
}
