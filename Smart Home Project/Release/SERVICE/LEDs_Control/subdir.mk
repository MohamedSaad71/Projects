################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/LEDs_Control/SERVICE_LEDS_Control.c 

OBJS += \
./SERVICE/LEDs_Control/SERVICE_LEDS_Control.o 

C_DEPS += \
./SERVICE/LEDs_Control/SERVICE_LEDS_Control.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/LEDs_Control/%.o: ../SERVICE/LEDs_Control/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


