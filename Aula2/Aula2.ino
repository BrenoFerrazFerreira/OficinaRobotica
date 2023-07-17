#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3); //rx, tx

//motor a 
#define IN1 13
#define IN2 12

//motor b
#define IN3 11
#define IN4 10

int state_rec;
char state;

void setup() {
  //Inicializa as portas como entrada e saída.
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //Inicializa a comunicação serial em 9600 bits.
  bluetooth.begin(9600);

}

void loop() {
  while (bluetooth.available()){
    state = bluetooth.read();
  
    // Se o estado recebido for igual a 'F', o carro se movimenta para frente.
    if(state == 'F'){
      forward();  
    }
    else if(state == 'B'){// Se o estado recebido for igual a 'B', o carro se movimenta para trás.
      backward();  
    }
    else if(state == 'L'){// Se o estado recebido for igual a 'L', o carro se movimenta para esquerda.
      left();  
    }
    else if(state == 'R'){// Se o estado recebido for igual a 'R', o carro se movimenta para direita.
      right();  
    }
    else if(state == 'S'){// Se o estado recebido for igual a 'S', o carro permanece parado.
      Stop();  
    }
    else{
      Stop();
    }
  }
}

  void forward(){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
  }

  void backward(){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
  }

  void left(){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
  }

  void right(){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
  }

  void Stop(){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
  }
  
