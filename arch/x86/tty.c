/*
 * tty.c
 *
 * This is the teletype class...
 *
 *  Created on: 13.01.2018
 *      Author: Dennis Lucas Buchholz
 */

#if !defined(__cplusplus)
/* Booleans are not included in C by default. Yet in CPP they are. */
#include <stdbool.h>
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <teemex/io.h>
#include <teemex/string.h>
#include <teemex/vga.h>
#include <teemex/tty.h>

// VGA memory adress for text mode
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t tty_row;
static size_t tty_col;

// Coordinates of the TTY cursor
static size_t tty_csr_x;
static size_t tty_csr_y;

static uint16_t* tty_buffer;

// TTY attribute (color)
static uint8_t tty_attr = VGA_COLOR_GREEN;

void tty_init(void)
{
  tty_row = 0;
  tty_col = 0;
  tty_csr_x = 0;
  tty_csr_y = 0;

  tty_clear();
}

void tty_move_csr(void)
{
  unsigned temp;

  temp = tty_csr_y * 80 + tty_csr_x;

  outb(0x3D4, 14);
  outb(0x3D5, temp >> 8);
  outb(0x3D4, 15);
  outb(0x3D5, temp);
}

void tty_change_color (uint8_t _color)
{
  tty_attr = _color;
}

void tty_putchar(char _char)
{
  short* destination;
  unsigned att = tty_attr << 8;

  if(_char == '0x08'){ if (tty_csr_x != 0){ tty_csr_x--; }}
  else if(_char == '0x09'){ tty_csr_x = (tty_csr_x + 8) & ~(8 - 1); }
  else if(_char == '\r'){ tty_csr_x = 0; }
  else if(_char == '\n'){ tty_csr_x = 0; tty_csr_y++; }
  else if(_char >= ' '){ destination = VGA_MEMORY + (tty_csr_y * 80 + tty_csr_x); *destination = _char | att; tty_csr_x++; }

  if (tty_csr_x >= 80){ tty_csr_x = 0; tty_csr_y++; }
}

void tty_print(const char* _data)
{
  for(int i = 0; i < strlen(_data); i++) { tty_putchar(_data[i]); }
}

void tty_clear()
{
  int i = 0;
  while(i < 80 * 25 * 2)
  {
    VGA_MEMORY[i++] = 0;
  }

  tty_csr_x = 0;
  tty_csr_y = 0;
}
