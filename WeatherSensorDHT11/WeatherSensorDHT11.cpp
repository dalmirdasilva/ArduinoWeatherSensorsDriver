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

WeatherSensorDHT11::WeatherSensorDHT11(unsigned char dataPin) :
        dataPin(dataPin) {
    lastReadTime = millis() - WEATHER_MILLIS_BETWEEN_READS;
    lastHumity = 0.0;
    lastTemperature = 0.0;
    lastCode = SUCCESS;
    pinMode(dataPin, OUTPUT);
    digitalWrite(dataPin, HIGH);
}

WeatherSensorDHT11::~WeatherSensorDHT11() {
}

float WeatherSensorDHT11::getHumidity() {
    if (isAvailable()) {
        lastCode = readPackage(this->buf);
    }
    return lastHumity;
}

float WeatherSensorDHT11::getTemperature() {
    if (isAvailable()) {
        lastCode = readPackage(this->buf);
    }
    return lastTemperature;
}

bool WeatherSensorDHT11::isAvailable() {
    return (lastReadTime + WEATHER_MILLIS_BETWEEN_READS) <= millis();
}

WeatherSensorDHT11::Code WeatherSensorDHT11::readPackage(unsigned char *buf) {
    unsigned char checkSum;
    unsigned long m = 0;
    while (!isAvailable())
        ;
    lastReadTime = millis();
    pinMode(dataPin, OUTPUT);
    digitalWrite(dataPin, LOW);
    delay(WEATHER_REQUEST_LOW_LENGTH);
    digitalWrite(dataPin, HIGH);
    pinMode(dataPin, INPUT);
    m = waitFor(dataPin, LOW, WEATHER_REQUEST_HIGH_LENGTH);
    if (m == 0) {
        return ERROR_CONDITION1_NOT_MET;
    }
    m = waitFor(dataPin, HIGH, WEATHER_RESPONSE_LOW_LENGTH);
    if (m == 0) {
        return ERROR_CONDITION2_NOT_MET;
    }
    m = waitFor(dataPin, LOW, WEATHER_RESPONSE_HIGH_LENGTH);
    if (m == 0) {
        return ERROR_CONDITION3_NOT_MET;
    }
    for (unsigned char i = 0; i < 5; i++) {
        buf[i] = read();
    }
    pinMode(dataPin, OUTPUT);
    digitalWrite(dataPin, HIGH);
    checkSum = buf[0] + buf[1] + buf[2] + buf[3];
    if (buf[4] != checkSum) {
        return ERROR_CHECKSUM;
    }
    lastHumity = makeFloat(this->buf);
    lastTemperature = makeFloat(&(this->buf[2]));
    return SUCCESS;
}

unsigned char WeatherSensorDHT11::read() {
    unsigned char d = 0;
    unsigned long m = 0;
    for (unsigned char i = 0; i < 8; i++) {
        m = waitFor(dataPin, HIGH, WEATHER_START_TRANSMIT_LENGTH);
        if (m > 0) {
            m = waitFor(dataPin, LOW, WEATHER_ONE_LENGTH);
            if (m > WEATHER_ZERO_LENGTH) {
                d |= (1 << (7 - i));
            }
        }
    }
    return d;
}

unsigned long WeatherSensorDHT11::waitFor(unsigned char pin,
        unsigned char state, unsigned long timeout) {
    unsigned char bit = digitalPinToBitMask(pin);
    unsigned char port = digitalPinToPort(pin);
    unsigned char stateMask = (state ? bit : 0);
    unsigned long width = 0;
    unsigned long numloops = 0;
    unsigned long maxloops = microsecondsToClockCycles(timeout) / 16;
    while ((*portInputRegister(port) & bit) != stateMask) {
        if (numloops++ == maxloops) {
            return 0;
        }
        width++;
    }
    return clockCyclesToMicroseconds(width * 21 + 8);
}

float WeatherSensorDHT11::makeFloat(unsigned char *buf) {
    float f = 0.0;
    f += *buf;
    f += *(buf + 1) / 256.0;
    return f;
}

#endif /* __ARDUINO_DRIVER_WEATHER_SENSOR_DHT11_CPP__ */
