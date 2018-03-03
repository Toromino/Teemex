# Teemex Kernel

## What is Teemex?
Teemex aims to be a lightweight OS kernel, primarily for learning purposes.

## Required Packages
The following packages are required to build Teemex:
- nasm
- GNU's gcc & ld
- qemu-system-x86_64 (for testing)

## Compiling
```
make teemex
```

## Testing
```
qemu-system-x86_64 -kernel start.bin
```
