#include <Time.h>
#include <TimeLib.h>

#include <DHT.h>
#include <Servo.h> //Desactiva el pwm en los pines 9 y 10

#define DHTPIN 7 //Se define que al pin 7 estará conectado el sensor
#define DHTTYPE DHT11 //Definimos que el sensor a usar es el DHT11
DHT dht(DHTPIN, DHTTYPE); //Definimos el nombre del sensor con "dht" y donde irá conectado junto con el modelo
Servo miServo;

int conTiempo = 0;
int conTiempo2 = 0;

const int rele2 = 5; // Pin del rele 2
const int rele1 = 6; // Pin del rele 1

const int pinServo = 2;
const int pulsoMin = 550; // pulso en us para girar el servo a 0 grados
const int pulsoMax = 2250; // pulso en us para girar el servo a 180 grados

long miliVolts;
long temperatura;

void setup() {
  Serial.begin(9600); // Se inicia la comunicacion serial
  pinMode(rele2, OUTPUT);
  pinMode(rele1, OUTPUT);
  miServo.attach(pinServo, pulsoMin, pulsoMax);
}

void loop() {
  if(timeStatus() == timeNotSet){
     setTime(0,0,0,1,1,2016);
  }

  conTiempo = minute();
  
  
  float h = dht.readHumidity(); //Variable para leer la humedad
  float t = dht.readTemperature();
  
  if(isnan(h) || isnan(t)) //Si lo recibido en el comando de humedad y temperatura no es un número escribir "ERR"
  {
    Serial.println("ERRORRRR");
    return;
  }
  else{
    float hi = dht.computeHeatIndex(t, h); //Calcular temperatura y humedad
  
    if(t<=40.0){
      digitalWrite(rele1, LOW); // LOW encendido HIGH apagado
      digitalWrite(rele2, LOW); // LOW encendido HIGH apagado

      if(t>=50.0){
        digitalWrite(rele1, HIGH); // LOW encendido HIGH apagado
        digitalWrite(rele2, HIGH); // LOW encendido HIGH apagado
      }
    }
    else{
      
    }
    
    if(conTiempo < conTiempo2){
      if(((conTiempo + 60) - conTiempo2) >= 20){
        conTiempo2 = conTiempo;
        miServo.write(0);
        delay(2000);
        miServo.write(180);
        delay(2000);
        miServo.write(0);
      }
    }
    else{
      if((conTiempo - conTiempo2) >= 20){
        conTiempo2 = conTiempo;
        miServo.write(0);
        delay(2000);
        miServo.write(180);
        delay(2000);
        miServo.write(0);
      }
    }
    
    Serial.print("Servooo 1: ");
    Serial.print(miServo.read());
    miServo.write(180);
    delay(2000);
    Serial.print("Servooo 2: ");
    Serial.print(miServo.read());
    Serial.print(" ---Temperatura: ");
    Serial.print(t);
    Serial.println(" grados");
    Serial.print(", Humedad: ");
    Serial.print(h);
    Serial.print("%");
    Serial.print(", HI: ");
    Serial.print(hi);
    Serial.println("%");
    //delay(5000);
  
    digitalClockDisplay(); 
  }
}

void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year());
  Serial.println();
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
