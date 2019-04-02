/*
  BigMotor.h - Library for controlling the Victor SPX.
  Created by Matt Hall, March 4, 2019.
  Released into the public domain.
*/
#ifndef BigMotor_h
#define BigMotor_h

#include "Arduino.h"
#include <Servo.h>

/**
 * Configuration variables
 */
const int SPEED_MIN_MAX[] = {-100, 100};
const int SPEED_DEFAULT = 0;
const int ACCEL_MIN_MAX[] = {0, 100};
const int ACCEL_DEFAULT = 1;

class BigMotor
{
public:
  BigMotor(int t);
  void pin(int pin);
  void rotate(int speed);
  void LinearAccel(int speed, int duration_ms);

  void setSpeed(int speed);
  void setAcceleration(int accel);
  void run();

  int speedToApproach = SPEED_DEFAULT;
  int acceleration = ACCEL_DEFAULT;

private:
  int _pin;
  int _speed;
  int currentSpeed = SPEED_DEFAULT;
  Servo _motor;
};

#endif
