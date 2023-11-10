################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SERVICE/TempControl/subdir.mk
-include SERVICE/SET_ON_FLAG/subdir.mk
-include SERVICE/OpenDoor/subdir.mk
-include SERVICE/LockHouse/subdir.mk
-include SERVICE/LEDs_Control/subdir.mk
-include SERVICE/EnterPass/subdir.mk
-include SERVICE/EVERYTHING_ON/subdir.mk
-include SERVICE/DisplayDateTime/subdir.mk
-include SERVICE/CurtainsSetFlag/subdir.mk
-include SERVICE/CheckIR/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer1/subdir.mk
-include MCAL/Timer0/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/EXT/subdir.mk
-include MCAL/EEPROM/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Solenoid/subdir.mk
-include HAL/SERVO/subdir.mk
-include HAL/RTC/subdir.mk
-include HAL/Password/subdir.mk
-include HAL/PIR/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LDR/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KeyPad/subdir.mk
-include HAL/IR/subdir.mk
-include HAL/DC\ TRIAL/DC\ TRIAL/Debug/subdir.mk
-include HAL/DC\ TRIAL/DC\ TRIAL/subdir.mk
-include HAL/Buzzrer/subdir.mk
-include HAL/Button/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVR_Project.lss \
AVR_Project.lss \
AVR_Project.lss \
AVR_Project.lss \
AVR_Project.lss \
AVR_Project.lss \
AVR_Project.lss \
AVR_Project.lss \
AVR_Project.lss \
AVR_Project.lss \
AVR_Project.lss \

FLASH_IMAGE += \
AVR_Project.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \
sizedummy \
sizedummy \
sizedummy \
sizedummy \
sizedummy \
sizedummy \
sizedummy \
sizedummy \
sizedummy \


# All Target
all: AVR_Project.elf secondary-outputs

# Tool invocations
AVR_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_Project.map -mmcu=atmega32 -o "AVR_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_Project.lss: AVR_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_Project.elf  >"AVR_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_Project.hex: AVR_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_Project.elf  "AVR_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
