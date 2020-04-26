/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: Create your own festive lights display 
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum States {Start, Init, Light13, Release13, Light24, Release24, Light35, Release35, LightAll} state;
unsigned char TMPB = 0x00;

void Tick() {
	switch(state) { //transitions
		case Start:
			state = Init;
			break;
		case Init:
			if((~PINA & 0x01) == 0x01) {
				state = Light13;
			}
			else {
				state = Init;
			}
			break;
		case Light13:
			if((~PINA & 0x01) == 0x01) {
                                state = Light13;
                        }
			else {
				state = Release13;
			}
			break;
		case Release13:
			if((~PINA & 0x01) != 0x01) {
				state = Light24;
			}
			else {
				state = Release13;
			}
			break;
		case Light24:
			if((~PINA & 0x01) == 0x01) {
				state = Light24;
			}
			else {
				state = Release24;
			}
			break;
		case Release24:
                        if((~PINA & 0x01) != 0x01) {
                                state = Light35;
                        }
                        else {
                                state = Release24;
                        }
                        break;
		case Light35:
			if((~PINA & 0x01) == 0x01) {
       				state = Light35;
                        }
			else {
				state = Release35;
			}
			break;
		case Release35:
                        if((~PINA & 0x01) != 0x01) {
                                state = LightAll;
                        }
                        else {
                                state = Release35;
                        }
                        break;
		case LightAll:
			if((PINA & 0x01) == 0x01) { //If button is held down then stay in release
				state = LightAll;
			}
			else {
				state = Init;
			}
			break;
		default:
			break; 
	}

	switch(state) { //actions
		case Start:
                        TMPB = 0x00;
                        break;
                case Init:
			TMPB = 0x00;
                        break;
                case Light13:
                        TMPB = 0x05; //0000 0101
                        break;
                case Release13:	
			break;
		case Light24:
			TMPB = 0x0A; //0000 1010
                        break;
		case Release24:
			break;
                case Light35:
			TMPB = 0x14; //0001 0100
                        break;
		case Release35:
			break;
                case LightAll:
			TMPB = 0x1F; //0001 1111
                        break;
                default:
                        break; 
	}

	PORTB = TMPB;
}


int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF; PORTB = 0x00;
	state = Start; //Inital state		
	//unsigned char TMPB = 0x00;
	
    /* Insert your solution below */
    while (1) {
	TMPB = 0x00;
	Tick();
    }
       return 1;
}
