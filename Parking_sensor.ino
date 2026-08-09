#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int TRIG = 7;
const int ECHO = 6;

const int GREEN = 8;
const int YELLOW = 9;
const int RED = 10;
const int BUZZER = 13;

const int SAFE = 40;
const int CAUTION = 20;
const int DANGER = 10;

unsigned long lastBeep = 0;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("PARKING SENSOR");
  delay(2000);
  lcd.clear();
}

void loop() {
  long distance = getDistance();

  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  if (distance > SAFE) {
    lcd.setCursor(0, 1);
    lcd.print("ALL CLEAR!     ");

    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
    noTone(BUZZER);
  }
  else if (distance > CAUTION) {
    lcd.setCursor(0, 1);
    lcd.print("SLOW DOWN...   ");

    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED, LOW);
    beep(600);
  }
  else if (distance > DANGER) {
    lcd.setCursor(0, 1);
    lcd.print("CAUTION!!!     ");

    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED, HIGH);
    beep(250);
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("** STOP! **    ");

    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
    beep(80);
  }

  delay(100);
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  long distance = duration * 0.0343 / 2;

  if (distance > 200) distance = 200;

  return distance;
}

void beep(int interval) {
  unsigned long currentTime = millis();

  if (currentTime - lastBeep >= interval) {
    lastBeep = currentTime;
    tone(BUZZER, 1000, 50);
  }
}
