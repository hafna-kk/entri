################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/bmp280.c \
../Drivers/Src/spi.c \
../Drivers/Src/stm32f401xx_gpio_driver.c \
../Drivers/Src/stm32f401xx_i2c_driver.c \
../Drivers/Src/stm32f401xx_rcc_driver.c \
../Drivers/Src/stm32f401xx_spi_driver.c \
../Drivers/Src/stm32f401xx_usart_driver.c 

OBJS += \
./Drivers/Src/bmp280.o \
./Drivers/Src/spi.o \
./Drivers/Src/stm32f401xx_gpio_driver.o \
./Drivers/Src/stm32f401xx_i2c_driver.o \
./Drivers/Src/stm32f401xx_rcc_driver.o \
./Drivers/Src/stm32f401xx_spi_driver.o \
./Drivers/Src/stm32f401xx_usart_driver.o 

C_DEPS += \
./Drivers/Src/bmp280.d \
./Drivers/Src/spi.d \
./Drivers/Src/stm32f401xx_gpio_driver.d \
./Drivers/Src/stm32f401xx_i2c_driver.d \
./Drivers/Src/stm32f401xx_rcc_driver.d \
./Drivers/Src/stm32f401xx_spi_driver.d \
./Drivers/Src/stm32f401xx_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/hafna/Desktop/Embedded system/STM32/DriverDev/Drivers/Inc" -I"C:/Users/hafna/Desktop/Embedded system/STM32/DriverDev/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/bmp280.cyclo ./Drivers/Src/bmp280.d ./Drivers/Src/bmp280.o ./Drivers/Src/bmp280.su ./Drivers/Src/spi.cyclo ./Drivers/Src/spi.d ./Drivers/Src/spi.o ./Drivers/Src/spi.su ./Drivers/Src/stm32f401xx_gpio_driver.cyclo ./Drivers/Src/stm32f401xx_gpio_driver.d ./Drivers/Src/stm32f401xx_gpio_driver.o ./Drivers/Src/stm32f401xx_gpio_driver.su ./Drivers/Src/stm32f401xx_i2c_driver.cyclo ./Drivers/Src/stm32f401xx_i2c_driver.d ./Drivers/Src/stm32f401xx_i2c_driver.o ./Drivers/Src/stm32f401xx_i2c_driver.su ./Drivers/Src/stm32f401xx_rcc_driver.cyclo ./Drivers/Src/stm32f401xx_rcc_driver.d ./Drivers/Src/stm32f401xx_rcc_driver.o ./Drivers/Src/stm32f401xx_rcc_driver.su ./Drivers/Src/stm32f401xx_spi_driver.cyclo ./Drivers/Src/stm32f401xx_spi_driver.d ./Drivers/Src/stm32f401xx_spi_driver.o ./Drivers/Src/stm32f401xx_spi_driver.su ./Drivers/Src/stm32f401xx_usart_driver.cyclo ./Drivers/Src/stm32f401xx_usart_driver.d ./Drivers/Src/stm32f401xx_usart_driver.o ./Drivers/Src/stm32f401xx_usart_driver.su

.PHONY: clean-Drivers-2f-Src

