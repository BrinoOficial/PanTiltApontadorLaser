#include <Servo.h>

Servo base;
Servo braco;

const int  pot1 = A0;
const int  pot2 = A1;
const int  laser = 3;
const int  botao =2;

int  pos1 = 0;
int  pos2 = 0;
int  angulo1 = 0;
int  angulo2 = 0;
int  estadoBotao = 1;
int  leituraBotao = 0;

void setup(){
    braco.attach(6);
    base.attach(5);
    pinMode(laser, OUTPUT);
    pinMode(botao, INPUT_PULLUP);
	
}

void loop(){
    pos1 = analogRead(pot1);
    pos2 = analogRead(pot2);
    angulo1 = map(pos1,0,1023,0,180);
    angulo2 = map(pos2,0,1023,0,180);
    base.write(angulo1);
    braco.write(angulo2);
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