#include <DHT.h>
#include <math.h>

#define pinDHT A0
#define DHTType DHT11

#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define DP 9

//pinos que ativam os digitos do display
int digits[] = {10,11,12,13};

//pinos que ativam os segmentos do digito
int segments[] = {A,B,C,D,E,F,G,DP};

//pinos que formam os digitos do display
int zero[] = {A,B,C,D,E,F};
int um[] = {B,C};
int dois[] = {A,B,G,E,D};
int tres[] = {A,B,G,C,D};
int quatro[] = {F,G,B,C};
int cinco[] = {A,F,G,C,D};
int seis[] = {A,F,C,D,E,G};
int sete[] = {A,B,C};
int oito[] = {A,B,C,D,E,F,G};
int nove[] = {A,B,C,F,G,D};
int celsius[] = {D,E,G};

//inicializa o objeto que controla o dht
DHT sensor(pinDHT, DHTType);

void clearDisplay(){
    int i;
    for(i=0;i<8;i++){
        digitalWrite(segments[i], LOW);
    }

    for(i=0;i<4;i++){
        digitalWrite(digits[i], HIGH);
    }
}

void setSegments(int segs[], int digit, int dp, int size){
    int i;
    for(i=0;i<size;i++){
        digitalWrite(segs[i], HIGH);
    }
    digitalWrite(digit, LOW);
    if(dp == 1){
        digitalWrite(DP, HIGH);
    }
    else{
        digitalWrite(DP, LOW);
    }
}

void writeDisplay(int num, int digit, int dp){
    switch (num)
    {
    case 1:
        setSegments(um,digit,dp,2);
        // digitalWrite(digit, HIGH);
        break;
    case 2:
        setSegments(dois,digit,dp,5);
        break;
    case 3:
        setSegments(tres,digit,dp,4);
        break;
    case 4:
        setSegments(quatro,digit,dp,4);
        break;
    case 5:
        setSegments(cinco,digit,dp,5);
        break;
    case 6:
        setSegments(seis,digit,dp,6);
        break;
    case 7:
        setSegments(sete,digit,dp,3);
        break;
    case 8:
        setSegments(oito,digit,dp,7);
        break;
    case 9:
        setSegments(nove,digit,dp,6);
        break;
    default:
        break;
    }
}

void setup(){
    int i;
    for(i=0;i<8;i++){
        pinMode(segments[i], OUTPUT);
    }

    for(i=0;i<4;i++){
        pinMode(digits[i], OUTPUT);
    }

    sensor.begin();

    clearDisplay();
    // setSegments(tres, digits[0], 1, 5);
    Serial.begin(9600);
}


void loop(){
    float t = sensor.readTemperature();
    float h = sensor.readHumidity();
    
    double i,f;
    f = modf(t, &i);

    int t0 = i/10;
    int t1 = (int) i % 10;
    int t2 = f*10;

    writeDisplay(t0,digits[0],0);
    clearDisplay();
    writeDisplay(t1,digits[1],1);
    clearDisplay();
    writeDisplay(t2,digits[2],0);
    clearDisplay();

    setSegments(celsius,digits[3],0,3);
    clearDisplay();

    // Serial.println(t0);
    // Serial.println(t1);
    // Serial.println(t2);
    // Serial.println(t2);

    // delay(3000);
}