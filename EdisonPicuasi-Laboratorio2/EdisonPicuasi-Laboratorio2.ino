//Edison Picuasi
//Laboratorio 2

int A=13; //Pin salida display
int B=12; //Pin salida display
int C=11; //Pin salida display
int D=10; //Pin salida display
int dec=9;  //Pin de control display
int uni=8;  //Pin de control display
int S1=7; //Pin entrada sensor 1
int S2=6; //Pin entrada sensor 2

int ledV=5; //pin salida led
int ledR=4; //pin salida led

int decenas=0;  //variable de almacenaje
int unidades=0; //variable de almacenaje
int cont1=0;  //variable almacenaje valor sensor
int cont2=0;  //variable almacenaje valor sensor
int ver1; //variable almacenaje
int ver2; //variable almacenaje
int pos[3]; //variable almacenaje
int i=0; //variable conteo

int valor=0;  //variable incremento

void setup() {
Serial.begin(9600);
pinMode(A,OUTPUT);  //configuracion pin salida
pinMode(B,OUTPUT);  //configuracion pin salida
pinMode(C,OUTPUT);  //configuracion pin salida
pinMode(D,OUTPUT);  //configuracion pin salida
pinMode(dec,OUTPUT);  //configuracion pin salida
pinMode(uni,OUTPUT);  //configuracion pin salida
pinMode(S1,INPUT);  //configuracion pin entrada
pinMode(S2,INPUT);  //configuracion pin entrada
pinMode(ledV,OUTPUT); //configuracion salida
pinMode(ledR,OUTPUT); //configuracion salida


}

void loop() {

/*----------Lectura Valor Sensores----------*/

delay(50);
cont1=digitalRead(S1);  //variable almacenaje del sensor
cont2=digitalRead(S2);  //variable almacenaje del sensor
/*----------SENSOR 1----------*/
  if(cont1==LOW){
  //delay(100);
  Serial.print("Sensor A: ");
  Serial.println(cont1);
  ver1=1; //almacena valor
  i++;  //incrementa posicion
  pos[i]=ver1;  //almacena valor en posicion i
  }
/*----------SENSOR 2----------*/

  if(cont2==LOW){
  //delay(100);
  Serial.print("Sensor B: ");
  Serial.println(cont2);
  ver2=2; //almacena valor
  i++;  //incrementa posicion
  pos[i]=ver2;  //almacena valor en posicion i
  }
/*----------Condicion de Reset Contador----------*/

if(cont1==HIGH&&cont2==HIGH&&i==2){
  i=0;  //reinicia variable
  pos[1]=0; //reinicia valor en la posisicon 1
  pos[2]=0; //reinicia valor en la posisicon 1
  }  
  Serial.print("POSICION ");
  Serial.println(i);
  Serial.println(pos[i]);
  
/*----------Condicion de Aumento----------*/

if (pos[1]==1&&pos[2]==2){

  Serial.println("Persona Entra");
  digitalWrite(ledV,HIGH); //variable ledV enciende
  delay(80);
  digitalWrite(ledV,LOW); //variable ledV apaga
  delay(80);
  valor++;  //incrementa variable
  decenas=valor/10; //almacena el valor de conteo
  unidades=(valor-decenas*10);  //almacena el valor de conteo
  }
/*----------Condicion de Reduccion----------*/

  if (pos[1]==2&&pos[2]==1){
 
  Serial.println("Persona Sale");
  digitalWrite(ledR,HIGH);  //variable ledR enciende
  delay(80);
  digitalWrite(ledR,LOW); //varible ledR apaga
  delay(80);
  valor--;  //disminuye variable
  decenas=valor/10; //almacena el valor de conteo
  unidades=(valor-decenas*10);  //almacena el valor de conteo
  }
/*----------Visualizacion en Displays----------*/

digitalWrite(dec,HIGH); //activa pin de decenas
digitalWrite(uni,LOW);  //desactiva el pin de las unidades
numeros(decenas); //llamamos al metodo
delay(80);

digitalWrite(dec,LOW);  //desactiva pin de decenas
digitalWrite(uni,HIGH); //activa pin de unidades
numeros(unidades);  //llamamos al metodo
delay(80);


}

void numeros(int j){
  switch(j){
    case 0:
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;
    case 1:
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;
    case 2:
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;
    case 3:
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;
    case 4:
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
    case 5:
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
    case 6:
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
    case 7:
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
    case 8:
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,HIGH);
    break;
    case 9:
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,HIGH);
    break;
    }
}
