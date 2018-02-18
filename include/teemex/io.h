#ifndef _TEEMEX_IO_H
#define _TEEMEX_IO_H

static inline uint8_t inb(unsigned short _port)
{
	uint8_t output;

	__asm__ __volatile__ ("inb %1, %0" : "=a" (output) : "Nd"(_port));

	return output;
}

static inline void outb(unsigned short _port, unsigned char _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

#endif
