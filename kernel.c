/*
 ============================================================================
 Name        : kern.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

void screen_print (char *text)
{
	char *mem = (char*)0xb8000;
	while(*text)
	{
		*mem++ = *text++;
		*mem++ = 0x3;
	}
}

void screen_clear ()
{
	char *mem = (char*)0xb8000;
	int i = 0;
	while (i < 80 * 25 *2)
	{
		mem[i++] = 0;
	}
}

void kernel_main()
{
	screen_clear();
	screen_print("---------TEST KERNEL BY TOROMINO----------");
}
