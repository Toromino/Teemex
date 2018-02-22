# Teemex Kernel

## What is Teemex?
Teemex aims to be a lightweight OS kernel, which is easy to understand for human beings. Primarily for learning purposes.

## Required Packages
The following packages are required to build this kernel:
- nasm
- GNU's gcc & ld
- qemu-system-x86_64 (for testing)

## Compiling

```
make teemex
```

And you could use qemu for testing...
```
qemu-system-x86_64 -kernel start.bin
```
