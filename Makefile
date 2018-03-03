##
## Makefile
##
## This Makefile contains all neccesary build routines.
## For better structuring and clarity everything is in this single file.
##
##  Created on: 13.01.2018
##      Author: Dennis Lucas Buchholz
##

# Default programs used for building...
CC 					:= gcc
LD 					:= ld

WARNINGS		:= -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
						 	 -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
	             -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
	             -Wconversion -Wstrict-prototypes
CFLAGS			:= -g -O2 -nostdlib -nostartfiles -nodefaultlibs -m32 -Iinclude $(WARNINGS)

PREFIX 			:= teemex
INCLUDEDIR	:= $(PREFIX)/include
LIBDIR 			:= $(PREFIX)/lib

OBJS 				:= tty.o

#CFLAGS := $(CFLAGS) $(ARCH_CFLAGS)
.PHONY: clean

teemex: teemex.bin
	make clean

lib/string.c.o: lib/string.c
	@$(CC) $(CFLAGS) -MMD -MP -c lib/string.c -o lib/string.c.o

arch/x86/tty.c.o: arch/x86/tty.c
	@$(CC) $(CFLAGS) -MMD -MP -c arch/x86/tty.c -o arch/x86/tty.c.o

arch/x86/boot.asm.o: arch/x86/boot.asm
	nasm -f elf32 -o arch/x86/boot.asm.o arch/x86/boot.asm

init/main.c.o: init/main.c
	@$(CC) $(CFLAGS) -MMD -MP -c init/main.c -o init/main.c.o

teemex.bin: lib/string.c.o arch/x86/boot.asm.o arch/x86/tty.c.o init/main.c.o
	ld -T arch/x86/linker.ld -m elf_i386 -o teemex.bin lib/string.c.o arch/x86/boot.asm.o arch/x86/tty.c.o init/main.c.o

# Will come up with a better solution ... later :)
clean:
	rm */*.o
	rm */*.d
	rm */*/*.o
	rm */*/*.d
