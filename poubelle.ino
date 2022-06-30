/******************************************************************
* Auteurs:
*   Rognone Alex
* Fac des sciences Valrose - Nice
* UE Communication sans fil
******************************************************************/

#include <Servo.h>
#define trigPin 8
#define echoPin 7
// Definition des variables
int MesureMaxi = 50; // distance maxi a mesurer //
int MesureMini = 3; // distance mini a mesurer //
long duree;
long distance;
Servo myServo;
void setup()
{
  pinMode(trigPin, OUTPUT); // Broche Trigger en sortie //
  pinMode(echoPin, INPUT); // Broche Echo en entree //
  Serial.begin (9600);
  myServo.attach(A0); // Défini sur quelle pin est attaché le servo moteur
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duree = pulseIn(echoPin, HIGH);
  distance = duree*0.034/2;
  
  if (distance >= MesureMaxi || distance <= MesureMini) {
    Serial.println("Erreur");
  }
  else {
    servoOuvert();
  }
  delay(1000);
}

int calculDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duree = pulseIn(echoPin, HIGH); // Gets echoPin
  distance= duree*0.034/2;
  return distance;
}

int servoOuvert(){
  for(int i=0;i<=100;i++){  
    myServo.write(i);
    delay(50);
  }
}

//int servoFermer(){
//  for(int i=150;i>0;i--){  
//    myServo.write(i);
//    delay(200);
//  }
//}

// 0x26, 0x0B, 0x5C, 0xF0
// 0x12, 0xC0, 0x45, 0x2D, 0x1C, 0x24, 0xED, 0xD9, 0x74, 0x20, 0xED, 0xC0, 0xAA, 0x46, 0x5A, 0xEE
// 0x1B, 0xF4, 0x92, 0x02, 0x82, 0xA3, 0x60, 0xDB, 0x37, 0xC1, 0x05, 0x4B, 0x2F, 0x23, 0xCF, 0x8C
