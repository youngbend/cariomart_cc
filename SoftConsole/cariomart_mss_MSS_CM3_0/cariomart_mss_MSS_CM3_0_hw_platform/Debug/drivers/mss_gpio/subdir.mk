################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/mss_gpio/mss_gpio.c 

OBJS += \
./drivers/mss_gpio/mss_gpio.o 

C_DEPS += \
./drivers/mss_gpio/mss_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/mss_gpio/%.o: ../drivers/mss_gpio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\CMSIS -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\CMSIS\startup_gcc -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_gpio -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_nvm -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_nvm\drivers -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_nvm\drivers\F2DSS_NVM -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_pdma -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_rtc -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_rtc\drivers -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_rtc\drivers\mss_rtc -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_timer -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\drivers\mss_uart -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\hal -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\hal\CortexM3 -IC:\Microsemi\Projects\cariomart_cc\SoftConsole\cariomart_mss_MSS_CM3_0\cariomart_mss_MSS_CM3_0_hw_platform\hal\CortexM3\GNU -O0 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


