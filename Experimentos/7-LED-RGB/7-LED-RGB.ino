//pinos dos botoes
int pinBotR = 2;
int pinBotG = 3;
int pinBotB = 4;

//pinos do led RGB
int pinLED_R = 9;
int pinLED_G = 10;
int pinLED_B = 11;

//qtd de tons de cada cor
int tons = 3;
int intervalo = 255 / tons;

//valor de cada cor
int R = 0;
int G = 0;
int B = 0;

//estado do botao R
int estadoBotR = LOW;
int estadoBotR_ant = LOW;

//estado do botao G
int estadoBotG = LOW;
int estadoBotG_ant = LOW;

//estado do botao B
int estadoBotB = LOW;
int estadoBotB_ant = LOW;

void setup(){
	//pinos dos botoes definidos como INPUT_PULLUP
	pinMode(pinBotR, INPUT_PULLUP);
	pinMode(pinBotG, INPUT_PULLUP);
	pinMode(pinBotB, INPUT_PULLUP);

	//pinos do led definidos como saida
	pinMode(pinLED_R, OUTPUT);
	pinMode(pinLED_G, OUTPUT);
	pinMode(pinLED_B, OUTPUT);

	//escreve 0 em cada cor do led
	analogWrite(pinLED_R, R);
	analogWrite(pinLED_G, G);
	analogWrite(pinLED_B, B);
}

void loop(){
	//le o estado do botao R
	estadoBotR = digitalRead(pinBotR);

	if (estadoBotR == LOW && estadoBotR_ant == HIGH){
		//incrementa um tom na cor R
		R += intervalo;
		if (R > 255){
			R = 0;
		}
	}

	estadoBotR_ant = estadoBotR;

	estadoBotG = digitalRead(pinBotG);
	if (estadoBotG == LOW && estadoBotG_ant == HIGH){
		//incrementa um tom na cor G
		G += intervalo;
		if (G > 255){
			G = 0;
		}
	}

	estadoBotG_ant = estadoBotG;

	estadoBotB = digitalRead(pinBotB);
	if (estadoBotB == LOW && estadoBotB_ant == HIGH){
		//incrementa um tom na cor B
		B += intervalo;
		if (B > 255){
			B = 0;
		}
	}

	estadoBotB_ant = estadoBotB;

	//escreve o valor das cores do led
	analogWrite(pinLED_R, R);
	analogWrite(pinLED_G, G);
	analogWrite(pinLED_B, B);
}
