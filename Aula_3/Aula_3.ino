//Inclui todas as bibliotecas necessárias para realização do programa
#include <Ultrasonic.h>
#include <Servo.h>

// Cria váriaveis com as portas de cada componente
#define pinoServo 7
#define Trig 8
#define Echo 9
#define MotorB1 10
#define MotorB2 11
#define MotorA1 13
#define MotorA2 12

// Cria váriaveis para distâncias
int distanciaD;
int distanciaE;

float distanciaObstaculo = 35;

Ultrasonic ultrasonico(Trig, Echo);

Servo servo;

void setup() {
  // Inicia a comunicação serial em 9600 bits
  Serial.begin(9600);
  
  servo.attach(pinoServo);
  // Inicializa as portas como entrada ou saída
  //pinos da ponte H
  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);
  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);
  
  servo.write(90);
  //Radar();
}

void loop() {

  Serial.println(ultrasonico.Ranging(CM));
  
  if (ultrasonico.Ranging(CM) <= distanciaObstaculo) {
    Andar(5);
      int statuss = Radar();
      delay(500);
      if (statuss == 1) {
        Andar(2);
        delay(600);
        Andar(4);
        delay(400);
        Andar(5);
      }
      if (statuss == 2) {
        Andar(2);
        delay(600);
        Andar(3);
        delay(400);
        Andar(5);
      }
      if (statuss == 0) {
        Andar(2);
        delay(500);
        Andar(4);
        delay(300);
        Andar(5);
      }
      delay(1000);
    }
  else {
    Andar(1);
  }
}

void Andar(int direcao) {
  if (direcao == 1) { // anda pra frente
    digitalWrite(MotorB1, HIGH);
    digitalWrite(MotorB2, LOW);
    digitalWrite(MotorA1, HIGH);
    digitalWrite(MotorA2, LOW);
  }

  if (direcao == 2) { // anda pra trás
    digitalWrite(MotorB1, LOW);
    digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorA1, LOW);
    digitalWrite(MotorA2, HIGH);
  }

  if (direcao == 3) { // faz curva pra direita
    digitalWrite(MotorB1, HIGH);
    digitalWrite(MotorB2, LOW);
    digitalWrite(MotorA1, LOW);
    digitalWrite(MotorA2, HIGH);
  }

  if (direcao == 4) { // faz curva pra esquerda
    digitalWrite(MotorB1, LOW);
    digitalWrite(MotorB2, HIGH);
    digitalWrite(MotorA1, HIGH);
    digitalWrite(MotorA2, LOW);
  }

  if (direcao == 5) { // FREIA
    digitalWrite(MotorB1, LOW);
    digitalWrite(MotorB2, LOW);
    digitalWrite(MotorA1, LOW);
    digitalWrite(MotorA2, LOW);
  }
}

int Radar() {
  delay(1000);
  servo.write(175);
  delay(1000);
  distanciaD = ultrasonico.Ranging(CM);

  delay(1000);
  servo.write(10);
  delay(1000);
  distanciaE = ultrasonico.Ranging(CM);

  delay(1000);
  servo.write(90);

  if (distanciaD > distanciaE) {
    return 1; // se tiver espaço na direita
  }
  if (distanciaD < distanciaE) {
    return 2; //se tiver espaço na esquerda
  }
  if (distanciaD == distanciaE) {
    return 0;
  }
}
