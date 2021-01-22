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

enum State{start, led0, led1, buttonWait} state;
void Tick(){
	switch (state) { // transitions
		case start:
			state = led0;
			break;
		case led0:
			if(PINA == 0x01){
				state = led1;
			}
			else{
				state = led0;
			}
			break;
		case led1:
			if(PINA ==0x00){
				state = buttonWait;
			}
			else{
				state= led1;
			}
			break;
		case buttonWait:
			if(PINA == 0x01){
				state = led0;
			}
			else{
				state = buttonWait;
			}
			break;
		default:
			state = start;
			break;
	}

	switch (state) { //actions
		case led0:
			PORTB = 0x01;
			break;
		case led1:
			PORTB = 0x02;
			break;
		case buttonWait:
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
	Tick();
    }
    return 1;
}
