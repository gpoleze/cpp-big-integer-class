################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/allTests.cpp 

OBJS += \
./tests/allTests.o 

CPP_DEPS += \
./tests/allTests.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/gabrielpferreira/Documents/workspace/Personal Projects/BigInteger/BigInteger/src/h" -I"/Users/gabrielpferreira/Documents/workspace/Personal Projects/BigInteger/BigInteger/src/cpp" -I"/Users/gabrielpferreira/Documents/workspace/Personal Projects/BigInteger/BigIntegerUnitTests/gtestLIB" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


