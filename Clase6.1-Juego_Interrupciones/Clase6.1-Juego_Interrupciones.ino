/*
Interrupcion 0: Permite seleccioanr juego, activa (Interrupcion), activar juego y parar juego
Interrupcion 1: 
*/

int ledG=13;
int ledR=12;
int on=0;
int selec_juego=0;
int num;
int j=0;
int i;
void setup() {
pinMode(ledG,OUTPUT);
pinMode(ledR,OUTPUT);
Serial.begin(9600);
attachInterrupt(0,Menu,LOW);
attachInterrupt(1,opcion,LOW);
}

void loop() {

}

void Menu (){
  
  switch(on){
    
    case 0:
    on++;
    Serial.println("Seleccionar Juego");
    break;
    case 1:
    on++;
    Serial.println("Seleccione el numero de veces");
    break;
    case 2:
    on++;
    Serial.println("Empieza Juego");
    break;
    case 3:
    on=0;
    Serial.println("Finalizar Sistema");
    break;
    }
  }

void opcion (){
if(on==1){
  if(selec_juego<2){
    
    selec_juego++;
    }else{
      
      selec_juego=1;
      
      }
  Serial.print("JUEGO: ");
  Serial.println(selec_juego);
  
  }
  
if(on==2){
  if(num<10){
    
    num++;
    }else{
      num=0;
      }
  
    Serial.print("Numero: ");
  Serial.println(num);
  
  }
  if(on==3){
    
    if(selec_juego==1){
      
      for(;i<num;i++){
        
        digitalWrite(ledR,HIGH);
        digitalWrite(ledG,HIGH);
        delay(200); 
        digitalWrite(ledR,LOW);
        digitalWrite(ledG,LOW);
        delay(200);
        }
      
      }else{
        
        for(; j<num; j++){
          
                  
        digitalWrite(ledR,HIGH);
        digitalWrite(ledG,LOW);
        delay(200); 
        digitalWrite(ledR,LOW);
        digitalWrite(ledG,HIGH);
        delay(200);  
          }
        
        }
    
    
    }  
  
  }
