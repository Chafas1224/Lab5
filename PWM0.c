/*
 * PWM0.c
 *
 * Created: 14/04/2024 12:23:36
 *  Author: pablo
 */ 
#include "PWM0.h"

void initPWM0FastA(uint8_t inverted, uint16_t prescaler){
	//Configurando el pin PD6 como salida (OC0A)
	DDRD |= (1<<DDD6);
	
	TCCR0A = 0;
	if(inverted){
		//Configurando OC0A como invertido
		TCCR0A |= (1<<COM0A1)|(1<<COM0A0);
	}
	else{
		//Configurando OC0A como no invertido
		TCCR0A |= (1<<COM0A1);
	}
	
	
	//Configurando Modo PWM FAST TOP = 0xFF
	TCCR0A |= (1<<WGM01)|(1<<WGM00);
	//Prescaler de 1024
	TCCR0B |= (1<<CS02)|(1<<CS00);	
}

void initPWM0FastB(uint8_t inverted, uint16_t prescaler){
	//Configurando el pin PD6 como salida (OC0A)
	DDRD |= (1<<DDD5);
	
	TCCR0B = 0;
	
	if(inverted){
		//Configurando OC0A como invertido
		TCCR0B |= (1<<COM0B1)|(1<<COM0B0);
	}
	else{
		//Configurando OC0A como no invertido
		TCCR0B |= (1<<COM0B1);
	}
	
	//Configurando Modo PWM FAST TOP = 0xFF
	TCCR0A |= (1<<WGM01)|(1<<WGM00);
	//Prescaler de 1024
	TCCR0B |= (1<<CS02)|(1<<CS00);
}

void updateDutyCicleA(uint8_t duty){
	OCR0A = duty;
}

void updateDutyCicleB(uint8_t duty){
	OCR0B = duty;
}