//Edison Picuasi
//Deber 1 - Juego de LEDS

int leds [8]={13,12,11,10,9,8,7,6}; //pines de leds
int i=0; //variable de incremento
int j=0;  //variable de incremento

void setup() {

//CONFIGURACION DE LEDS
for(;i<8;i++){
  pinMode(leds[i],OUTPUT);  //inicializa pines de leds como salida
  }
}

void loop() {
/*-------------- JUEGO 1 --------------*/
//LEDS PARES

for(i=1;i<8;i=i+2){
  
  digitalWrite(leds[i],HIGH); //se encienden los leds pares
  delay(200); //
  
  }
i=0;  //se reinicia la variable
delay(600); 

for(i=1;i<8;i=i+2){
  
  digitalWrite(leds[i],LOW);  //se apagan los leds
  delay(200);
  }
i=0;  //se reinicia la variable
delay(600);

/*-------------- JUEGO 2 --------------*/
//LEDS IMPARES

for(i=0;i<8;i=i+2){
  
  digitalWrite(leds[i],HIGH); //se encienden los leds impares
  delay(200);
  
  }
i=0;  //se reinicia la variable
delay(600);

for(i=0;i<8;i=i+2){
  
  digitalWrite(leds[i],LOW);  //se apagan los leds
  }
i=0;  //se reinicia la variable
delay(600);
/*-------------- JUEGO 3 --------------*/
//TODOS LOS LEDS ENCENDIDOS

for(;i<8;i++){
  
 digitalWrite(leds[i],HIGH);  //se encienden los leds
 delay(200); 
  
  }
i=0;  //se reinicia la variable
delay(600);

for(;i<8;i++){
  
 digitalWrite(leds[i],LOW); //se apagan los leds
 delay(200); 
  
  }
i=0;  //se reinicia la variable
delay(600);
/*-------------- JUEGO 4 --------------*/
//LEDS ALEATORIOS
for(;i<8;i++){
  
  digitalWrite(leds[random(8)],HIGH);  //se encienden leds aleatorios
  delay(200);
  
  }
i=0;  //se reinicia la variable
delay(600); 

for(;i<8;i++){
  
 digitalWrite(leds[i],LOW); //se apagan los leds
 delay(200); 
  
  }
i=0;  //se reinicia la variable
delay(600);
/*-------------- JUEGO 5 --------------*/
// LEDS BINARIO

  for(;i<256;i++)
  {
     for(j=0;j<8;j++)
     {
       if(((i>>j)&1)==1)
           digitalWrite(leds[j],HIGH);  //se encienden los leds
       else digitalWrite(leds[j],LOW);  //se apagan los leds
     }
     delay(60);
  }
i=0;  //se reinicia la variable
j=0;  //se reinicia la variable
delay(200);

  for(;i<8;i++){
  
 digitalWrite(leds[i],LOW); //se apagan todos los leds
 delay(100); 
  
  }
i=0;  //se reinicia la variable
delay(600);
}
