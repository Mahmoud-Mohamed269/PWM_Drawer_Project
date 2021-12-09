/*
 * DIO.h
 *
 *  Created on: Sep 11, 2021
 *      Author: LENOVOOOO
 */
#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../type.h"
#include "../../bit_math.h"
#include <avr/io.h>
#include "DIO_Types.h"
#include "DIO_Config.h"
//Macros
//Definitions
//function prototypes

void dio_init(void) ;
void DIO_WRITE(uint8 channel, uint8 state);
uint8 DIO_READ(uint8 channel);
#endif /* MCAL_DIO_DIO_H_ */
