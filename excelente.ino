#include <IRremote.h>

//#include <IRremoteInt.h>

int RECV_PIN = 2; //define input pin on Arduino

IRrecv irrecv(RECV_PIN);
decode_results results;
#define E1 10  // Enable Pin for motor 1
#define E2 11  // Enable Pin for motor 2
 
#define I1 8  // Control pin 1  motor 1
#define I2 9  // Control pin 2  motor 1
#define I3 12  // Control pin 1  motor 2
#define I4 13  // Control pin 2  motor 2

long distance; 
long time;
int  outU= 6;// trig salida
int inU = 7; // echo entrada

int estado;

void setup()
{

  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
 
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  
  pinMode(inU, INPUT);
  pinMode(outU, OUTPUT);
   irrecv.enableIRIn();
  attachInterrupt(0, control,RISING);
  Serial.begin(9600);
}

void retroceso(){
  analogWrite(E1, 255); 
  analogWrite(E2, 255); 
  
  delay(10);
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
  
}
void acelerar(){
  analogWrite(E1, 255); 
  analogWrite(E2, 255); 
  
  //delay(10);
 
  
  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
}

void izquierda(){
  analogWrite(E1, 255); 
  analogWrite(E2, 255); 
  
  delay(10);
  
  digitalWrite(I1,HIGH );
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW9);
}

void derecha(){
  analogWrite(E1, 255); 
  analogWrite(E2, 255);
  
  delay(10);
  
  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
}


void detener(){
  
  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);
 
}
void paro(){
  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);

}

void loop() {
  
    digitalWrite(outU,LOW);
    delayMicroseconds(10);
    digitalWrite(outU, HIGH);
    delayMicroseconds(10);
    time=pulseIn(inU, HIGH);
    distance= int(0.017*time); 
    if(distance <=30){
      if(estado==0){
      detener();
      estado=1;
      }

   
      //Serial.print("estado: ");
      //Serial.print(estado);
      //delay(3000);
      //izquierda();
      //delay(1000);
      //retroceso();
      
    }
    Serial.print("Distancia  ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(100);
  
}

void control(){
  if (irrecv.decode(&results)) {
    Serial.println(results.value );
    irrecv.resume(); // Receive the next value
  }
  if(results.value==3600){
     acelerar();
    estado=1;

  }
  if(results.value==2064){
    retroceso();
    estado=0;
    
  }
  if(results.value==2576){
    derecha();
    estado=0;
  }
  if(results.value==3088){
    izquierda();
    estado=0;
  }
  if(results.value==528){
    paro();
    estado=1;
  }
  

}
