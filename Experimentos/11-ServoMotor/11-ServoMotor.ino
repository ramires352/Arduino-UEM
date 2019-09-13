#include <IRremote.h>
#include <Servo.h>

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

//pino do servo motor
int pinServo = 6;

//pino do sensor ir
int pinIR = 3;

//objeto que controla o servo motor
Servo s;

IRrecv receptor(pinIR);

decode_results resultado;

//armazena o codigo do botao pressionado no controle remoto
int codigo;

//incremento para os botoes << e >>
int incremento = 20;

void setup(){
    receptor.enableIRIn();
    s.attach(pinServo);
    s.write(0);
}


void loop(){
    if(receptor.decode(&resultado)){
        codigo = resultado.value;

        int intervalo = 20;

        switch(codigo){
            //botao 0
            case(0xFF6897):
                s.write(0);
                break;
            //botao 1
            case(0xFF30CF):
                s.write(intervalo*1);
                break;
            //botao 2
            case(0xFF18E7):
                s.write(intervalo*2);
                break;
            //botao 3
            case(0xFF7A85):
                s.write(intervalo*3);
                break;
            //botao 4
            case(0xFF10EF):
                s.write(intervalo*4);
                break;
            //botao 5
            case(0xFF38C7):
                s.write(intervalo*5);
                break;
            //botao 6
            case(0xFF5AA5):
                s.write(intervalo*6);
                break;
            //botao 7
            case(0xFF42BD):
                s.write(intervalo*7);
                break;
            //botao 8
            case(0xFF4AB5):
                s.write(intervalo*8);
                break;
            //botao 9
            case(0xFF52AD):
                s.write(intervalo*9);
                break;
            //botao >>
            case(0xFF906F):
                incremento += 20;
                if(incremento > 180){
                    incremento = 180;
                }
                s.write(incremento);
                break;
            //botao <<
            case(0xFFE01F):
                incremento -= 20;
                if(incremento < 0){
                    incremento = 0;
                }
                s.write(incremento);
                break;
        }
        receptor.resume();
    }
    delay(50);
}