################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMERS/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/LED/subdir.mk
-include APPLICATION/subdir.mk
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
Again.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Again.elf secondary-outputs

# Tool invocations
Again.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Again.map -mmcu=atmega16 -o "Again.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Again.lss: Again.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Again.elf  >"Again.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Again.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Again.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Again.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
