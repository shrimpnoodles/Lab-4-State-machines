/*	Author: hcier001
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum States {start, LED0, BPUSH, BNOTP} state;
unsigned button;
void Tick(){
	switch(state) { //transitions
		case start:
			state = LED0;
			break;
		case LED0:
			if(button == 0x01){
				state = BPUSH;
			}
			break;
		case BPUSH:
			if(button == 0X00){
				state = BNOTP;
			}
			break;
		case BNOTP:
			if(button == 0x01){
				state = LED0;
			}
			break;
		default:
			state = start;
			break;
		}
	switch(state){ //actions
		case LED0:
			PORTB= 0X01;
			break;
		case BPUSH:
			PORTB = 0x02;
			break;
		case BNOTP:
			PORTB = 0x02;
			break;
		default:
			break;
	}
}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0X00; PORTA = 0XFF;
	DDRB = 0XFF; PORTB = 0X00;
	state = start;
    /* Insert your solution below */
    while (1) {
	button = PINA;
	Tick();
    }

    return 1;
}
