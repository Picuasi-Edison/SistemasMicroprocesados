//ALARMA CHEVYSTAR

int numero,on,opcion;
int pass[3];
int passre[3]={3,2,1};
void setup(){
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  }

void loop(){
  if(digitalRead(6)==HIGH){
    numero=1;
    delay(300);
    opcion++;
    }
  if(digitalRead(5)==HIGH){
    numero=2;
    delay(300);
    opcion++;
    }
  if(digitalRead(4)==HIGH){
    numero=3;
    delay(300);
    opcion++;
    }
    switch(opcion){
      
      case 1:
      pass[0]=numero;
        //Serial.println(pass[0]);
      break;
      case 2:
      pass[1]=numero;
        //Serial.println( pass[1]); 
      break;
      case 3:
      pass[2]=numero;
        //Serial.println( pass[2]);
      break;
      default:
      opcion=0;
      }

if(digitalRead(7)==HIGH){
  
  if(pass[0]==passre[0]&&pass[1]==passre[1]&&pass[2]==passre[2]){
    
    Serial.println("Contrasena Correcta");
    }else{
      
      opcion=0;
      Serial.println("Contrasena Incorrecta");
      }
  
  }   
  }
