teemex: kernel.o loader.o teemex.bin
	make clean
loader.o: loader.asm
	nasm -f elf32 -o loader.o loader.asm

kernel.o: init/main.c
	gcc -m32 -o kernel.o -c init/main.c -nostdlib -nostartfiles -nodefaultlibs

teemex.bin:
	ld -T linker.ld -m elf_i386 -o teemex.bin loader.o kernel.o

clean:
	rm *.o
