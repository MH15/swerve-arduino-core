/*
  Step.h - Library for controlling A4988 drivers.
  Created by Matt Hall, Februrary 19, 2019.
  Released into the public domain.
*/
#ifndef Step_h
#define Step_h

#include "Arduino.h"

/**
 * Configuration variables
 */
const int ANGLE_DEFAULT = 0;
const int STEPS_PER_REVOLUTION = 200;

class Step
{
public:
  Step(int test);
  void pin(int stepPin, int dirPin);
  void rotate(int deg, int dir);

  void setStepsPerRev(int steps);
  void setAngle(int deg);
  void run();

  int angleToApproach = ANGLE_DEFAULT;
  int stepsPerRev = STEPS_PER_REVOLUTION;

private:
  int _stepPin;
  int _dirPin;
  int currentAngle = ANGLE_DEFAULT;
};

#endif
