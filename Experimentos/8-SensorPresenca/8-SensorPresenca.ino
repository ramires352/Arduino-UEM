int pinPIR = 2;
int pinLED_R = 9;
int pinLED_G = 10;
int pinLED_B = 11;

int acionamento = LOW;

void cores(int pR, int pG, int pB){
    int i;
    int R,G,B;
    for(i=0;i<=255;i++){
        R = i;
        G = 255 - i;
        B = i/2;

        // Serial.println(G);

        acenderRGB(R,G,B,pR,pG,pB);

        delay(1);

        // acenderRGB(0,0,0,pR,pG,pB);

        // delay(50);
    }

    for(i=255;i>=0;i--){
        R = i;
        G = 255 - i;
        B = i/2;

        // Serial.println(G);
        acenderRGB(R,G,B,pR,pG,pB);

        delay(1);
    }
}

void acenderRGB(int R, int G, int B, int pR, int pG, int pB){
    analogWrite(pR, R);
    analogWrite(pG, G);
    analogWrite(pB, B);
}

void setup(){
    pinMode(pinPIR, INPUT);
    pinMode(pinLED_R, OUTPUT);
    pinMode(pinLED_G, OUTPUT);
    pinMode(pinLED_B, OUTPUT);

    acenderRGB(0,0,0,pinLED_R,pinLED_G,pinLED_B);

    // Serial.begin(9600);
}


void loop(){
    // cores(pinLED_R, pinLED_G, pinLED_B);
    acionamento = digitalRead(pinPIR);

    if(acionamento == HIGH){
        cores(pinLED_R, pinLED_G, pinLED_B);
    }

    else{
        acenderRGB(0,0,0,pinLED_R,pinLED_G,pinLED_B);
    }
}