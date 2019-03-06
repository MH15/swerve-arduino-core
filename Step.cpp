/*
  Step.c - Library for controlling A4988 drivers.
  Created by Matt Hall, Februrary 19, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Step.h"

Step::Step(int stepPin, int dirPin)
{
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  _stepPin = stepPin;
  _dirPin = dirPin;
}

#define STEPS_PER_REV 200

void Step::rotate(int degrees, int dir)
{
  // Set direction of the rotation
  digitalWrite(_dirPin, dir);

  int pulses = (degrees / 360) * STEPS_PER_REV;
  for (int x = 0; x < pulses; x++)
  {
    digitalWrite(_stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(_stepPin, LOW);
    delayMicroseconds(500);
  }
}
