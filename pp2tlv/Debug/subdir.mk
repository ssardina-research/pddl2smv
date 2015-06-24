################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../ast.o \
../grammar.tab.o \
../lex.yy.o \
../main.o \
../planprog.o \
../planprog2tlv.o \
../symtable.o 

CPP_SRCS += \
../ast.cpp \
../main.cpp \
../planprog.cpp \
../planprog2tlv.cpp \
../symtable.cpp 

C_SRCS += \
../lex.yy.c 

CC_SRCS += \
../grammar.tab.cc 

OBJS += \
./ast.o \
./grammar.tab.o \
./lex.yy.o \
./main.o \
./planprog.o \
./planprog2tlv.o \
./symtable.o 

C_DEPS += \
./lex.yy.d 

CC_DEPS += \
./grammar.tab.d 

CPP_DEPS += \
./ast.d \
./main.d \
./planprog.d \
./planprog2tlv.d \
./symtable.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


