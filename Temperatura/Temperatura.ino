#include <DHT.h>

#define DHTPIN 7 //Se define que al pin 7 estará conectado el sensor
#define DHTTYPE DHT11 //Definimos que el sensor a usar es el DHT11
DHT dht(DHTPIN, DHTTYPE); //Definimos el nombre del sensor con "dht" y donde irá conectado junto con el modelo

int cont = 0;
const int sensor = 7; // Entrada del sensor
const int rojo = 6; // Pin del LED
const int azul = 5; // Pin del LED
const int rele2 = 5; // Pin del rele 2
const int rele1 = 6; // Pin del rele 1

void setup() {
  Serial.begin(9600); // Se inicia la comunicacion serial
  pinMode(rele2, OUTPUT);
  pinMode(rele1, OUTPUT);
  pinMode(rojo, OUTPUT); // Declaro el LED como salida
  pinMode(azul, OUTPUT); // Declaro el LED como salida
}

void loop() {
  float h = dht.readHumidity(); //Variable para leer la humedad
  float t = dht.readTemperature();
  
  if(isnan(h) || isnan(t)) //Si lo recibido en el comando de humedad y temperatura no es un número escribir "ERR"
  {
    Serial.println("ERRORRRR");
    return;
  }
  
  miliVolts = (digitalRead(sensor) * 5000L) / 1023; // Calculamos los mV en la entrada
  temperatura = miliVolts / 10; // Se calcula la temperatura
  
  float hi = dht.computeHeatIndex(t, h); //Calcular temperatura y humedad

//  if(t>=30.0){
//    digitalWrite(rojo, HIGH); // Apagamos el LED
//    digitalWrite(azul, LOW); // Apagamos el LED
//  }
//  else{
//    digitalWrite(rojo, LOW); // Apagamos el LED
//    digitalWrite(azul, HIGH); // Apagamos el LED
//  }
  
  //digitalWrite(rele2, HIGH); // Encendemos el LED
  
  digitalWrite(rele2, LOW); // LOW encendido HIGH apagado  
  digitalWrite(rele1, LOW); // LOW encendido HIGH apagado 
  
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" grados");
  Serial.print(", Humedad: ");
  Serial.print(h);
  Serial.print("%");
  Serial.print(", HI: ");
  Serial.print(hi);
  Serial.println("%");
  //delay(5000);
}
