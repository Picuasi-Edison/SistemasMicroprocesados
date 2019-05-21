//Edison Picuasi
//Deber3-Cedula CX


String nci; //varaiable String ingreso (validacion) por CX
int numero,par1,par2,par3,par4,impar1,impar2,impar3,impar4,impar5,valid;  //variable de incremento
int ntam=0; //variable tamano string
int suma=0,suma2=0; //variable de suma impares pares
void setup() {
Serial.begin(9600);//inicializa CX
Serial.println("Sistema de Verificacion de C.I.");  //mensaje CX
Serial.println("Ingrese C.I."); //mensaje CX
Serial.println("Ejemplo: 100100379-5"); //mensaje CX
}

void loop() {

if(Serial.available()>0){
  nci=Serial.readString();  //almacena el dato
  ntam=nci.length();  //determina el tamano del string y lo almacena
  
  char vector1[ntam]; //variable char con el tamano del string
  
  nci.toCharArray(vector1,ntam);  //combierte el String en char
//Serial.println(ntam);

//condicion de validacion

   if(ntam==11){
    Serial.println("");
    Serial.println("Numero de digitos correcto"); //mensaje CX
     String region=nci.substring(0,2);  //crea variable y extrae los datos de la cadena
     numero=region.toInt(); //cambia el tipo de dato
    //Serial.println(numero); //mensaje CX
    

/*------------Numero 1------------*/
      String num1=nci.substring(0,1); //crea nueva variable  y extrae datos
      impar1=(num1.toInt())*2;  //cambia el tipo de dato y multiplica 
      //Serial.println(impar1);
      if(impar1>9){ //comprueba si el numero es menor a 9
        impar1=impar1-9;  //si es mayor resta 9
        //Serial.println(impar1);
        }
/*------------Numero 3------------*/
      String num3=nci.substring(2,3); //crea nueva variable  y extrae datos
      impar2=(num3.toInt())*2;  //cambia el tipo de dato y multiplica
      //Serial.println(impar2);
      if(impar2>9){ //comprueba si el numero es menor a 9
        impar2=impar2-9;  //si es mayor resta 9
        //Serial.println(impar2);
        }
/*------------Numero 5------------*/
      String num5=nci.substring(4,5); //crea nueva variable  y extrae datos
      impar3=(num5.toInt())*2;  //cambia el tipo de dato y multiplica
      //Serial.println(impar3);
      if(impar3>9){ //comprueba si el numero es menor a 9
        impar3=impar3-9;  //si es mayor resta 9
        //Serial.println(impar3);
        }
/*------------Numero 7------------*/
      String num7=nci.substring(6,7); //crea nueva variable  y extrae datos
      impar4=(num7.toInt())*2;  //cambia el tipo de dato y multiplica
      //Serial.println(impar4);
      if(impar4>9){ //comprueba si el numero es menor a 9
        impar4=impar4-9;  //si es mayor resta 9
        //Serial.println(impar4);
        }
/*------------Numero 9------------*/
      String num9=nci.substring(8,9); //crea nueva variable  y extrae datos
      impar5=(num9.toInt())*2;  //cambia el tipo de dato y multiplica
      //Serial.println(impar5);
      if(impar5>9){ //comprueba si el numero es menor a 9
        impar5=impar5-9;  //si es mayor resta 9
        //Serial.println(impar5);
        }
/*------------Numero 2------------*/
      String num2=nci.substring(1,2); //crea nueva variable  y extrae datos
      par1=(num2.toInt());  //cambia tipo de dato
/*------------Numero 4------------*/
      String num4=nci.substring(3,4); //crea nueva variable  y extrae datos
      par2=(num4.toInt());  //cambia tipo de dato
/*------------Numero 6------------*/
      String num6=nci.substring(5,6); //crea nueva variable  y extrae datos
      par3=(num6.toInt());  //cambia tipo de dato
/*------------Numero 8------------*/
      String num8=nci.substring(7,8); //crea nueva variable  y extrae datos
      par4=(num8.toInt());  //cambia tipo de dato
/*------------SUMA------------*/
suma=impar1+impar2+impar3+impar4+impar5;  //suma de resultados impar
suma2=par1+par2+par3+par4;  //suma resultados de par
int total=suma+suma2; //suma total entre par e impar

int total2=total/10;  //crea variable del primer digito
total2=(total2+1)*10; //convierte al numero decimal consecutivo
total2=total2-total;  //resta entre el valor decimal consecutivo y la suma entre los numeros pares e impares
//Serial.println(total2);
String result=nci.substring(10,11); //crea variable y extrae los valores
valid=result.toInt(); //cambia tipo de dato
//Serial.println(valid);

//condicion validar ultimo digito
if(valid==total2){
  Serial.println("LA C.I. ES DE ECUADOR");

//Condicion para determinar la provincia

if(numero>=1&&numero<=24){  
      Serial.print("Provincia: ");
      switch(numero){
        
        case 1:
        Serial.println("Azuay");
        break;
        case 2:
        Serial.println("Bolivar");
        break;
        case 3:
        Serial.println("Canar");
        break;
        case 4:
        Serial.println("Carchi");
        break;
        case 5:
        Serial.println("Cotopaxi");
        break;
        case 6:
        Serial.println("Chimborazo");
        break;
        case 7:
        Serial.println("El Oro");
        break;
        case 8:
        Serial.println("Esmeraldas");
        break;
        case 9:
        Serial.println("Guayas");
        break;
        case 10:
        Serial.println("Imbabura");
        break;
        case 11:
        Serial.println("Loja");
        break;
        case 12:
        Serial.println("Los Rios");
        break;
        case 13:
        Serial.println("Manabi");
        break;
        case 14:
        Serial.println("Morona Santiago");
        break;
        case 15:
        Serial.println("Napo");
        break;
        case 16:
        Serial.println("Pastaza");
        break;
        case 17:
        Serial.println("Pichincha");
        break;
        case 18:
        Serial.println("Tungurahua");
        break;
        case 19:
        Serial.println("Zamora Chinchipe");
        break;
        case 20:
        Serial.println("Galapagos");
        break;
        case 21:
        Serial.println("Sucumbios");
        break;
        case 22:
        Serial.println("Orellana");
        break;
        case 23:
        Serial.println("Santo Domingo de los Tsachilas");
        break;
        case 24:
        Serial.println("Santa lena");
        break;
        default:
        Serial.println("No pertenece a ninguna Provincia");
        }
      }
  
  }else{
    Serial.println("LA C.I. ES INCORRECTA");
    }
    }else{
      Serial.println("");
      Serial.println("Ingrese Nuevamente");
      }
  }
}
  
