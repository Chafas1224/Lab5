/*
 * PWM1.h
 *
 * Created: 15/04/2024 13:18:29
 *  Author: pablo
 */ 


#ifndef PWM1_H_
#define PWM1_H_

#include <stdint.h>
#include <avr/io.h>

#define invertido 1
#define no_invertido 0

//Función para configurar PWM1
void initPWM1Fast_16bit(uint8_t inverted, uint16_t prescaler);


//Función para actualizar el ciclo A del timer 1
 void updateDutyCycle1A(uint8_t dutyH, uint8_t dutyL);




#endif /* PWM1_H_ */