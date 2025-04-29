void setup() {
  pinMode(13, OUTPUT);       // PIN 13 buat LED
  pinMode(2, INPUT_PULLUP);  // PIN 2 buat tombol, aktifkan internal pull-up resistor
}

void loop() {
  int tombol = digitalRead(2);  // Baca tombol

  if (tombol == LOW) {          // Kalau tombol ditekan (LOW karena pull-up)
    digitalWrite(13, HIGH);     // Nyalain LED
  } else {
    digitalWrite(13, LOW);      // Kalau tombol dilepas, matiin LED
  }
}
