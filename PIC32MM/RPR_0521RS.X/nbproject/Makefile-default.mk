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
<<<<<<< HEAD
${OBJECTDIR}/_ext/1360930230/RPR0521RS.o: ../lib/RPR0521RS.c  .generated_files/e6aecf90b53f573f587a52b38bf847425708f7e2.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/_ext/1360930230/RPR0521RS.o: ../lib/RPR0521RS.c  .generated_files/44046315a54c02ac63fb5bbeb54faec88c6acb03.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/RPR0521RS.o.d" -o ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o ../lib/RPR0521RS.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/_ext/1360930230/UART.o: ../lib/UART.c  .generated_files/3fa1cdfae4010a6f6c734d037a789ca3dfc6774d.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/_ext/1360930230/UART.o: ../lib/UART.c  .generated_files/92dd00374eddccacf1118b4138a3a59d2ae8ba5a.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/UART.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/UART.o.d" -o ${OBJECTDIR}/_ext/1360930230/UART.o ../lib/UART.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o: ../lib/i2c_using_simple.c  .generated_files/c82c303762ccdf09da8dc07e05283565657e3b50.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o: ../lib/i2c_using_simple.c  .generated_files/a5a144adab187d899d5e38141b48f209497a23f7.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o.d" -o ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o ../lib/i2c_using_simple.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/c9699f9d279970c56d2b7e743f1414cdacde21a2.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/ed6d815abd7b302ed468e6deca3990ffb6ec7d85.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o mcc_generated_files/drivers/i2c_simple_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/8a234353492972780e26406a213f61ea541a17cf.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/4d53f9c82c3982214dd488e9b86bb1957a425d97.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o mcc_generated_files/drivers/i2c_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/b7f253ab40f858372d5b0454bb2c13cae5862fe8.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/41aaed3abb50271bc1de58289b917ef92e6469c7.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o mcc_generated_files/drivers/i2c_types.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/fd5645dfc3aca3e2f149cd09c8fbf1f292875e68.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/42bdea26da30a6c6bb3224a935c1f835e5436f1.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart2.o mcc_generated_files/uart2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/1e1aeb7d52d1e2b4217ba3d16163d0151e2c1ac6.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/fef3a23570f33d4ebb8e4bd5f5fbb2b3695d007f.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/beb03757350c9838618c2f8f4185619d56bbdd8e.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/4742d884b163f4a00189be0e7127e01b8e8a4742.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/5bcf093d41c8e26afb19cea77f28b2e2e4e605c7.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/b2056873507f5bdb9b064dddc37159fc8d5423b5.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/exceptions.o.d" -o ${OBJECTDIR}/mcc_generated_files/exceptions.o mcc_generated_files/exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/d6dd8fd94e6dc6a0f923cc6b42e98498477ec5c9.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/1d9d961665ccb6950ef955065bb5f116f7760608.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/f08b85dc2149ded76921beff17c6afd95f5b44b9.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/fe8f49b6e2264128cb7acb03acd273e9f7dd15aa.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/f1c6e1be4ad28414f503e8e11bf4a930ef1fde5a.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/4ca5eca6b2e9b0142889a6eaafb36ccf1697f04b.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/delay.o: mcc_generated_files/delay.c  .generated_files/c2f2cb846505a8787df5e78af5304053ed890ce1.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/delay.o: mcc_generated_files/delay.c  .generated_files/ed694ea248bb5b71f0f062716e3810fc16ca885c.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/delay.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/delay.o.d" -o ${OBJECTDIR}/mcc_generated_files/delay.o mcc_generated_files/delay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/i2c1_driver.o: mcc_generated_files/i2c1_driver.c  .generated_files/d7cdca875bb5b760a86c6a3fd199308e7bd10acf.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/i2c1_driver.o: mcc_generated_files/i2c1_driver.c  .generated_files/817558594f70082a3755fdd3ab939ceec15f15bd.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c1_driver.o.d" -o ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o mcc_generated_files/i2c1_driver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/main.o: main.c  .generated_files/56b80d099ac1bf36e36cd015718fc8b7412372f2.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/main.o: main.c  .generated_files/453f5b30cf902376619fc51d8103123bf30a1f29.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
<<<<<<< HEAD
${OBJECTDIR}/_ext/1360930230/RPR0521RS.o: ../lib/RPR0521RS.c  .generated_files/1b469ddfd61f80a1c2cd7e140ce622219941e560.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/_ext/1360930230/RPR0521RS.o: ../lib/RPR0521RS.c  .generated_files/b61a66907c9657054d2afa515dda5f28465c648c.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/RPR0521RS.o.d" -o ${OBJECTDIR}/_ext/1360930230/RPR0521RS.o ../lib/RPR0521RS.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/_ext/1360930230/UART.o: ../lib/UART.c  .generated_files/1c971f14084bbfd45dd80eece9eb783082305e92.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/_ext/1360930230/UART.o: ../lib/UART.c  .generated_files/300378d8596e56711927bf7b5df59b742b046c70.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/UART.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/UART.o.d" -o ${OBJECTDIR}/_ext/1360930230/UART.o ../lib/UART.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o: ../lib/i2c_using_simple.c  .generated_files/9ecde7227579dec30f731138de276c783b0b38c9.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o: ../lib/i2c_using_simple.c  .generated_files/52fc833530c3af4542a6ec0d0094f855772ed062.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/_ext/1360930230" 
	@${RM} ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o.d" -o ${OBJECTDIR}/_ext/1360930230/i2c_using_simple.o ../lib/i2c_using_simple.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/3cc5648229cc6d7a93d430ac99c2169acc9c84b6.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o: mcc_generated_files/drivers/i2c_simple_master.c  .generated_files/d49f28e6fef71a8dc70cd1bbd91d02555a346e2d.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_simple_master.o mcc_generated_files/drivers/i2c_simple_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/c66b99c5383d35505183dbd6d0c6cf517ae3a960.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o: mcc_generated_files/drivers/i2c_master.c  .generated_files/21c07f3cf203aa63cd3b3ad77ba5bef290812c74.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_master.o mcc_generated_files/drivers/i2c_master.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/e1abe54f0ec11e23de649feb444dee5855cd135c.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o: mcc_generated_files/drivers/i2c_types.c  .generated_files/784780524895eea9eb5fa6059ce2c26f95a0f7e2.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/drivers" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o.d" -o ${OBJECTDIR}/mcc_generated_files/drivers/i2c_types.o mcc_generated_files/drivers/i2c_types.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/a8f5821ea9611f720c0b53fe2aeae57126ff46e3.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/uart2.o: mcc_generated_files/uart2.c  .generated_files/af22d6addf88fcc40ce806d64f0d7f90ecd6992d.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart2.o.d" -o ${OBJECTDIR}/mcc_generated_files/uart2.o mcc_generated_files/uart2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/fb5cc74dd436d68fcfbed96e514006d8ac2d8095.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/5b7ef5dc6ce87efd615c7f5eadc4e16537856fcb.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d" -o ${OBJECTDIR}/mcc_generated_files/clock.o mcc_generated_files/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/e855059f05471a382636c1b2c130b295c4f31f93.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/4baf1cb5d8a4c63d3bd4b73b118a5a8ac66d71c3.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d" -o ${OBJECTDIR}/mcc_generated_files/system.o mcc_generated_files/system.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/42fedcc9b2ca2a310611686dc512a9db9ba878ee.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/exceptions.o: mcc_generated_files/exceptions.c  .generated_files/257975465322f34341b73891d2182a62166d790e.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/exceptions.o.d" -o ${OBJECTDIR}/mcc_generated_files/exceptions.o mcc_generated_files/exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/152271d43e888745b3201c70e4222f49a1ecb4a4.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/9e6a75e754ec6021040a500e9001e64d0a1cb03.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/2d11c399e4581d921ab1b45dd3caadf22d5c6643.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/1fd17517fa836b9cf6020301a8e6c69466b6a620.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o mcc_generated_files/interrupt_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/7f0f8b340873fd1775998c3738564af2a8131bd4.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/aea3784786e1f5d094bcdd33b3173b3631dffaf8.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o mcc_generated_files/pin_manager.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/delay.o: mcc_generated_files/delay.c  .generated_files/3e3455350ef3a4cf8535876cc6456a0903531a0c.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/delay.o: mcc_generated_files/delay.c  .generated_files/51ae22f2684dcb0e5e6c204803fff4896d34132b.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/delay.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/delay.o.d" -o ${OBJECTDIR}/mcc_generated_files/delay.o mcc_generated_files/delay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/mcc_generated_files/i2c1_driver.o: mcc_generated_files/i2c1_driver.c  .generated_files/dd07f17a7efd158bde5d4b6cad4015e9060dadba.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/mcc_generated_files/i2c1_driver.o: mcc_generated_files/i2c1_driver.c  .generated_files/3f22fe4e90319341c5e5b86c71ba704f4e3bbf64.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../lib" -I"mcc_generated_files" -I"mcc_generated_files/drivers" -ffunction-sections -fdata-sections -O2 -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/i2c1_driver.o.d" -o ${OBJECTDIR}/mcc_generated_files/i2c1_driver.o mcc_generated_files/i2c1_driver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
<<<<<<< HEAD
${OBJECTDIR}/main.o: main.c  .generated_files/9c6d9a27b58a8d80bca12a7bc3ce02437ee10abe.flag .generated_files/96f60eb670172c87a9b4a549401560e90c320e69.flag
=======
${OBJECTDIR}/main.o: main.c  .generated_files/938b9138a76cee245a5549cac5729b186b2d9f58.flag .generated_files/2d564709a8b4406af36196596b59c455b9b421e3.flag
>>>>>>> cce1e1cc0d33292771a05450124b72d8e39c9e54
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
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/RPR_0521RS.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC016FF -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=200,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
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
