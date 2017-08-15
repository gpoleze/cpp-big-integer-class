################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/gabrielpferreira/Documents/workspace/Personal\ Projects/BigInteger/BigInteger/src/cpp/BigInteger.cpp 

OBJS += \
./cpp/BigInteger.o 

CPP_DEPS += \
./cpp/BigInteger.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/BigInteger.o: /Users/gabrielpferreira/Documents/workspace/Personal\ Projects/BigInteger/BigInteger/src/cpp/BigInteger.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/gabrielpferreira/Documents/workspace/Personal Projects/BigInteger/BigInteger/src/h" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


