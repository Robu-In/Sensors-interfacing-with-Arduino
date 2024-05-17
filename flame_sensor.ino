
int flame_sensor_pin = 4;       // initializing pin 4 as the sensor output pin
int buzzer_pin = 3;             // initializing pin 3 as the buzzer pin
int led_pin = 2;                // initializing the pin 2 as the led pin
 
int flame_pin = HIGH;           // state of sensor
 
 
void setup()
{
  pinMode(led_pin, OUTPUT);             // declaring led pin as output pin
  pinMode(flame_sensor_pin, INPUT);     // declaring sensor pin as input pin for Arduino
  pinMode(buzzer_pin, OUTPUT);          // declaring buzzer pin as output pin
  Serial.begin(9600);                   // setting baud rate at 9600
}
 
 
void loop()
{
  flame_pin = digitalRead(flame_sensor_pin);          // reading from the sensor
  if (flame_pin == HIGH)                               // applying condition
  {
    Serial.println("FLAME, FLAME, FLAME");
    digitalWrite(led_pin, HIGH);                      // if state is high, then turn high the led
    playMelody();                                     // play a melody on the buzzer
  }
  else
  {
    Serial.println("no flame");
    digitalWrite(led_pin, LOW);                       // otherwise turn it low
    noTone(buzzer_pin);                               // stop playing any tone
  }
}
 
 
void playMelody()
{
  // Play a simple melody: C4, E4, G4, C5
  tone(buzzer_pin, 262, 200);             // C4
  delay(200);
  tone(buzzer_pin, 330, 200);             // E4
  delay(200);
  tone(buzzer_pin, 392, 200);             // G4
  delay(200);
  tone(buzzer_pin, 523, 200);             // C5
  delay(200);
}