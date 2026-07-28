################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/MemMang/heap_4.c 

OBJS += \
./Thirdparty/portable/MemMang/heap_4.o 

C_DEPS += \
./Thirdparty/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/MemMang/%.o Thirdparty/portable/MemMang/%.su Thirdparty/portable/MemMang/%.cyclo: ../Thirdparty/portable/MemMang/%.c Thirdparty/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Thirdparty-2f-portable-2f-MemMang

clean-Thirdparty-2f-portable-2f-MemMang:
	-$(RM) ./Thirdparty/portable/MemMang/heap_4.cyclo ./Thirdparty/portable/MemMang/heap_4.d ./Thirdparty/portable/MemMang/heap_4.o ./Thirdparty/portable/MemMang/heap_4.su

.PHONY: clean-Thirdparty-2f-portable-2f-MemMang

