//Edison Picuasi
//Laboratorio 2

int A=13;
int B=12;
int C=11;
int D=10;
int dec=9;
int uni=8;
int S1=7;
int S2=6;

int ledV=5;
int ledR=4;

int decenas=0;
int unidades=0;
int cont1=0;
int cont2=0;
int ver1;
int ver2;
int pos[3];
int i=0;

int valor=0;

void setup() {
Serial.begin(9600);
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(dec,OUTPUT);
pinMode(uni,OUTPUT);
pinMode(S1,INPUT);
pinMode(S2,INPUT);
pinMode(ledV,OUTPUT);
pinMode(ledR,OUTPUT);


}

void loop() {

/*----------Lectura Valor Sensores----------*/

delay(50);
cont1=digitalRead(S1);
cont2=digitalRead(S2);
/*----------SENSOR 1----------*/
  if(cont1==LOW){
  delay(100);
  Serial.print("Sensor A: ");
  Serial.println(cont1);
  ver1=1;
  i++;
  pos[i]=ver1;
  }
/*----------SENSOR 2----------*/

  if(cont2==LOW){
  delay(100);
  Serial.print("Sensor B: ");
  Serial.println(cont2);
  ver2=2;
  i++;
  pos[i]=ver2;
  }
/*----------Condicion de Reset Contador----------*/

if(cont1==HIGH&&cont2==HIGH&&i==2){
  i=0;
  pos[1]=0;
  pos[2]=0;
  }  
  Serial.print("POSICION ");
  Serial.println(i);
  Serial.println(pos[i]);
  
/*----------Condicion de Aumento----------*/

if (pos[1]==1&&pos[2]==2){

  Serial.println("Persona Entra");
  digitalWrite(ledV,HIGH);
  delay(80);
  digitalWrite(ledV,LOW);
  delay(80);
  valor++;
  decenas=valor/10; //almacena el valor de conteo
  unidades=(valor-decenas*10);  //almacena el valor de conteo
  }
/*----------Condicion de Reduccion----------*/

  if (pos[1]==2&&pos[2]==1){
 
  Serial.println("Persona Sale");
  digitalWrite(ledR,HIGH);
  delay(80);
  digitalWrite(ledR,LOW);
  delay(80);
  valor--;
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
