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
int thora, tminuto, tsegundo;  //variables temporizador
int ahora, aminuto; //variables alarma
int opcion, presion = 5, contpass = 0;
int aestado, passestado, on;
int verpass[4];  //variable ingreso de contrasena
int noche[4];
int ntime;
int nkey = 5;
int light, horario,alight;
String msg1,msg2,msg3,msg4;

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
    for(int i=0;i<20;i++){
    EEPROM.write(i,0);
    }
  */

  //RELOJ
  segundo = EEPROM.read(0);
  minuto = EEPROM.read(1);
  hora = EEPROM.read(2);
  //ALARMA
  aminuto = EEPROM.read(3);
  ahora = EEPROM.read(4);
  //Estado de la alarma
  aestado = EEPROM.read(5);
  //Estado Luces
  alight = EEPROM.read(10);
  //Contrasena almacenada en EEPROM
  /*
    EEPROM.write(6,1);
    EEPROM.write(7,2);
    EEPROM.write(8,3);
    EEPROM.write(9,6);
  */
  Timer1.initialize(10000000);
  Timer1.attachInterrupt(reloj);
  MsTimer2::set(1000,temporizador);
  Serial.print("Alarma hora: ");
  Serial.println(EEPROM.read(4));
  Serial.print("Alarma minuto: ");
  Serial.println(EEPROM.read(3));
  Serial.print("Contrasena Actual: ");
  Serial.print(EEPROM.read(6));
  Serial.print(EEPROM.read(7));
  Serial.print(EEPROM.read(8));
  Serial.println(EEPROM.read(9));

}

void loop() {
  customKey = customKeypad.getKey();  //almacena el dato ingresado por teclado
  menu();
  /////////////////////////////////Validar////////////////////////////////////////////
  if (opcion == 1) {
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

    if (contpass == 4) {
      if (verpass[0] == EEPROM.read(6) && verpass[1] == EEPROM.read(7) &&
          verpass[2] == EEPROM.read(8) && verpass[3] == EEPROM.read(9)) {
        //lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correcto        ");
        Serial.println("CORRECTO");
        delay(400);
        aestado = 1 - aestado;
        EEPROM.update(5, aestado);
        contpass = 0;
        presion = 5;
        opcion = 0;
        Serial.print("Estado Alarma: ");
        Serial.println(aestado);
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Incorrecto      ");
        Serial.println("INCORRECTO");
        contpass = 0;
        presion = 5;
      }
    }
  }

  if (opcion == 5) {
      lcd.setCursor(0,0);
      lcd.print("Enter OLD Pass");
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

    if (contpass == 4) {
      if (verpass[0] == EEPROM.read(6) && verpass[1] == EEPROM.read(7) &&
          verpass[2] == EEPROM.read(8) && verpass[3] == EEPROM.read(9)) {
        //lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correcto        ");
        Serial.println("CORRECTO");
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
        Serial.println("INCORRECTO");
        contpass = 0;
        presion = 5;
        passestado = 2;
      }
    }
  }

  if (passestado == 1) {
        lcd.setCursor(0,0);
        lcd.print("Enter NEW PASS");
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
    if (nkey == 9) {
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(400);
      lcd.print("PASS CHANGED");
      msg3=String(String(EEPROM.read(2))+":"+String(EEPROM.read(1)));
      nkey = 6;
      passestado = 0;
      presion=5;
      opcion = 0;
    }

  }

  //////////////////////////Sistema de Seguridad///////////////////////////////
  //Seleccion de sensores
  if (opcion == 2) {
    if (digitalRead(46) == LOW || digitalRead(45) == LOW || digitalRead(44) == LOW || digitalRead(43) == LOW) {
      Serial.println("Uno o mas sensores no esta activado");
      delay(200);
    } else {
      
      Serial.println("Sensores activado");
      delay(200);
    }
  }
  if (EEPROM.read(5)==1) {
    if (digitalRead(46) == LOW || digitalRead(45) == LOW || digitalRead(44) == LOW || digitalRead(43) == LOW) {
      //Serial.println("INTRUSO");
      digitalWrite(51, HIGH);

      msg2=String(String(EEPROM.read(2))+":"+String(EEPROM.read(1)));
    }
  } else {
    digitalWrite(51, LOW);

  }
  //////////////////////////Sistema de luces///////////////////////////////////

  //Cambio de alarma hora luces
  if (horario == 1) {
      lcd.setCursor(0,0);
      lcd.print("Enter NEW TIME");
    if (customKey == '0' || customKey == '1' || customKey == '2' || customKey == '3' || customKey == '4' || customKey == '5' ||
        customKey == '6' || customKey == '7' || customKey == '8' || customKey == '9') {
      customKey = customKey - 48;
      noche[ntime] = customKey; //almacena el dato ingresado en cada posicion
      ntime++; //aumenta contador
      presion++;
      lcd.setCursor(presion, 1);
      lcd.print('*');
      Serial.println(customKey);
    }

    if (ntime == 4) {
      int hora = (noche[0] * 10) + noche[1];
      int minuto = (noche[2] * 10) + noche[3];
      if (hora < 24 && minuto < 60) {
        EEPROM.update(3, minuto);
        EEPROM.update(4, hora);
        Serial.println("Horario Cambiado");

        msg4=String(String(EEPROM.read(4))+":"+String(EEPROM.read(3)));
        ntime = 0;
        horario = 0;
        opcion = 0;
        presion=5;
      } else {
        Serial.println("Ingrese una hora Valida");
        ntime = 0;
        presion=5;
      }
    }
  }

  if(EEPROM.read(10)==1){
  if (EEPROM.read(1) == EEPROM.read(3) && EEPROM.read(2) == EEPROM.read(4)) {
    MsTimer2::start();
    }
  if(tminuto==2){
   digitalWrite(50,HIGH); 
   digitalWrite(49,HIGH);
    }
  if(tminuto==3){ 
   digitalWrite(48,HIGH);
    }
  if(tminuto==5){
   digitalWrite(47,HIGH);
    }

  if(EEPROM.read(1)==0&&EEPROM.read(2)==0){
    
    MsTimer2::stop();
    tminuto=0;
    thora=0;
    digitalWrite(50,LOW);
    digitalWrite(49,LOW);
    digitalWrite(48,LOW);
    digitalWrite(47,LOW);
    }
  
        
  }else{
    
    MsTimer2::stop();
    tminuto=0;
    thora=0;
    digitalWrite(50,LOW);
    digitalWrite(49,LOW);
    digitalWrite(48,LOW);
    digitalWrite(47,LOW);
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
      if (hora < 24) {
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


void menu () {
  switch (customKey) {
    case 65:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Validate PASS");
      opcion = 1;
      Serial.println("Ingrese Contrasena");
      break;
    case 66:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Security System");
      lcd.setCursor(0, 1);
      lcd.print("ENTER PASS");
      opcion = 2;
      
      break;
    case 67:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Light System");
      on = 1 - on;
      if (on == 0) {
        light = 1;
        Serial.println("Luces Activadas");
        EEPROM.update(10,light);
        lcd.setCursor(6,1);
        lcd.print("ON");
        delay(400);
        opcion = 0;
      } else {
        light = 0;
        EEPROM.update(10,light);
        Serial.println("Luces Desactivadas");
        lcd.setCursor(6,1);
        lcd.print("OFF");
        delay(400);
        opcion=0;
      }
      
      break;
    case 68:
    opcion=4;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Event List");
      Serial.println("LISTA DE EVENTOS");
      String msg41;
      if (EEPROM.read(5) == 1) {
        msg1 = "Activado";
      } else {
        msg1 = "Desactivado";
      }

      if (EEPROM.read(10) == 1) {
        msg41 = "Activado";
      } else {
        msg41 = "Desactivado";
      }
      //Titulo
      Serial.print("EVENTO ");
      Serial.print("\t ");
      Serial.print("REGISTRO ");
      Serial.print("\t ");
      Serial.println("ESTADO ACTUAL");
      //evento1
      Serial.print("ALARMA ");
      Serial.print("\t ");
      Serial.print(msg2);
      Serial.print("\t ");
      Serial.println(msg1);
      //evento2
      Serial.print("PASSWORD ");
      Serial.print("\t ");
      Serial.print(msg3);
      Serial.print("\t ");
      Serial.println("Ultima Actualizacion");
      //evento2
      Serial.print("LUCES ");
      Serial.print("\t ");
      Serial.print(msg4);
      Serial.print("\t ");
      Serial.println(msg41);
      break;
  
  }

switch(customKey){
  case 70:
      //lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CHANGE PASS");
      delay(600);
      opcion = 5;
      break;
    case 71:
      //lcd.clear();
      Serial.println("Ingrese nueva Hora");
      delay(600);
      opcion=6;
      horario = 1;
      break;
  
  }
 
}


void temporizador () {
  if (tsegundo < 59) {
    tsegundo++;
  } else {
    tsegundo = 0;
    if (tminuto < 59) {
      tminuto++;
    } else {
      tminuto = 0;
      if (thora < 24) {
        thora++;
      } else {
        thora = 0;
      }
    }
  }

if (tsegundo < 10) { //comprueba el valor
      lcd.clear();  //limpia el lcd
      lcd.setCursor(9, 1); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(10, 1); //posiciona el cursor
      lcd.print('0'); //Imprime mensaje
      lcd.setCursor(11, 1); //posiciona el cursor
      lcd.print(tsegundo); //Imprime mensaje
    } else {
      lcd.clear();  //limpia el lcd
      lcd.setCursor(9,1); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(10, 1); //posiciona el cursor
      lcd.print(tsegundo); //Imprime mensaje

    }
    if (tminuto < 10) { //comprueba el valor
      lcd.setCursor(6, 1); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(7, 1); //posiciona el cursor
      lcd.print('0'); //Imprime mensaje
      lcd.setCursor(8, 1); //posiciona el cursor
      lcd.print(tminuto);  //Imprime mensaje
    } else {
      lcd.setCursor(6, 1); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(7, 1); //posiciona el cursor
      lcd.print(tminuto);  //Imprime mensaje
    }
    if (thora < 10) { //comprueba el valor
      lcd.setCursor(4, 1); //posiciona el cursor
      lcd.print('0'); //Imprime mensaje
      lcd.setCursor(5, 1); //posiciona el cursor
      lcd.print(thora);  //Imprime mensaje
    } else {
      lcd.setCursor(4, 1); //posiciona el cursor
      lcd.print(thora);  //Imprime mensaje
    }

  
}
