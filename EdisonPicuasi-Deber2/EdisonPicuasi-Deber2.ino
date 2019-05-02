//Edison Picuasi
//Deber 2

int bt1=7;
int bt2=6;
int bt3=5;
int A=13;
int B=12;
int C=11;
int D=10;
int dec=9;
int uni=8;
int cont1=0,cont2=0,cont3=0;
int on=0;
int decenas=0;
int unidades=0;
void setup() {
Serial.begin(9600);
pinMode(bt1,INPUT);
pinMode(bt2,INPUT);
pinMode(bt3,INPUT);
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(dec,OUTPUT);
pinMode(uni,OUTPUT);
}

void loop() {
if(digitalRead(bt1)==LOW){
  //on=1-on;
  if(cont1<25){
    cont1++;
    Serial.println(cont1);
    }else{
      
      cont1=0;
      }
decenas=cont1/10;
unidades=cont1-decenas*10;
digitalWrite(dec,HIGH);
digitalWrite(uni,LOW);
numeros(decenas);
delay(50);
digitalWrite(dec,LOW);
digitalWrite(uni,HIGH);
numeros(unidades);
delay(50);

    
  }
if(digitalRead(bt2)==LOW){
 // on=1-on;
  if(cont2<25){
    cont2++;
    Serial.println(cont2);
    }else{
      cont2==0;
      }
decenas=cont2/10;
unidades=cont2-decenas*10;
digitalWrite(dec,HIGH);
digitalWrite(uni,LOW);
numeros(decenas);
delay(80);
digitalWrite(dec,LOW);
digitalWrite(uni,HIGH);
numeros(unidades);
delay(80);
  }

if(digitalRead(bt3)==LOW){
  cont3=cont1+cont2;  
  }
decenas=cont3/10;
unidades=cont3-decenas*10;
digitalWrite(dec,HIGH);
digitalWrite(uni,LOW);
numeros(decenas);
delay(80);
digitalWrite(dec,LOW);
digitalWrite(uni,HIGH);
numeros(unidades);
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
