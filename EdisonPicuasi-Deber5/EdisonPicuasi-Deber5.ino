//EDISON PICUASI
//DEBER 5
//Manejo de Teclado Matricial
/*
Actividad
Consultar el funcionamiento del teclado matricial y validar 
una contraseña de 4 dígitos visualizado en una lcd.

*/

#include <Keypad.h> //incluimos libreria del teclado matricial
#include <LiquidCrystal.h>  //incluimos libreria del lcd

LiquidCrystal lcd(36,35,34,33,32,31); //declara y asigna los pines del lcd

const byte filas = 4; //4 filas
const byte columnas = 4; //4 columnas

char pass [4]={'1','2','3','4'};  //variable contrasena predfinida
char verpass[4];  //variable ingreso de contrasena

char customKey; //variable ingreso keypad

int contpass=0; //variable incremento para caracteres ingresados
int estado; //variable de reinicio array

//crear la variable y asignar los caracteres de ingreso
char teclado[filas][columnas] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'.','0','=','/'}
};
byte rowPins[filas] = {29, 28, 27, 26}; //asignamos los pines para las filas
byte colPins[columnas] = {25, 24, 23, 22}; //asignamos los pines para las comunas

Keypad customKeypad = Keypad( makeKeymap(teclado), rowPins, colPins, filas, columnas); 


void setup(){
  Serial.begin(9600); //inicializa CX Seraial
  lcd.begin(16,2);  //inicializa lcd

}
  
void loop(){
//msg inicio
if(estado==0){
  lcd.setCursor(0,0); //posiciona cursor
  lcd.print("Ingres. Contra."); //immprime msg en el lcd
  }
//reset datos del array
if(estado==1){
    for(int i=0;i<5;i++){ 
    verpass[i]=0; //reset de datos en cada posicion
    }
   contpass=0;  //reinicia contador
}
if(estado==2){
  lcd.clear();  //limpia el lcd
  lcd.setCursor(3,0); //posiciona el cursor
  lcd.print("BIENVENIDO");  //imprime msg en lcd
   contpass=0;  //reinicia contador
}

  customKey = customKeypad.getKey();  //almacena el dato ingresado por teclado

//comprueba si se ingreso un dato por teclado 
  if(customKey){
    verpass[contpass]=customKey; //almacena el dato ingresado en cada posicion
    lcd.setCursor(contpass,1);  //posiciona el cursor
    lcd.print(verpass[contpass]); //imprime el dato de cada posicion del char
    contpass++; //aumenta contador
    }
//comprueba si el numero de caracteres es igual a 4
  if(contpass==4){
    lcd.clear();  //limpia el lcd
    lcd.setCursor(0,1); //posiciona el cursor
    //verifica si los caracteres ingresado coinciden con los caracteres de la contrasena predefinida
    if(verpass[0]==pass[0]&&verpass[1]==pass[1]&&
       verpass[2]==pass[2]&&verpass[3]==pass[3]){
      lcd.print("Correcto");  //imprime msg en lcd
      estado=2; //cambia de estado
      }else{
      lcd.print("Incorrecto");  //imprime msg en lcd
      estado=1; //cambia de estado
        }
        delay(500); //permite visulizar el msg en lcd
        lcd.clear();  //limpia el lcd
        }
}
