/*
BOTOES DO CONTROLE
 
POWER - FFA25D
MENU - FFE21D
TEST - FF22DD
MAIS - FF02FD
BACK - FFC23D
<< - FFE01F
PLAY - FFA857
>> - FF906F
0 - FF6897
MENOS - FF9867
C - FFB04F
1 - FF30CF
2 - FF18E7
3 - FF7A85
4 - FF10EF
5 - FF38C7
6 - FF5AA5
7 - FF42BD
8 - FF4AB5
9 - FF52AD
*/

#include <IRremote.h>

//pino do receptor infravermelho
int pinIR = 3;
IRrecv receptor(pinIR);

//pinos dos LEDS
int pinLED[] = {9,10,11,12,13};

//pino do motor DC
int pinDC = 3;

decode_results resultado;

//armazena o codigo do botao pressionado
int codigo;

void apagarLEDS(){
    int i;
    for(i=0;i<5;i++){
        digitalWrite(pinLED[i], LOW);
    }
}

void acenderLEDS(int qtd){
    apagarLEDS();

    int i;
    
    for(i=0;i<qtd;i++){
        digitalWrite(pinLED[i], HIGH);
    }
    delay(100);
}

void setup(){
    int i;

    for(i=0;i<5;i++){
        pinMode(pinLED[i], OUTPUT);
    }

    pinMode(pinDC, OUTPUT);

    receptor.enableIRIn();
}


void loop(){
    if(receptor.decode(&resultado)){
        codigo = resultado.value;

        switch (codigo){
            //botao 0
            case (0xFF6897):
                apagarLEDS();
                break;
            //botao 1
            case (0xFF30CF):
                acenderLEDS(1);
                break;
            //botao 2    
            case (0xFF18E7):
                acenderLEDS(2);
                break;
            //botao 3
            case (0xFF7A85):
                acenderLEDS(3);
                break;
            //botao 4
            case (0xFF10EF):
                acenderLEDS(4);
                break;
            //botao 5
            case (0xFF38C7):
                acenderLEDS(5);
                break;
            default:
                break;
        }
        receptor.resume();
    }
    delay(100);

}