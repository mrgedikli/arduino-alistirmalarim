#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sicaklik;
int sicaklikpin = A0;

unsigned long previousMillis = 0;  // onceki olcum zamanını  vermeye yarar.
const long interval = 2000;            // iki olcum arasında gecen sureyi vermeye yarar.

void setup() {
    lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
     unsigned long currentMillis = millis();  // şuanki zamanı al

   // belirledigimiz aralıkta olcum yap
  if (currentMillis - previousMillis >= interval) {
    sicaklik = ((analogRead(sicaklikpin) * 4.88) - 500) / 10;

       lcd.clear();
    lcd.setCursor(0, 0);
       lcd.print("Sicaklik: ");
    lcd.print(sicaklik);
       lcd.print(" C ");

      lcd.setCursor(0, 1);
    lcd.print("Gecen Sure: ");
      lcd.print((currentMillis - previousMillis) / 1000);   // ms'yi saniyeye cevirip öyle yazdir.
    lcd.print(" s");

     Serial.print("Sicaklik: ");
    Serial.print(sicaklik);
     Serial.print(" C, Gecen Sure: ");
    Serial.print((currentMillis - previousMillis) / 1000);
     Serial.println(" s");

     previousMillis = currentMillis;  // önceki ölçüm zamanını güncelle
  }

  delay(200);
}
   
               
               
