/*
PUERTOS COMO ENTRADA DE DATOS DIGITALES
  setup
  pinMode(pin,INPUT);

  loop
  digitalRead(pin);
*/
int sw1=7;
int led1=8;
int led2=6;
int b1=5;
int on=0;
int cont=0;
int A=12;
int B=11;
int C=10;
int D=9;
int dec=4;
int uni=3;
int decenas=0;
int unidades=0;
void setup() {
Serial.begin(9600);
pinMode(sw1,INPUT);//switch
pinMode(b1,INPUT);//boton
pinMode(led1,OUTPUT);//LED1
pinMode(led2,OUTPUT);//LED2

pinMode(A,OUTPUT);//display
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(dec,OUTPUT);
pinMode(uni,OUTPUT);
}

void loop() {
  
/*----------------------------------------*/ 

  if(digitalRead(sw1)==HIGH){
    
    digitalWrite(led1,HIGH);
    delay(200);
    }else{
      digitalWrite(led1,LOW);
      delay(200);
      }

/*----------------------------------------*/      
  if(digitalRead(b1)==LOW){
    delay(600);
    on=1-on;
  
    if(cont<20){
      cont++;
      }else{
        cont=0;
        }
  }
        decenas=cont/10;
        unidades=cont-decenas*10;
        digitalWrite(dec,HIGH);
        digitalWrite(uni,LOW);
        numeros(decenas);
        delay(50);
        digitalWrite(dec,LOW);
        digitalWrite(uni,HIGH);
        numeros(unidades);
  
    if(on==1){
      digitalWrite(led2,HIGH);
      }else{
        digitalWrite(led2,LOW);
        }

}   

void numeros(int dato){
  
  switch(dato){
  
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
