/*
  Step.h - Library for controlling A4988 drivers.
  Created by Matt Hall, Februrary 19, 2019.
  Released into the public domain.
*/
#ifndef Step_h
#define Step_h

#include "Arduino.h"

class Step
{
public:
  Step(int test);
  void pin(int stepPin, int dirPin);
  void rotate(int deg, int dir);

private:
  int _stepPin;
  int _dirPin;
};

#endif
