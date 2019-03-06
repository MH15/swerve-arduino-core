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

BigMotor::BigMotor(int t)
{
//  Serial.print("loaded motor");
//  Servo _motor;
//  _motor.attach(pin);
//  _motor.write(98);
  int _speed = 0;
}


void BigMotor::pin(int pin){
  Serial.println("attaching motor");
  _motor.attach(pin);
//  _motor.write(98);
}


/**
 * Rotate the motor at given speed and direction instantly
 * @param {int} speed: how fast the motor turns, -100 being full throttle
 *    backwards, 0 being stopped and 100 being full throttle forwards
 * @param {bool} dir: true to rotate clockwise, false to rotate
 *    counter-clockwise
 */
void BigMotor::rotate(int speed)
{
  // bounds limiting
  // To Do: pass by reference to another library limit(&speed, 100)
  if (speed > 100)
  {
    speed = 100;
  }
  else if (speed < -100)
  {
    speed = -100;
  }

  // store the (valid) speed
  _speed = speed;

  int pwm_signal = stop_signal;
  double percent = (double)speed / 100;
  int range;

  // clockwise elses counter-clockwise
  if (speed >= 0)
  {
    range = max_signal - stop_signal;
    pwm_signal = percent * range + stop_signal;
  }
  else
  {
    range = stop_signal - min_signal;
    pwm_signal = stop_signal - percent * range;
  }
//  Serial.print("speed: " + (String)speed);
//  Serial.println("; pwm: " + (String)pwm_signal);
  _motor.write(pwm_signal);
}

/**
 * Accelerate the motor linearaly over a duration
 * @param {int} speed: the speed to accelerate to
 * @param {int} duration_ms: how long the transition should take
 */
void BigMotor::LinearAccel(int speed, int duration_ms)
{
  Serial.println("accel to: " + (String)speed);
  int last_speed = _speed;
  int range = speed - last_speed;

  for (int i = 0; i < duration_ms; i++)
  {
    double percent = (double)i / (double)duration_ms;
    delay(1);
    speed = last_speed + range * percent;
    // change the revolve speed every step to make a transition
    rotate(speed);
  }

  // store the new speed
  _speed = speed;
  Serial.println("done accel");
}
