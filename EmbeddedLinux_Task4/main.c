
#include <avr/io.h>
#include <util/delay.h>
#include"DIO.h"
#include"Port.h"


int main(void)
{
usint8_t count =0;

DIO_enumSetPortConfig (DIO_enumPortB,DIO_enumInputInternalPU); //DDRB =0X00 //PORTB=0XFF;
DIO_enumSetPortConfig (DIO_enumPortA,DIO_enumOutput); //DDRA=0XFF
DIO_enumSetPort(DIO_enumPortA,DIO_enumLogicLow); //PORTA=0X00;


	/* Replace with your application code */
	while (1)
	{
		if(!READ_BIT(PINB,0)){
			count++;
			PORTA=count;
			_delay_ms(100);

		}
	
	}
	return 0;
}
