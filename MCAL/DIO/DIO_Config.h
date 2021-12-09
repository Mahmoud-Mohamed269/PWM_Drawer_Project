/*
 * DIO_Config.h
 *
 *  Created on: Sep 17, 2021
 *      Author: LENOVOOOO
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_
#include "DIO.h"
typedef struct{
	Dio_port_type port;
	Dio_pin_type pin;
	Dio_Dir_type dir;
}pin_config_type;

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
