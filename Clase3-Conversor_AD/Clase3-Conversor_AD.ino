/*Conversor Analogo Digital
6 conversores de 10 bits, 5/1023=0.0048
*/
int A=7;
int B=6;
int C=5;
int D=4;
int cad=0;
void setup() {
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
//pin analogo no necesita configuracion
}

void loop() {
cad=(analogRead(A0)*3)/1023;

numeros(cad);
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
