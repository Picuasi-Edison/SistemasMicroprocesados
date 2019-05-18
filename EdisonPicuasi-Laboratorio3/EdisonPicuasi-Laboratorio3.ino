//Edison Picuasi
//Contador de personas

String pass1, pass2,pass3, pass4, pass5;


String CX;
int tam;
int A=13;
int B=12;
int C=11;
int D=10;
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
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(D,OUTPUT);
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
    Serial.print("CORRECTO"); 
    on1++;
    if(on1==1){
    cont++;
    if(validar[0]=='A'){
      cont2++;
      }
      }
    if(on1==2){
      cont--;
      if(validar[0]=='A'){
      cont2--;
      }
      }
     //Serial.println(cont2); 
  }

/*------------Password 2------------*/
  if(CX.equals(pass2)){
    Serial.print("CORRECTO");
    on2++;
    if(on2==1){
    cont++;
    if(validar[0]=='A'){
      cont2++;
      }
      }
    if(on2==2){
      cont--;
      if(validar[0]=='A'){
      cont2--;
      }
      }
     //Serial.println(cont2);
  }
/*------------Password 3------------*/
  if(CX.equals(pass3)){
    Serial.print("CORRECTO");
    on3++;
    if(on3==1){
    cont++;
    if(validar[0]=='A'){
      cont2++;
      }
      }
    if(on3==2){
      cont--;
      if(validar[0]=='A'){
      cont2--;
      }
      }
     //Serial.println(cont2);
  }
/*------------Password 4------------*/
  if(CX.equals(pass4)){
    Serial.print("CORRECTO");
    on4++;
    if(on4==1){
    cont++;
    if(validar[0]=='F'){
      cont2=cont2+2;
      }
      }
    if(on4==2){
      cont--;
      if(validar[0]=='F'){
      cont2=cont2-2;
      }
      }
     //Serial.println(cont2);
  }
/*------------Password 5------------*/
  if(CX.equals(pass5)){
    Serial.print("CORRECTO");
    on5++;
    if(on5==1){
    cont++;
    if(validar[0]=='F'){
      cont2=cont2+2;
      }
      }
    if(on5==2){
      cont--;
      if(validar[0]=='F'){
      cont2=cont2-2;
      }
      }
     //Serial.println(cont2);
      }
delay(200);
      if(CX!=pass1||CX!=pass2||CX!=pass3||CX!=pass4||CX!=pass5){
    Serial.println("INCORRECTO");
    }else{
      
      Serial.println("CORRECTO");
      }
  }

  
 
}
