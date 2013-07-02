#include <WeatherSensor.h>
#include <WeatherSensorDHT11.h>

WeatherSensorDHT11 w(14);

void printError(WeatherSensorDHT11::Code code) {
  switch(code) {

    case WeatherSensorDHT11::ERROR_CHECKSUM:
      Serial.println("Error: Checksum mismatch.");

    case WeatherSensorDHT11::ERROR_CONDITION1_NOT_MET:
      Serial.println("Error: Condition 1 not met.");

    case WeatherSensorDHT11::ERROR_CONDITION2_NOT_MET:
      Serial.println("Error: Condition 2 not met.");

    default:
      Serial.println("Error: No idea!");
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  float b;

  b = w.getHumidity();
  if (w.getLastCode() != WeatherSensorDHT11::SUCCESS) {
    printError(w.getLastCode());
  } 
  else {
    Serial.print("The humdity = ");
    Serial.print(b);
    Serial.print("%, ");
  }

  b = w.getTemperature();
  if (w.getLastCode() != WeatherSensorDHT11::SUCCESS) {
    printError(w.getLastCode());
  } 
  else {
    Serial.print("temperature = ");
    Serial.print(b);
    Serial.println("C  ");
  }
  delay(1000);
}
