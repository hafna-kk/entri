################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/GCC/PPC405_Xilinx/port.c 

S_UPPER_SRCS += \
../Thirdparty/portable/GCC/PPC405_Xilinx/portasm.S 

OBJS += \
./Thirdparty/portable/GCC/PPC405_Xilinx/port.o \
./Thirdparty/portable/GCC/PPC405_Xilinx/portasm.o 

S_UPPER_DEPS += \
./Thirdparty/portable/GCC/PPC405_Xilinx/portasm.d 

C_DEPS += \
./Thirdparty/portable/GCC/PPC405_Xilinx/port.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/PPC405_Xilinx/%.o Thirdparty/portable/GCC/PPC405_Xilinx/%.su Thirdparty/portable/GCC/PPC405_Xilinx/%.cyclo: ../Thirdparty/portable/GCC/PPC405_Xilinx/%.c Thirdparty/portable/GCC/PPC405_Xilinx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Thirdparty/portable/GCC/PPC405_Xilinx/%.o: ../Thirdparty/portable/GCC/PPC405_Xilinx/%.S Thirdparty/portable/GCC/PPC405_Xilinx/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-PPC405_Xilinx

clean-Thirdparty-2f-portable-2f-GCC-2f-PPC405_Xilinx:
	-$(RM) ./Thirdparty/portable/GCC/PPC405_Xilinx/port.cyclo ./Thirdparty/portable/GCC/PPC405_Xilinx/port.d ./Thirdparty/portable/GCC/PPC405_Xilinx/port.o ./Thirdparty/portable/GCC/PPC405_Xilinx/port.su ./Thirdparty/portable/GCC/PPC405_Xilinx/portasm.d ./Thirdparty/portable/GCC/PPC405_Xilinx/portasm.o

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-PPC405_Xilinx

