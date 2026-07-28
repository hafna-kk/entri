################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/FreeRTOS/examples/cmake_example/main.c 

OBJS += \
./Thirdparty/FreeRTOS/examples/cmake_example/main.o 

C_DEPS += \
./Thirdparty/FreeRTOS/examples/cmake_example/main.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/FreeRTOS/examples/cmake_example/%.o Thirdparty/FreeRTOS/examples/cmake_example/%.su Thirdparty/FreeRTOS/examples/cmake_example/%.cyclo: ../Thirdparty/FreeRTOS/examples/cmake_example/%.c Thirdparty/FreeRTOS/examples/cmake_example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I"C:/Users/hafna/Desktop/RTOS-workspace/RTOS1/Thirdparty/FreeRTOS/include" -I"C:/Users/hafna/Desktop/RTOS-workspace/RTOS1/Thirdparty/FreeRTOS" -I"C:/Users/hafna/Desktop/RTOS-workspace/RTOS1/Thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Thirdparty-2f-FreeRTOS-2f-examples-2f-cmake_example

clean-Thirdparty-2f-FreeRTOS-2f-examples-2f-cmake_example:
	-$(RM) ./Thirdparty/FreeRTOS/examples/cmake_example/main.cyclo ./Thirdparty/FreeRTOS/examples/cmake_example/main.d ./Thirdparty/FreeRTOS/examples/cmake_example/main.o ./Thirdparty/FreeRTOS/examples/cmake_example/main.su

.PHONY: clean-Thirdparty-2f-FreeRTOS-2f-examples-2f-cmake_example

