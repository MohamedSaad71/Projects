################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/Garage/DIO.c \
../SERVICE/Garage/GARAGE.c \
../SERVICE/Garage/LCD.c \
../SERVICE/Garage/Ultrasonic_Prog.c 

OBJS += \
./SERVICE/Garage/DIO.o \
./SERVICE/Garage/GARAGE.o \
./SERVICE/Garage/LCD.o \
./SERVICE/Garage/Ultrasonic_Prog.o 

C_DEPS += \
./SERVICE/Garage/DIO.d \
./SERVICE/Garage/GARAGE.d \
./SERVICE/Garage/LCD.d \
./SERVICE/Garage/Ultrasonic_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/Garage/%.o: ../SERVICE/Garage/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


