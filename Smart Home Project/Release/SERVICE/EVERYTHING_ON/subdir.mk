################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/EVERYTHING_ON/EverythingOn.c 

OBJS += \
./SERVICE/EVERYTHING_ON/EverythingOn.o 

C_DEPS += \
./SERVICE/EVERYTHING_ON/EverythingOn.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/EVERYTHING_ON/%.o: ../SERVICE/EVERYTHING_ON/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


