#ifndef _TEEMEX_TTY_H
#define _TEEMEX_TTY_H

#include <stddef.h>
#include <stdint.h>

void tty_init(void);
void tty_putchar(char _char);
void tty_print(const char* _data);
void tty_clear(void);
void tty_move_csr(void);
void tty_change_color(uint8_t _color);

#endif
