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

/**
 * The time between consecutive reads.
 * 
 * @param dataPin
 */
#define MILLIS_BETWEEN_READS    800

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
    
public:
    
    enum Code {
        SUCCESS = 0x00,
        ERROR_CHECKSUM = 0x01,
        ERROR_CONDITION1_NOT_MET = 0x02,
        ERROR_CONDITION2_NOT_MET = 0x04
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
    unsigned char getHumidity();

    /**
     * Returns the temperature.
     * 
     * @retun               The temperature.
     */
    unsigned char getTemperature();
    
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
    Code readData(unsigned char buf[5]);
    
    /**
     * Makes a float number from a read data.
     * 
     * @param i         The read data.
     * @return          The float conversion.
     */
    float makeFloat(unsigned char* i);
    
    /**
     * Return true if the device is available for a read operation.
     * 
     * @return 
     */
    bool isAvailable();
    
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
     * Reads a byte from the device.
     * 
     * @return 
     */
    unsigned char read();
};

#endif /* __ARDUINO_DRIVER_WEATHER_SENSOR_DHT11_H__ */
