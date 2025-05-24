#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 32
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// alamat I2C LCD 16x2 biasa 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Monitoring...");
}

void loop() {
  delay(2000);

  float suhu = dht.readTemperature();
  float lembap = dht.readHumidity();

  if (isnan(suhu) || isnan(lembap)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor gagal    ");
    lcd.setCursor(0, 1);
    lcd.print("baca data!      ");
    return;
  }

  // menaampilkan di serial
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" °C, Kelembapan: ");
  Serial.print(lembap);
  Serial.println(" %");

  // menampilkan di LCD
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(suhu, 1);
  lcd.print((char)223); // simbol derajat
  lcd.print("C     ");

  lcd.setCursor(0, 1);
  lcd.print("Lembap: ");
  lcd.print(lembap, 1);
  lcd.print("%     ");
}
