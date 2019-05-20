//Edison Picuasi
//Deber3-Cedula CX


String nci; //varaiable String ingreso (validacion) por CX
int numero,par1,par2,par3,par4,impar1,impar2,impar3,impar4,impar5,valid;  //variable de incremento
int ntam=0; //variable tamano string
int suma=0,suma2=0;
void setup() {
Serial.begin(9600);
Serial.println("Sistema de Verificacion de C.I.");
Serial.println("Ingrese C.I.");
}

void loop() {

if(Serial.available()>0){
  nci=Serial.readString();  //almacena el dato
  ntam=nci.length();  //determina el tamano del string y lo almacena
  
  char vector1[ntam]; //variable char con el tamano del string
  
  nci.toCharArray(vector1,ntam);  //combierte el String en char
Serial.println(ntam);

//condicion de validacion

   if(ntam==11){
    Serial.println("Correcto");
     String region=nci.substring(0,2);
     numero=region.toInt();
    Serial.println(numero);
    if(numero>=1&&numero<=24){
      Serial.println("Ecuador");
      }

/*------------Numero 1------------*/
      String num1=nci.substring(0,1);
      int impar1=(num1.toInt())*2;
      //Serial.println(impar1);
      if(impar1>9){
        impar1=impar1-9;
        //Serial.println(impar1);
        }
/*------------Numero 3------------*/
      String num3=nci.substring(2,3);
      impar2=(num3.toInt())*2;
      //Serial.println(impar2);
      if(impar2>9){
        impar2=impar2-9;
        //Serial.println(impar2);
        }
/*------------Numero 5------------*/
      String num5=nci.substring(4,5);
      impar3=(num5.toInt())*2;
      //Serial.println(impar3);
      if(impar3>9){
        impar3=impar3-9;
        //Serial.println(impar3);
        }
/*------------Numero 7------------*/
      String num7=nci.substring(6,7);
      impar4=(num7.toInt())*2;
      //Serial.println(impar4);
      if(impar4>9){
        impar4=impar4-9;
        //Serial.println(impar4);
        }
/*------------Numero 9------------*/
      String num9=nci.substring(8,9);
      impar5=(num9.toInt())*2;
      //Serial.println(impar5);
      if(impar5>9){
        impar5=impar5-9;
        //Serial.println(impar5);
        }
/*------------Numero 2------------*/
      String num2=nci.substring(1,2);
      par1=(num2.toInt());
/*------------Numero 4------------*/
      String num4=nci.substring(3,4);
      par2=(num4.toInt());
/*------------Numero 6------------*/
      String num6=nci.substring(5,6);
      par3=(num6.toInt());
/*------------Numero 8------------*/
      String num8=nci.substring(7,8);
      par4=(num8.toInt());
/*------------SUMA------------*/
suma=impar1+impar2+impar3+impar4+impar5;
suma2=par1+par2+par3+par4;
int total=suma+suma2;

int total2=total/10;
total2=(total2+1)*10;
total2=total2-total;
//Serial.println(total2);
String result=nci.substring(10,11);
valid=result.toInt();
//Serial.println(valid);
if(valid==total2){
  Serial.println("LA C.I. ES DE ECUADOR");
  }else{
    Serial.println("LA C.I. ES DE OTRA REGION");
    }
    }else{
      Serial.println("Ingrese Nuevamente");
      }
  }
}
  
