/*
 * console.c
 *
 *  Created on: 20.08.2017
 *      Author: Dennis Lucas Buchholz
 */

int attr = 0x0F;
int csr_x = 0, csr_y = 0;
unsigned short *mem;

void vid_init ()
{
	mem = (short *)0xB8000;
	console_clear();
}

int str_length(char *str)
{
    int len = 0;
    int i;

    for (i=0; str[i] != 0; i++)
    {
        len++;
    }
    return(len);
}

void move_csr ()
{
	unsigned temp;

	    temp = csr_y * 80 + csr_x;

	    outportb(0x3D4, 14);
	    outportb(0x3D5, temp >> 8);
	    outportb(0x3D4, 15);
	    outportb(0x3D5, temp);
}

void console_put_str (char str)
{
	short* dest;
	unsigned att = attr << 8;

	if (str == 0x08)
	{
		if (csr_x != 0) csr_x--;
	}

	else if (str == 0x09)
		{
			csr_x = (csr_x + 8) & ~(8 - 1);
	}

	else if (str == '\r')
	{
		csr_x = 0;
	}

	else if (str == '\n')
	{
		csr_x = 0;
		csr_y++;
	}

	else if (str >= ' ')
	{
		dest = mem + (csr_y * 80 + csr_x);
		*dest = str | att;
		csr_x++;
	}

	if (csr_x >= 80)
		{
			csr_x = 0;
			csr_y++;
	}

	move_csr();
}


void console_print (char *text)
{
	for(int i = 0; i < str_length(text); i++)
	{
		console_put_str(text[i]);
	}
}

void console_clear ()
{
	int i = 0;
	while (i < 80 * 25 *2)
	{
		mem[i++] = 0;
	}

	csr_x = 0;
	csr_y = 0;
	move_csr();
}
