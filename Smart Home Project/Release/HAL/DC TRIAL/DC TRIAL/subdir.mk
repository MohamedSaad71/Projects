################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/DC\ TRIAL/DC\ TRIAL/DCMOTOR_Prog.c \
../HAL/DC\ TRIAL/DC\ TRIAL/DIO.c 

OBJS += \
./HAL/DC\ TRIAL/DC\ TRIAL/DCMOTOR_Prog.o \
./HAL/DC\ TRIAL/DC\ TRIAL/DIO.o 

C_DEPS += \
./HAL/DC\ TRIAL/DC\ TRIAL/DCMOTOR_Prog.d \
./HAL/DC\ TRIAL/DC\ TRIAL/DIO.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/DC\ TRIAL/DC\ TRIAL/DCMOTOR_Prog.o: ../HAL/DC\ TRIAL/DC\ TRIAL/DCMOTOR_Prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/DC TRIAL/DC TRIAL/DCMOTOR_Prog.d" -MT"HAL/DC\ TRIAL/DC\ TRIAL/DCMOTOR_Prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/DC\ TRIAL/DC\ TRIAL/DIO.o: ../HAL/DC\ TRIAL/DC\ TRIAL/DIO.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/DC TRIAL/DC TRIAL/DIO.d" -MT"HAL/DC\ TRIAL/DC\ TRIAL/DIO.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


