#----------------------------------------------
# GNUMakefile for xc8-cc
# Plattform: Microchip PICmicro
# Compiler: xc8-cc
#----------------------------------------------

PROJECT = doppelblitz
TARGET = 18F45K20

#----------------------------------------------
# Paths
#----------------------------------------------
XC8_DIR = "C:\DevTools\Microchip\xc8\v3.10\bin"
DFP_DIR = c:/DevTools/Microchip/packs/PIC18F-K_DFP/1.15.303

#----------------------------------------------
# Tools
#----------------------------------------------
CC = $(XC8_DIR)\xc8-cc.exe
AS = $(XC8_DIR)\xc8-cc.exe
LD = $(XC8_DIR)\xc8-cc.exe
AR = $(XC8_DIR)\xc8-ar.exe

#----------------------------------------------
# Includes
#----------------------------------------------
INCPATH = 
LKRPATH =
LIBPATH =

#----------------------------------------------
# Options
#----------------------------------------------
CFLAGS = -mcpu=$(TARGET) -mdfp="$(DFP_DIR)/xc8" -Wa,-a -O2 -msummary=+psect,-class,+mem,-hex,-file
LFLAGS =
RFLAGS =

# ignore all make-internal rules
.SUFFIXES:

#----------------------------------------------
# Targets
#----------------------------------------------
.PHONY: all
all: $(PROJECT).hex

.PHONY: $(PROJECT)
$(PROJECT): $(PROJECT).hex

.PHONY: clean
clean:
	-@del /q /e *.bak *.cmf *.d *.elf *.hxl *.i *.lst *.o *.p1 *.rlf *.s *.sdb *.sym

.PHONY: clean-all
clean-all: clean
	-@del /q /e *.hex

#----------------------------------------------
# Pattern rules
#----------------------------------------------
#
%.hex : %.c
	$(CC) $(CFLAGS) -o$(PROJECT).hex $<

# relocatable assembler
#%.out : %.c
#	@$(CC) -a$@ -Act12+7+10 -ed -ew $(CFLAGS) -r $<

# absolute assembler
#%.asm : %.c
#	@$(CC) -a$@ -AtJ12+7+14 -ed -ew $(CFLAGS) $<

#----------------------------------------------
# Explicit rules
#----------------------------------------------


