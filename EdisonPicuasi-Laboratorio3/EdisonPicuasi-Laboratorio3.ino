//Edison Picuasi
//Contador de personas

String pass1, pass2,pass3, pass4, pass5;
int b1,b2,b3,b4,b5;

String CX;
int tam;
int A=13;
int B=12;
int C=11;
int D=10;
int dec=9;
int uni=8;
int unidades=0;
int decenas=0;
int cont,cont2;
int on1,on2,on3,on4,on5;
void setup() {
  pass1=String("AD12");
  pass2=String("AI68");
  pass3=String("AO89");
  pass4=String("FJ90");
  pass5=String("FE56");
  Serial.begin(9600);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(dec,OUTPUT);
  pinMode(uni,OUTPUT);
  Serial.println("Contador de personas mediante CX");
  Serial.println("Ingrese la Contrasena:");
  Serial.println("Ejemplo: AB01");
  Serial.println("NOTA:La contrasena solo puede ser usada 2 veces para el ingreso y salida");
}

void loop() {
if(Serial.available()>0){
  CX=Serial.readString();
  tam=CX.length()+1;
  char validar [tam];
  CX.toCharArray(validar,tam);
/*------------Password 1------------*/
  if(CX.equals(pass1)){
    on1++;
    if(on1==1){
      cont2++;
      b1=1;
      }
    if(on1==2&&b1==1){
      cont2--;
      on1=3;
      }
      if(on1==3){
        
        on1
        =0;
        
        }
     Serial.println(on1);
  }

  Serial.println(b1);
/*------------Password 2------------*/
  if(CX.equals(pass2)){
    on2++;
    if(on2==1){
    if(validar[0]=='A'){
      cont2++;
      }
      }
    if(on2==2){
      if(validar[0]=='A'){
      cont2--;
      }
      on2=3;
      }
      if(on2==3){
        
        on2=0;
        
        }
     //Serial.println(cont2);
  }
/*------------Password 3------------*/
  if(CX.equals(pass3)){
    on3++;
    if(on3==1){
    if(validar[0]=='A'){
      cont2++;
      }
      }
    if(on3==2){
      if(validar[0]=='A'){
      cont2--;
      }
      on3=3;
      }
      if(on3==3){
        
        on3=0;
        }
     //Serial.println(cont2);
  }
/*------------Password 4------------*/
  if(CX.equals(pass4)){
    on4++;
    if(on4==1){
    if(validar[0]=='F'){
      cont2=cont2+2;
      }
      }
    if(on4==2){
      if(validar[0]=='F'){
      cont2=cont2-2;
      }
      on4=3;
      }
      if(on4==3){
        
        on4=0;
        }
     //Serial.println(cont2);
  }
/*------------Password 5------------*/
  if(CX.equals(pass5)){
    on5++;
    if(on5==1){
    if(validar[0]=='F'){
      cont2=cont2+2;
      }
      }
    if(on5==2){
      if(validar[0]=='F'){
      cont2=cont2-2;
      }
      on5=3;
      }
      if(on5==3){
        
        on5=0;
        }
     //Serial.println(cont2);
      }
Serial.println(cont2);
if(CX.equals(pass1)||CX.equals(pass2)||CX.equals(pass3)||CX.equals(pass4)||CX.equals(pass5)){
  Serial.println("");  
  Serial.println("CORRECTO");
  
  }else{
    Serial.println("");
    Serial.println("INCORRECTO");
    }
     decenas=(cont2/10);
     unidades=cont2-decenas*10;
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
