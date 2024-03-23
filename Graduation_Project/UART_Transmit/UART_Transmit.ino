#include <HardwareSerial.h>

void setup() {
  Serial.begin(115200); // Initialize serial communication at 115200 baud
  delay(100);
}

void loop() {
    int number = 123; // Example number to send
    Serial.println(number);
    delay(500);
}