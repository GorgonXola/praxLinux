#include <AFMotor.h>

#define time 300
#define mtSpeed 180
#define way A14
#define patt A15

int leds[10] = {22, 24, 28, 26, 34, 36, 40, 32, 38, 30};

AF_DCMotor motor1(1);

void patern2() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      digitalWrite(leds[j], LOW);
    }
    for (int k = 0; k <= i; k++) {
      digitalWrite(leds[k], HIGH);
    }
    delay(time);
  }
  for (int i = 0; i < 10; i++) {
    digitalWrite(leds[i], LOW);
    delay(time / 2);
  }
}

void clockwise() {
  motor1.setSpeed(mtSpeed);
  motor1.run(FORWARD);
}

void unclockwise() {
  motor1.setSpeed(mtSpeed);
  motor1.run(BACKWARD);
}

void setup() {
  for (int i = 0; i <= 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(way, INPUT);
  pinMode(patt, INPUT);
}

void loop() {
  patern2();
  clockwise();

  delay(time);
}
