#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
char auth[] = "cVWmVy230IIODjuarQqMtk-jUABRcUfc";
char ssid[] = "Ktayal";
char pass[] = "1357924680";
int rbpins[7] = {2, 4, 5, 18, 19, 23, 32}, rwpins[7] = {33, 25, 26, 27, 15, 12, 13}, i, j, pinstate = 1, a = 34, wait;
void setup()
{
  //7 reds,6 greens,5 blues,5 whites
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  for (i = 0; i < 7; i++)
  {
    pinMode(rbpins[i], OUTPUT);
  }
  for (i = 0; i < 7; i++)
  {
    pinMode(rwpins[i], OUTPUT);
  }
  pinMode(a, INPUT); Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Blynk.begin("cVWmVy230IIODjuarQqMtk-jUABRcUfc", ssid, pass);
}
void loop()
{
  lcd.clear();
  lcd.print("Click switch for ");
  lcd.setCursor(0, 1);
  lcd.print("creating patterns");
  pinstate = digitalRead(a);
  if (pinstate == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("Turn on the the ");
    lcd.setCursor(0, 1);
    lcd.print("Blynk app");
    Blynk.run();
    wait = millis();
    if (wait > 50000)
    {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Happy");
      lcd.setCursor(3, 1);
      lcd.print("Diwali!!!");
    }
  }
  else
  {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Happy");
    lcd.setCursor(3, 1);
    lcd.print("Diwali!!!");
    for (i = 0; i < 7; i++)
    {
      Serial.print(i);
      digitalWrite(rbpins[i], HIGH);
      delay(100);
      digitalWrite(rbpins[i], LOW);
      delay(10);
    }
    for (j = 0; j < 7; j++)
    {
      Serial.print(i);
      digitalWrite(rwpins[j], HIGH);
      delay(100);
      digitalWrite(rwpins[j], LOW);
      delay(10);
    }
    for (j = 5; j >= 0; j--)
    {
      Serial.print(i);
      digitalWrite(rwpins[j], HIGH);
      delay(100);
      digitalWrite(rwpins[j], LOW);
      delay(10);
    }
    for (i = 6; i >= 1; i--)
    {
      Serial.print(i);
      digitalWrite(rbpins[i], HIGH);
      delay(100);
      digitalWrite(rbpins[i], LOW);
      delay(10);
    }
    for (i = 0; i <= 6; i = i + 2)
    {
      digitalWrite(rbpins[i], HIGH);
      delay(100);
    }
    for (i = 0; i <= 6; i = i + 2)
    {
      digitalWrite(rbpins[i], LOW);
      delay(100);
    }
    for (i = 1; i <= 5; i = i + 2)
    {
      digitalWrite(rbpins[i], HIGH);
      delay(100);
    }
    for (i = 1; i <= 5; i = i + 2)
    {
      digitalWrite(rbpins[i], LOW);
      delay(100);
    }
    for (i = 0; i <= 6; i = i + 2)
    {
      digitalWrite(rwpins[i], HIGH);
      delay(100);
    }
    for (i = 0; i <= 6; i = i + 2)
    {
      digitalWrite(rwpins[i], LOW);
      delay(100);
    }
    for (i = 1; i <= 5; i = i + 2)
    {
      digitalWrite(rwpins[i], HIGH);
      delay(100);
    }
    for (i = 1; i <= 5; i = i + 2)
    {
      digitalWrite(rwpins[i], LOW);
      delay(100);
    }
    for (i = 0; i <= 6; i = i + 2)
    {
      j = 5 - i;
      digitalWrite(rbpins[i], HIGH);
      delay(200);
      digitalWrite(rbpins[i], LOW);
      delay(10);
      digitalWrite(rwpins[j], HIGH);
      delay(200);
      digitalWrite(rwpins[j], LOW);
      delay(10);
    }
    j = 0;
    for (i = 5; i >= -1; i = i - 2)
    {
      j = 5 - i;
      digitalWrite(rwpins[j], HIGH);
      delay(200);
      digitalWrite(rwpins[j], LOW);
      delay(10);
      digitalWrite(rbpins[i], HIGH);
      delay(200);
      digitalWrite(rbpins[i], LOW);
      delay(10);
    }
    for (j = 0; j < 3; j++)
    {
      for (i = 0; i < 7; i++)
      {
        digitalWrite(rbpins[i], HIGH);
        digitalWrite(rwpins[i], HIGH);
        delay(50);
        digitalWrite(rbpins[i], LOW);
        digitalWrite(rwpins[i], LOW);
        delay(50);
      }
    }
    for (j = 0; j < 3; j++)
    {
      for (i = 0; i < 7; i++)
      {
        digitalWrite(rbpins[i], HIGH);
        digitalWrite(rwpins[i], HIGH);
      }
      delay(150);
      for (i = 0; i < 7; i++)
      {
        digitalWrite(rbpins[i], LOW);
        digitalWrite(rwpins[i], LOW);
      }
      delay(300);
    }
  }
}
