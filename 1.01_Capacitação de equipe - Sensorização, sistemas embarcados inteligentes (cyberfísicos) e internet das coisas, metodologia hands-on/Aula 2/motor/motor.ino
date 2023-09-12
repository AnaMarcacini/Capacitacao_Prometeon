// Controle de posição de um servomotor usando um potenciômetro 
#include <Servo.h> 
Servo myservo; // cria um objeto servo para controlar o servomotor 
int potpin = A0; // seleciona pino de saída onde sera conectado o potenciômetro
int val; // define variável onde sera armazenada a leitura do valor de leitura analógica 

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9); // define o pino físico onde estará conectado o servomotor (no caso pino 9) 
} 

void loop() 
{ 
val = analogRead(potpin); // lê o valor do potenciômetro (valor entre 0 e 1023) 
Serial.println(val);
val = map(val, 0, 1023, 0, 180); // associa valor do potenciômetro à escala de acionamento do servo (valor entre 0 e 180 graus) 
myservo.write(val); // envia commando para servomotor conforme valor da escala acima 
delay(15); // espera para que motor se movimente até a posição desejada 
}

