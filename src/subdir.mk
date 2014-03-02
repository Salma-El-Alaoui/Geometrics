################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application.cpp \
../Cercle.cpp \
../CmdAjoutC.cpp \
../CmdAjoutL.cpp \
../CmdAjoutOA.cpp \
../CmdAjoutPL.cpp \
../CmdAjoutR.cpp \
../CmdClear.cpp \
../CmdLoad.cpp \
../CmdMove.cpp \
../CmdSave.cpp \
../CmdSuppression.cpp \
../Commande.cpp \
../CommandeHis.cpp \
../CommandesManager.cpp \
../EltGeo.cpp \
../Ligne.cpp \
../Modele.cpp \
../ObjAgr.cpp \
../Point.cpp \
../Polyligne.cpp \
../Rectangle.cpp \
../Test.cpp 

OBJS += \
./Application.o \
./Cercle.o \
./CmdAjoutC.o \
./CmdAjoutL.o \
./CmdAjoutOA.o \
./CmdAjoutPL.o \
./CmdAjoutR.o \
./CmdClear.o \
./CmdLoad.o \
./CmdMove.o \
./CmdSave.o \
./CmdSuppression.o \
./Commande.o \
./CommandeHis.o \
./CommandesManager.o \
./EltGeo.o \
./Ligne.o \
./Modele.o \
./ObjAgr.o \
./Point.o \
./Polyligne.o \
./Rectangle.o \
./Test.o 

CPP_DEPS += \
./Application.d \
./Cercle.d \
./CmdAjoutC.d \
./CmdAjoutL.d \
./CmdAjoutOA.d \
./CmdAjoutPL.d \
./CmdAjoutR.d \
./CmdClear.d \
./CmdLoad.d \
./CmdMove.d \
./CmdSave.d \
./CmdSuppression.d \
./Commande.d \
./CommandeHis.d \
./CommandesManager.d \
./EltGeo.d \
./Ligne.d \
./Modele.d \
./ObjAgr.d \
./Point.d \
./Polyligne.d \
./Rectangle.d \
./Test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


