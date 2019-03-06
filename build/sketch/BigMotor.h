/*
  BigMotor.h - Library for controlling the Victor SPX.
  Created by Matt Hall, March 4, 2019.
  Released into the public domain.
*/
#ifndef BigMotor_h
#define BigMotor_h

#include <Servo.h>
#include "Arduino.h"

class BigMotor
{
public:
  BigMotor(int pin);
  void rotate(int speed, bool dir);

private:
  int _pin;
  Servo _motor;
};

#endif
