#include <Ultrasonic.h>
#include <LiquidCrystal.h>

//Pinos do sensor de distancia
int pinTrigger = 6;
int pinEcho = 7;

//Pino potenciometro
int pinPot = A0;

//Pino buzzer
int pinBuzz = 10;

//distancia minima em cm
int distanciaMinima = 3;
//distancia maxima em cm
int distanciaMaxima = 15;

//distancia lida pelo sensor
float distance = 0;
float distanceAnt = 0;

//limite de distancia para tocar o alarme
int limite = 0;

//inicia o display
LiquidCrystal lcd(12,11,2,3,4,5);

//inicia o sensor de distancia
Ultrasonic ultrasonic(pinTrigger, pinEcho);

//mostra a distancia minima no display
void showMinDistance(){
    lcd.setCursor(0,1);

    int valorPot = analogRead(pinPot);

    limite = map(valorPot,0,1023,distanciaMinima,distanciaMaxima);

    lcd.print("Min dist: ");
    lcd.print(limite);
    lcd.print("cm      ");
}

//mostra a distancia atual no display
void showCurrentDistance(){
    lcd.setCursor(0,0);

    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print("cm      ");   
}

void setup(){
    pinMode(pinPot,INPUT);

    lcd.begin(16,2);
    Serial.begin(9600);
}

void loop(){
    showMinDistance();

    long microsec = ultrasonic.timing();
    distance = ultrasonic.convert(microsec, Ultrasonic::CM);

    showCurrentDistance();

    //Toca buzzer se a distancia for menor que o limite
    if(distance < limite){
        tone(pinBuzz,150);
    }
    else{
        noTone(pinBuzz);
    }
}