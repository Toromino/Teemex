# Teemex Kernel

## What is Teemex?
Teemex aims to be a lightweight OS kernel, which is easy to understand for human beings. Primarily for learning purposes. 

## Required Packages
The following packages are required to build this kernel:
- nasm
- gcc
- ld
- qemu-system-i386 (for testing)

## Compiling

### Windows
On Windows you'll need a POSIX shell like MinGW or Cygwin to be installed, to use make.
For compiling use...
```
make.exe Makefile
```

And you can use qemu to run it.
```
qemu-system-i386 -kernel start.bin
```

### Linux
On Linux it's fairly easy...
```
make teemex
```

And use qemu to run it.
```
qemu-system-i386 -kernel start.bin
```
