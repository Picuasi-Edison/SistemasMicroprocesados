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

LiquidCrystal lcd(36, 35, 34, 33, 32, 31); //declara y asigna los pines del lcd

const byte filas = 4; //4 filas
const byte columnas = 4; //4 columnas
String cifra;
int customKey;

//crear la variable y asignar los caracteres de ingreso
char teclado[filas][columnas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'F', '0', 'G', 'D'}
};
byte rowPins[filas] = {29, 28, 27, 26}; //asignamos los pines para las filas
byte colPins[columnas] = {25, 24, 23, 22}; //asignamos los pines para las comunas

Keypad customKeypad = Keypad( makeKeymap(teclado), rowPins, colPins, filas, columnas);

int hora, minuto, segundo;  //variables reloj
int tsegundo;  //variables temporizador
int ahora, aminuto; //variables alarma
int opcion, presion = 5, contpass = 0;
int aestado, passestado, on;
int verpass[5];  //variable ingreso de contrasena
int noche[4];
int ntime;
int nkey = 5;
int light, horario,alight;
String msg1,msg2,msg3,msg4;
int intentos=3;
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
/*
    for(int i=0;i<40;i++){
    EEPROM.write(i,0);
    }
*/  

  //Reloj almacenada en EEPROM

    //EEPROM.write(1,50);  //minuto
    //EEPROM.write(2,11);  //hora

  //Alarma del sistema de luces almacenada en EEPROM

    //EEPROM.write(3,40);  //minuto alarma luces
    //EEPROM.write(4,20);  //hora alarma luces
    
  //Contrasena almacenada en EEPROM
/*
    //ADMIN
    EEPROM.write(10,1);  //password
    EEPROM.write(11,2);  //password
    EEPROM.write(12,3);  //password
    EEPROM.write(13,4);  //password
    EEPROM.write(14,5);  //password
    //USERONE1
    EEPROM.write(15,1);  //password
    EEPROM.write(16,1);  //password
    EEPROM.write(17,2);  //password
    EEPROM.write(18,4);  //password
    EEPROM.write(19,5);  //password
    //USERONE2
    EEPROM.write(20,2);  //password
    EEPROM.write(21,2);  //password
    EEPROM.write(22,2);  //password
    EEPROM.write(23,4);  //password
    EEPROM.write(24,5);  //password
    //USERTWO1
    EEPROM.write(25,1);  //password
    EEPROM.write(26,1);  //password
    EEPROM.write(27,2);  //password
    EEPROM.write(28,3);  //password
    EEPROM.write(29,6);  //password
    //USERTWO2
    EEPROM.write(30,2);  //password
    EEPROM.write(31,2);  //password
    EEPROM.write(32,4);  //password
    EEPROM.write(33,3);  //password
    EEPROM.write(34,1);  //password
*/
 
  //Dato almacenado estado de alarma
  //EEPROM.write(5,0);  //password
  //RELOJ
  segundo = EEPROM.read(0);
  minuto = EEPROM.read(1);
  hora = EEPROM.read(2);
  //SENSORES
  aminuto = EEPROM.read(3);
  ahora = EEPROM.read(4);
  //Estado de la alarma
  aestado = EEPROM.read(5);
  //Estado Luces
  alight = EEPROM.read(9);

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(reloj);
  MsTimer2::set(1000,temporizador);

}

void loop() {
  customKey = customKeypad.getKey();  //almacena el dato ingresado por teclado
  menu();
  /////////////////////////////////Validar////////////////////////////////////////////
  if (opcion == 2) {
    if (customKey == '0' || customKey == '1' || customKey == '2' || customKey == '3' || customKey == '4' ||
        customKey == '5' || customKey == '6' || customKey == '7' || customKey == '8' || customKey == '9') {
      customKey = customKey - 48;
      verpass[contpass] = customKey; //almacena el dato ingresado en cada posicion
      contpass++; //aumenta contador
      presion++;
      lcd.setCursor(presion, 1);
      lcd.print('*');
      Serial.println(customKey);
    }
    if (contpass == 5) {
//USERONE1
      if (verpass[0] == EEPROM.read(15) && verpass[1] == EEPROM.read(16) &&
          verpass[2] == EEPROM.read(17) && verpass[3] == EEPROM.read(18)&&
          verpass[4] == EEPROM.read(19)) {
        Serial.println("CORRECTO");
        aestado = 1 - aestado;
        EEPROM.update(5, aestado);
        Serial.print("alarma: ");
        Serial.println(aestado);
        contpass = 0;
        presion = 5;
        if(aestado==1){
        MsTimer2::start();
        }
        opcion=0;
      }
//USERONE2
      else if (verpass[0] == EEPROM.read(20) && verpass[1] == EEPROM.read(21) &&
          verpass[2] == EEPROM.read(22) && verpass[3] == EEPROM.read(23)&&
          verpass[4] == EEPROM.read(24)) {
        Serial.println("CORRECTO");
        aestado = 1 - aestado;
        EEPROM.update(5, aestado);
        Serial.print("alarma: ");
        Serial.println(aestado);
        contpass = 0;
        presion = 5;
        if(aestado==1){
        MsTimer2::start();
        }
        opcion=0;
      }
//USERTWO1
      else if (verpass[0] == EEPROM.read(25) && verpass[1] == EEPROM.read(26) &&
          verpass[2] == EEPROM.read(27) && verpass[3] == EEPROM.read(28)&&
          verpass[4] == EEPROM.read(29)) {
        Serial.println("CORRECTO");
        aestado = 1 - aestado;
        EEPROM.update(5, aestado);
        Serial.print("alarma: ");
        Serial.println(aestado);
        contpass = 0;
        presion = 5;
        if(aestado==1){
        MsTimer2::start();
        }
        opcion=0;
      }
//USERTWO2
      else if (verpass[0] == EEPROM.read(30) && verpass[1] == EEPROM.read(31) &&
          verpass[2] == EEPROM.read(32) && verpass[3] == EEPROM.read(33)&&
          verpass[4] == EEPROM.read(34)) {
      Serial.println("CORRECTO");
        aestado = 1 - aestado;
        EEPROM.update(5, aestado);
        Serial.print("alarma: ");
        Serial.println(aestado);
        contpass = 0;
        presion = 5;
        if(aestado==1){
        MsTimer2::start();
        }
        opcion=0;
      }else{
        intentos=intentos-1;
        Serial.println(intentos);
        contpass = 0;
        presion = 5;
        }     
    }
  }

if(tsegundo==20){
  MsTimer2::stop();
  tsegundo=0;
  EEPROM.update(9,1);
  }

  if(intentos==0){
    opcion=5;
    }

  if (opcion == 5) {
      
    if (customKey == '0' || customKey == '1' || customKey == '2' || customKey == '3' || customKey == '4' ||
        customKey == '5' || customKey == '6' || customKey == '7' || customKey == '8' || customKey == '9') {
      customKey = customKey - 48;
      verpass[contpass] = customKey; //almacena el dato ingresado en cada posicion
      contpass++; //aumenta contador
      presion++;
      lcd.setCursor(presion, 1);
      lcd.print('*');
      Serial.println(customKey);
    }

    if (contpass == 5) {
      if (verpass[0] == EEPROM.read(10) && verpass[1] == EEPROM.read(11) &&
          verpass[2] == EEPROM.read(12) && verpass[3] == EEPROM.read(13)&&
          verpass[4] == EEPROM.read(14)) {
        //lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correcto        ");
        Serial.println("MASTER CORRECTO");
        delay(400);
        contpass = 0;
        presion = 5;
        passestado = 1;
        lcd.clear();
        opcion=6;
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Incorrecto      ");
        Serial.println("MASTER INCORRECTO");
        contpass = 0;
        presion = 5;
        passestado = 2;
      }
    }
  }

  if (passestado == 1) {
        lcd.setCursor(0,0);
        lcd.print("SELECT USER");
    if (customKey == '0' || customKey == '1' || customKey == '2' || customKey == '3' || customKey == '4' ||
        customKey == '5' || customKey == '6' || customKey == '7' || customKey == '8' || customKey == '9') {
      nkey++;
      customKey = customKey - 48;
      EEPROM.update(nkey, customKey);
      presion++;
      lcd.setCursor(presion, 1);
      lcd.print('*');
      Serial.println(customKey);
    }
  }

  //////////////////////////Sistema de Seguridad///////////////////////////////
  if (EEPROM.read(5)==1) {
    if (digitalRead(46) == HIGH || digitalRead(45) == HIGH || digitalRead(44) == HIGH || digitalRead(43) == HIGH) {
      digitalWrite(51, HIGH);
    }
  } else {
    digitalWrite(51, LOW);
  }
  //////////////////////////Sistema de luces///////////////////////////////////
  if(EEPROM.read(9)==1){
  if (EEPROM.read(1) == 30 && EEPROM.read(2) == 18) {

    digitalWrite(50,HIGH); 
    digitalWrite(49,HIGH);
    digitalWrite(48,HIGH); 
    digitalWrite(47,HIGH);
    }

  if(EEPROM.read(1)==0&&EEPROM.read(2)==0){
    digitalWrite(50,LOW);
    digitalWrite(49,LOW);
    digitalWrite(48,LOW);
    digitalWrite(47,LOW);
    }
  }else{
    digitalWrite(50,LOW);
    digitalWrite(49,LOW);
    digitalWrite(48,LOW);
    digitalWrite(47,LOW);
    }
}

void menu () {
  switch (customKey) {
    case 65:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SAVE BATTERY");
      opcion = 1;
      break;
    case 66:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SYSTEM ACTIVATIO");
      opcion = 2;   
      break;
    case 67:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CHANGE PASSWORDS");
      break;
  } 
}


void temporizador () {
tsegundo++;
Serial.print("Temporizador: ");
Serial.println(tsegundo);
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
