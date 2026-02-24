//chekpoint 1
//une élastique

#include <Servo.h>
Servo monServo;
#define pinServo 6
#define enA 3
#define in1 4
#define in2 5 
#define in3 9
#define in4 10 
#define enB 11

#define R_S 7 //ir sensor Right
#define L_S 8 //ir sensor Left

#define TRIG_PIN 12
#define ECHO_PIN 2
int i = 1;

void setup(){ 
pinMode(R_S, INPUT);
pinMode(L_S, INPUT);

pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);

pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);   
pinMode(in4, OUTPUT);
pinMode(enB, OUTPUT);
i = 1;
analogWrite(enA, 38);
analogWrite(enB, 38);
monServo.attach(pinServo);
delay(100);
}

void loop(){  
long distance = getDistance();
  
if (distance <= 20) {
    stop();
  }
else {
    if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){forword();}   //if Right Sensor and Left Sensor are at White color then it will call forword function

    if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

    if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

    if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){
      if(i <= 18){
          ralentir();
          delay(400);
      }
      if(i > 18){
	back();
	back();
	back();
        stop();
        delay(500);
        lance();
        stop();
      }
      else {
           i = i + 1;
      }
    }
  }
}
void forword(){  //forword
  analogWrite(enB, 51);
  analogWrite(enA, 53);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  delay(10);
}

void ralentir(){  //forword
  analogWrite(enB, 40);
  analogWrite(enA, 40);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  delay(10);
}
void back(){ 
  analogWrite(enB, 51);
  analogWrite(enA, 53);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  delay(10);
}

void turnRight(){ //turnRight
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  delay(10);
}

void turnLeft(){ //turnLeft
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  delay(10);
}

void stop(){ //stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(10);
}

// Fonction pour obtenir la distance à partir du capteur à ultrasons
long getDistance() {
  // Envoyer une impulsion de 10 µs pour déclencher le capteur
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Mesurer la durée de l'écho
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculer la distance en cm
  long distance = (duration / 2) * 0.0344;  // Vitesse du son = 0.0344 cm/µs
  
  return distance;
}

void lance(){
for (int angle = 0; angle <= 90; angle++) {
    monServo.write(angle); 
    delay(1);  
  }

  delay(3000); 

for (int angle = 90; angle >= 0; angle--) {
    monServo.write(angle);  
    delay(10);  
  }
  delay(3000);
}