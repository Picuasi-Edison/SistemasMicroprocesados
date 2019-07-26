#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);
String CX;
String a1;
int a2,k=0;
int j=0;
int posicion;
int sumar,restar;
int tam,dato;
char variable=',';
void setup() {
Serial.begin(9600);
lcd.begin(16,2);
attachInterrupt(0,suma,HIGH);
attachInterrupt(1,resta,HIGH);
Serial.println("INGRESE CARACTERES");
}

void loop() {
if(Serial.available()>0){
  
  CX=Serial.readString();
tam=CX.length()+1;
char cadena [tam];
CX.toCharArray(cadena,tam);

for(;j<=tam;j++){
 switch(cadena[j]){  
    case'0'...'1':
    break;
    case ',':
k++;
//Serial.println(k);   

 int nuevo[k];

 for(int p=0;p<k;p++){
  
  nuevo[p]=j;
Serial.print(p);
Serial.println(nuevo[p]);
  
  }

    break;


  }


  }

  }  
}

void suma(){
  Serial.println("Sumar");
  //lcd.clear();
  lcd.setCursor(0,0);
  
  //sumar=a1+a2;
  lcd.print(sumar);
  }

void resta(){
    Serial.println("Restar");
  //lcd.clear();
  lcd.setCursor(0,1);
  
  //restar=a1+a2;
  lcd.print(restar);
  
  
  }
