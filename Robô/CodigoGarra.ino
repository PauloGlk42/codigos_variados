#include <Servo.h>

#define pinVelMotorPrincipal 6
#define motorPrincipalCima 8
#define motorPrincipalBaixo 7
#define motorBaseHor 2
#define motorBaseAnt 4
#define pinVelMotorBase 5
#define readPin1 A0
#define readPin2 A1
#define readPin3 A2
#define readPin4 A3
#define pinSW 13

Servo principal;
Servo garra;
Servo garra180;

int velocidade;
int velocidadeRotacao;
int VRX;
int VRY;
int VRX2;
int VRY2;
bool statusSW;

void setup() {
  pinMode(pinVelMotorPrincipal, OUTPUT);
  pinMode(motorPrincipalCima, OUTPUT);
  pinMode(motorPrincipalBaixo, OUTPUT);
  pinMode(motorBaseHor, OUTPUT);
  pinMode(motorBaseAnt, OUTPUT);
  pinMode(pinVelMotorBase, OUTPUT);
  pinMode(readPin1, INPUT);
  pinMode(readPin2, INPUT);
  pinMode(readPin3, INPUT);
  pinMode(readPin4, INPUT);
  pinMode(pinSW, INPUT);

  digitalWrite(motorPrincipalCima, LOW);
  digitalWrite(motorPrincipalBaixo, LOW);
  digitalWrite(motorBaseHor, LOW);
  digitalWrite(motorBaseAnt, LOW);

  garra.attach(9);
  principal.attach(10);
  garra180.attach(11);
  garra.write(0);
  principal.write(0);
  garra180.write(0);

  Serial.begin(9600);
}

void loop() {
  VRX = analogRead(readPin1);
  VRY = analogRead(readPin2);
  statusSW = digitalRead(pinSW);
  VRX2 = analogRead(readPin3);
  VRY2 = analogRead(readPin4);

  // Mapeie o valor de VRX para o intervalo de 0 a 1023
  // para o intervalo de velocidade que você deseja (60 a 255)
  velocidade = map(VRX, 0, 1023, 180, 255);
  velocidadeRotacao = map(VRY, 0, 1023, 230, 255);

  // Controle da direção do motor principal
  if (VRY > 400 && VRX < 600) {
    digitalWrite(motorPrincipalCima, LOW);
    digitalWrite(motorPrincipalBaixo, LOW);
  } else if (VRY < 400) {
    analogWrite(pinVelMotorPrincipal, velocidade);
    digitalWrite(motorPrincipalCima, HIGH);
    digitalWrite(motorPrincipalBaixo, LOW);
  } else if (VRY > 600) {
    analogWrite(pinVelMotorPrincipal, velocidade);
    digitalWrite(motorPrincipalCima, LOW);
    digitalWrite(motorPrincipalBaixo, HIGH);
  }

  if (VRX > 400 && VRX < 600) {
    digitalWrite(motorBaseHor, LOW);
    digitalWrite(motorBaseAnt, LOW);
  } else if (VRX < 400) {
    analogWrite(pinVelMotorBase, velocidadeRotacao);
    digitalWrite(motorBaseHor, HIGH);
    digitalWrite(motorBaseAnt, LOW);
  } else if (VRX > 600) {
    analogWrite(pinVelMotorBase, velocidadeRotacao);
    digitalWrite(motorBaseHor, LOW);
    digitalWrite(motorBaseAnt, HIGH);
  }
  
  principal.write(map(VRX2, 0 , 1023, 0, 180));
  garra180.write(map(VRY2, 0 , 1023, 0, 180));
  
  if(!statusSW){
    garra.write(180);
  }else{
    garra.write(45);
  }
  
}

