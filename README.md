# Teemex Kernel

## What is Teemex?
Teemex aims to be a lightweight OS kernel, which is easy to understand for human beeings. 

## Required Packages
The following packages are required to build this kernel:
- nasm
- gcc
- ld
- qemu-system-i386 (for testing)

## Compiling

### Windows
On Windows you'll need MinGW, Cygwin or something different to be installed.
To compile it, type this in the MSYS Shell...
```
make.exe Makefile
```

And you can use qemu to run it.
```
qemu-system-i386 -kernel start.bin
```

### Linux
To compile it on Linux type...
```
make teemex
```

And use qemu to run it.
```
qemu-system-i386 -kernel start.bin
```
