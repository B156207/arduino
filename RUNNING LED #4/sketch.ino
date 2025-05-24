const int ledCount = 6;
int ledPins[] = {2, 3, 4, 5, 6, 7};

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Nyala dari kiri ke kanan
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(150);
    digitalWrite(ledPins[i], LOW);
  }

  // Nyala dari kanan ke kiri
  for (int i = ledCount - 2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(150);
    digitalWrite(ledPins[i], LOW);
  }
}
