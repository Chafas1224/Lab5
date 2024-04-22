/*
 * PWM1.c
 *
 * Created: 15/04/2024 13:22:23
 *  Author: pablo
 */ 

#include "PWM1.h"

void initPWM1Fast_16bit(uint8_t inverted, uint16_t prescaler){
	//cli();
	UCSR0B = 0;
	//Configurar el pin PB1 como salida para OC1A
	DDRB |= (1<<DDB1);
	
	//Limpiar registros
	TCCR1A = 0;
	TCCR1B = 0;
	
	//Configuración de modo y prescaler
	TCCR1A |= (1<<COM1A1);
	
	
	//Establecer el modo de operación como PWM 16-bit
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM13)|(1<<WGM12);
	
	//Confgurar prescaler
	TCCR1B |= (1<<CS11);
	
	//Escribir 39999 a ICR1 dividido entre H y L
	ICR1H = 0x9C;
	ICR1L = 0x3F;
	
	//sei();
/*
	//Establecer si se quiere invertido o no invertido
	if (inverted)
	{
		TCCR1A |= (1<<COM1A0) | (1<<COM1A1);
	}
	else{
		TCCR1A |= (COM1A1);
	}
*/
/*
 switch (prescaler) {
	 case 1:
	 TCCR1B |= (1 << CS10);
	 break;
	 case 8:
	 TCCR1B |= (1 << CS11);
	 break;
	 case 64:
	 TCCR1B |= (1 << CS11) | (1 << CS10);
	 break;
	 case 256:
	 TCCR1B |= (1 << CS12);
	 break;
	 case 1024:
	 TCCR1B |= (1 << CS12) | (1 << CS10);
	 break;
	 default:
	 // Configuración de prescaler no soportada, usar 1:1 como default
	 TCCR1B |= (1 << CS10);
	 break;
	 }*/
 }
 
 void updateDutyCycle1A(uint8_t dutyH, uint8_t dutyL) {
	 OCR1AH = dutyH; 
	 OCR1AL = dutyL; // Ajusta el ciclo de trabajo para OC1A
 }