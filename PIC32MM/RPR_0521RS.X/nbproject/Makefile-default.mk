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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RPR_0521RS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RPR_0521RS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../lib/RPR0521RS.c ../lib/UART.c ../lib/i2c_using_simple.c mcc_generated_files/drivers/i2c_simple_master.c mcc_generated_files/drivers/i2c_master.c mcc_generated_files/drivers/i2c_types.c mcc_generated_files/uart2.c mcc_generated_files/clock.c mcc_generated_files/system.c mcc_generated_files/exceptions.c mcc_generated_files/mcc.c mcc_generated_files/interrupt_manager.c mcc_generated_files/pin_manager.c mcc_generated_files/delay.c mcc_generated_files/i2c1_driver.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360930230/RPR0521RS.o ${OBJECTDIR}/_ext/1360930230/UART.o ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o ${OBJECTDIR}/mcc_generated_files/uart2.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/exceptions.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/delay.o ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360930230/RPR0521RS.o.d ${OBJECTDIR}/_ext/1360930230/UART.o.d ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o.d ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d ${OBJECTDIR}/mcc_generated_files/uart2.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/exceptions.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/delay.o.d ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360930230/RPR0521RS.o ${OBJECTDIR}/_ext/1360930230/UART.o ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o ${OBJECTDIR}/mcc_generated_files/uart2.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/exceptions.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/delay.o ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=../lib/RPR0521RS.c ../lib/UART.c ../lib/i2c_using_simple.c mcc_generated_files/drivers/i2c_simple_master.c mcc_generated_files/drivers/i2c_master.c mcc_generated_files/drivers/i2c_types.c mcc_generated_files/uart2.c mcc_generated_files/clock.c mcc_generated_files/system.c mcc_generated_files/exceptions.c mcc_generated_files/mcc.c mcc_generated_files/interrupt_manager.c mcc_generated_files/pin_manager.c mcc_generated_files/delay.c mcc_generated_files/i2c1_driver.c main.c



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

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/RPR_0521RS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MM0256GPM048
MP_LINKER_FILE_OPTION=
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
${OBJECTDIR}/_ext/1360930230/RPR0521RS.o: ../lib/RPR0521RS.c  .generated_files/f130c09f3a026c15a577597a397e87fc579fa5d3.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/RPR0521RS.o.d" -o ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o ../lib/RPR0521RS.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360930230/UART.o: ../lib/UART.c  .generated_files/b6ff5b5da240c61b5be6a77e5ab1b1c29d62c854.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/UART.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/UART.o.d" -o ${OBJECTDIR}/_ext/1360930230/UART.o ../lib/UART.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o: ../lib/i2c_using_simple.c  .generated_files/ad27a3e9d6053e0cc94ad52385a616aa88084ecf.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o.d" -o ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o ../lib/i2c_using_simple.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/b1c4a9fa87427198860a5932c075201cc80ffa40.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o mcc_generated_files/drivers/i2c_simple_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/d862da500ce986206892b3b233dde539dd0ae062.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o mcc_generated_files/drivers/i2c_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/3185e3460aed516fe23ce718cc4eae078a914e15.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o mcc_generated_files/drivers/i2c_types.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/72d26e57229ce0b3f61b2525246a886cd79e14f7.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart2.o mcc_generated_files/uart2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/9ed3fdf0796149c788b673cb854fda2c1417740.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/e8101711a9b6a21d96873868cf0ebd5e3edf50e2.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/6407faabfe2b3cbb4ce4fffa25d8000ab971b64d.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/exceptions.o.d" -o ${OBJECTDIR}/mcc_generated_files/exceptions.o mcc_generated_files/exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/67225631ed538c6562da6c9ca49e8c540060cbad.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/d6532aaed645e4ad1c8d80cc8fbeff1cc952dd3.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/d8f04a4cb30b7a1ac20bf72944a6b2523df42d97.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/delay.o: mcc_generated_files/delay.c  .generated_files/e756ccc7a43fb8227eeb5e677c20b67c77ce4f67.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/delay.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/delay.o.d" -o ${OBJECTDIR}/mcc_generated_files/delay.o mcc_generated_files/delay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/i2c1_driver.o: mcc_generated_files/i2c1_driver.c  .generated_files/f6b9488e9f2db9fdfab48412482ce9d0cb513a5b.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c1_driver.o.d" -o ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o mcc_generated_files/i2c1_driver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/be1f219684dea91812b0cef0f43bc3e47061fa38.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1360930230/RPR0521RS.o: ../lib/RPR0521RS.c  .generated_files/1b469ddfd61f80a1c2cd7e140ce622219941e560.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/RPR0521RS.o.d" -o ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o ../lib/RPR0521RS.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360930230/UART.o: ../lib/UART.c  .generated_files/1c971f14084bbfd45dd80eece9eb783082305e92.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/UART.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/UART.o.d" -o ${OBJECTDIR}/_ext/1360930230/UART.o ../lib/UART.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o: ../lib/i2c_using_simple.c  .generated_files/9ecde7227579dec30f731138de276c783b0b38c9.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o.d" -o ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o ../lib/i2c_using_simple.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/3cc5648229cc6d7a93d430ac99c2169acc9c84b6.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o mcc_generated_files/drivers/i2c_simple_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/c66b99c5383d35505183dbd6d0c6cf517ae3a960.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o mcc_generated_files/drivers/i2c_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/e1abe54f0ec11e23de649feb444dee5855cd135c.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o mcc_generated_files/drivers/i2c_types.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/a8f5821ea9611f720c0b53fe2aeae57126ff46e3.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart2.o mcc_generated_files/uart2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/fb5cc74dd436d68fcfbed96e514006d8ac2d8095.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/e855059f05471a382636c1b2c130b295c4f31f93.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/42fedcc9b2ca2a310611686dc512a9db9ba878ee.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/exceptions.o.d" -o ${OBJECTDIR}/mcc_generated_files/exceptions.o mcc_generated_files/exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/152271d43e888745b3201c70e4222f49a1ecb4a4.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/2d11c399e4581d921ab1b45dd3caadf22d5c6643.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/7f0f8b340873fd1775998c3738564af2a8131bd4.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/delay.o: mcc_generated_files/delay.c  .generated_files/3e3455350ef3a4cf8535876cc6456a0903531a0c.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/delay.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/delay.o.d" -o ${OBJECTDIR}/mcc_generated_files/delay.o mcc_generated_files/delay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mcc_generated_files/i2c1_driver.o: mcc_generated_files/i2c1_driver.c  .generated_files/dd07f17a7efd158bde5d4b6cad4015e9060dadba.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c1_driver.o.d" -o ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o mcc_generated_files/i2c1_driver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/9c6d9a27b58a8d80bca12a7bc3ce02437ee10abe.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/RPR_0521RS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/RPR_0521RS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=200,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/RPR_0521RS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/RPR_0521RS.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=200,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/RPR_0521RS.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
