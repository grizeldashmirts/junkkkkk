#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int in1 = 5;
int in2 = 6;
int trig = 10;
int echo = 9;
float getDist() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  float dur, dist;
  dur = pulseIn(echo, HIGH);
  dist = (dur * .0343) / 2;
  return dist;
}
void motGo(int speed) {
    speed = constrain(speed, -100, 100);
  }
  if (speed == 0) {
    analogWrite(in1, 0);
    analogWrite(in2, 0);
  } else if (speed > 0) {
    speed = map(speed, 0, 100, 0, 255);
    analogWrite(in1, speed);
    analogWrite(in2, 0);
  } else {
    speed = abs(speed);
    speed = map(speed, 0, 100, 0, 255);
    analogWrite(in1, 0);
    analogWrite(in2, speed);
  }
  Serial.println(speed);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Welcome Human!");
  delay(5000);
  lcd.clear();
  lcd.print("Distance: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  motGo(50);
lcd.setCursor(0, 1);
lcd.print("                ");
lcd.setCursor(0, 1);
lcd.print(getDist());
lcd.print("cm");
  delay(1000);
  motGo(150);
lcd.setCursor(0, 1);
lcd.print("                ");
lcd.setCursor(0, 1);
lcd.print(getDist());
lcd.print("cm");
  delay(1000);
  motGo(0);
lcd.setCursor(0, 1);
lcd.print("                ");
lcd.setCursor(0, 1);
lcd.print(getDist());
lcd.print("cm");
  delay(1000);
  motGo(-50);
lcd.setCursor(0, 1);
lcd.print("                ");
lcd.setCursor(0, 1);
lcd.print(getDist());
lcd.print("cm");
  delay(1000);
  motGo(-150);
lcd.setCursor(0, 1);
lcd.print("                ");
lcd.setCursor(0, 1);
lcd.print(getDist());
lcd.print("cm");
  delay(1000);
}
