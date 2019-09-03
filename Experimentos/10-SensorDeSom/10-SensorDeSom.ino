int pinLED = 2; //pino LED
int pinSom = 3; //pino do sensor de som
boolean ligar = LOW; //estado do led (ligado ou desligado)

void setup(){
    //pino led definido como saida
    pinMode(pinLED, OUTPUT);
    //pino som definido como entrada
    pinMode(pinSom, INPUT);
}


void loop(){
    //faz a leitura do sensor de som
    int som = digitalRead(pinSom);

    //se som = LOW entao detectou som
    if(som == LOW){
        //inverte o estado do led; se estiver HIGH, passa para LOW e vice-versa
        ligar = !ligar;
        //escreve o estado do LED
        digitalWrite(pinLED, ligar);
        //espera 1s
        delay(1000);
    }
}