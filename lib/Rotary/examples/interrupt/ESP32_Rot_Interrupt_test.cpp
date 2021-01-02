#include <Arduino.h>    // Core arduino library
#include <Wire.h>

#include <Rotary.h>
#include <Debounce.h>

#define ROTCOUNT              24 // Number of detents in a single rotation of the knob
#define ROTPIN_A              13
#define ROTPIN_B              12

Rotary rotary = Rotary(ROTPIN_A, ROTPIN_B);
unsigned char result;

void setup(void) {
  Serial.begin(115200);
  Serial.println(F("Hello! Rot Test"));
  pinMode(ROTPIN_A, INPUT_PULLUP);
  pinMode(ROTPIN_B, INPUT_PULLUP);

  attachInterrupt(ROTPIN_A, rotate, CHANGE);
  attachInterrupt(ROTPIN_B, rotate, CHANGE);
}

void loop() { }

void rotate() {
  //Serial.println("Rotate!");
  result = rotary.process();
  //Serial.println(result);

  if (result == DIR_CCW) {
    Serial.println("Counter-clockwise!");
  } else if (result == DIR_CW) {
    Serial.println("Clockwise!");
  }

}
