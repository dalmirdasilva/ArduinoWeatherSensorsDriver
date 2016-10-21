/**
 * Arduino - Weather sensor
 * 
 * The class for the MPU9250.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_WEATHER_SENSOR_MPU9250_H__
#define __ARDUINO_DRIVER_WEATHER_SENSOR_MPU9250_H__ 1

#include <Arduino.h>
#include <WeatherSensor.h>
#include <RegisterBasedWiredDevice.h>

#define MPU9250_ADDRESS 0x68

/**
 * Other industry-leading features include on-chip 16-bit ADCs, programmable digital filters, a precision clock
 * with 1% drift from -40°C to 85°C, an embedded temperature sensor, and programmable interrupts.
 * The device features I2C and SPI serial interfaces, a VDD operating range of 1.71 to 3.6V, and a separate digital
 * IO supply, VDDIO from 1.71V to 3.6V.
 *
 * An on-chip temperature sensor and ADC are used to measure the MPU-6500 die temperature. The readings
 * from the ADC can be read from the FIFO or the Sensor Data registers.
 */
class WeatherSensorMPU9250 : public WeatherSensor, public RegisterBasedWiredDevice {
public:

    enum Register {
        PWR_MGMT_1 = 0x6b,
        PWR_MGMT_2 = 0x6c,
        TEMP_OUT_H = 0x41,
        TEMP_OUT_L = 0x42
    };

    WeatherSensorMPU9250(bool ad0);

    /**
     * Returns the air humidity.
     *
     * NOTE: Not implemented.
     *
     * @retun               The air humidity.
     */
    float getHumidity() {
        return 0.0;
    }

    /**
     * Returns the temperature.
     *
     * @retun               The temperature.
     */
    float getTemperature();

    float convertToDegreeCelsius(unsigned char *buf);
};

#endif /* __ARDUINO_DRIVER_WEATHER_SENSOR_MPU9250_H__ */
