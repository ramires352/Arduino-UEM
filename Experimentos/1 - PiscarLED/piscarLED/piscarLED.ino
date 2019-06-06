void setup() {
  //Executa apenas uma vez

  //Definição do pino positivo que será ligado ao LED
  int pinoLED = 2

  //Definição do pino pinoLED como saída
  pinMode(pinoLED, OUTPUT); 
}

void loop() {
  //Executa indefinidamente

  //Envia um sinal alto (5V) para o pinoLED
  digitalWrite(pinoLED, HIGH);

  //Espera 1 segundo
  delay(1000);

  //Envia um sinal baixo (0V) para o pinoLED
  digitalWrite(pinoLED, LOW);

  //Espera 1 segundo
  delay(1000);
}
