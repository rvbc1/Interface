################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Interface1.cpp \
../src/Interface1_manager.cpp \
../src/List.cpp \
../src/List_element.cpp \
../src/Parameter.cpp \
../src/main.cpp 

OBJS += \
./src/Interface1.o \
./src/Interface1_manager.o \
./src/List.o \
./src/List_element.o \
./src/Parameter.o \
./src/main.o 

CPP_DEPS += \
./src/Interface1.d \
./src/Interface1_manager.d \
./src/List.d \
./src/List_element.d \
./src/Parameter.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


