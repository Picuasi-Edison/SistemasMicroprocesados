//Picuasi Edison
//Laboratorio 5

/*
Actividad

Realice una calculadora con las operaciones de suma, resta 
multiplicación y división de dos dígitos visualizado en una lcd.

*/

#include <Keypad.h> //incluimos libreria del teclado matricial
#include <LiquidCrystal.h>  //incluimos libreria del lcd

LiquidCrystal lcd(36,35,34,33,32,31); //declara y asigna los pines del lcd

const byte filas = 4; //4 filas
const byte columnas = 4; //4 columnas
String cifra;
char customKey;
unsigned int cont,pos,op,tam,imp,result,pres=0;
String valor,valor2;
int oper1,oper2;
float operd1,operd2,resd;
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
void setup() {
lcd.begin(16,2);
Serial.begin(9600);
lcd.setCursor(5,0);
delay(800);
lcd.print("CASIO");
lcd.setCursor(0,1);
lcd.print("Calc. de 3");
}

void loop() {
customKey = customKeypad.getKey();  //almacena el dato ingresado por teclado

  if(customKey=='0'||customKey=='1'||customKey=='2'||customKey=='3'||customKey=='4'||customKey=='5'||customKey=='6'||customKey=='7'||
     customKey=='8'||customKey=='9'||customKey=='+'||customKey=='-'||customKey=='*'||customKey=='/'){
    lcd.clear();
    lcd.setCursor(0,0);
    cifra=cifra+customKey;
    lcd.print(cifra);
    cont++;
    operaciones();
  }
if(customKey=='='||customKey=='C'){
  cont++;
  operaciones();
  }

tam=cifra.length();

if(op==1&&imp==1){
    result=oper1+oper2;
    lcd.setCursor(0,1);
    lcd.print(result);
    
  }
if(op==2&&imp==1){
      int result=oper1-oper2;
      lcd.setCursor(0,1);
      lcd.print(result);
  }
if(op==3&&imp==1){
    result=oper1*oper2;
    lcd.setCursor(0,1);
    lcd.print(result);
  }
if(op==4&&imp==1){
    resd=operd1/operd2;
    lcd.setCursor(0,1);
    lcd.print(resd);
    
  }

}

void operaciones(){
  switch(customKey){
    case '+':
    pos=cont;
    valor=cifra.substring(0,pos-1);
    oper1=valor.toInt();
    op=1;
    break;
    case '-':
    pos=cont;
    valor=cifra.substring(0,pos-1);
    oper1=valor.toInt();
    op=2;
    break;
    case '*':
    pos=cont;
    valor=cifra.substring(0,pos-1);
    oper1=valor.toInt();
    op=3;
    break;
    case '/':
    pos=cont;
    valor=cifra.substring(0,pos-1);
    operd1=valor.toFloat();
    op=4;
    break;
    case '=':
    valor2=cifra.substring(pos,tam);
    oper2=valor2.toInt();
    operd2=valor2.toFloat();
    cont=0;
    imp=1;
    break;
    case 'C':
    cont=0;
    op=0;
    valor="";
    valor2="";
    cifra="";
    imp=0;
    lcd.clear();
    break;
    }
  }
