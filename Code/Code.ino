//Prateek
//https://justdoelectronics.com
//https://www.youtube.com/c/JustDoElectronics/videos

#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
const int servoPin = 3;
const int touchPin = 2;
int ledPin = 13;
int touchState = 0;
int directionState = 0;
Servo myservo;
int pos = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print(" Touch Based");
  lcd.setCursor(0, 1);
  lcd.print("Door Lock System");
  myservo.attach(3);
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  touchState = digitalRead(touchPin);
  if (directionState == 0) {
    if (touchState == HIGH) {
      directionState = 1;
      for (pos = 0; pos < 180; pos += 1)
        digitalWrite(ledPin, 1);
      lcd.clear();
      lcd.print("Status: Locked");
      lcd.setCursor(0, 1);
      lcd.print("Touch to Unlock");
      {
        myservo.write(pos);
        delay(15);
      }
    }

  } else if (directionState == 1) {
    if (touchState == HIGH) {
      directionState = 0;

      for (pos = 180; pos >= 1; pos -= 1)
        digitalWrite(ledPin, 0);
      lcd.clear();
      lcd.print("Status: Unlocked");
      lcd.setCursor(0, 1);
      lcd.print("Touch to Lock");
      {
        myservo.write(pos);
        delay(15);
      }
    }
  }
}
