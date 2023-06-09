################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/bsp.c \
../BSP/bsp_beep.c \
../BSP/bsp_encoder.c \
../BSP/bsp_key.c \
../BSP/bsp_motion.c \
../BSP/bsp_motor.c \
../BSP/bsp_mpu9250.c \
../BSP/bsp_mpuiic.c \
../BSP/bsp_pid.c \
../BSP/bsp_pwmServo.c \
../BSP/bsp_uart.c 

OBJS += \
./BSP/bsp.o \
./BSP/bsp_beep.o \
./BSP/bsp_encoder.o \
./BSP/bsp_key.o \
./BSP/bsp_motion.o \
./BSP/bsp_motor.o \
./BSP/bsp_mpu9250.o \
./BSP/bsp_mpuiic.o \
./BSP/bsp_pid.o \
./BSP/bsp_pwmServo.o \
./BSP/bsp_uart.o 

C_DEPS += \
./BSP/bsp.d \
./BSP/bsp_beep.d \
./BSP/bsp_encoder.d \
./BSP/bsp_key.d \
./BSP/bsp_motion.d \
./BSP/bsp_motor.d \
./BSP/bsp_mpu9250.d \
./BSP/bsp_mpuiic.d \
./BSP/bsp_pid.d \
./BSP/bsp_pwmServo.d \
./BSP/bsp_uart.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/%.o BSP/%.su BSP/%.cyclo: ../BSP/%.c BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../BSP -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-BSP

clean-BSP:
	-$(RM) ./BSP/bsp.cyclo ./BSP/bsp.d ./BSP/bsp.o ./BSP/bsp.su ./BSP/bsp_beep.cyclo ./BSP/bsp_beep.d ./BSP/bsp_beep.o ./BSP/bsp_beep.su ./BSP/bsp_encoder.cyclo ./BSP/bsp_encoder.d ./BSP/bsp_encoder.o ./BSP/bsp_encoder.su ./BSP/bsp_key.cyclo ./BSP/bsp_key.d ./BSP/bsp_key.o ./BSP/bsp_key.su ./BSP/bsp_motion.cyclo ./BSP/bsp_motion.d ./BSP/bsp_motion.o ./BSP/bsp_motion.su ./BSP/bsp_motor.cyclo ./BSP/bsp_motor.d ./BSP/bsp_motor.o ./BSP/bsp_motor.su ./BSP/bsp_mpu9250.cyclo ./BSP/bsp_mpu9250.d ./BSP/bsp_mpu9250.o ./BSP/bsp_mpu9250.su ./BSP/bsp_mpuiic.cyclo ./BSP/bsp_mpuiic.d ./BSP/bsp_mpuiic.o ./BSP/bsp_mpuiic.su ./BSP/bsp_pid.cyclo ./BSP/bsp_pid.d ./BSP/bsp_pid.o ./BSP/bsp_pid.su ./BSP/bsp_pwmServo.cyclo ./BSP/bsp_pwmServo.d ./BSP/bsp_pwmServo.o ./BSP/bsp_pwmServo.su ./BSP/bsp_uart.cyclo ./BSP/bsp_uart.d ./BSP/bsp_uart.o ./BSP/bsp_uart.su

.PHONY: clean-BSP

