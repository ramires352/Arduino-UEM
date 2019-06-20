//Pinos do joystick
int eixoX = A4;
int eixoY = A5;

//Pinos da matriz
int linhas[8] = {2,3,4,5,6,7,8,9};
int colunas[8] = {10,11,12,13,A0,A1,A2,A3};

//Ponto inicial da matriz 0,0
int posX = 0;
int posY = 0;

int posXAnt = 0;
int posYAnt = 0;

//Apaga o ponto l,c da matriz
void apagarPonto(int l, int c){
    digitalWrite(linhas[l],LOW);
    digitalWrite(colunas[c],HIGH);
}

//Acende o ponto l,c da matriz
void acenderPonto(int l, int c){
    digitalWrite(linhas[l],HIGH);
    digitalWrite(colunas[c],LOW);
}

void setup(){
    int i;

    //Define os pinos da matriz como saida
    for(i=0;i<8;i++){
        pinMode(linhas[i],OUTPUT);
        pinMode(colunas[i],OUTPUT);
    }

    //Inicia a matriz apagada
    for(i=0;i<8;i++){
        digitalWrite(linhas[i],LOW);
    }
    for(i=0;i<8;i++){
        digitalWrite(colunas[i],HIGH);
    }
}


void loop(){
    //Leitura dos valores X e Y do joystick
    int valorX = analogRead(eixoX);
    int valorY = analogRead(eixoY);

    //Posicao anterior do ponto da matriz
    posXAnt = posX;
    posYAnt = posY;

    //detecta se o joystick está para cima
    if(valorX == 0){
        apagarPonto(posX,posY);
        posX--;
    }
    
    //detecta se o joystick está para baixo
    if(valorX == 1023){
        apagarPonto(posX,posY);
        posX++;
    }

    //detecta se o joystick está para a direita
    if(valorY == 0){
        apagarPonto(posX,posY);
        posY++;
    }

    //detecta se o joystick está para a esquerda
    if(valorY == 1023){
        apagarPonto(posX,posY);
        posY--;
    }

    //Tratamento de borda da matriz
    if(posX < 0) posX = 7;
    if(posX > 7) posX = 0;
    if(posY < 0) posY = 7;
    if(posY > 7) posY = 0;

    //Acende o novo ponto
    acenderPonto(posX,posY);

    //Espera 1 segundo
    delay(1000);
}
