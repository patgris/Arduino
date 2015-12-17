#include <DHT.h>

#define DHTPIN 7 //Se define que al pin 7 estará conectado el sensor
#define DHTTYPE DHT11 //Definimos que el sensor a usar es el DHT11

DHT dht(DHTPIN, DHTTYPE); //Definimos el nombre del sensor con "dht" y donde irá conectado junto con el modelo

int cont = 0;
const int sensor = 7; // Entrada del sensor
const int led = 4; // Pin del LED
const int rele2 = 13; // Pin del rele 2

long miliVolts;
long temperatura;

void setup() {
  Serial.begin(9600); // Se inicia la comunicacion serial
  pinMode(rele2, OUTPUT); 
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

  
  digitalWrite(rele2, HIGH); // Encendemos el LED
  delay(5000);
  digitalWrite(rele2, LOW); // Apagamos el LED
  
  
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" grados");
  Serial.print(", Humedad: ");
  Serial.print(h);
  Serial.print("%");
  Serial.print(", HI: ");
  Serial.print(hi);
  Serial.println("%");
  delay(5000);
}
