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
                        
enum States {Start, Init, Light13, Release13, Light24, Release24, Light35, Release35, Light46, Release46, LightAll, ReleaseLight} state;
unsigned char tmpA;
unsigned char tmpB;

void Tick() {
        switch(state) { //transitions
                case Start:
                        state = Init;
                        break;
                case Init:
                        if((tmpA & 0x01) == 0x01) {
                                state = Light13;
                        }
                        else {
                                state = Init;
                        }
                        break;
                case Light13:
                        if((tmpA & 0x01) == 0x01) {
                                state = Light13;
                        }
                        else {
                                state = Release13;
                        }
                        break;
                case Release13:
                        if((tmpA & 0x01) == 0x01) {
                                state = Light24;
                        }
                        else {
                                state = Release13;
                        }
                        break;
                case Light24:
                        if((tmpA & 0x01) == 0x01) {
                                state = Light24;
                        }
                        else {
                                state = Release24;
                        }
                        break;
                case Release24:
                        if((tmpA & 0x01) == 0x01) {
                                state = Light35;
                        }
                        else {
                                state = Release24;
                        }
                        break;
                case Light35:
                        if((tmpA & 0x01) == 0x01) {
                                state = Light35;
                        }
                        else {
                                state = Release35;
                        }
                        break;
                case Release35:
                        if((tmpA & 0x01) == 0x01) {
                                state = Light46;
                        }
                        else {
                                state = Release35;
                        }
                        break;
                case Light46:
			if((tmpA & 0x01) == 0x01) {
                                state = Light46;
                        }
                        else {
                                state = Release46;
                        }
			break;
		case Release46:
			if((tmpA & 0x01) == 0x01) {
                                state = LightAll;
                        }
                        else {
                                state = Release46;
                        }
			break;
		case LightAll:
                        if((tmpA & 0x01) == 0x01) { //If button is held down then stay in release
                                state = LightAll;
                        }
                        else {
                                state = ReleaseLight;
                        }
                        break;
		case ReleaseLight:
			if((tmpA & 0x01) == 0x01) {
				state = Init;
			}
			else {
				state = ReleaseLight;
			}
			break;
                default:
                        break;
        }
        switch(state) { //actions
                case Start:
                        tmpB = 0x00;
                        break;
                case Init:
                        tmpB = 0x00;
                        break;
                case Light13:
                        tmpB = 0x05; //0000 0101
                        break;
                case Release13:
                        break;
                case Light24:
                        tmpB = 0x0A; //0000 1010
                        break;
                case Release24:
                        break;
                case Light35:
                        tmpB = 0x14; //0001 0100
                        break;
                case Release35:
                        break;
		case Light46:
			tmpB = 0x28; //0010 1000
			break;
		case Release46:
                	break;
		case LightAll:
                        tmpB = 0x3F; //0001 1111
                        break;
		case ReleaseLight:
			break;
                default:
                        break;
        }
}


int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF; PORTB = 0x00;
        state = Start; //Inital state

    /* Insert your solution below */
    while (1) {
	tmpA = ~PINA;
        tmpB = PINB;
        Tick();
	PORTB = tmpB;
    }
       return 1;
}
