global loader
extern main
MAGIC equ 0x1badb002
FLAGS equ 0x3
CHECKSUM equ -(MAGIC+FLAGS)

section .text
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

loader:
call main
cli

quit:
hlt
jmp quit
