/*
  BigMotor.h - Library for controlling the Victor SPX.
  Created by Matt Hall, March 4, 2019.
  Released into the public domain.
*/
#ifndef BigMotor_h
#define BigMotor_h

#include "Arduino.h"
#include <Servo.h>

class BigMotor
{
public:
  BigMotor(int t);
  void pin(int pin);
  void rotate(int speed);
  void LinearAccel(int speed, int duration_ms);

private:
  int _pin;
  int _speed;
  Servo _motor;
};

#endif
