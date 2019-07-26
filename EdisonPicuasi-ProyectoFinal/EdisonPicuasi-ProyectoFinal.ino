#include <LiquidCrystal.h>



LiquidCrystal lcd(13,12,11,10,9,8);

String CX;

int i=0,j=0,ntam,tam;
int k = 0;
int cad;

int m=0;
void setup() {
Serial.begin(9600);
lcd.begin(16,2);
attachInterrupt(0,menu,FALLING);
attachInterrupt(1,opciones,FALLING);
Serial.println("ORIENTACION LCD");
Serial.println("");
Serial.print("Velocidad CAD");
Serial.println(analogRead(0));
}

void loop() {
 
if(i==1){

  if(Serial.available()>0){
  CX=Serial.readString();
  tam=CX.length()+1;
  cad=analogRead(0);
  lcd.setCursor(0,0);
  lcd.print("Sistema ON ");
  lcd.setCursor(0,1);
  lcd.print(CX);
  }
}
delay(cad);
if(i==2){
    if(j==1){
    
    char msg[tam];
    CX.toCharArray(msg,tam);
    for(int i=16;i>=1;i--)
  {
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(i, 1);
 
    // Escribimos el texto
    lcd.print(CX);
 
    // Esperamos
    delay(cad);
  }



for(int k=1;k<tam;k++){
  String texto = CX.substring(k-1);
 
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(0, 1);
 
    // Escribimos el texto
    lcd.print(texto);
 
    // Esperamos
    delay(cad);
  
  }

    }
    
    


    if(j==2){
    char msg[tam];
    CX.toCharArray(msg,tam);
    /*
    lcd.setCursor(16,1);
    lcd.autoscroll();
    //lcd.scrollDisplayRight();
    for (int p=0; p < 25; p++) {
    
    lcd.print(msg[k]);
    
    }
     */ 


     for(int i=tam; i>0 ; i--)
  {
    String texto = CX.substring(i-1);
 
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(0, 1);
 
    // Escribimos el texto
    lcd.print(texto);
 
    // Esperamos
    delay(cad);
  }


  for(int i=1; i<=16;i++)
  {
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    lcd.setCursor(i, 1);
 
    // Escribimos el texto
    lcd.print(CX);
 
    // Esperamos
    delay(cad);
  }
    }
}

}





void menu(){
  delay(100);
  i++;
  switch(i){
    case 1:
    Serial.println("");
    Serial.println("INGRESE PALABRA");
    Serial.println("");
    lcd.setCursor(0,0);
    lcd.print("Sistema ON  ");
    break;
    case 2:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Selec. Orient.  ");
    break;
    case 3:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sistema OFF  ");
    Serial.println("Sistema OFF");
    m=1;
    j=0;
    break;
    case 4:
    i=0;
    m=0;
    break;
    }
  if(m==1){
    lcd.clear();
    }
  }

void opciones(){
  delay(100);
  j++;
  switch(j){
    case 1:
    lcd.clear();
    lcd.setCursor(16,0);
    lcd.print("Izquierda");
    Serial.println("");
    Serial.println("Izquierda");
    break;
    case 2:
    lcd.clear();
    lcd.setCursor(16,1);
    lcd.print("Derecha");
    Serial.println("");
    Serial.println("Derecha");
    break;
    case 3:
    lcd.clear();
    j=0;
    break;

    
    }
  
  }
