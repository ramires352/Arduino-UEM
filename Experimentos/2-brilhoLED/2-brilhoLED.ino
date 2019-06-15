//Definição dos pinos
int pinoPOT = A0; //Pino analogico do potenciometro
int pinoLED = 3; //Pino PWM do LED

float luminosidade;

float valorPOT;

void setup() {
  pinMode(pinoPOT, INPUT); //Pino de entrada
  pinMode(pinoLED, OUTPUT); //Pino de saida

}

void loop() {
  valorPOT = analogRead(pinoPOT); //Le o valor do potenciometro

  luminosidade = map(valorPOT, 0, 1023, 0, 255); //faz o mapeamento do valor do potenciometro para 0-255

  analogWrite(pinoLED,luminosidade); //envia o sinal para o LED
}