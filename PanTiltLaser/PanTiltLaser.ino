// Inclui a biblioteca do Servo
#include <Servo.h>


// Declara dois objetos servo
Servo base;
Servo braco;

// Define as portas a serem usadas
const int  pot1 = A0;
const int  pot2 = A1;
const int  laser = 3;
const int  botao =2;

// Define variaveis para ajudar no controle
int  pos1 = 0;
int  pos2 = 0;
int  angulo1 = 0;
int  angulo2 = 0;
int  estadoBotao = 1;
int  leituraBotao = 0;

void setup(){
    // Conecta os servos nas devidas portas do Arduino
    braco.attach(6);
    base.attach(5);
    // Declara o nosso apontador laser como saida
    pinMode(laser, OUTPUT);
    // Declara o nosso botao como uma entrada com um filtro
    pinMode(botao, INPUT_PULLUP);
	
}

void loop(){
    // Executa a leitura do joystick
    pos1 = analogRead(pot1);
    pos2 = analogRead(pot2);
    // Realiza um remapeamento. A entrada na porta Analogica é um valor entre 0 e 1023 e queremos transforma-lo em um valor para o servo, entre 0 e 180
    angulo1 = map(pos1,0,1023,0,180);
    angulo2 = map(pos2,0,1023,0,180);
    // Escreve o valor nos servos
    base.write(angulo1);
    braco.write(angulo2);
    // Le o botao e inverte o estado do laser, ligando-o ou desligando-o
    leituraBotao =  digitalRead(botao);
    if(leituraBotao == LOW){
	estadoBotao = !(estadoBotao);
	delay(300);
    }
   if(estadoBotao == LOW){
	digitalWrite(laser,HIGH);
    }else{
     	digitalWrite(laser,LOW);
   }
   delay(150);
}
