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
enum States {start, init, p0push, p1push, reset} state;
unsigned portcCount;
void Tick(){
	switch(state) { //transitions
		case start:
			state = init;
			break;
		case init:
			if(PINA == 0X01){
				state = p0push;
			}
			else if(PINA == 0x02){
				state = p1push;
			}
			break;
		case p0push:
			if(PINA == 0x02){
				state = reset;
			}
			break;
		case p1push:
			if(PINA == 0x01){
				state = reset;
			}
			break;
		case reset:
			break;
		default:
			state = start;
			break;
		}
	switch(state){ //actions
		case init:
			portcCount =7;
			break;
		case p0push:
			if(portcCount < 9){
				portcCount++;
			}
			break;
		case p1push: 
			if(portcCount > 0){
				portcCount--;
			}
			break;
		case reset:
			portcCount =0;
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
	portcCount = 7;
    /* Insert your solution below */
    while (1) {
	Tick();
	PORTC = portcCount;
    }

    return 1;
}
