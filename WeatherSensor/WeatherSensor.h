/**
 * Arduino - Weather sensor
 * 
 * WeatherSensor.h
 * 
 * The abstract class for the weather sensors.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_WEATHER_SENSOR_H__
#define __ARDUINO_DRIVER_WEATHER_SENSOR_H__ 1

class WeatherSensor {
public:

    /**
     * Returns the air humidity.
     * 
     * @retun               The air humidity.
     */
    virtual float getHumidity() = 0;

    /**
     * Returns the temperature.
     * 
     * @retun               The temperature.
     */
    virtual float getTemperature() = 0;
};

#endif /* __ARDUINO_DRIVER_WEATHER_SENSOR_H__ */
