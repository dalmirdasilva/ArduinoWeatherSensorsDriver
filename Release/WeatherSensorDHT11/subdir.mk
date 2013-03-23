################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../WeatherSensorDHT11/WeatherSensorDHT11.cpp 

OBJS += \
./WeatherSensorDHT11/WeatherSensorDHT11.o 

CPP_DEPS += \
./WeatherSensorDHT11/WeatherSensorDHT11.d 


# Each subdirectory must supply rules for building sources it contributes
WeatherSensorDHT11/%.o: ../WeatherSensorDHT11/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard -I"/storage/microcontroller/arduino/driver/sensor/weather/WeatherSensor" -I"/storage/microcontroller/arduino/driver/sensor/weather/WeatherSensorDHT11" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


