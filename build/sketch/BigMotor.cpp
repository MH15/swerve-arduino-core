/*
  BigMotor.c - Library for controlling the Victor SPX.
  Created by Matt Hall, March 4, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
#include <Servo.h>
#include "BigMotor.h"

/* The 'Servo.h' library allows you to control motors and servos by passing any value between
0 and 180 into the "write" method (talon.write() in this program).
For a motor:   0 is full power in one direction,
             180 is full direction in the opposite direction,
              90 is stop.
For a servo:   0 is all the way one direction,
             180 is all the way in the opposite direction,
              90 is the middle.
*/

int max_signal = 180;
int stop_signal = 90;
int min_signal = 6;

int pos = 0;

BigMotor::BigMotor(int pin)
{
  Servo _motor;
  _motor.attach(pin);
}

/**
 * Rotate the motor at given speed and direction instantly
 * @param {int} speed: how fast the motor turns, 0 being stopped
 *    and 100 being full throttle
 * @param {bool} dir: true to rotate clockwise, false to rotate
 *    counter-clockwise
 */
void BigMotor::rotate(int speed, bool dir)
{

  int pwm_signal = stop_signal;
  double percent = (double)speed / 100;
  int range;

  // clockwise elses counter-clockwise
  if (dir)
  {
    range = max_signal - stop_signal;
    pwm_signal = percent * range + stop_signal;
  }
  else
  {
    range = stop_signal - min_signal;
    pwm_signal = stop_signal - percent * range;
  }

  _motor.write(pwm_signal);
}
