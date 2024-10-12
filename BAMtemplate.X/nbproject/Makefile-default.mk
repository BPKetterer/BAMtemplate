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
FINAL_IMAGE=${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=button.c error.c external_interrupt.c port.c print.c serial.c queue.c rotary_encoder.c pause.c main.c interrupt.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/button.o ${OBJECTDIR}/error.o ${OBJECTDIR}/external_interrupt.o ${OBJECTDIR}/port.o ${OBJECTDIR}/print.o ${OBJECTDIR}/serial.o ${OBJECTDIR}/queue.o ${OBJECTDIR}/rotary_encoder.o ${OBJECTDIR}/pause.o ${OBJECTDIR}/main.o ${OBJECTDIR}/interrupt.o
POSSIBLE_DEPFILES=${OBJECTDIR}/button.o.d ${OBJECTDIR}/error.o.d ${OBJECTDIR}/external_interrupt.o.d ${OBJECTDIR}/port.o.d ${OBJECTDIR}/print.o.d ${OBJECTDIR}/serial.o.d ${OBJECTDIR}/queue.o.d ${OBJECTDIR}/rotary_encoder.o.d ${OBJECTDIR}/pause.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/interrupt.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/button.o ${OBJECTDIR}/error.o ${OBJECTDIR}/external_interrupt.o ${OBJECTDIR}/port.o ${OBJECTDIR}/print.o ${OBJECTDIR}/serial.o ${OBJECTDIR}/queue.o ${OBJECTDIR}/rotary_encoder.o ${OBJECTDIR}/pause.o ${OBJECTDIR}/main.o ${OBJECTDIR}/interrupt.o

# Source Files
SOURCEFILES=button.c error.c external_interrupt.c port.c print.c serial.c queue.c rotary_encoder.c pause.c main.c interrupt.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega168PA
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/button.o: button.c  .generated_files/flags/default/714fc344d639ea8866cbca650e885168a472f6a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/button.o.d 
	@${RM} ${OBJECTDIR}/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/button.o.d" -MT "${OBJECTDIR}/button.o.d" -MT ${OBJECTDIR}/button.o -o ${OBJECTDIR}/button.o button.c 
	
${OBJECTDIR}/error.o: error.c  .generated_files/flags/default/551c4429e2e0f980c0d9ad8921fb16f24145e44c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/error.o.d 
	@${RM} ${OBJECTDIR}/error.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/error.o.d" -MT "${OBJECTDIR}/error.o.d" -MT ${OBJECTDIR}/error.o -o ${OBJECTDIR}/error.o error.c 
	
${OBJECTDIR}/external_interrupt.o: external_interrupt.c  .generated_files/flags/default/6f6ac397430c438bf47cdb283b858004c43b8e7f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/external_interrupt.o.d 
	@${RM} ${OBJECTDIR}/external_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/external_interrupt.o.d" -MT "${OBJECTDIR}/external_interrupt.o.d" -MT ${OBJECTDIR}/external_interrupt.o -o ${OBJECTDIR}/external_interrupt.o external_interrupt.c 
	
${OBJECTDIR}/port.o: port.c  .generated_files/flags/default/94e77a49f17201657c7097433e30b1d11c86d6d9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/port.o.d 
	@${RM} ${OBJECTDIR}/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/port.o.d" -MT "${OBJECTDIR}/port.o.d" -MT ${OBJECTDIR}/port.o -o ${OBJECTDIR}/port.o port.c 
	
${OBJECTDIR}/print.o: print.c  .generated_files/flags/default/d3f38436828f3f3fd617694fa5910a5a16a044b7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/print.o.d 
	@${RM} ${OBJECTDIR}/print.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/print.o.d" -MT "${OBJECTDIR}/print.o.d" -MT ${OBJECTDIR}/print.o -o ${OBJECTDIR}/print.o print.c 
	
${OBJECTDIR}/serial.o: serial.c  .generated_files/flags/default/bdcfd031e264766b22bfa825623305b362211446 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial.o.d 
	@${RM} ${OBJECTDIR}/serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/serial.o.d" -MT "${OBJECTDIR}/serial.o.d" -MT ${OBJECTDIR}/serial.o -o ${OBJECTDIR}/serial.o serial.c 
	
${OBJECTDIR}/queue.o: queue.c  .generated_files/flags/default/4d5171494cffce7ed77f3ce884dcb26047e20155 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/queue.o.d 
	@${RM} ${OBJECTDIR}/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/queue.o.d" -MT "${OBJECTDIR}/queue.o.d" -MT ${OBJECTDIR}/queue.o -o ${OBJECTDIR}/queue.o queue.c 
	
${OBJECTDIR}/rotary_encoder.o: rotary_encoder.c  .generated_files/flags/default/9002aedb5927ddc85792e6e0ea20d1b756792e1a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rotary_encoder.o.d 
	@${RM} ${OBJECTDIR}/rotary_encoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/rotary_encoder.o.d" -MT "${OBJECTDIR}/rotary_encoder.o.d" -MT ${OBJECTDIR}/rotary_encoder.o -o ${OBJECTDIR}/rotary_encoder.o rotary_encoder.c 
	
${OBJECTDIR}/pause.o: pause.c  .generated_files/flags/default/bd63a7bd1c4f9fb9f0046d9a2717135fd50aef47 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pause.o.d 
	@${RM} ${OBJECTDIR}/pause.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/pause.o.d" -MT "${OBJECTDIR}/pause.o.d" -MT ${OBJECTDIR}/pause.o -o ${OBJECTDIR}/pause.o pause.c 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/2a9b594275aa07f2af7a5490c13a2990464f4613 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/interrupt.o: interrupt.c  .generated_files/flags/default/fb380a5bd71b35568d81af399ac0126b1efa3469 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupt.o.d 
	@${RM} ${OBJECTDIR}/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/interrupt.o.d" -MT "${OBJECTDIR}/interrupt.o.d" -MT ${OBJECTDIR}/interrupt.o -o ${OBJECTDIR}/interrupt.o interrupt.c 
	
else
${OBJECTDIR}/button.o: button.c  .generated_files/flags/default/a87eca2bec8db352848d49b5b337d81b1d1a655f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/button.o.d 
	@${RM} ${OBJECTDIR}/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/button.o.d" -MT "${OBJECTDIR}/button.o.d" -MT ${OBJECTDIR}/button.o -o ${OBJECTDIR}/button.o button.c 
	
${OBJECTDIR}/error.o: error.c  .generated_files/flags/default/217a8dc101fe0219d60f4fd99001e3776d37ce9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/error.o.d 
	@${RM} ${OBJECTDIR}/error.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/error.o.d" -MT "${OBJECTDIR}/error.o.d" -MT ${OBJECTDIR}/error.o -o ${OBJECTDIR}/error.o error.c 
	
${OBJECTDIR}/external_interrupt.o: external_interrupt.c  .generated_files/flags/default/18c421b969e3409f5179fecb601bd3c9a7f49b4e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/external_interrupt.o.d 
	@${RM} ${OBJECTDIR}/external_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/external_interrupt.o.d" -MT "${OBJECTDIR}/external_interrupt.o.d" -MT ${OBJECTDIR}/external_interrupt.o -o ${OBJECTDIR}/external_interrupt.o external_interrupt.c 
	
${OBJECTDIR}/port.o: port.c  .generated_files/flags/default/e4351fb960826eae238e235917c283282d8c6652 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/port.o.d 
	@${RM} ${OBJECTDIR}/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/port.o.d" -MT "${OBJECTDIR}/port.o.d" -MT ${OBJECTDIR}/port.o -o ${OBJECTDIR}/port.o port.c 
	
${OBJECTDIR}/print.o: print.c  .generated_files/flags/default/a6b0ec3099a77ca03e4fce1b6d4608a49aa67765 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/print.o.d 
	@${RM} ${OBJECTDIR}/print.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/print.o.d" -MT "${OBJECTDIR}/print.o.d" -MT ${OBJECTDIR}/print.o -o ${OBJECTDIR}/print.o print.c 
	
${OBJECTDIR}/serial.o: serial.c  .generated_files/flags/default/36a20e0015d628f774cbeb63d2e6c2a70aca8a0b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial.o.d 
	@${RM} ${OBJECTDIR}/serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/serial.o.d" -MT "${OBJECTDIR}/serial.o.d" -MT ${OBJECTDIR}/serial.o -o ${OBJECTDIR}/serial.o serial.c 
	
${OBJECTDIR}/queue.o: queue.c  .generated_files/flags/default/c4965b8a605907c084fe9d3a576ca071501af29b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/queue.o.d 
	@${RM} ${OBJECTDIR}/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/queue.o.d" -MT "${OBJECTDIR}/queue.o.d" -MT ${OBJECTDIR}/queue.o -o ${OBJECTDIR}/queue.o queue.c 
	
${OBJECTDIR}/rotary_encoder.o: rotary_encoder.c  .generated_files/flags/default/3b76e2db9405193969c932a2f6781c79f17e0bf2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rotary_encoder.o.d 
	@${RM} ${OBJECTDIR}/rotary_encoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/rotary_encoder.o.d" -MT "${OBJECTDIR}/rotary_encoder.o.d" -MT ${OBJECTDIR}/rotary_encoder.o -o ${OBJECTDIR}/rotary_encoder.o rotary_encoder.c 
	
${OBJECTDIR}/pause.o: pause.c  .generated_files/flags/default/16c629ef1ec593513189f9ebbb3607908035e2ee .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pause.o.d 
	@${RM} ${OBJECTDIR}/pause.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/pause.o.d" -MT "${OBJECTDIR}/pause.o.d" -MT ${OBJECTDIR}/pause.o -o ${OBJECTDIR}/pause.o pause.c 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/ca69955b521b693597973dfa14574bf19bf4a7c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/interrupt.o: interrupt.c  .generated_files/flags/default/a0a0c49e32cc3d16be7429a6850a13425db71ec6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupt.o.d 
	@${RM} ${OBJECTDIR}/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem --std=c90 -Werror -Wdouble-promotion -Wfloat-conversion     -MD -MP -MF "${OBJECTDIR}/interrupt.o.d" -MT "${OBJECTDIR}/interrupt.o.d" -MT ${OBJECTDIR}/interrupt.o -o ${OBJECTDIR}/interrupt.o interrupt.c 
	
endif

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
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/BAMtemplate.X.${IMAGE_TYPE}.hex"
	
endif


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

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
