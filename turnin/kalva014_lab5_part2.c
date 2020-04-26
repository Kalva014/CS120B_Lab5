/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description:  A car has a fuel-level sensor that sets PA3..PA0 to a value between 0 (empty) and 15 (full).
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
  int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
    /* Insert your solution below */
    while (1) {
	
	button = ~PINA; // Since button when pushed is 0 flip every bit

	if (button == 0) {
		PORTC = 0x40;
	}
	else if(button <= 2) {
		PORTC = 0x60; //0110 0000
	}
	else if((button <= 4) && (button > 2)) {
		PORTC = 0x70; //0111 0000
	}
	else if((button <= 6) && (button >= 5)) {
		PORTC = 0x38; //0011 1000
	}
	else if((button <= 9) && (button >= 7)) {
		PORTC = 0x3C; //0011 1100
	}
	else if((button <= 12) && (button >= 10)) {
		PORTC = 0x3E; //0011 1110
	}
	else if((button <= 15) && (button >= 13)) {
		PORTC = 0x3F ; //0011 1111
	}
    }
    return 1;
}
