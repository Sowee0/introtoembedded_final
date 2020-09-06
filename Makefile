#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets: MSP432
#                HOST
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Output file

OUTPUT = final.out
MAPFILE = final.map
# Platform Overrides
PLATFORM = HOST
COURSE = COURSE1
VERBOSITY = 

# Architectures Specific Flags
LINKER_FILE = ./msp432p401r.lds 
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs



# Compiler Flags and Defines
CC = gcc
LDFLAGS = 
COMMONCFLAGS = -O0 -Wall -Werror -g -std=c99
CPPFLAGs = 

#Setting flags according to the target
ifeq ($(PLATFORM),HOST)
		CC = gcc
		CFLAGS = $(COMMONCFLAGS) -I$(INCLUDECOMMON) -D$(PLATFORM) -D$(COURSE) -D$(VERBOSITY)
		OFILES = $(SOURCES:.c=.o)
		SOURCE = $(SOURCECOMMON)
		OBJDUMP = objdump
		SIZEUTIL = size
		
	else
		CC = arm-none-eabi-gcc
		LDFLAGS = -T$(LINKER_FILE)
		CFLAGS = $(COMMONCFLAGS) -I$(INCLUDECOMMON) -I$(INCLUDEMSP) -I$(INCLUDECMSIS) -D$(PLATFORM)  -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
		OFILES = $(SOURCES:.c=.o)
		IFILES = $(SOURCES:.c=.i)
		SOURCE = $(SOURCECOMMON) $(SOURCEMSP)
		OBJDUMP = arm-none-eabi-objdump
		SIZEUTIL = arm-none-eabi-size
	endif




#Compiles all object files and links the final executable
.PHONY: build
build: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LDFLAGS) -o $(OUTPUT)
	$(SIZEUTIL) $(OUTPUT) $(OFILES)

#This rule compiles the object files
%.o: $(SOURCE)
	$(CC) -c $(CFLAGS) $(SOURCE)

%.i: $(SOURCE)
	$(CC) -E $(CFLAGS) $(SOURCE)  

%.asm: $(OFILES)
	$(CC) -c $(CFLAGS) $(SOURCE) -S
	$(OBJDUMP) -x $(OFILES)

#This recipe compiles all the files but DOES NOT link
.PHONY: compile-all
compile-all: $(OFILES)


#Removes all compiled objects, preprocessed outputs, assembly outputs
.PHONY: clean
clean:
	rm -f *.map
	rm -f *.asm
	rm -f *.o
	rm -f *.i
	rm -f *.s 
	rm -f *.out

