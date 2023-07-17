//motor a 
#define IN1 13
#define IN2 12

//motor b
#define IN3 11
#define IN4 10

//Definição dos pinos dos sensores
#define pin_S1 7
#define pin_S2 6

bool Sensor1 = 0;
bool Sensor2 = 0;

void setup() {
  //Inicializa as portas como entrada e saída.
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //Setamos os pinos dos sensores como entrada
  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);

}

void loop() {
  //Neste processo armazenamos o valor lido pelo sensor na variável que armazena tais dados.
  Sensor1 = digitalRead(pin_S1);
  Sensor2 = digitalRead(pin_S2);

  //Aqui está toda a lógica de comportamento do robô: Para a cor branca atribuímos o valor 0 e, para a cor preta, o valor 1.
  if((Sensor1 == 0) && (Sensor2 == 0)){ // Se detectar na extremidade das faixas duas cores brancas
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
  }
  if((Sensor1 == 1) && (Sensor2 == 0)){ // Se detectar um lado preto e o outro branco
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
  }
  if((Sensor1 == 0) && (Sensor2 == 1)){ // Se detectar um lado branco e o outro preto
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
}
}
