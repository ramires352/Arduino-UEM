int eixoX = A4;
int eixoY = A5;

int linhas[8] = {2,3,4,5,6,7,8,9};
int colunas[8] = {10,11,12,13,A0,A1,A2,A3};

int posX = 0;
int posY = 0;

int posXAnt = 0;
int posYAnt = 0;

void apagarPonto(int l, int c){
    digitalWrite(linhas[l],LOW);
    digitalWrite(colunas[c],HIGH);
}

void acenderPonto(int l, int c){
    digitalWrite(linhas[l],HIGH);
    digitalWrite(colunas[c],LOW);
}

void setup(){
    Serial.begin(9600);

    int i;

    for(i=0;i<8;i++){
        pinMode(linhas[i],OUTPUT);
        pinMode(colunas[i],OUTPUT);
    }

    for(i=0;i<8;i++){
        digitalWrite(linhas[i],LOW);
    }
    for(i=0;i<8;i++){
        digitalWrite(colunas[i],HIGH);
    }
}


void loop(){
    int valorX = analogRead(eixoX);
    int valorY = analogRead(eixoY);

    posXAnt = posX;
    posYAnt = posY;

    if(valorX == 0){
        Serial.println("Para Cima");
        apagarPonto(posX,posY);
        posX--;
    }
    
    if(valorX == 1023){
        Serial.println("Para Baixo");
        apagarPonto(posX,posY);
        posX++;
    }

    if(valorY == 0){
        Serial.println("Direita");
        apagarPonto(posX,posY);
        posY++;
    }

    if(valorY == 1023){
        Serial.println("Esquerda");
        apagarPonto(posX,posY);
        posY--;
    }

    if(posX < 0) posX = 7;
    if(posX > 7) posX = 0;
    if(posY < 0) posY = 7;
    if(posY > 7) posY = 0;

    acenderPonto(posX,posY);

    if(posX != posXAnt && posY != posYAnt){
        apagarPonto(posXAnt, posYAnt);
    }
    
    Serial.print(posX);
    Serial.print(" ");
    Serial.print(posY);
    Serial.print("\n");

    delay(1000);
}
