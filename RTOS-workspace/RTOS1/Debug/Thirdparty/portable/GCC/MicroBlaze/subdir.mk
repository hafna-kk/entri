################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Thirdparty/portable/GCC/MicroBlaze/portasm.s 

C_SRCS += \
../Thirdparty/portable/GCC/MicroBlaze/port.c 

OBJS += \
./Thirdparty/portable/GCC/MicroBlaze/port.o \
./Thirdparty/portable/GCC/MicroBlaze/portasm.o 

S_DEPS += \
./Thirdparty/portable/GCC/MicroBlaze/portasm.d 

C_DEPS += \
./Thirdparty/portable/GCC/MicroBlaze/port.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/MicroBlaze/%.o Thirdparty/portable/GCC/MicroBlaze/%.su Thirdparty/portable/GCC/MicroBlaze/%.cyclo: ../Thirdparty/portable/GCC/MicroBlaze/%.c Thirdparty/portable/GCC/MicroBlaze/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Thirdparty/portable/GCC/MicroBlaze/%.o: ../Thirdparty/portable/GCC/MicroBlaze/%.s Thirdparty/portable/GCC/MicroBlaze/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-MicroBlaze

clean-Thirdparty-2f-portable-2f-GCC-2f-MicroBlaze:
	-$(RM) ./Thirdparty/portable/GCC/MicroBlaze/port.cyclo ./Thirdparty/portable/GCC/MicroBlaze/port.d ./Thirdparty/portable/GCC/MicroBlaze/port.o ./Thirdparty/portable/GCC/MicroBlaze/port.su ./Thirdparty/portable/GCC/MicroBlaze/portasm.d ./Thirdparty/portable/GCC/MicroBlaze/portasm.o

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-MicroBlaze

