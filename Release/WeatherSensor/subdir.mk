################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../WeatherSensor/WeatherSensor.cpp 

OBJS += \
./WeatherSensor/WeatherSensor.o 

CPP_DEPS += \
./WeatherSensor/WeatherSensor.d 


# Each subdirectory must supply rules for building sources it contributes
WeatherSensor/%.o: ../WeatherSensor/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard -I"/storage/microcontroller/arduino/driver/sensor/weather/WeatherSensor" -I"/storage/microcontroller/arduino/driver/sensor/weather/WeatherSensorDHT11" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


