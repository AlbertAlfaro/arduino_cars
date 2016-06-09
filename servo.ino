#include <Servo.h>
Servo myservo; 

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
        pinMode(13,OUTPUT);
        pinMode(12,OUTPUT);
        pinMode(11,OUTPUT);
	myservo.attach(9); 
	myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
	int valor=myservo.read();
        Serial.println(valor);
        for(valor=0;valor<=180;valor++){
          if(valor==45){
            
            myservo.write(45);
            digitalWrite(11,LOW);
            digitalWrite(13,HIGH);
	    delay(2000);
            Serial.println(45);
            
            
          
          }
          
           if(valor==90){
            
            myservo.write(90);
            digitalWrite(13,LOW);
            digitalWrite(12,HIGH);
	    delay(2000);
            Serial.println(90);
            
          
          }
          if(valor==180){
            
            myservo.write(180);
            digitalWrite(12 ,LOW);
            digitalWrite(11,HIGH);
	    delay(2000);
            Serial.println(180);
          
          }
        
        
        }

}
