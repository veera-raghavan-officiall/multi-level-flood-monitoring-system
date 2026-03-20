#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int trig = 7;
int echo = 6;
int red = 5;
int blue = 4;
int green = 3;
int buz = 2;

int distance;
long duration;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buz, OUTPUT);
  
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if(distance < 10) {
    digitalWrite(red, HIGH);
    digitalWrite(buz, HIGH);
    lcd.print("🚨 FLOOD ALERT ");
  }
  else if(distance < 20) {
    digitalWrite(blue, HIGH);
    digitalWrite(buz, LOW);
    lcd.print("⚠️ WARNING ");
  }
  else {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(buz, LOW);
    lcd.print("✅ SAFE ");
  }

  delay(500);
  lcd.clear();
}