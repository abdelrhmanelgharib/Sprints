################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/I2C/I2C_Program.c 

OBJS += \
./MCAL/I2C/I2C_Program.o 

C_DEPS += \
./MCAL/I2C/I2C_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/I2C/%.o: ../MCAL/I2C/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\iti 3 month\iti avr workspace\BCM\SERVICE" -I"D:\iti 3 month\iti avr workspace\BCM\MCAL\DIO" -I"D:\iti 3 month\iti avr workspace\BCM\MCAL\I2C" -I"D:\iti 3 month\iti avr workspace\BCM\APP" -I"D:\iti 3 month\iti avr workspace\BCM\lib" -I"D:\iti 3 month\iti avr workspace\BCM\MCAL\SPI" -I"D:\iti 3 month\iti avr workspace\BCM\MCAL\UART" -I"D:\iti 3 month\iti avr workspace\BCM\SERVICE\SER_UART" -I"D:\iti 3 month\iti avr workspace\BCM\SERVICE\SER_UART" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\BCM\BCM" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


