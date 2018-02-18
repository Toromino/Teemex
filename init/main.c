/*
 * main.c
 *
 * The main class...
 *
 *  Created on: 20.08.2017
 *      Author: Dennis Lucas Buchholz
 */

#include <stdio.h>
#include <teemex/vga.h>
#include <teemex/tty.h>

/*
 * t_main() is currently the main entry point,
 * it get's called by boot.asm of the pursuant architecture
 */
void t_main()
{
	tty_init();
	tty_change_color(VGA_COLOR_GREEN);
	tty_print("-- Teemex Kernel v0.1 --");
	tty_print("\n\n[User|Test-System /]: ");
	tty_move_csr();

}
