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
<<<<<<< HEAD

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
			state = buttonWait;
			break;
		case buttonWait:
			if(PINA == 0x01){
				state = led0;
			}
			else{
				state = buttonWait;
=======
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
>>>>>>> 90c746160a6dd657438e35456c316a60576ec826
			}
			break;
		default:
			state = start;
			break;
		}
<<<<<<< HEAD
	switch (state) { //actions
		case led0:
			PORTB = 0x01;
			break;
		case led1:
			PORTB = 0x02;
			break;
		case buttonWait:
=======
	switch(state){ //actions
		case LED0:
			PORTB= 0X01;
			break;
		case BPUSH:
			PORTB = 0x02;
			break;
		case BNOTP:
>>>>>>> 90c746160a6dd657438e35456c316a60576ec826
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
<<<<<<< HEAD
	Tick();
    }
=======
	button = PINA;
	Tick();
    }

>>>>>>> 90c746160a6dd657438e35456c316a60576ec826
    return 1;
}
