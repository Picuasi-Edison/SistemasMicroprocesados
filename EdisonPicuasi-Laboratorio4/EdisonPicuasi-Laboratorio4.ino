int pass[5]={1,2,3,4,6};  //contrasena
int i=0,j=0;
int ntam,estado,alarma; //variable de incremento
int a1,a2,a3,a4,a5; //variable conversion tipo de dato
int s1=13,s2=12,s3=11,s4=10,s5=9; //pines sensores
String CX;  //variable String ingreso de contrasena
void setup() {
Serial.begin(9600); //inicializa Comunicacion Serial
pinMode(s1,INPUT);  //configura pin del sensor
pinMode(s2,INPUT);  //configura pin del sensor
pinMode(s3,INPUT);  //configura pin del sensor
pinMode(s4,INPUT);  //configura pin del sensor
pinMode(s5,INPUT);  //configura pin del sensor
attachInterrupt(0,menu,LOW);  //interrupcion para el menu
attachInterrupt(1,seleccion,LOW); //interrupcion para seleccion de sensores
}

void loop() {
/*=============CAMBIAR CONTRASENA=============*/
if(i==1){
    if(Serial.available()>0){  //verifica si existe un dato en CX
    CX=Serial.readString(); //lee y almacena los datos en CX
    ntam=CX.length();  //determina el tamano de la CX
    //Serial.println(ntam);

    String n1=CX.substring(0,1);  //extrae del string un dato especifico
    String n2=CX.substring(1,2);  //extrae del string un dato especifico
    String n3=CX.substring(2,3);  //extrae del string un dato especifico
    String n4=CX.substring(3,4);  //extrae del string un dato especifico
    String n5=CX.substring(4,5);  //extrae del string un dato especifico
    a1=n1.toInt();  //combierte el String a int
    a2=n2.toInt();  //combierte el String a int
    a3=n3.toInt();  //combierte el String a int
    a4=n4.toInt();  //combierte el String a int
    a5=n5.toInt();  //combierte el String a int

    pass[0]=a1; //reemplaza el dato del vector contrasena
    pass[1]=a2; //reemplaza el dato del vector contrasena
    pass[2]=a3; //reemplaza el dato del vector contrasena
    pass[3]=a4; //reemplaza el dato del vector contrasena
    pass[4]=a5; //reemplaza el dato del vector contrasena
    }
  }
/*=============ACTIVAR ALARMA=============*/
if(i==3){  
  if(Serial.available()>0){
    CX=Serial.readString();
    ntam=CX.length();
    //Serial.println(ntam);

    String n1=CX.substring(0,1);  //extrae del string un dato especifico
    String n2=CX.substring(1,2);  //extrae del string un dato especifico
    String n3=CX.substring(2,3);  //extrae del string un dato especifico
    String n4=CX.substring(3,4);  //extrae del string un dato especifico
    String n5=CX.substring(4,5);  //extrae del string un dato especifico
    a1=n1.toInt();  //combierte el String a int
    a2=n2.toInt();  //combierte el String a int
    a3=n3.toInt();  //combierte el String a int
    a4=n4.toInt();  //combierte el String a int
    a5=n5.toInt();  //combierte el String a int
    if(a1==pass[0]&&a2==pass[1]&&a3==pass[2]&&a4==pass[3]&&a5==pass[4]){
      Serial.println("CORRECTO");
      estado=1;
      }else{
        Serial.println("INCORRECTO");
        }
   }
  }

 if(estado==1){ 
  for(int k=0;k<=j;k++){
    
    switch(k){
    case 1:
    if(digitalRead(s1)==HIGH){
        alarma=1;
    Serial.println("S1");}
    break;
    case 2:
    if(digitalRead(s2)==HIGH){
      alarma=1;
    Serial.println("S2");}
    break;
    case 3:
    if(digitalRead(s3)==HIGH){
        alarma=1;
    Serial.println("S3");}
    break;
    case 4:
    if(digitalRead(s4)==HIGH){
        alarma=1;
    Serial.println("S4");}
    break;
    case 5:
    if(digitalRead(s5)==HIGH){
        alarma=1;
    Serial.println("S5");}
    break;
      
      }
    
    }
  
  }

  if(alarma==1){
    
    Serial.println("SONANDO");
    }
  
/*=============DESACTIVAR ALARMA=============*/
if(i==4){
   if(Serial.available()>0){
    CX=Serial.readString();
    ntam=CX.length();
    Serial.println(ntam);

    String n1=CX.substring(0,1);
    String n2=CX.substring(1,2);
    String n3=CX.substring(2,3);
    String n4=CX.substring(3,4);
    String n5=CX.substring(4,5);
    a1=n1.toInt();
    a2=n2.toInt();
    a3=n3.toInt();
    a4=n4.toInt();
    a5=n5.toInt();
    if(a1==pass[0]&&a2==pass[1]&&a3==pass[2]&&a4==pass[3]&&a5==pass[4]){
      Serial.println("CORRECTO");
      estado=0;
      alarma=0;
      }else{
        Serial.println("INCORRECTO");
        }
   }
  }

}

void menu(){
i++;
switch(i)  {
  
  case 1:
  Serial.println("Cambio de Contrasena");
  break;
  case 2:
  Serial.println("Seleccion de sensores");
  break;
  case 3:
  Serial.println("Activar Alarma");
  break;
  case 4:
  Serial.println("Parar Alarma");
  break;
  default:
  i=0;
  
  }
}

void seleccion(){

 if(i==2){
 j++;
  switch(j){
    case 1:
    Serial.println("Sensor 1: Activado");
    break;
    case 2:
    Serial.println("Sensor 2: Activado");
    break;
    case 3:
    Serial.println("Sensor 3: Activado");
    break;
    case 4:
    Serial.println("Sensor 4: Activado");
    break;
    case 5:
    Serial.println("Sensor 5: Activado");
    break;
    default: 
    j=0;
  }
}
}
