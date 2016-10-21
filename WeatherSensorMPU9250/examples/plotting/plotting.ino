#include <Wire.h>
#include <WiredDevice.h>
#include <RegisterBasedWiredDevice.h>
#include <WeatherSensor.h>
#include <WeatherSensorMPU9250.h>

WeatherSensorMPU9250 weather(0);

unsigned char buf[2];
unsigned long now;

void setup() {
    Serial.begin(9600);
}

void loop() {
    weather.readRegisterBlock(WeatherSensorMPU9250::TEMP_OUT_H, buf, 2);
    Serial.write(0xaa);
    Serial.write(buf, 2);
    Serial.write(0x00);
    Serial.write(0x00);
    Serial.write(0x00);
    Serial.write(0x00);
    Serial.write(0x00);
    now = millis();
    Serial.write((unsigned char *) &now, 4);
    Serial.write(0xbb);
}