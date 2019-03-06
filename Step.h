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
  Step(int stepPin, int dirPin);
  void rotate(int degrees, int dir);

private:
  int _stepPin;
  int _dirPin;
};

#endif
