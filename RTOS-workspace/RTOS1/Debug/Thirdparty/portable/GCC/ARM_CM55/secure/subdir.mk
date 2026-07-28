################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/GCC/ARM_CM55/secure/secure_context.c \
../Thirdparty/portable/GCC/ARM_CM55/secure/secure_context_port.c \
../Thirdparty/portable/GCC/ARM_CM55/secure/secure_heap.c \
../Thirdparty/portable/GCC/ARM_CM55/secure/secure_init.c 

OBJS += \
./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context.o \
./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context_port.o \
./Thirdparty/portable/GCC/ARM_CM55/secure/secure_heap.o \
./Thirdparty/portable/GCC/ARM_CM55/secure/secure_init.o 

C_DEPS += \
./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context.d \
./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context_port.d \
./Thirdparty/portable/GCC/ARM_CM55/secure/secure_heap.d \
./Thirdparty/portable/GCC/ARM_CM55/secure/secure_init.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/ARM_CM55/secure/%.o Thirdparty/portable/GCC/ARM_CM55/secure/%.su Thirdparty/portable/GCC/ARM_CM55/secure/%.cyclo: ../Thirdparty/portable/GCC/ARM_CM55/secure/%.c Thirdparty/portable/GCC/ARM_CM55/secure/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-ARM_CM55-2f-secure

clean-Thirdparty-2f-portable-2f-GCC-2f-ARM_CM55-2f-secure:
	-$(RM) ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context.cyclo ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context.d ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context.o ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context.su ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context_port.cyclo ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context_port.d ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context_port.o ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_context_port.su ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_heap.cyclo ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_heap.d ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_heap.o ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_heap.su ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_init.cyclo ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_init.d ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_init.o ./Thirdparty/portable/GCC/ARM_CM55/secure/secure_init.su

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-ARM_CM55-2f-secure

