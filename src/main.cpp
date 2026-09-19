#include <Arduino.h>

const int touchPins[] = {T9, T8, T6, T4, T7}; // setando os pinos que estão sendo usados
const int totalPins = sizeof(touchPins) / sizeof(touchPins[0]); // busca qtd de pins de acordo com o tamanho do array totalPins dividido pelo tamanho de "cada pino"

void setup() {
  // começando comunicação serial
  Serial.begin(115200);
  delay(1000); 
  Serial.println("Iniciando o teste de toque nos pinos...");
  
  // configura o pino 2 (LED azul da placa) como saída
  pinMode(2, OUTPUT);
}

void loop() {
  bool touched = false; /// variável flag que alerta o toque

  for (int i = 0; i < totalPins; i++) { // percorre todos os pinos
    int value = touchRead(touchPins[i]);
  if(value < 30) {
    Serial.print("Você tocou no pino: ");
    Serial.println(i);
    Serial.println(" | VALOR: ");
    Serial.println(value);

    touched = true;
  } 
  }

  if (touched) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  delay(100); 
}