# 1 "/Users/matthewhall/Documents/Arduino/serial_victor/serial_victor.ino"
# 1 "/Users/matthewhall/Documents/Arduino/serial_victor/serial_victor.ino"

# 3 "/Users/matthewhall/Documents/Arduino/serial_victor/serial_victor.ino" 2
# 4 "/Users/matthewhall/Documents/Arduino/serial_victor/serial_victor.ino" 2

// defines pins numbers
const int stepPin = 3;
const int dirPin = 4;
const int victor_pin = 5;

// Declare the steppers
Step stepper(stepPin, dirPin);
BigMotor victor(victor_pin);

void setup()
{
  Serial.begin(9600);
  // wait for serial port to connect. Needed for native USB port only
  while (!Serial)
  {
    ;
  }
}

void loop()
{
  while (Serial.available() == 0)
  {
    ;
  }

  String input = Serial.readString();
  input = input.substring(0, input.length() - 1);

  // start the motor
  int speed = input.toInt();
  victor.rotate(speed, 0x1);

  // rotate the stepper 90 degrees
  stepper.rotate(90, 0x1);

  // wait two seconds then turn off the motor
  delay(2000);
  victor.rotate(0, 0x1);
}
