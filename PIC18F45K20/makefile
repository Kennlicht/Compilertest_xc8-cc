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
DFP_DIR = "c:/DevTools/Microchip/packs/PIC18F-K_DFP/1.15.303/xc8"

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
CFLAGS = -O2 -std=c99 -Wpedantic
LFLAGS = -Wa,-a -msummary=+psect,-class,+mem,-hex,-file
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
# compile
%.p1 : %.c
	$(CC) -mcpu=$(TARGET) -mdfp=$(DFP_DIR) $(CFLAGS) -c $< -o$@

# link
%.hex : %.p1
	$(CC) -mcpu=$(TARGET) -mdfp=$(DFP_DIR) $(LFLAGS) -o$(PROJECT).hex $<

# compile + link
%.hex : %.c
	$(CC) -mcpu=$(TARGET) -mdfp=$(DFP_DIR) $(CFLAGS) $(LFLAGS) -o$(PROJECT).hex $<

#----------------------------------------------
# Explicit rules
#----------------------------------------------


