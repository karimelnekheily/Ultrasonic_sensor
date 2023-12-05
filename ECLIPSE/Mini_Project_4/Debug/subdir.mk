################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO.c \
../ICU.c \
../LCD.c \
../Mini_project4_karim.c \
../ULTRASONIC.c 

OBJS += \
./GPIO.o \
./ICU.o \
./LCD.o \
./Mini_project4_karim.o \
./ULTRASONIC.o 

C_DEPS += \
./GPIO.d \
./ICU.d \
./LCD.d \
./Mini_project4_karim.d \
./ULTRASONIC.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


