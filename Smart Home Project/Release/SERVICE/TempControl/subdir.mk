################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/TempControl/TempControl.c 

OBJS += \
./SERVICE/TempControl/TempControl.o 

C_DEPS += \
./SERVICE/TempControl/TempControl.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/TempControl/%.o: ../SERVICE/TempControl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


