################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Csro/fnd_output/fnd_output.c \
../Csro/fnd_output/fnd_output_gpio.c 

OBJS += \
./Csro/fnd_output/fnd_output.o \
./Csro/fnd_output/fnd_output_gpio.o 

C_DEPS += \
./Csro/fnd_output/fnd_output.d \
./Csro/fnd_output/fnd_output_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Csro/fnd_output/%.o: ../Csro/fnd_output/%.c Csro/fnd_output/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Csro/fnd_com" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Csro/fnd_input" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Csro/fnd_output" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Modbus_RTU" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/key_com_motor_ctrl_ert_rtw" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/com_process" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/key_com_motor_ctrl" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/key_process" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/motor_ctrl" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Simulink/slprj/ert/_sharedutils" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.7.0/csro_4ch_motor/Csro/fnd_eeprom" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

