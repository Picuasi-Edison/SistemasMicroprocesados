int pass[5]={1,2,3,4,6};  //contrasena
int i=0,j=0;
int ntam,estado,alarma; //variable de incremento
int a1,a2,a3,a4,a5; //variable conversion tipo de dato
int s1=12,s2=11,s3=10,s4=9,s5=8; //pines sensores
String CX;  //variable String ingreso de contrasena

int spk=13;                                           // altavoz a GND y pin 13
int c[5]={131,262,523,1046,2093}; // frecuencias 4 octavas de Do
int cs[5]={139,277,554,1108,2217};  // Do#
int d[5]={147,294,587,1175,2349}; // Re
int ds[5]={156,311,622,1244,2489};  // Re#
int e[5]={165,330,659,1319,2637}; // Mi
int f[5]={175,349,698,1397,2794}; // Fa
int fs[5]={185,370,740,1480,2960};  // Fa#
int g[5]={196,392,784,1568,3136}; // Sol
int gs[5]={208,415,831,1661,3322};  // Sol#
int a[5]={220,440,880,1760,3520}; // La
int as[5]={233,466,932,1866,3729};  // La#
int b[5]={247,494,988,1976,3951}; // Si




void setup() {
Serial.begin(9600); //inicializa Comunicacion Serial
pinMode(spk,OUTPUT);  //configura pin del speaker
pinMode(s1,INPUT);  //configura pin del sensor
pinMode(s2,INPUT);  //configura pin del sensor
pinMode(s3,INPUT);  //configura pin del sensor
pinMode(s4,INPUT);  //configura pin del sensor
pinMode(s5,INPUT);  //configura pin del sensor
attachInterrupt(0,menu,FALLING);  //interrupcion para el menu
attachInterrupt(1,seleccion,FALLING); //interrupcion para seleccion de sensores
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

    Serial.println("Contrasena Modificada");
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
    tono();
    //Serial.println("SONANDO");
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
      Serial.println("Alarma Desactivada");
      estado=0;
      alarma=0;
      }else{
        Serial.println("INCORRECTO");
        }
   }
  }

}

void menu(){
  delay(200);
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
delay(200);
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


void tono (){
  /*                  HARRY POTTER                    */
/**************************************/
nota(b[2], 500);          
nota(e[3],1000); 
nota(g[3], 250);
nota(fs[3],250);
nota(e[3],1000);
nota(b[3],500);
nota(a[3],1250);
nota(fs[3],1000);    
nota(b[2], 500);
nota(e[3],1000);
nota(g[3],250);  
nota(fs[3],250);
nota(d[3],1000);
nota(e[3],500 );
nota(b[2],1000 );    
noTone(spk); 
delay(1000);   
nota(b[2], 500);
nota(e[3],1000);
nota(g[3], 250);
nota(fs[3],250);
nota(e[3],1000);
nota(b[3],500);
nota(d[4],1000);
nota(cs[4],500);
nota(c[4],1000);
nota(a[3],500);
nota(c[4],1000);
nota(b[3],250);
nota(as[3],250);
nota(b[2],1000);
nota(g[3],500);
nota(e[3],1000);
noTone(spk); 
delay(2000);      
  }
  void nota(int frec, int t)
{
    tone(spk,frec);      // suena la nota frec recibida
    delay(t);                // para despues de un tiempo t
}
