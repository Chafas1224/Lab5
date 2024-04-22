/*
 * PWM0.h
 *
 * Created: 14/04/2024 12:19:04
 *  Author: pablo
 */ 


#ifndef PWM0_H_
#define PWM0_H_

#include <stdint.h>
#include <avr/io.h>

#define invertido 1
#define no_invertido 0

//Funcion para configurar PWM0 Modo Fast Canal A
void initPWM0FastA(uint8_t inverted, uint16_t prescaler);

//Funcion para configurar PWM0 Modo Fast Canal B
void initPWM0FastB(uint8_t inverted, uint16_t prescaler);

//Función para configurar el DutyCicle de A
void updateDutyCicleA(uint8_t duty);

//Función para congfigurar el DutyCicle de B
void updateDutyCicleB(uint8_t duty);




#endif /* PWM0_H_ */