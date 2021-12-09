################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/External_Interupts/Ex_Int.c 

OBJS += \
./MCAL/External_Interupts/Ex_Int.o 

C_DEPS += \
./MCAL/External_Interupts/Ex_Int.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/External_Interupts/%.o: ../MCAL/External_Interupts/%.c MCAL/External_Interupts/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


