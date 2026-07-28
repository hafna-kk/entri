################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/GCC/NiosII/port.c 

S_UPPER_SRCS += \
../Thirdparty/portable/GCC/NiosII/port_asm.S 

OBJS += \
./Thirdparty/portable/GCC/NiosII/port.o \
./Thirdparty/portable/GCC/NiosII/port_asm.o 

S_UPPER_DEPS += \
./Thirdparty/portable/GCC/NiosII/port_asm.d 

C_DEPS += \
./Thirdparty/portable/GCC/NiosII/port.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/NiosII/%.o Thirdparty/portable/GCC/NiosII/%.su Thirdparty/portable/GCC/NiosII/%.cyclo: ../Thirdparty/portable/GCC/NiosII/%.c Thirdparty/portable/GCC/NiosII/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Thirdparty/portable/GCC/NiosII/%.o: ../Thirdparty/portable/GCC/NiosII/%.S Thirdparty/portable/GCC/NiosII/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-NiosII

clean-Thirdparty-2f-portable-2f-GCC-2f-NiosII:
	-$(RM) ./Thirdparty/portable/GCC/NiosII/port.cyclo ./Thirdparty/portable/GCC/NiosII/port.d ./Thirdparty/portable/GCC/NiosII/port.o ./Thirdparty/portable/GCC/NiosII/port.su ./Thirdparty/portable/GCC/NiosII/port_asm.d ./Thirdparty/portable/GCC/NiosII/port_asm.o

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-NiosII

