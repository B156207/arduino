void setup() {
  pinMode(13, OUTPUT); // LED di pin 13
}

void loop() {
  int pot = analogRead(A0); // Baca nilai potensiometer 0–1023
  int jeda = map(pot, 0, 1023, 100, 1000); // Ubah ke delay 100-1000 ms

  digitalWrite(13, HIGH); // LED nyala
  delay(jeda);            // Tunggu jeda
  digitalWrite(13, LOW);  // LED mati
  delay(jeda);            // Tunggu jeda
}
