#include <LiquidCrystal.h>
#include <MsTimer2.h>
#include <TimerOne.h>
#include <EEPROM.h>
//Edison Picuasi
//PRUEBA II BIMESTRE

LiquidCrystal lcd(13,12,11,10,9,8); //declara y asigna los pines del lcd

int segundo, minuto, hora;
int csegundo,cminuto,chora;
int opcion=0,estado,j=0;
int llegada;
String msg;
void setup() {
  
Serial.begin(9600);
lcd.begin(16,2);
lcd.setCursor(6,0);
lcd.print("CASIO");
Serial.println("PRESIONE BOTON 1");
Serial.println("Para Ingresar al menu");
segundo=EEPROM.read(0);
minuto=EEPROM.read(1);
hora=EEPROM.read(2);
Timer1.initialize(1000000);
Timer1.attachInterrupt(reloj);
MsTimer2::set(1000,cronometro);
attachInterrupt(0,modos,FALLING);
attachInterrupt(1,cambio,FALLING);

////reinicio valores llegadas//
for(int i=0;i<20;i++){
  EEPROM.write(i,0);
 }
 
}

void loop() {

}

void reloj(){
if(segundo<59){
  segundo++;
  }else{
    segundo=0;
    if(minuto<59){
      minuto++;
      }else{
        minuto=0;
        if(hora<12){
          hora++;
          }else{
            hora=0;
            }
        }
    }
     
if(opcion==1){     
     
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
if(csegundo<59){
  csegundo++;
  }else{
    csegundo=0;
    if(cminuto<59){
      cminuto++;
      }else{
        cminuto=0;
        if(chora<12){
          chora++;
          }else{
            chora=0;
            }
        }
    }


if(opcion==2){
    if(csegundo<10){ //comprueba el valor
    lcd.clear();  //limpia el lcd
    lcd.setCursor(9,0); //posiciona el cursor
    lcd.print(':'); //Imprime mensaje
    lcd.setCursor(10,0);  //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(11,0);  //posiciona el cursor
    lcd.print(csegundo); //Imprime mensaje
    }else{
      lcd.clear();  //limpia el lcd
      lcd.setCursor(9,0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(10,0);  //posiciona el cursor
      lcd.print(csegundo); //Imprime mensaje
      
      }
   if(cminuto<10){ //comprueba el valor
    lcd.setCursor(6,0); //posiciona el cursor
    lcd.print(':'); //Imprime mensaje
    lcd.setCursor(7,0); //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(8,0); //posiciona el cursor
    lcd.print(cminuto);  //Imprime mensaje
    }else{
      lcd.setCursor(6,0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(7,0); //posiciona el cursor
      lcd.print(cminuto);  //Imprime mensaje
      }
    if(chora<10){  //comprueba el valor
    lcd.setCursor(4,0); //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(5,0); //posiciona el cursor
    lcd.print(chora);  //Imprime mensaje

    }else{
      lcd.setCursor(4,0); //posiciona el cursor
      lcd.print(chora);  //Imprime mensaje

      }
  }
  
  }


void modos(){
  opcion++;
  switch(opcion){
    case 0:
    opcion++;
    break;
    case 1:
    lcd.clear();
    Serial.println("RELOJ");
    break;
    case 2:
    lcd.clear();
    Serial.println("CRONOMETRO");
    if(csegundo<10){ //comprueba el valor
    lcd.clear();  //limpia el lcd
    lcd.setCursor(9,0); //posiciona el cursor
    lcd.print(':'); //Imprime mensaje
    lcd.setCursor(10,0);  //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(11,0);  //posiciona el cursor
    lcd.print(csegundo); //Imprime mensaje
    }else{
      lcd.clear();  //limpia el lcd
      lcd.setCursor(9,0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(10,0);  //posiciona el cursor
      lcd.print(csegundo); //Imprime mensaje
      
      }
   if(cminuto<10){ //comprueba el valor
    lcd.setCursor(6,0); //posiciona el cursor
    lcd.print(':'); //Imprime mensaje
    lcd.setCursor(7,0); //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(8,0); //posiciona el cursor
    lcd.print(cminuto);  //Imprime mensaje
    }else{
      lcd.setCursor(6,0); //posiciona el cursor
      lcd.print(':'); //Imprime mensaje
      lcd.setCursor(7,0); //posiciona el cursor
      lcd.print(cminuto);  //Imprime mensaje
      }
    if(chora<10){  //comprueba el valor
    lcd.setCursor(4,0); //posiciona el cursor
    lcd.print('0'); //Imprime mensaje
    lcd.setCursor(5,0); //posiciona el cursor
    lcd.print(chora);  //Imprime mensaje
    }else{
      lcd.setCursor(4,0); //posiciona el cursor
      lcd.print(chora);  //Imprime mensaje
      }
    break;
    case 3:
    Serial.println("INICIO");
    break;
    case 4:
    Serial.println("PARADA TOTAL");
    MsTimer2::stop();
    break;
    case 5:
    Serial.println("REINICIO CRONOMETRO");
    csegundo=0;
    cminuto=0;
    chora=0;
    break;
    case 6:
    Serial.println("VISUALIZACION DE DATOS");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(EEPROM.read(9));
    lcd.setCursor(3,0);
    lcd.print(EEPROM.read(10));
    lcd.setCursor(6,0);
    lcd.print(EEPROM.read(11));
    lcd.setCursor(9,0);
    lcd.print(EEPROM.read(12));
    lcd.setCursor(12,0);
    lcd.print(EEPROM.read(13));
    lcd.setCursor(15,0);
    lcd.print(EEPROM.read(14));
    lcd.setCursor(0,1);
    lcd.print(EEPROM.read(15));
    lcd.setCursor(3,1);
    lcd.print(EEPROM.read(16));
    lcd.setCursor(6,1);
    lcd.print(EEPROM.read(17));
    lcd.setCursor(9,1);
    lcd.print(EEPROM.read(18));
    lcd.setCursor(12,1);
    lcd.print(EEPROM.read(19));
    break;

    default:
    opcion=1;
    for(int i=0;i<20;i++){
  EEPROM.write(i,0);
 }
    }
  
  }

void cambio (){
  j=1-j;

  llegada++;
  if(j==0){
    MsTimer2::start();
    }
switch(llegada){
  
  case 3://1
  EEPROM.update(9,csegundo);
  break;
  case 4:
  EEPROM.update(10,csegundo);
  break;
  case 5:
  EEPROM.update(11,csegundo);
  break;
  case 6:
  EEPROM.update(12,csegundo);
  break;
  case 7:
  EEPROM.update(13,csegundo);
  break;
  case 8:
  EEPROM.update(14,csegundo);
  break;
  case 9:
  EEPROM.update(15,csegundo);
  break;
  case 10:
  EEPROM.update(16,csegundo);
  break;
  case 11:
  EEPROM.update(17,csegundo);
  break;
  case 12:
  EEPROM.update(18,csegundo);
  break;
  case 13:
  EEPROM.update(19,csegundo);
  break;
  }
  }
