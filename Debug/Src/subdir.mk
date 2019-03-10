################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/font.c \
../Src/lcd-tft.c \
../Src/main.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_it.c \
../Src/system_stm32f1xx.c \
../Src/touchscreen.c \
../Src/ui.c 

OBJS += \
./Src/font.o \
./Src/lcd-tft.o \
./Src/main.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/system_stm32f1xx.o \
./Src/touchscreen.o \
./Src/ui.o 

C_DEPS += \
./Src/font.d \
./Src/lcd-tft.d \
./Src/main.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/system_stm32f1xx.d \
./Src/touchscreen.d \
./Src/ui.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F103xE -I"/Users/jackv/work/sdr/Inc" -I"/Users/jackv/work/sdr/Drivers/STM32F1xx_HAL_Driver/Inc" -I"/Users/jackv/work/sdr/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"/Users/jackv/work/sdr/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"/Users/jackv/work/sdr/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


