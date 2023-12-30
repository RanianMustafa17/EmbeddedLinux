/*
 * DIO_RegAdd.h
 *
 * Created: 27/11/2023 15:52:09
 *  Author: Rania
 */ 


#ifndef DIO_REGADD_H_
#define DIO_REGADD_H_

#include "std_types.h"

#define  PINA   *((volatile usint8_t*)0x39)
#define  PINB   *((volatile usint8_t*)0x36)
#define  PINC   *((volatile usint8_t*)0x33)
#define  PIND   *((volatile usint8_t*)0x30)

#define  DDRA   *((volatile usint8_t*)0x3A)
#define  DDRB   *((volatile usint8_t*)0x37)
#define  DDRC   *((volatile usint8_t*)0x34)
#define  DDRD   *((volatile usint8_t*)0x31)

#define  PORTA  *((volatile usint8_t*)0x3B)
#define  PORTB  *((volatile usint8_t*)0x38)
#define  PORTC  *((volatile usint8_t*)0x35)
#define  PORTD  *((volatile usint8_t*)0x32)




#endif /* DIO_REGADD_H_ */