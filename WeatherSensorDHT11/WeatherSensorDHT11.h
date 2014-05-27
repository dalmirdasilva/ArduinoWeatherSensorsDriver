/**
 * Arduino - Weather sensor
 * 
 * WeatherSensorDHT11.h
 * 
 * The class for the DHT11 weather sensor.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_WEATHER_SENSOR_DHT11_H__
#define __ARDUINO_DRIVER_WEATHER_SENSOR_DHT11_H__ 1

#include <WeatherSensor.h>
#include <Arduino.h>
#include <wiring_private.h>
#include <pins_arduino.h>

/**
 * The time between consecutive reads.
 * 
 * @param dataPin
 */
#define WEATHER_MILLIS_BETWEEN_READS            800

#define WEATHER_REQUEST_LOW_LENGTH              20
#define WEATHER_REQUEST_HIGH_LENGTH             40

#define WEATHER_RESPONSE_LOW_LENGTH             80
#define WEATHER_RESPONSE_HIGH_LENGTH            80

#define WEATHER_START_TRANSMIT_LENGTH           50

#define WEATHER_ZERO_LENGTH                     40
#define WEATHER_ONE_LENGTH                      70

class WeatherSensorDHT11 : public WeatherSensor {
    
    /**
     * A internal buffer.
     */
    unsigned char buf[5];
    
    /**
     * The data pin.
     */
    unsigned char dataPin;
    
    /**
     * The last read time.
     */
    unsigned long lastReadTime;
    
    /**
     * The last humity.
     */
    float lastHumity;

    /**
     * The last temperature.
     */
    float lastTemperature;

public:
    
    enum Code {
        SUCCESS = 0x00,
        ERROR_CHECKSUM = 0x01,
        ERROR_CONDITION1_NOT_MET = 0x02,
        ERROR_CONDITION2_NOT_MET = 0x04,
        ERROR_CONDITION3_NOT_MET = 0x08
    };
    
    /**
     * Public constructor
     * 
     * @param dataPin       The data pin.
     */
    WeatherSensorDHT11(unsigned char dataPin);

    /**
     * Returns the air humidity.
     * 
     * @retun               The air humidity.
     */
    float getHumidity();

    /**
     * Returns the temperature.
     * 
     * @retun               The temperature.
     */
    float getTemperature();
    
    /**
     * Gets the last read code.
     *
     * @return
     */
    Code getLastCode() {
        return lastCode;
    }

private:

    Code lastCode;

    /**
     * Reads 5 bytes from the device.
     * 
     * 1st byte: Integer part of the humidity.
     * 2nd byte: Fractional part of the humidity.
     * 3th byte: Integer part of the temperature.
     * 4th byte: Fractional part of the temperature.
     * 5th byte: Checksum.
     * 
     * @return          The error code.
     */
    Code readPackage(unsigned char *buf);

    /**
     * Makes a float number from a read data.
     * 
     * @param buf         The read data.
     * @return          The float conversion.
     */
    float makeFloat(unsigned char *buf);
    
    /**
     * Return true if the device is available for a read operation.
     * 
     * @return 
     */
    bool isAvailable();
    
    /**
     * Reads a byte from the device.
     * 
     * @return 
     */
    unsigned char read();

    /**
     * Waits for a given state on a input pin
     */
    unsigned long waitFor(unsigned char pin, unsigned char state, unsigned long timeout);
};

#endif /* __ARDUINO_DRIVER_WEATHER_SENSOR_DHT11_H__ */
