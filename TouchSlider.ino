#include <Wire.h>
#include "SparkFun_CAP1203.h" // Click here to get the library: http://librarymanager/All#SparkFun_CAP1203

CAP1203 sensor; // Initialize sensor
const int ledPinRight = 13; // Define the LED pin for right touch
const int ledPinMiddle = 12; // Define the LED pin for middle touch
const int ledPinLeft = 11; // Define the LED pin for left touch

void setup()
{
  Wire.begin();       // Join I2C bus
  Serial.begin(9600); // Start serial for output
  pinMode(ledPinRight, OUTPUT); // Set LED pin for right touch as output
  pinMode(ledPinMiddle, OUTPUT); // Set LED pin for middle touch as output
  pinMode(ledPinLeft, OUTPUT); // Set LED pin for left touch as output
  
  // Setup sensor
  if (sensor.begin() == false)
  {
    Serial.println("Not connected. Please check connections and read the hookup guide.");
    while (1)
      ;
  }
  else
  {
    Serial.println("Connected!");
  }
}

void loop()
{
  if (sensor.isLeftTouched() == true)
  {
    Serial.println("Left");
    digitalWrite(ledPinLeft, HIGH); // Turn on LED on pin 11
  }
  else
  {
    digitalWrite(ledPinLeft, LOW); // Turn off LED on pin 11
  }

  if (sensor.isMiddleTouched() == true)
  {
    Serial.println("Middle");
    digitalWrite(ledPinMiddle, HIGH); // Turn on LED on pin 12
  }
  else
  {
    digitalWrite(ledPinMiddle, LOW); // Turn off LED on pin 12
  }

  if (sensor.isRightTouched() == true)
  {
    Serial.println("Right");
    digitalWrite(ledPinRight, HIGH); // Turn on LED on pin 13
  }
  else
  {
    digitalWrite(ledPinRight, LOW); // Turn off LED on pin 13
  }
}
