/*
SISTEMA DE SEGURIDAD

Instrucciones: 
Realizar un sistema de seguridad que tiene las siguientes características: 
Tiene 3 modos del sistema: activación de seguridad, modo ahorro de batería, cambio de contraseña de usuarios. 
* Modo ahorro de batería: El sistema busca reducir en máximo su consumo de recursos al apagar sus periféricos y entrar a un modo sleep interno (lcd también).
* Modo de activación: Este modo se basa en ingresar una de las 2 contraseñas por usuario que existen (diferentes a contraseña máster), 
al ser ingresada al usuario le otorga 20 segundo para salir y activan los sensores. Además, encienden luces de forma aleatoria para simular presencia. 
Si la alarma es activada se registra en la EEPROM el evento sucedido, la hora y activa una sirena. 
Para suspender la alarma, se debe ingresar la contraseña de usuario. 
Si no es activada la alarma cada 2 minutos se almacenan las condiciones de sensores en caso de un apagado general. 
Los sensores de monitoreo lo eligen cada grupo y el número de ellos (mínimo 2).
* Modo cambio de contraseña: El sistema cuenta con una contraseña máster y de usuario (5 caracteres), si el usuario no recuerda su contraseña 
puede ingresar la máster y cambiarla. 
Si se reinicia el sistema debería mantener el cambio. Finalmente, si para activar el sistema el usuario se equivoca 3 veces el sistema se bloquea 
hasta ingresar contraseña máster. El ingreso de contraseñas se lo realiza por teclado matricial.

*/

#include <LiquidCrystal.h>
#include <TimerOne.h>
#include <MsTimer2.h>
#include <EEPROM.h>
#include <Keypad.h>
#include <Password.h>

LiquidCrystal lcd(36, 35, 34, 33, 32, 31); //declara y asigna los pines del lcd


String newPasswordString;
char newPassword[6];

Password master = Password( "12345" );
Password userone1 = Password( "11425" );
Password userone2 = Password( "22425" );
Password usertwo1 = Password( "33255" );
Password usertwo2 = Password( "44255" );


byte maxPasswordLength = 6; 
byte currentPasswordLength = 0;
const byte filas = 4; //4 filas
const byte columnas = 4; //4 columnas

//crear la variable y asignar los caracteres de ingreso
char teclado[filas][columnas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[filas] = {29, 28, 27, 26}; //asignamos los pines para las filas
byte colPins[columnas] = {25, 24, 23, 22}; //asignamos los pines para las comunas

Keypad keypad = Keypad( makeKeymap(teclado), rowPins, colPins, filas, columnas);

int hora, minuto, segundo;  //variables reloj
int ahora, aminuto; //variables alarma
int opcion, intentos=3;




void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(51, OUTPUT); //buzzer
  pinMode(50, OUTPUT); //led 1
  pinMode(49, OUTPUT); //led 2
  pinMode(48, OUTPUT); //led 3
  pinMode(47, OUTPUT); //led 4
  pinMode(46, INPUT); //sensor 1
  pinMode(45, INPUT); //sensor 2
  pinMode(44, INPUT); //sensor 3
  pinMode(43, INPUT); //sensor 4

    for(int i=0;i<40;i++){
    EEPROM.write(i,0);
    }


  //Reloj almacenada en EEPROM

    //EEPROM.write(1,50);  //minuto
    //EEPROM.write(2,11);  //hora
    
  //Contrasena almacenada en EEPROM
  /*
    EEPROM.write(6,1);  //password
    EEPROM.write(7,2);  //password
    EEPROM.write(8,3);  //password
    EEPROM.write(9,6);  //password
  */
  //Dato almacenado estado de alarma
  //EEPROM.write(5,0);  //password
  //RELOJ
  segundo = EEPROM.read(0);
  minuto = EEPROM.read(1);
  hora = EEPROM.read(2);
  
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(reloj);
 

}

void loop(){
   menu();
   
  if(opcion==1){
    Serial.println("AHORRO DE BATERIA");  
    }

  if(opcion==2){
       checkPassword();
    }
  }

void menu () {   
  char key = keypad.getKey();
  if (key != NO_KEY){
      delay(60); 
      switch (key){
      case 'A':
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("BATTERY SAVE");
      opcion=1; 
      break; 
      case 'B': 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SYSTEM ACTIVATIO");
      opcion=2; 
      break; 
      case 'C': 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("CHANGE PASSWORDS");
      opcion=3; 
      break; 
      case 'D': 

      break; 
      case '#':  
      break;
      case '*': 

      break;
      default: 
      processNumberKey(key);
      }
   }
}
 
 
void processNumberKey(char key) {
   Serial.print(key);
   currentPasswordLength++;
   userone1.append(key);
   if (currentPasswordLength == maxPasswordLength) {
      checkPassword();
   } 
}



void checkPassword() {
   if (userone1.evaluate()||userone2.evaluate()||usertwo1.evaluate()||usertwo2.evaluate()){
      Serial.println("CORRECTO");
   } else {
      intentos=intentos-1;
      Serial.println("Incorrecto");
      Serial.print("Numero de Intentos: ");
      Serial.println(intentos);
   } 

}
void reloj () {
  if (segundo < 59) {
    segundo++;
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

  if (opcion == 0) {

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

}
