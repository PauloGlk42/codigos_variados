#define pinVelMotorEsquerdo 6
#define motorEsquerdoFrente 8
#define motorEsquerdoTras 7
#define motorDireitoFrente 2
#define motorDireitoTras 4
#define pinVelMotorDireito 5
#define readPin1 A0
#define readPin2 A1

int velocidade = 0;

int VRX;
int VRY;

void setup() {
  pinMode(pinVelMotorEsquerdo, OUTPUT);
  pinMode(motorEsquerdoFrente, OUTPUT);
  pinMode(motorEsquerdoTras, OUTPUT);
  pinMode(motorDireitoFrente, OUTPUT);
  pinMode(motorDireitoTras, OUTPUT);
  pinMode(pinVelMotorDireito, OUTPUT);

  digitalWrite(motorEsquerdoFrente, LOW);
  digitalWrite(motorEsquerdoTras, LOW);
  digitalWrite(motorDireitoFrente, LOW);
  digitalWrite(motorDireitoTras, LOW);
  
  analogWrite(pinVelMotorEsquerdo, velocidade);
  analogWrite(pinVelMotorDireito, velocidade);

  pinMode(readPin1, INPUT);
  pinMode(readPin2 ,INPUT);

}

void loop() {
  VRX = analogRead(readPin1);
  VRY = analogRead(readPin2);

  if(VRX > 400 && VRX < 600){
    if(VRY > 400 && VRY < 600){
      digitalWrite(motorEsquerdoFrente, LOW);
      digitalWrite(motorEsquerdoTras, LOW);
      digitalWrite(motorDireitoFrente, LOW);
      digitalWrite(motorDireitoTras, LOW);
    }else{
      if(VRY < 400){
        analogWrite(pinVelMotorEsquerdo, map(VRY, 0 , 400, 255, 60));
        analogWrite(pinVelMotorDireito, map(VRY, 0 , 400, 255, 60));
        digitalWrite(motorEsquerdoFrente, LOW);
        digitalWrite(motorEsquerdoTras, HIGH);
        digitalWrite(motorDireitoFrente, LOW);
        digitalWrite(motorDireitoTras, HIGH);
      }else{
        analogWrite(pinVelMotorEsquerdo, map(VRY, 600 , 1023, 60, 255));
        analogWrite(pinVelMotorDireito, map(VRY, 600 , 1023, 60, 255));
        digitalWrite(motorEsquerdoFrente, HIGH);
        digitalWrite(motorEsquerdoTras, LOW);
        digitalWrite(motorDireitoFrente, HIGH);
        digitalWrite(motorDireitoTras, LOW);  
      }
    }
  }else{
    if(VRX < 400){
      analogWrite(pinVelMotorEsquerdo, map(VRX, 0 , 400, 255, 60));
      analogWrite(pinVelMotorDireito, map(VRX, 0 , 400, 255, 60));
      digitalWrite(motorEsquerdoFrente, LOW);
      digitalWrite(motorEsquerdoTras, HIGH);
      digitalWrite(motorDireitoFrente, HIGH);
      digitalWrite(motorDireitoTras, LOW);
    }else{
      analogWrite(pinVelMotorEsquerdo, map(VRX, 600 , 1023 , 60, 255));
      analogWrite(pinVelMotorDireito, map(VRX, 600 , 1023 , 60, 255));
      digitalWrite(motorEsquerdoFrente, HIGH);
      digitalWrite(motorEsquerdoTras, LOW);
      digitalWrite(motorDireitoFrente, LOW);
      digitalWrite(motorDireitoTras, HIGH);
    }
  }
}
