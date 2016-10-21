#include <Wire.h>
#include <WiredDevice.h>
#include <RegisterBasedWiredDevice.h>
#include <WeatherSensor.h>
#include <WeatherSensorMPU9250.h>

WeatherSensorMPU9250 weather(0);

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println(weather.getTemperature());
    delay(1000);
}
