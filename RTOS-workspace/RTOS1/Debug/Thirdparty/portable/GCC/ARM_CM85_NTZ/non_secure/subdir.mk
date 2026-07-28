################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/mpu_wrappers_v2_asm.c \
../Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/port.c \
../Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/portasm.c 

OBJS += \
./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/mpu_wrappers_v2_asm.o \
./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/port.o \
./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/portasm.o 

C_DEPS += \
./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/mpu_wrappers_v2_asm.d \
./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/port.d \
./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/portasm.d 


# Each subdirectory must supply rules for building sources it contributes
Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/%.o Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/%.su Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/%.cyclo: ../Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/%.c Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Thirdparty-2f-portable-2f-GCC-2f-ARM_CM85_NTZ-2f-non_secure

clean-Thirdparty-2f-portable-2f-GCC-2f-ARM_CM85_NTZ-2f-non_secure:
	-$(RM) ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/mpu_wrappers_v2_asm.cyclo ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/mpu_wrappers_v2_asm.d ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/mpu_wrappers_v2_asm.o ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/mpu_wrappers_v2_asm.su ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/port.cyclo ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/port.d ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/port.o ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/port.su ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/portasm.cyclo ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/portasm.d ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/portasm.o ./Thirdparty/portable/GCC/ARM_CM85_NTZ/non_secure/portasm.su

.PHONY: clean-Thirdparty-2f-portable-2f-GCC-2f-ARM_CM85_NTZ-2f-non_secure

