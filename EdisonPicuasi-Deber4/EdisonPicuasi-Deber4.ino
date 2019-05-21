//Edison Picuasi
//Deber 4
//verificar
//  1. La Proviancia  
//  2. Registro de 4 digitos  
//  3. no contenga numeros en la parte de letras

String ver; //variable almacenamiento ingreso serial
String letras, numeros; //variable de separacion substring
int tam,taml,tamn;  //variable de almacenamiento extension de substring
int sec1=0,sec2=0,sec3=0; //variable de incremento

void setup() {
Serial.begin(9600); //inicializa Serial
Serial.println("Ingrese la placa vehicular:");  //Mensaje CX
Serial.println("Ejemplo: ABC-1234 "); //Mensaje CX
}

void loop() {
//condicion de datos en CX
if(Serial.available()>0){
  ver=Serial.readString();  //almacena los datos
  tam=ver.length(); //determina el tamano

  char vector[tam]; //vector con el tamano de la cadena anterior
  ver.toCharArray(vector,tam);  //cambia de tipo

/*--------NO TENGA NUMEROS--------*/

letras=ver.substring(0,ver.indexOf('-')); //extrae los datos
taml=letras.length()+1; //determina el tamno
  char vecl[taml]; //crea un vector con el tamano determinado anteriormente
  letras.toCharArray(vecl,taml);
  
//Comprueba cada celda si corresponde a una letra

for (int i=0;i<3;i++){
switch(vecl[i]){
  case 'A'...'Z': //determina que el vector sea solo letras
  sec1++; //incrementa 
  //Serial.println(sec1);
  break;
  }
  
}//sec1=0;
  
/*--------REGISTRO 4 DIGITOS--------*/

numeros=ver.substring(ver.indexOf('-')+1,ver.length()); //extrae datos
tamn=numeros.length()+1;  //determina el tamano
char vecn[tamn];  //crea un nuevo vector
  numeros.toCharArray(vecn,tamn); //cambia de tipo
for(int j=0;j<4;j++){
  
  switch(vecn[j]){  
  case '0'...'9': //determina que los caracteres sean solo numeros
  sec2++;  //variable aumenta
  //Serial.println(sec2);
  break;
  }
  sec3=sec1+sec2;  //almacena la sumatoria
  //Serial.println(sec3);
  if(sec3==7){  //condicion de ingreso
    Serial.println(""); //mensaje CX
    Serial.println("Ingreso Correcto"); //mensaje CX

/*--------PROVINCIAS--------*/
switch (vector[0]){
  
    case 'A':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Azuay");
    break;
    case 'B':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Bolivar");
    break;
    case 'C':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Carchi");
    break;
    case 'E':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Esmeraldas");
    break;
    case 'G':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Guayas");
    break;
    case 'H':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Chimborazo");
    break;
    case 'I':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Imbabura");
    break;
    case 'J':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Santo Domingo de los Tsachilas");
    break;
    case 'K':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Sucumbios");
    break;
    case 'L':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Loja");
    break;
    case 'M':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Manabi");
    break;
    case 'N':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Napo");
    break;
    case 'O':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("El Oro");
    break;
    case 'P':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Pichincha");
    break;
    case 'Q':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Orellana");
    break;
    case 'R':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Los Rios");
    break;
    case 'S':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Pastaza");
    break;
    case 'T':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Tungurahua");
    break;
    case 'U':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Cañar");
    break;
    case 'V':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Morona Santiago");
    break;
    case 'W':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Galapagos");
    break;
    case 'X':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Cotopaxi");
    break;
    case 'Y':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Azuay");
    break;
    case 'Z':
    Serial.println("");
    Serial.println("La Provincia es: ");
    Serial.println("Zamora Chinchipe");
    break;

    }


switch (vector[1]){
  
    case 'A':
    Serial.println("");
    Serial.println("Tipo de Vehiculo: ");
    Serial.println("Comercial");
    break;

     case 'U':
    Serial.println("");
    Serial.println("Tipo de Vehiculo: ");
    Serial.println("Comercial");
    break;
     case 'Z':
    Serial.println("");
    Serial.println("Tipo de Vehiculo: ");
    Serial.println("Comercial");
    break;
     case 'E':
    Serial.println("");
    Serial.println("Tipo de Vehiculo: ");
    Serial.println("Gubernamental");
    break;
       case 'X':
    Serial.println("");
    Serial.println("Tipo de Vehiculo: ");
    Serial.println("Uso Oficial");
    break;
     case 'M':
    Serial.println("");
    Serial.println("Tipo de Vehiculo: ");
    Serial.println("GAD");
    break;
    default:
     Serial.println("");
    Serial.println("Tipo de Vehiculo: ");
    Serial.println("Privado");
    
}   
    }
  
  }

sec1=0;
sec2=0;

}

}
