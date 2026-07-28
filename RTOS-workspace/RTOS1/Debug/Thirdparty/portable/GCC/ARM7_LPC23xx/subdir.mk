################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/GCC/ARM7_LPC23xx/port.c \
../Thirdparty/portable/GCC/ARM7_LPC23xx/portISR.c 

OBJS += \
./Thirdparty/portable/GCC/ARM7_LPC23xx/port.o \
./Thirdparty/portable/GCC/ARM7_LPC23xx/portISR.o 

C_DEPS += \
./Thirdparty/portable/GCC/ARM7_LPC23xx/port.d \
./Thirdparty/portable/GCC/ARM7_LPC23xx/portISR.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/ARM7_LPC23xx/%.o Thirdparty/portable/GCC/ARM7_LPC23xx/%.su Thirdparty/portable/GCC/ARM7_LPC23xx/%.cyclo: ../Thirdparty/portable/GCC/ARM7_LPC23xx/%.c Thirdparty/portable/GCC/ARM7_LPC23xx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-ARM7_LPC23xx

clean-Thirdparty-2f-portable-2f-GCC-2f-ARM7_LPC23xx:
	-$(RM) ./Thirdparty/portable/GCC/ARM7_LPC23xx/port.cyclo ./Thirdparty/portable/GCC/ARM7_LPC23xx/port.d ./Thirdparty/portable/GCC/ARM7_LPC23xx/port.o ./Thirdparty/portable/GCC/ARM7_LPC23xx/port.su ./Thirdparty/portable/GCC/ARM7_LPC23xx/portISR.cyclo ./Thirdparty/portable/GCC/ARM7_LPC23xx/portISR.d ./Thirdparty/portable/GCC/ARM7_LPC23xx/portISR.o ./Thirdparty/portable/GCC/ARM7_LPC23xx/portISR.su

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-ARM7_LPC23xx

