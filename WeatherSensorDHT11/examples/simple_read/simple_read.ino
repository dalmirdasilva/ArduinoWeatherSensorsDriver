#include <WeatherSensor.h>
#include <WeatherSensorDHT11.h>

WeatherSensorDHT11 w(14);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("The humdity = ");
  Serial.print(w.getHumidity());
  Serial.print("%, ");
  Serial.print("temperature = ");
  delay(2);
  Serial.print(w.getTemperature());
  Serial.println("C  ");
  delay(1000);
}
