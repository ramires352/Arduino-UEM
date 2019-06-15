//Definicao dos pinos de cada segmento do display
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

int segmentos[] = {A,B,C,D,E,F,G}; //Array de pinos do display
int pinBotao = 9; //pino do botao

//variaveis para controle do botao
int estadoAtual = LOW;
int estadoAnterior = LOW;

//Digito que sera escrito no display
int digito = 0;

//Quantidade de segmentos para cada digito
int qtdSegmentos[] = {6,2,5,5,4,5,6,3,8,6};

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

//Apaga o display
void apagar(){
    int i;
    for(i=0;i<7;i++){
        digitalWrite(oito[i],LOW);
    }
}

void setup(){
    int i;
    //Define os pinos do display como saida
    for(i=0;i<7;i++){
        pinMode(segmentos[i], OUTPUT);
    }

    //Define o pino do botao como input
    //PullUP utiliza um resistor interno do arduino para simplificar o circuito
    pinMode(pinBotao, INPUT_PULLUP);
}

void loop(){
    int i;
    //faz a leitura do pino do botao
    //por conta da utilizacao do PullUP o botao fica no estado
    //HIGH quando nao for apertado
    //LOW quando for apertado
    estadoAtual = digitalRead(pinBotao);

    //detecta se o botao foi apertado
    if(estadoAtual == LOW && estadoAnterior == HIGH){
        //incrementa o digito
        digito++;
    }

    estadoAnterior = estadoAtual;

    //volta o digito para 0 caso chegue a 10
    if(digito == 10){
        digito = 0;
    }

    switch(digito){
        case 0:
            apagar();
            for(i=0;i<qtdSegmentos[0];i++){ //Acende os segmentos do digito 1
                digitalWrite(zero[i],HIGH);
            }
            break;
        case 1:
            apagar();
            for(i=0;i<qtdSegmentos[1];i++){ //Acende os segmentos do digito 1
                digitalWrite(um[i],HIGH);
            }
            break;

        case 2:
            apagar();
            for(i=0;i<qtdSegmentos[2];i++){ //Acende os segmentos do digito 2
                digitalWrite(dois[i],HIGH);
            }
            break;
            
        case 3:
            apagar();
            for(i=0;i<qtdSegmentos[3];i++){ //Acende os segmentos do digito 3
                digitalWrite(tres[i],HIGH);
            }
            break;
        case 4:
            apagar();
            for(i=0;i<qtdSegmentos[4];i++){ //Acende os segmentos do digito 4
                digitalWrite(quatro[i],HIGH);
            }
            break;
        case 5:
            apagar();
            for(i=0;i<qtdSegmentos[5];i++){ //Acende os segmentos do digito 5
                digitalWrite(cinco[i],HIGH);
            }
            break;
        case 6:
            apagar();
            for(i=0;i<qtdSegmentos[6];i++){ //Acende os segmentos do digito 6
                digitalWrite(seis[i],HIGH);
            }
            break;
        case 7:
            apagar();
            for(i=0;i<qtdSegmentos[7];i++){ //Acende os segmentos do digito 7
                digitalWrite(sete[i],HIGH);
            }
            break;
        case 8:
            apagar();
            for(i=0;i<qtdSegmentos[8];i++){ //Acende os segmentos do digito 8
                digitalWrite(oito[i],HIGH);
            }
            break;
        case 9:
            apagar();
            for(i=0;i<qtdSegmentos[9];i++){ //Acende os segmentos do digito 9
                digitalWrite(nove[i],HIGH);
            }
            break;
    }
}