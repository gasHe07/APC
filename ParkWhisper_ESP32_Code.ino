#include <HardwareSerial.h>
#include "BluetoothSerial.h"
#define TX  22
#define RX  23
#define BUZZ_PIN  13 //pin dedicato al buzzer
int dist;
HardwareSerial uart(2); // uso UART2 (Serial2 su ESP32)
BluetoothSerial BT;

void setup() {
  Serial.begin(9600);
  uart.begin(9600, SERIAL_8N1, TX, RX);
  BT.begin("ESP32_ELIO");
  pinMode(BUZZ_PIN, OUTPUT);
}

void loop() {
  if (uart.available()) {
    String input = uart.readStringUntil('\n'); // leggo la riga
    input.trim(); // rimuove spazi e \r
    if (input.length() > 0) {
      dist = input.toInt(); // converto in intero
      if (dist > 0) {
        Serial.print(dist); // stampa distanza se valida
        Serial.println(" cm");
        BT.print(dist);
        BT.println(" cm");
        if(dist <= 15 && dist > 10){
          tone(BUZZ_PIN, 1000, 100);
        }
        else if (dist <= 10 && dist > 5){
          tone(BUZZ_PIN, 2000, 50);
        }
        else if (dist <= 5){
          tone(BUZZ_PIN, 3000, 25);
        }
        noTone(BUZZ_PIN);
      }
    }
  }
}
