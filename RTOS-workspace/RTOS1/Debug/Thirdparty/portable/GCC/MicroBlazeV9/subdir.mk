################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/GCC/MicroBlazeV9/port.c \
../Thirdparty/portable/GCC/MicroBlazeV9/port_exceptions.c 

S_UPPER_SRCS += \
../Thirdparty/portable/GCC/MicroBlazeV9/portasm.S 

OBJS += \
./Thirdparty/portable/GCC/MicroBlazeV9/port.o \
./Thirdparty/portable/GCC/MicroBlazeV9/port_exceptions.o \
./Thirdparty/portable/GCC/MicroBlazeV9/portasm.o 

S_UPPER_DEPS += \
./Thirdparty/portable/GCC/MicroBlazeV9/portasm.d 

C_DEPS += \
./Thirdparty/portable/GCC/MicroBlazeV9/port.d \
./Thirdparty/portable/GCC/MicroBlazeV9/port_exceptions.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/MicroBlazeV9/%.o Thirdparty/portable/GCC/MicroBlazeV9/%.su Thirdparty/portable/GCC/MicroBlazeV9/%.cyclo: ../Thirdparty/portable/GCC/MicroBlazeV9/%.c Thirdparty/portable/GCC/MicroBlazeV9/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Thirdparty/portable/GCC/MicroBlazeV9/%.o: ../Thirdparty/portable/GCC/MicroBlazeV9/%.S Thirdparty/portable/GCC/MicroBlazeV9/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-MicroBlazeV9

clean-Thirdparty-2f-portable-2f-GCC-2f-MicroBlazeV9:
	-$(RM) ./Thirdparty/portable/GCC/MicroBlazeV9/port.cyclo ./Thirdparty/portable/GCC/MicroBlazeV9/port.d ./Thirdparty/portable/GCC/MicroBlazeV9/port.o ./Thirdparty/portable/GCC/MicroBlazeV9/port.su ./Thirdparty/portable/GCC/MicroBlazeV9/port_exceptions.cyclo ./Thirdparty/portable/GCC/MicroBlazeV9/port_exceptions.d ./Thirdparty/portable/GCC/MicroBlazeV9/port_exceptions.o ./Thirdparty/portable/GCC/MicroBlazeV9/port_exceptions.su ./Thirdparty/portable/GCC/MicroBlazeV9/portasm.d ./Thirdparty/portable/GCC/MicroBlazeV9/portasm.o

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-MicroBlazeV9

