################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer1/Timer1_prog.c 

OBJS += \
./MCAL/Timer1/Timer1_prog.o 

C_DEPS += \
./MCAL/Timer1/Timer1_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer1/%.o: ../MCAL/Timer1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Mohamed\NTI\Embedded projects\AVR_Project\HAL\LCD" -I"C:\Ayaya\NTI 4 Month\EclipseProjects\AVR_Project\HAL\Password" -I"C:\Ayaya\NTI 4 Month\EclipseProjects\AVR_Project\HAL\RTC" -I"E:\Mohamed\NTI\Embedded projects\AVR_Project\MCAL\DIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


