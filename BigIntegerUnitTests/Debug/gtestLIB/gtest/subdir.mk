################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../gtestLIB/gtest/gtest-all.cc 

CC_DEPS += \
./gtestLIB/gtest/gtest-all.d 

OBJS += \
./gtestLIB/gtest/gtest-all.o 


# Each subdirectory must supply rules for building sources it contributes
gtestLIB/gtest/%.o: ../gtestLIB/gtest/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/gabrielpferreira/Documents/workspace/Personal Projects/BigInteger/BigIntegerUnitTests/gtestLIB" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


