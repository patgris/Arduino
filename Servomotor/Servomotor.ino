#include <DHT.h>
#include <Servo.h> //Desactiva el pwm en los pines 9 y 10

//#define DHTPIN 7 //Se define que al pin 7 estará conectado el sensor
//#define DHTTYPE DHT11 //Definimos que el sensor a usar es el DHT11

//DHT dht(DHTPIN, DHTTYPE); //Definimos el nombre del sensor con "dht" y donde irá conectado junto con el modelo

Servo miServo;

const int pinServo = 2;
const int pulsoMin = 550; // pulso en us para girar el servo a 0 grados
const int pulsoMax = 2250; // pulso en us para girar el servo a 180 grados

void setup() {
  //Serial.begin(9600); // Se inicia la comunicacion serial
  miServo.attach(pinServo, pulsoMin, pulsoMax);
  //Las entradas analogicas se configuran automaticamente
}

void loop() {
  miServo.write(0);
  delay(2000);
  miServo.write(0);
  delay(2000);
}
