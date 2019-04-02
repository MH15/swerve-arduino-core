/*
  Step.c - Library for controlling A4988 drivers.
  Created by Matt Hall, Februrary 19, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Step.h"

#define STEPS_PER_REV 200

Step::Step(int test)
{
  int test2 = test + 1;
  angle = 0;
  position = 0;
}

/**
 * Attach the Step object to given pins
 * @param {int} stepPin: a PWM pin for the step control
 * @param {int} dirPin: a PWM pin for the direction control
 */
void Step::pin(int stepPin, int dirPin)
{
  Serial.println("Loading Stepper on pin " + (String)stepPin + ".");
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  _stepPin = stepPin;
  _dirPin = dirPin;
}

/**
 * Rotate the stepper a certain amount and direction
 * @param {int} deg: the degrees to turn the stepper
 * @param {int} dir: the direction in which to rotate, 
 *    HIGH is counterclockwise and LOW is clockwise
 */
void Step::rotate(int deg, int dir)
{

  int pulses = (deg / (float)360) * STEPS_PER_REV;

  digitalWrite(_dirPin, dir);
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < pulses; x++)
  {
    digitalWrite(_stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(_stepPin, LOW);
    delayMicroseconds(500);
  }
}

void Step::run()
{
  while (abs(angle - position) > 0)
  {
    int dir;
    if (angle > position)
    {
      dir = HIGH;
      position++;
    }
    else
    {
      dir = LOW;
      position--;
    }

    // set direction
    digitalWrite(_dirPin, dir);

    digitalWrite(_stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(_stepPin, LOW);
    delayMicroseconds(500);
  }
}

void Step::setAngle(int deg)
{
  angle = deg;
}
