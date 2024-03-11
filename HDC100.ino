#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_HDC1000.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define HDC_SDA 4
#define HDC_SCL 5

Adafruit_HDC1000 hdc;

Adafruit_SSD1306 display = Adafruit_SSD1306();

void setup() {
  Serial.begin(9600);
  Serial.println(F("HDC100 test"));


  // initialize with the I2C addr 0x3C (for the 128x32)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(100);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  if (!hdc.begin()) {
    Serial.println("Could not find a valid HDC100 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  display.setCursor(0, 0);
  display.clearDisplay();

  float temperature = hdc.readTemperature();
  float humidity = hdc.readHumidity();

  Serial.print("Temperature = "); Serial.print(temperature); Serial.println(" *C");
  display.print("Temperature: "); display.print(temperature); display.println(" *C");

  Serial.print("Humidity = "); Serial.print(humidity); Serial.println(" %");
  display.print("Humidity: "); display.print(humidity); display.println(" %");

  Serial.println();
  display.display();
  delay(2000);
}
