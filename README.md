# Teemex Kernel

## What is Teemex?
Teemex aims to be a lightweight OS kernel supporting several CPU architecture. It was primarily created for learning purposes.

Currently Teemex only supports x86 CPUs.

## Required Packages
The following packages are required to build Teemex:
- nasm
- GNU's gcc, g++-multilib & ld
- qemu-system-x86_64 (for testing)

## Compiling
```
make teemex
```

## Testing
```
qemu-system-x86_64 -kernel teemex.bin
```
