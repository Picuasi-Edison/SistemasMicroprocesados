//Edison Picuasi
//Deber3-Cedula CX


String nci; //varaiable String ingreso (validacion) por CX
char cedula [11]; //variable de ingreso cedula
int i=0,j=0;  //variable de incremento
int ntam=0; //variable tamano string

void setup() {
Serial.begin(9600);
Serial.println("Sistema de Verificacion de C.I.");
Serial.println("Ingrese C.I.");

//Ingreso de Contrasena CX
for(;j<11;j){
  if(Serial.available()>0){
    cedula[j]=Serial.read();  //almacena el dato en el vector
    j++;  //variable de alamcenamiento aumenta
    Serial.println(cedula[j]);  //imprime por CX el dato en cada posicion
    }
  }
  
  Serial.println("Ingrese C.I. a validar");

//Serial.println(cedula[0]);
//Serial.println(cedula[10]);  
}

void loop() {

if(Serial.available()>0){
  nci=Serial.readString();  //almacena el dato
  ntam=nci.length()+1;  //determina el tamano del string y lo almacena
  
  char vector1[ntam]; //variable char con el tamano del string
  
  nci.toCharArray(vector1,ntam);  //combierte el String en char
//Serial.println(ntam);
//Serial.println(vector1[0]);
//Serial.println(vector1[10]); 

//condicion de validacion

  if(vector1[0]==cedula[0]&&vector1[1]==cedula[1]&&vector1[2]==cedula[2]&&vector1[3]==cedula[3]&&
     vector1[4]==cedula[4]&&vector1[5]==cedula[5]&&vector1[6]==cedula[6]&&vector1[7]==cedula[7]&&
     vector1[8]==cedula[8]&&vector1[9]==cedula[9]&&vector1[10]==cedula[10]){
      
      Serial.println("Correcto");
      }else{
        Serial.println("Incorrecto");
      }
  }
}
  
