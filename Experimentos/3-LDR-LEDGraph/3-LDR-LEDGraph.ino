int pinLDR = A0; //pino do LDR
int ledCount = 10; //quantidade de LEDs

int ledPins[] = {
    2,3,4,5,6,7,8,9,10,11
}; //array de pinos onde estao conectados os LEDs

void setup(){
    int led;
    for(led = 0; led < ledCount; led++){ 
        pinMode(ledPins[led], OUTPUT); //Define os pinos dos LEDs como saida
    }
}


void loop(){
    //leitura do valor do LDR
    int estadoLDR = analogRead(pinLDR);

    //mapeia o valor do LDR para uma quantidade entre 0 e ledCount
    int ledLevel = map(estadoLDR, 0, 1023, 0, ledCount);

    int led;

    //Itera sobre os leds
    for(led = 0; led < ledCount; led++){
        //se o indice for menor que ledLevel
        if(led < ledLevel){
            //acende o LED
            digitalWrite(ledPins[led], HIGH);
        }
        //se o indice for maior que ledLevel
        else{
            //apaga o led
            digitalWrite(ledPins[led],LOW);
        }
    }
}