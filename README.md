# Kernel

## Required Packages
The following packages are required to build this kernel:
- nasm
- gcc
- ld
- qemu-system-i386 (optional)

## Compiling

### Windows
On Windows you'll need MinGW, Cygwin or something different to be installed.
To compile it, type this in the MSYS Shell...
```
nasm -f elf32 -o loader.o loader.asm

gcc -m32 -o kernel.o -c kernel.c -nostdlib -nostartfiles -nodefaultlibs

ld -T linker.ld -m elf_i386 -o start.bin loader.o kernel.o
```

And you can use qemu to run it.
```
qemu-system-i386 -kernel start.bin
```

### Linux
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
