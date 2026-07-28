################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/GCC/RISC-V/port.c 

S_UPPER_SRCS += \
../Thirdparty/portable/GCC/RISC-V/portASM.S 

OBJS += \
./Thirdparty/portable/GCC/RISC-V/port.o \
./Thirdparty/portable/GCC/RISC-V/portASM.o 

S_UPPER_DEPS += \
./Thirdparty/portable/GCC/RISC-V/portASM.d 

C_DEPS += \
./Thirdparty/portable/GCC/RISC-V/port.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/RISC-V/%.o Thirdparty/portable/GCC/RISC-V/%.su Thirdparty/portable/GCC/RISC-V/%.cyclo: ../Thirdparty/portable/GCC/RISC-V/%.c Thirdparty/portable/GCC/RISC-V/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Thirdparty/portable/GCC/RISC-V/%.o: ../Thirdparty/portable/GCC/RISC-V/%.S Thirdparty/portable/GCC/RISC-V/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-RISC-2d-V

clean-Thirdparty-2f-portable-2f-GCC-2f-RISC-2d-V:
	-$(RM) ./Thirdparty/portable/GCC/RISC-V/port.cyclo ./Thirdparty/portable/GCC/RISC-V/port.d ./Thirdparty/portable/GCC/RISC-V/port.o ./Thirdparty/portable/GCC/RISC-V/port.su ./Thirdparty/portable/GCC/RISC-V/portASM.d ./Thirdparty/portable/GCC/RISC-V/portASM.o

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-RISC-2d-V

