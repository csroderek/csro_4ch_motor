################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/dma.c \
../Core/Src/freertos.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_hal_timebase_tim.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/dma.o \
./Core/Src/freertos.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_hal_timebase_tim.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/dma.d \
./Core/Src/freertos.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_hal_timebase_tim.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Csro/fnd_com" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Csro/fnd_input" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Csro/fnd_output" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Modbus_RTU" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/key_com_motor_ctrl_ert_rtw" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/com_process" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/key_com_motor_ctrl" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/key_process" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/motor_ctrl" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/_sharedutils" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Csro/fnd_eeprom" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

