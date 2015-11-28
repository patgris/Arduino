// Parpadeo de LED

int estado = 0; // Guarda el estaso del boton
int salida = 0; //Guarda el estado anterior del boton
int estadoAnterior =0; //0 = LED está apagado, 1 = LED encendido

void setup() {
  pinMode(8, INPUT); // Declaro el boton como entrada
  pinMode(4, OUTPUT); // Declaro el LED como salida
  
}

void loop() {
  estado = digitalRead(8); // Leer el estado del boton
  
  if(estado==HIGH && estadoAnterior==LOW){ // Si estado esta en alto
    salida = 1 - salida; //
    delay(20);
  }
  
  estadoAnterior = estado; //Guarda el valor actual
  
  if(salida == 1){ // Si estado esta alto
    digitalWrite(4, HIGH); // Encendemos el LED
  }
  else{
    digitalWrite(4, LOW); // Apagamos el LED
  }
  
}
