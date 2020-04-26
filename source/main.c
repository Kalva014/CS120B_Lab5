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
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char TMPC = 0x00;
		
    /* Insert your solution below */
    while (1) {
	TMPC = 0x00;	
	//button = ~PINA; // Since button when pushed is 0 flip every bit

	if(((~PINA & 0x0F) > 0) && (~PINA & 0x0F) <= 2) {
		TMPC = 0x20; //0010 0000
	}
	else if(((~PINA & 0x0F) == 3) || ((~PINA & 0x0F) == 4)) {
		TMPC = 0x30; //0011 0000
	}
	else if(((~PINA & 0x0F) == 6) || ((~PINA & 0x0F) == 5)) {
		TMPC = 0x38; //0011 1000
	}
	else if(((~PINA & 0x0F) == 9) || ((~PINA & 0x0F) == 8) || ((~PINA & 0x0F) == 7)) {
		TMPC = 0x3C; //0011 1100
	}
	else if(((~PINA & 0x0F) == 12) || ((~PINA & 0x0F) == 11) || ((~PINA & 0x0F) == 10)) {
		TMPC = 0x3E; //0011 1110
	}
	else if(((~PINA & 0x0F) == 15) || ((~PINA & 0x0F) == 14) || ((~PINA & 0x0F) == 13)) {
		TMPC = 0x3F; //0011 1111
	}

	if(((~PINA & 0x0F) <= 4)) {
		TMPC = TMPC | 0x40 ; //0100 0000
	}
	
	PORTC = TMPC;
    }
    return 1;
}
