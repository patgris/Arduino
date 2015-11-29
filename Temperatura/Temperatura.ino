#include <DHT.h>

#define DHTPIN 7 //Se define que al pin 7 estará conectado el sensor
#define DHTTYPE DHT11 //Definimos que el sensor a usar es el DHT11

DHT dht(DHTPIN, DHTTYPE); //Definimos el nombre del sensor con "dht" y donde irá conectado junto con el modelo

const int sensor = 7; // Entrada del sensor
const int led = 4; // Pin del LED

long miliVolts;
long temperatura;

void setup() {
  Serial.begin(9600); // Se inicia la comunicacion serial

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
  
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" grados");
  Serial.print(", Humedad: ");
  Serial.print(h);
  Serial.print("%");
  Serial.print(", HI: ");
  Serial.print(hi);
  Serial.println("%");
  delay(2000);
}
