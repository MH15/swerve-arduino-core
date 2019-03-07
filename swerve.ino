
#include "BigMotor.h"
#include "Step.h"

// defines pins numbers
const int stepPin = 4;
const int dirPin = 3;
const int victor_pin = 5;

// declare the motors
Step stepper(8);
BigMotor motor(9);

// before
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
    ;

  delay(2000);
  Serial.println("SETUP");
  motor.pin(victor_pin);
  stepper.pin(stepPin, dirPin);
  stepper.rotate(360, HIGH);
}

void loop()
{
  while (Serial.available() == 0)
    ;

  String input = Serial.readString();

  int pos = input.toInt();

  // Bring the motor up to speed
  motor.LinearAccel(pos, 300);

  // Rotate the stepper 90 degrees
  stepper.rotate(90, HIGH);
}
