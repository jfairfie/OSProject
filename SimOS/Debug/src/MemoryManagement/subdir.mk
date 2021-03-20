################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MemoryManagement/Disk.cpp \
../src/MemoryManagement/PCB.cpp \
../src/MemoryManagement/RAM.cpp 

OBJS += \
./src/MemoryManagement/Disk.o \
./src/MemoryManagement/PCB.o \
./src/MemoryManagement/RAM.o 

CPP_DEPS += \
./src/MemoryManagement/Disk.d \
./src/MemoryManagement/PCB.d \
./src/MemoryManagement/RAM.d 


# Each subdirectory must supply rules for building sources it contributes
src/MemoryManagement/%.o: ../src/MemoryManagement/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


