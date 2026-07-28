################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/GCC/MSP430F449/port.c 

OBJS += \
./Thirdparty/portable/GCC/MSP430F449/port.o 

C_DEPS += \
./Thirdparty/portable/GCC/MSP430F449/port.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/MSP430F449/%.o Thirdparty/portable/GCC/MSP430F449/%.su Thirdparty/portable/GCC/MSP430F449/%.cyclo: ../Thirdparty/portable/GCC/MSP430F449/%.c Thirdparty/portable/GCC/MSP430F449/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-MSP430F449

clean-Thirdparty-2f-portable-2f-GCC-2f-MSP430F449:
	-$(RM) ./Thirdparty/portable/GCC/MSP430F449/port.cyclo ./Thirdparty/portable/GCC/MSP430F449/port.d ./Thirdparty/portable/GCC/MSP430F449/port.o ./Thirdparty/portable/GCC/MSP430F449/port.su

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-MSP430F449

