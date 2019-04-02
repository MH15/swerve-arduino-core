/*
  Step.c - Library for controlling A4988 drivers.
  Created by Matt Hall, Februrary 19, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Step.h"

Step::Step(int test)
{
  int test2 = test + 1;
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

  int pulses = (deg / (float)360) * stepsPerRev;

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

/**
 * Run the stepper to angleToApproach then hold
 */
void Step::run()
{
  while (abs(angleToApproach - currentAngle) > 0)
  {
    int dir;
    if (angleToApproach > currentAngle)
    {
      dir = HIGH;
      currentAngle++;
    }
    else
    {
      dir = LOW;
      currentAngle--;
    }

    // set direction
    digitalWrite(_dirPin, dir);

    digitalWrite(_stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(_stepPin, LOW);
    delayMicroseconds(500);
  }
}
/**
 * Set the angleToApproach that the motor shoudl gradually attain
 * @param {int} deg: angle in degrees [0, 360*n)
 */
void Step::setAngle(int deg)
{
  angleToApproach = deg;
}

/**
 * Set how many steps it takes to  make one full revolution of the stepper. By
 * default, stepsPerRev is 200, but gearing or belts are used on the stepper
 * there may be a need for changing how many steps belong in a full revolution.
 * @param {int} steps: the number of steps per full revolution
 */
void Step::setStepsPerRev(int steps)
{
  if (steps > 0)
  {
    stepsPerRev = steps;
  }
}