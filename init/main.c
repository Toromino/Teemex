/*
 * main.c
 *
 *  Created on: 20.08.2017
 *      Author: Dennis Lucas Buchholz
 */



#include <string.h>
#include "../console.c"

void outportb(unsigned short _port, unsigned char _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void main()
{
	vid_init();
	console_print("Test Kernel(v0.1) by Toromino");
	console_print("\n\n[Test|Test-System]: ");
	console_print(csr_y);
}
