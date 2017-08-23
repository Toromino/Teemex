# Kernel



## Compiling


### Linux
The following packages are required to compile this kernel on linux:
- nasm
- gcc
- ld
- qemu-system-i386 (optional)

To compile it on Linux type...
```
nasm -f elf32 -o loader.o loader.asm

gcc -m32 -o kernel.o -c kernel.c -nostdlib -nostartfiles -nodefaultlibs

ld -T linker.ld -m elf_i386 -o start.bin loader.o kernel.o
```

And use qemu to run it.
```
qemu-system-i386 -kernel start.bin
```
