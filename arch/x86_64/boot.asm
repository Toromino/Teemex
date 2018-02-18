global loader

; MULTIBOOT
section .multiboot

        ; Multiboot constants
        MBALIGN   equ   1<<0
        MEMINFO   equ   1<<1
        MAGIC     equ   0x1BADB002
        FLAGS     equ   MBALIGN | MEMINFO
        CHECKSUM  equ   -(MAGIC+FLAGS)

        align 4
        dd MAGIC
        dd FLAGS
        dd CHECKSUM

section .text

        loader:
                extern t_main
                call t_main
                cli

        quit:
                hlt
                jmp quit
