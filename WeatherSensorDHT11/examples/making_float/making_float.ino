#include <WeatherSensor.h>
#include <WeatherSensorDHT11.h>

WeatherSensorDHT11 w(14);

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned char buf[5];
  w.readData(buf);
  Serial.print("The humdity = ");
  Serial.print(w.makeFloat((unsigned char *) &buf[0]), DEC);
  Serial.print("%, ");
  Serial.print("temperature = ");
  Serial.print(w.makeFloat((unsigned char *) &buf[2]), DEC);
  Serial.println("C  ");
  delay(1000);
}