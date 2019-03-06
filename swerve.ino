
#include "BigMotor.h"
#include "Step.h"

// defines pins numbers
const int stepPin = 3;
const int dirPin = 4;
const int victor_pin = 5;

// Declare the steppers
//Step stepper(stepPin, dirPin);
//BigMotor victor(victor_pin);

BigMotor motor(9);

//#include <Servo.h>

//Servo talon;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  // wait for serial port to connect. Needed for native USB port only
  while (!Serial)
    ;

  delay(2000);
  Serial.println("SETUP");
  motor.pin(victor_pin);
}

void loop()
{
  while (Serial.available() == 0)
    ;

  String input = Serial.readString();
  // input = input.substring(0, input.length()-1); only if in Arduino IDE

  int pos = input.toInt();
  //  motor.rotate(pos);
  motor.LinearAccel(pos, 300);

  //  v.pin(6);
  //  Serial.write(val);

  //  digitalWrite(LED_BUILTIN, LOW);
  //  Serial.print("heyoooo");
  //  while (Serial.available() == 0)
  //  {
  //    ;
  //  }
  //  digitalWrite(LED_BUILTIN, HIGH);
  //
  //  String input = Serial.readString();
  //  input = input.substring(0, input.length() - 1);
  //  Serial.print("you wrote: " + input);
  //
  //  // start the motor
  //  int speed = input.toInt();
  //  victor.rotate(speed);
  //
  //  // rotate the stepper 90 degrees
  ////  stepper.rotate(90, HIGH);
  //
  //  // wait two seconds then turn off the motor
  //  delay(2000);
  //  victor.rotate(0);
}
