#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

String palabra,palabra2;
int i,j;
float dato,cambio,nuevo,dolar,conversion;

void setup() {
Serial.begin(9600);
lcd.begin(16,2);
attachInterrupt(0,funcion,FALLING);
attachInterrupt(1,monedas,FALLING);
}

void loop() {
dato=analogRead(0);

if(i>0&&i<6){
  lcd.setCursor(0,0);
  lcd.print(palabra); 
  conversion=dato*dolar;
  lcd.setCursor(9,0);
  lcd.print((float)dato); //el int combierte a entero el float

  }

if(j>0&&j<6){
  lcd.setCursor(0,1);
  lcd.print(palabra2);
  nuevo=conversion*cambio;
  lcd.setCursor(9,1);
  lcd.print((float)nuevo);
  }  
}

void monedas(){
  i++;
    Serial.print("Moneda 1:");
     Serial.println(i);
  switch (i){
    case 1:
    Serial.println("EURO");
    dolar=1.123;//euro a dolar
    palabra="EURO    ";
    break;
    case 2:
    Serial.println("DOLAR");
    dolar=1;//dolar a dolar
    palabra="DOLAR   ";
    break;
    case 3:
    Serial.println("PESO COLOMBIANO");
    
    dolar=0.000296;//peso a dolar
    palabra="PES. COL";
    break;
    case 4:
    Serial.println("SOL PERUANO");
       dolar=0.299;
    palabra="SOL PER ";
    break;
    case 5:
    Serial.println("PESO ARGENTINO");
        dolar=0.0222;
    palabra="PES. ARG";
    break;
    default:
    i=0;
    }
  
  }

void funcion(){
  j++;

  Serial.print("Moneda 2:");
  Serial.println(j);
  switch (j){
    case 1:
    Serial.println("EURO");
    cambio=0.89;//dolar a euro
    palabra2="EURO    ";
    break;
    case 2:
    Serial.println("DOLAR");
    cambio=1;//dolar a dolar
    palabra2="DOLAR   ";
    break;
    case 3:
    Serial.println("PESO COLOMBIANO");
    cambio=3371.90;
    palabra2="PES. COL";
    
    break;
    case 4:
    Serial.println("SOL PERUANO");
    cambio=3.34;
    palabra2="SOL PER ";
    break;
    case 5:
    Serial.println("PESO ARGENTINO");
    cambio= 44.99;
    palabra2="PES. ARG";
    break;
    default:
    j=0;
    }
  }
