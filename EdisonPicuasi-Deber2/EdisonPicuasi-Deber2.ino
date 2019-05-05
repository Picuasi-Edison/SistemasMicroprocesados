//Edison Picuasi
//Deber 2
//Suma de numeros, valores de incremento accionadas por botones 1 y 2, boton 3 realiza la operacion de suma

int bt1=7;  //pin boton 1
int bt2=6;  //pin boton 2
int bt3=5;  //pin boton 3
int A=13; //pin salida display
int B=12; //pin salida display
int C=11; //pin salida display
int D=10; //pin salida display
int dec=9;  //pin salida display
int uni=8;  //pin salida display
int cont1=0,cont2=0,cont3=0;  //varaibles de conteo
int decenas=0;  //variable de almacenamiento
int unidades=0; //variable de almacenamiento

void setup() {
Serial.begin(9600);
pinMode(bt1,INPUT); //Configuracion de pin
pinMode(bt2,INPUT); //Configuracion de pin
pinMode(bt3,INPUT); //Configuracion de pin
pinMode(A,OUTPUT); //Configuracion de pin
pinMode(B,OUTPUT); //Configuracion de pin
pinMode(C,OUTPUT); //Configuracion de pin
pinMode(D,OUTPUT); //Configuracion de pin
pinMode(dec,OUTPUT); //Configuracion de pin
pinMode(uni,OUTPUT); //Configuracion de pin
}

void loop() {
/*------ PRIMER OPERADOR ------*/

if(digitalRead(bt1)==LOW){  //condicion de activacion
  if(cont1<25){ //condicion de limiente del contador
    cont1++;  //el contador aumenta
    Serial.print("Contador 1: "); //Imprime mensaje por CX
    Serial.println(cont1);  //Imprime el valor por CX
    }else{
      cont1=0;  //reinicia la variable
      }
      
decenas=cont1/10; //almacena el valor de conteo
unidades=cont1-decenas*10;  //almacena el valor de conteo

  }
  
/*------ SEGUNDO OPERADOR ------*/
  
if(digitalRead(bt2)==LOW){  //condicion de activacion
 
  if(cont2<25){ //condicion limite del contador
    cont2++;  //el contador aumenta
    Serial.print("Contador 2: "); //Imprime mensaje por CX
    Serial.println(cont2);  //Imprime el valor por CX
    }else{
      cont2==0; //reinicia la variable
      }
      
decenas=cont2/10; //almacena el valor de conteo
unidades=cont2-decenas*10;  //almacena el valor de conteo

 }

/*------ SUMA ------*/

if(digitalRead(bt3)==LOW){  //condicion de activacion
  cont3=cont1+cont2;  //Almacena el valor de la suma entre los operadores 1 y 2
  Serial.print("La suma es igual a: "); //Imprime mensaje por CX
  Serial.println(cont3);  //Imprime el valor por CX
  decenas=cont3/10; //almacena el valor de conteo
  unidades=cont3-decenas*10;  //almacena el valor de conteo
  }

digitalWrite(dec,HIGH); //activa pin de decenas
digitalWrite(uni,LOW);  //desactiva el pin de las unidades
numeros(decenas); //llamamos al metodo
delay(80);

digitalWrite(dec,LOW);  //desactiva pin de decenas
digitalWrite(uni,HIGH); //activa pin de unidades
numeros(unidades);  //llamamos al metodo
delay(80);

}

void numeros (int j){
  
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
