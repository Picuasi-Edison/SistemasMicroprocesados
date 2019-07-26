/*
|2|4|0|1|8|0|
|1|2|1|2|
150A82
|1|5|0|A|8|2|

*Concatenar y Enviar dato
*String dato=String(String(analogRead(0))+"A"+String(analogRead(1))
*/

String dato;
String a0,a1;
int analog0,analog1;
void setup() {
Serial.begin(9600);
}

void loop() {

/*Concatenar Dato con analogos*/

/*dato=String(String(analogRead(0)/4)+"A"+String(analogRead(1)/4));
Serial.println(dato);
delay(1000);
*/

if(Serial.available()>0){
  dato=Serial.readString();
  //Serial.println(dato.indexOf("A"));
  a0=dato.substring(0,dato.indexOf("A"));
  //Serial.println(a0);
  a1=dato.substring(dato.indexOf("A")+1,dato.length());
  //Serial.println(a1);

  analog0=a0.toInt();
  analog1=a1.toInt();

  Serial.println(analog1*4);
  }




}
