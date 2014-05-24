/**
 * Arduino - Weather sensor
 * 
 * WeatherSensorDHT11.h
 * 
 * The class for the DHT11 weather sensor.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_WEATHER_SENSOR_DHT11_CPP__
#define __ARDUINO_DRIVER_WEATHER_SENSOR_DHT11_CPP__ 1

#include "WeatherSensorDHT11.h"

WeatherSensorDHT11::WeatherSensorDHT11(unsigned char dataPin) : dataPin(dataPin) {
    lastReadTime = millis() - MILLIS_BETWEEN_READS;
    lastCode = SUCCESS;
    pinMode(dataPin, OUTPUT);
    digitalWrite(dataPin, HIGH);
}

float WeatherSensorDHT11::makeFloat(unsigned char buf[2]) {
    float f = 0.0;
    f += *buf;
    f += *(buf + 1) / 256.0;
    return f;
}

unsigned char WeatherSensorDHT11::getHumidity() {
    if (isAvailable()) {
        lastCode = readData(this->buf);
    }
    return this->buf[0];
}

unsigned char WeatherSensorDHT11::getTemperature() {
    if (isAvailable()) {
        lastCode = readData(this->buf);
    }
    return this->buf[2];
}

bool WeatherSensorDHT11::isAvailable() {
    return (lastReadTime + MILLIS_BETWEEN_READS) <= millis();
}

WeatherSensorDHT11::Code WeatherSensorDHT11::readData(unsigned char buf[5]) {
    unsigned char in, checkSum;
    
    while (!isAvailable());
    lastReadTime = millis();
    
    digitalWrite(dataPin, LOW);
    delay(23);
    digitalWrite(dataPin, HIGH);
    delayMicroseconds(40);
    pinMode(dataPin, INPUT);
    delayMicroseconds(40);
    in = digitalRead(dataPin);
    if (in) {
        return ERROR_CONDITION1_NOT_MET;
    }
    delayMicroseconds(80);
    in = digitalRead(dataPin);
    if (!in) {
        return ERROR_CONDITION2_NOT_MET;
    }
    delayMicroseconds(80);
    for (unsigned char i = 0; i < 5; i++) {
        buf[i] = read();
    }
    pinMode(dataPin, OUTPUT);
    digitalWrite(dataPin, HIGH);
    checkSum = buf[0] + buf[1] + buf[2] + buf[3];
    if (buf[4] != checkSum) {
        return ERROR_CHECKSUM;
    }
    return SUCCESS;
}

unsigned char WeatherSensorDHT11::read() {
    unsigned char d = 0;
    for (unsigned char i = 0; i < 8; i++) {
        while (digitalRead(dataPin) == LOW);
        delayMicroseconds(30);
        if (digitalRead(dataPin) == HIGH) {
            d |= (1 << (7 - i));
        }
        while (digitalRead(dataPin) == HIGH);
    }
    return d;
}

#endif /* __ARDUINO_DRIVER_WEATHER_SENSOR_DHT11_CPP__ */
