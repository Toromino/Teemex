/*
 * keyboard.c
 *
 * PS/2 keyboard driver
 *
 *  Created on: 18.02.2018
 *      Author: Dennis Lucas Buchholz
 */

 enum keycode
 {
   ESCAPE_PRESSED = 0x01,
   NUM_1_PRESSED  = 0x02,
   NUM_2_PRESSED  = 0x03,
   NUM_3_PRESSED  = 0x04,
   NUM_4_PRESSED  = 0x05,
   NUM_5_PRESSED  = 0x06,
   NUM_6_PRESSED  = 0x07,
   NUM_7_PRESSED  = 0x08,
   NUM_8_PRESSED  = 0x09,
   NUM_9_PRESSED  = 0x0A,
   NUM_0_PRESSED  = 0x0B,
 };

 void keyboard_init()
 {

 }

 char keyboard_getKey()
 {
   return keycode[getKeycode()+1];
 }

 char getKeycode()
 {
   while (!(inb(0x64) & 1));
   return inb(0x60);
 }
