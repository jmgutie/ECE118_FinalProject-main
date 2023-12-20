#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Movement.c BumperService.c TemplateEventChecker.c TapeSensorService.c ES_Main.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/AD.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/BOARD.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_CheckEvents.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Framework.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_KeyboardInput.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_PostList.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Queue.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_TattleTale.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Timers.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/IO_Ports.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/LED.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/RC_Servo.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/pwm.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/serial.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/timers.c BeaconService.c HSM.c StartSubHSM.c ShootOn1SubHSM.c FireSubHSM.c ShootOn2SubHSM.c ReloadSubHSM.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Movement.o ${OBJECTDIR}/BumperService.o ${OBJECTDIR}/TemplateEventChecker.o ${OBJECTDIR}/TapeSensorService.o ${OBJECTDIR}/ES_Main.o ${OBJECTDIR}/_ext/1053023675/AD.o ${OBJECTDIR}/_ext/1053023675/BOARD.o ${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o ${OBJECTDIR}/_ext/1053023675/ES_Framework.o ${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o ${OBJECTDIR}/_ext/1053023675/ES_PostList.o ${OBJECTDIR}/_ext/1053023675/ES_Queue.o ${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o ${OBJECTDIR}/_ext/1053023675/ES_Timers.o ${OBJECTDIR}/_ext/1053023675/IO_Ports.o ${OBJECTDIR}/_ext/1053023675/LED.o ${OBJECTDIR}/_ext/1053023675/RC_Servo.o ${OBJECTDIR}/_ext/1053023675/pwm.o ${OBJECTDIR}/_ext/1053023675/serial.o ${OBJECTDIR}/_ext/1053023675/timers.o ${OBJECTDIR}/BeaconService.o ${OBJECTDIR}/HSM.o ${OBJECTDIR}/StartSubHSM.o ${OBJECTDIR}/ShootOn1SubHSM.o ${OBJECTDIR}/FireSubHSM.o ${OBJECTDIR}/ShootOn2SubHSM.o ${OBJECTDIR}/ReloadSubHSM.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Movement.o.d ${OBJECTDIR}/BumperService.o.d ${OBJECTDIR}/TemplateEventChecker.o.d ${OBJECTDIR}/TapeSensorService.o.d ${OBJECTDIR}/ES_Main.o.d ${OBJECTDIR}/_ext/1053023675/AD.o.d ${OBJECTDIR}/_ext/1053023675/BOARD.o.d ${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o.d ${OBJECTDIR}/_ext/1053023675/ES_Framework.o.d ${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o.d ${OBJECTDIR}/_ext/1053023675/ES_PostList.o.d ${OBJECTDIR}/_ext/1053023675/ES_Queue.o.d ${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o.d ${OBJECTDIR}/_ext/1053023675/ES_Timers.o.d ${OBJECTDIR}/_ext/1053023675/IO_Ports.o.d ${OBJECTDIR}/_ext/1053023675/LED.o.d ${OBJECTDIR}/_ext/1053023675/RC_Servo.o.d ${OBJECTDIR}/_ext/1053023675/pwm.o.d ${OBJECTDIR}/_ext/1053023675/serial.o.d ${OBJECTDIR}/_ext/1053023675/timers.o.d ${OBJECTDIR}/BeaconService.o.d ${OBJECTDIR}/HSM.o.d ${OBJECTDIR}/StartSubHSM.o.d ${OBJECTDIR}/ShootOn1SubHSM.o.d ${OBJECTDIR}/FireSubHSM.o.d ${OBJECTDIR}/ShootOn2SubHSM.o.d ${OBJECTDIR}/ReloadSubHSM.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Movement.o ${OBJECTDIR}/BumperService.o ${OBJECTDIR}/TemplateEventChecker.o ${OBJECTDIR}/TapeSensorService.o ${OBJECTDIR}/ES_Main.o ${OBJECTDIR}/_ext/1053023675/AD.o ${OBJECTDIR}/_ext/1053023675/BOARD.o ${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o ${OBJECTDIR}/_ext/1053023675/ES_Framework.o ${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o ${OBJECTDIR}/_ext/1053023675/ES_PostList.o ${OBJECTDIR}/_ext/1053023675/ES_Queue.o ${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o ${OBJECTDIR}/_ext/1053023675/ES_Timers.o ${OBJECTDIR}/_ext/1053023675/IO_Ports.o ${OBJECTDIR}/_ext/1053023675/LED.o ${OBJECTDIR}/_ext/1053023675/RC_Servo.o ${OBJECTDIR}/_ext/1053023675/pwm.o ${OBJECTDIR}/_ext/1053023675/serial.o ${OBJECTDIR}/_ext/1053023675/timers.o ${OBJECTDIR}/BeaconService.o ${OBJECTDIR}/HSM.o ${OBJECTDIR}/StartSubHSM.o ${OBJECTDIR}/ShootOn1SubHSM.o ${OBJECTDIR}/FireSubHSM.o ${OBJECTDIR}/ShootOn2SubHSM.o ${OBJECTDIR}/ReloadSubHSM.o

# Source Files
SOURCEFILES=Movement.c BumperService.c TemplateEventChecker.c TapeSensorService.c ES_Main.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/AD.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/BOARD.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_CheckEvents.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Framework.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_KeyboardInput.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_PostList.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Queue.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_TattleTale.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Timers.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/IO_Ports.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/LED.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/RC_Servo.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/pwm.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/serial.c E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/timers.c BeaconService.c HSM.c StartSubHSM.c ShootOn1SubHSM.c FireSubHSM.c ShootOn2SubHSM.c ReloadSubHSM.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

# The following macros may be used in the pre and post step lines
_/_=\\
ShExtension=.bat
Device=PIC32MX320F128H
ProjectDir="E:\classFIles\ECE118\Final_Project\ECE118_FinalProject\Final_Project.X"
ProjectName=Final_Project
ConfName=default
ImagePath="${DISTDIR}\Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="${DISTDIR}"
ImageName="Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  .pre ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=,--script="E:\classFIles\ECE118\Final_Project\ECE118_FinalProject\ECE118\bootloader320.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Movement.o: Movement.c  .generated_files/flags/default/21d0c9101f59f89b4c7adb1449463a9a06567981 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Movement.o.d 
	@${RM} ${OBJECTDIR}/Movement.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/Movement.o.d" -o ${OBJECTDIR}/Movement.o Movement.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BumperService.o: BumperService.c  .generated_files/flags/default/1cf075219a2e6e35edb8ecc10756c0a706dadcad .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BumperService.o.d 
	@${RM} ${OBJECTDIR}/BumperService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/BumperService.o.d" -o ${OBJECTDIR}/BumperService.o BumperService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TemplateEventChecker.o: TemplateEventChecker.c  .generated_files/flags/default/aad709de77fdce8d451ff3a669554a1bbe2b3494 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TemplateEventChecker.o.d 
	@${RM} ${OBJECTDIR}/TemplateEventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/TemplateEventChecker.o.d" -o ${OBJECTDIR}/TemplateEventChecker.o TemplateEventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TapeSensorService.o: TapeSensorService.c  .generated_files/flags/default/1ec493f147e07a2e085703d8bf22d27c13bbced8 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TapeSensorService.o.d 
	@${RM} ${OBJECTDIR}/TapeSensorService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/TapeSensorService.o.d" -o ${OBJECTDIR}/TapeSensorService.o TapeSensorService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_Main.o: ES_Main.c  .generated_files/flags/default/d67ab8b3b01945e9918a9afdde04356386535f1e .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_Main.o.d 
	@${RM} ${OBJECTDIR}/ES_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/ES_Main.o.d" -o ${OBJECTDIR}/ES_Main.o ES_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/AD.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/AD.c  .generated_files/flags/default/aa57f3f87e6df2081247d5c547732a61704a7942 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/AD.o.d" -o ${OBJECTDIR}/_ext/1053023675/AD.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/BOARD.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/BOARD.c  .generated_files/flags/default/a0a4dcdd9f6b4587ef0100911a9f73ed2a9c4db2 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/BOARD.o.d" -o ${OBJECTDIR}/_ext/1053023675/BOARD.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_CheckEvents.c  .generated_files/flags/default/a41c1c200896b118098fd63cc238f1da8ad578e8 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_Framework.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Framework.c  .generated_files/flags/default/fdd8f7e6a1d55c520d8e8784a55696009d877922 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_Framework.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_KeyboardInput.c  .generated_files/flags/default/4327b1859a446fb43409e7eb4516ccbea1852f57 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_PostList.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_PostList.c  .generated_files/flags/default/742151b0c28c2c419a0d3a97040b7d777c2030c7 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_PostList.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_Queue.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Queue.c  .generated_files/flags/default/419e9bde9fab06cf81ef865409aaf6c033daef06 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_Queue.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_TattleTale.c  .generated_files/flags/default/790853c98851ec6062423e50885f8d2f9de7a6fd .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_Timers.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Timers.c  .generated_files/flags/default/65084c0f0fe11b4dd5f029fe1780c4b51e1c7fe8 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_Timers.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/IO_Ports.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/IO_Ports.c  .generated_files/flags/default/e9feba5a73098056b123587866e831fd38a17d19 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/1053023675/IO_Ports.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/LED.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/LED.c  .generated_files/flags/default/d070a714203a31b1b6200d86c280eab4b66835ca .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/LED.o.d" -o ${OBJECTDIR}/_ext/1053023675/LED.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/RC_Servo.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/RC_Servo.c  .generated_files/flags/default/b5371fb0829c0a240c4b1155ca9bd35f05d4d8c4 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/RC_Servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/1053023675/RC_Servo.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/RC_Servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/pwm.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/pwm.c  .generated_files/flags/default/de908469cd93a1c8a190ddbf9427c1a0bbd50c3a .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/pwm.o.d" -o ${OBJECTDIR}/_ext/1053023675/pwm.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/serial.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/serial.c  .generated_files/flags/default/d5e6fc2402b856fca4d53ae3b3f5c5fb5d466496 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/serial.o.d" -o ${OBJECTDIR}/_ext/1053023675/serial.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/timers.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/timers.c  .generated_files/flags/default/47a227e520f128ac203559ecce2beda80c9ff37f .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/timers.o.d" -o ${OBJECTDIR}/_ext/1053023675/timers.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BeaconService.o: BeaconService.c  .generated_files/flags/default/b208af5fdf985ce73d1552b04e58a79056c96e09 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BeaconService.o.d 
	@${RM} ${OBJECTDIR}/BeaconService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/BeaconService.o.d" -o ${OBJECTDIR}/BeaconService.o BeaconService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM.o: HSM.c  .generated_files/flags/default/bc3afbde474151501a22730074f845baa5219bcc .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM.o.d 
	@${RM} ${OBJECTDIR}/HSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/HSM.o.d" -o ${OBJECTDIR}/HSM.o HSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/StartSubHSM.o: StartSubHSM.c  .generated_files/flags/default/ce25ae4782a566c7f097b007204b75c24e4a8604 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/StartSubHSM.o.d 
	@${RM} ${OBJECTDIR}/StartSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/StartSubHSM.o.d" -o ${OBJECTDIR}/StartSubHSM.o StartSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ShootOn1SubHSM.o: ShootOn1SubHSM.c  .generated_files/flags/default/d45a328962da5d6d6c9e1978c38b730503c60ce .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ShootOn1SubHSM.o.d 
	@${RM} ${OBJECTDIR}/ShootOn1SubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/ShootOn1SubHSM.o.d" -o ${OBJECTDIR}/ShootOn1SubHSM.o ShootOn1SubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FireSubHSM.o: FireSubHSM.c  .generated_files/flags/default/8cbbc53484902cc39562df59bfcaa3555f9fb8db .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FireSubHSM.o.d 
	@${RM} ${OBJECTDIR}/FireSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/FireSubHSM.o.d" -o ${OBJECTDIR}/FireSubHSM.o FireSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ShootOn2SubHSM.o: ShootOn2SubHSM.c  .generated_files/flags/default/8536873eead6936247d6af60a8bfe62ff0a7c04 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ShootOn2SubHSM.o.d 
	@${RM} ${OBJECTDIR}/ShootOn2SubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/ShootOn2SubHSM.o.d" -o ${OBJECTDIR}/ShootOn2SubHSM.o ShootOn2SubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ReloadSubHSM.o: ReloadSubHSM.c  .generated_files/flags/default/50ec2041fd507b55aa50bafbadcc0d9476c8c4cb .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ReloadSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ReloadSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/ReloadSubHSM.o.d" -o ${OBJECTDIR}/ReloadSubHSM.o ReloadSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/Movement.o: Movement.c  .generated_files/flags/default/f5a90ac49b1cb2ee824d253d8e45f9d1a39ba5d5 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Movement.o.d 
	@${RM} ${OBJECTDIR}/Movement.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/Movement.o.d" -o ${OBJECTDIR}/Movement.o Movement.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BumperService.o: BumperService.c  .generated_files/flags/default/a15f35bd49bd6f4f2463cc7d98b3140896d96573 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BumperService.o.d 
	@${RM} ${OBJECTDIR}/BumperService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/BumperService.o.d" -o ${OBJECTDIR}/BumperService.o BumperService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TemplateEventChecker.o: TemplateEventChecker.c  .generated_files/flags/default/1bebff15a194d85f7cecb603143a5d79807022f .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TemplateEventChecker.o.d 
	@${RM} ${OBJECTDIR}/TemplateEventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/TemplateEventChecker.o.d" -o ${OBJECTDIR}/TemplateEventChecker.o TemplateEventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/TapeSensorService.o: TapeSensorService.c  .generated_files/flags/default/8fcb771ddccd9688db096a5cd9f00ee1eebda3ab .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TapeSensorService.o.d 
	@${RM} ${OBJECTDIR}/TapeSensorService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/TapeSensorService.o.d" -o ${OBJECTDIR}/TapeSensorService.o TapeSensorService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ES_Main.o: ES_Main.c  .generated_files/flags/default/3831e0e23eb14419608bec00b9a9b8864b48dbf0 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ES_Main.o.d 
	@${RM} ${OBJECTDIR}/ES_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/ES_Main.o.d" -o ${OBJECTDIR}/ES_Main.o ES_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/AD.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/AD.c  .generated_files/flags/default/83e1140b8a9030065cb5dba8c0a71a9229dafeaa .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/AD.o.d" -o ${OBJECTDIR}/_ext/1053023675/AD.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/BOARD.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/BOARD.c  .generated_files/flags/default/ef9e76c078f7aca7a5ec9e227519e38032c92708 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/BOARD.o.d" -o ${OBJECTDIR}/_ext/1053023675/BOARD.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_CheckEvents.c  .generated_files/flags/default/ea482ebe10b4d9fe2cf83b2589140a2e0250c32b .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_CheckEvents.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_Framework.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Framework.c  .generated_files/flags/default/523ba7d54fe853381855594001e789cb719c31d5 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_Framework.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_KeyboardInput.c  .generated_files/flags/default/2d73ac5217a90e68ec4f4f1cad5aea6f24ccc35e .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_KeyboardInput.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_PostList.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_PostList.c  .generated_files/flags/default/757db3e930f6adcb2b14e55e91029347d768970 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_PostList.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_Queue.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Queue.c  .generated_files/flags/default/457b9196c3342cbfb1fb6107d9b3cac337097835 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_Queue.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_TattleTale.c  .generated_files/flags/default/d7f22e4a8c5be91dd2be1f1e98cda69ad166899c .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_TattleTale.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/ES_Timers.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Timers.c  .generated_files/flags/default/2fb77ec9b25d57ad95f2a0c855badc0dcfe91b07 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/1053023675/ES_Timers.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/IO_Ports.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/IO_Ports.c  .generated_files/flags/default/cb573a98325c81d545aba3cd6b00b9a38cefc5e9 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/1053023675/IO_Ports.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/LED.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/LED.c  .generated_files/flags/default/d994fb1c47ebee7f09e10f0b9bf395ac6edca10f .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/LED.o.d" -o ${OBJECTDIR}/_ext/1053023675/LED.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/RC_Servo.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/RC_Servo.c  .generated_files/flags/default/6b31df36d97bdb48eb72656415852ecf69cf7fae .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/RC_Servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/1053023675/RC_Servo.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/RC_Servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/pwm.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/pwm.c  .generated_files/flags/default/64e838548ae1d717967e701640131ac7c2c957a0 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/pwm.o.d" -o ${OBJECTDIR}/_ext/1053023675/pwm.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/serial.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/serial.c  .generated_files/flags/default/a507181a3037c5996e62c387a205fc9c6b1104f5 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/serial.o.d" -o ${OBJECTDIR}/_ext/1053023675/serial.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1053023675/timers.o: E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/timers.c  .generated_files/flags/default/598477415d3420a8fc9e95bc5077750b95b6d427 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}/_ext/1053023675" 
	@${RM} ${OBJECTDIR}/_ext/1053023675/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1053023675/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/_ext/1053023675/timers.o.d" -o ${OBJECTDIR}/_ext/1053023675/timers.o E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/src/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BeaconService.o: BeaconService.c  .generated_files/flags/default/349637e9a8fc4a0ab78685775eecb3e9509e94a3 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BeaconService.o.d 
	@${RM} ${OBJECTDIR}/BeaconService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/BeaconService.o.d" -o ${OBJECTDIR}/BeaconService.o BeaconService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/HSM.o: HSM.c  .generated_files/flags/default/5a95b67b9b58f31f40f953e3cb20d68fb96adf38 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/HSM.o.d 
	@${RM} ${OBJECTDIR}/HSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/HSM.o.d" -o ${OBJECTDIR}/HSM.o HSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/StartSubHSM.o: StartSubHSM.c  .generated_files/flags/default/5f29acce99b93e0816e9e8e12d6dafeae1ba7b46 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/StartSubHSM.o.d 
	@${RM} ${OBJECTDIR}/StartSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/StartSubHSM.o.d" -o ${OBJECTDIR}/StartSubHSM.o StartSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ShootOn1SubHSM.o: ShootOn1SubHSM.c  .generated_files/flags/default/d85175ca1cadfdbea0289954d9f9950d93afea4 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ShootOn1SubHSM.o.d 
	@${RM} ${OBJECTDIR}/ShootOn1SubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/ShootOn1SubHSM.o.d" -o ${OBJECTDIR}/ShootOn1SubHSM.o ShootOn1SubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FireSubHSM.o: FireSubHSM.c  .generated_files/flags/default/4d60fab5e31a615caa09449a3b0593438722b3bb .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FireSubHSM.o.d 
	@${RM} ${OBJECTDIR}/FireSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/FireSubHSM.o.d" -o ${OBJECTDIR}/FireSubHSM.o FireSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ShootOn2SubHSM.o: ShootOn2SubHSM.c  .generated_files/flags/default/14c5e19ac33d673050da45ef3a63beb0efbb11af .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ShootOn2SubHSM.o.d 
	@${RM} ${OBJECTDIR}/ShootOn2SubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/ShootOn2SubHSM.o.d" -o ${OBJECTDIR}/ShootOn2SubHSM.o ShootOn2SubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ReloadSubHSM.o: ReloadSubHSM.c  .generated_files/flags/default/99fb8665566e9dfe0427f1462324d134b43a6774 .generated_files/flags/default/2f91b9d9434964e13f75e4b661840d64d64b908b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ReloadSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ReloadSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -DSIMPLESERVICE_TEST -I"../ECE118/include" -I"." -I"../ECE118/src" -MP -MMD -MF "${OBJECTDIR}/ReloadSubHSM.o.d" -o ${OBJECTDIR}/ReloadSubHSM.o ReloadSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   E:/classFIles/ECE118/Final_Project/ECE118_FinalProject/ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif

.pre:
	@echo "--------------------------------------"
	@echo "User defined pre-build step: [python E:\classFIles\ECE118\Final_Project\ECE118_FinalProject\ECE118\scripts\Enum_To_String.py]"
	@python E:\classFIles\ECE118\Final_Project\ECE118_FinalProject\ECE118\scripts\Enum_To_String.py
	@echo "--------------------------------------"

# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
