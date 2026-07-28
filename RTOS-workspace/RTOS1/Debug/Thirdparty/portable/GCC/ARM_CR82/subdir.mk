################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/GCC/ARM_CR82/mpu_wrappers_v2_asm.c \
../Thirdparty/portable/GCC/ARM_CR82/port.c 

S_UPPER_SRCS += \
../Thirdparty/portable/GCC/ARM_CR82/portASM.S 

OBJS += \
./Thirdparty/portable/GCC/ARM_CR82/mpu_wrappers_v2_asm.o \
./Thirdparty/portable/GCC/ARM_CR82/port.o \
./Thirdparty/portable/GCC/ARM_CR82/portASM.o 

S_UPPER_DEPS += \
./Thirdparty/portable/GCC/ARM_CR82/portASM.d 

C_DEPS += \
./Thirdparty/portable/GCC/ARM_CR82/mpu_wrappers_v2_asm.d \
./Thirdparty/portable/GCC/ARM_CR82/port.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/ARM_CR82/%.o Thirdparty/portable/GCC/ARM_CR82/%.su Thirdparty/portable/GCC/ARM_CR82/%.cyclo: ../Thirdparty/portable/GCC/ARM_CR82/%.c Thirdparty/portable/GCC/ARM_CR82/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Thirdparty/portable/GCC/ARM_CR82/%.o: ../Thirdparty/portable/GCC/ARM_CR82/%.S Thirdparty/portable/GCC/ARM_CR82/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-ARM_CR82

clean-Thirdparty-2f-portable-2f-GCC-2f-ARM_CR82:
	-$(RM) ./Thirdparty/portable/GCC/ARM_CR82/mpu_wrappers_v2_asm.cyclo ./Thirdparty/portable/GCC/ARM_CR82/mpu_wrappers_v2_asm.d ./Thirdparty/portable/GCC/ARM_CR82/mpu_wrappers_v2_asm.o ./Thirdparty/portable/GCC/ARM_CR82/mpu_wrappers_v2_asm.su ./Thirdparty/portable/GCC/ARM_CR82/port.cyclo ./Thirdparty/portable/GCC/ARM_CR82/port.d ./Thirdparty/portable/GCC/ARM_CR82/port.o ./Thirdparty/portable/GCC/ARM_CR82/port.su ./Thirdparty/portable/GCC/ARM_CR82/portASM.d ./Thirdparty/portable/GCC/ARM_CR82/portASM.o

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-ARM_CR82

