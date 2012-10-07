#include <WeatherSensor.h>
#include <WeatherSensorDHT11.h>

unsigned char buf[5];
WeatherSensorDHT11 w(14);

void setup() {
  Serial.begin(9600);
}

void loop() {
  w.readData(buf);
  Serial.print("The humdity = ");
  Serial.print(buf[0], DEC);
  Serial.print(".");
  Serial.print(buf[1], DEC);
  Serial.print("%, ");
  Serial.print("temperature = ");
  Serial.print(buf[2], DEC);
  Serial.print(".");
  Serial.print(buf[3], DEC);
  Serial.println("C  ");
  delay(2000);
}