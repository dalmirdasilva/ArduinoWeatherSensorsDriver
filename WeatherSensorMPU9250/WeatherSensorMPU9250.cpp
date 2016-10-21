#include "WeatherSensorMPU9250.h"

WeatherSensorMPU9250::WeatherSensorMPU9250(bool ad0)
        : RegisterBasedWiredDevice(MPU9250_ADDRESS | (ad0 & 0x01)) {
}

float WeatherSensorMPU9250::getTemperature() {
    unsigned char buf[2];
    if (readRegisterBlock(TEMP_OUT_H, buf, 2) != 2) {
        return 0.0;
    }
    return convertToDegreeCelsius(buf);
    return 0.0;
}

float WeatherSensorMPU9250::convertToDegreeCelsius(unsigned char *buf) {
    float raw = (buf[0] << 8) | buf[1];
    return raw / 333.87 + 21.0;
}

