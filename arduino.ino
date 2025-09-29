#include <Servo.h>

Servo motorFL; // Front Left
Servo motorFR; // Front Right
Servo motorBL; // Back Left
Servo motorBR; // Back Right

String inputString = "";
boolean stringComplete = false;

const int LED_PIN = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  Serial.print("hello world\n");

  if (stringComplete) {
    int j1x, j1y, j2x, j2y;
    sscanf(inputString.c_str(), "%d,%d,%d,%d", &j1x, &j1y, &j2x, &j2y);

    Serial.print("FL: "); Serial.print(j1x);
    Serial.print(" FR: "); Serial.print(j1y);
    Serial.print(" BL: "); Serial.print(j2x);
    Serial.print(" BR: "); Serial.println(j2y);
  }
}

// read serial from ESP32
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}
