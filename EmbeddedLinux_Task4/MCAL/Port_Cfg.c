/*
 * Port_Cfg.c
 *
 * Created: 02/12/2023 17:12:13
 *  Author: Rania
 */ 


#include "Port.h"

#if (CFG_MODE == POST_BUILD_CFG_MODE)
DIO_enuPinOpt_t DIO_PinCfg[Num_Pins] = 
 {
	
		
		DIO_enuOutput_LOW,      /*PINA0 */  //LED 0
		DIO_enuOutput_LOW,	     /*PINA1 */	 //LED 1
		DIO_enuOutput_LOW,	     /*PINA2 */	 //LED 2
		DIO_enuOutput_LOW,	     /*PINA3 */	 //LED 3
		DIO_enuOutput_LOW,	     /*PINA4 */	 
		DIO_enuOutput_LOW,	     /*PINA5 */
		DIO_enuOutput_LOW,	     /*PINA6 */
		DIO_enuOutput_LOW,	     /*PINA7 */
		DIO_enuInput_PU,		 /*PINB0 */ //switch
		DIO_enuInput_PU,	     /*PINB1 */
		DIO_enuInput_PU,	     /*PINB2 */
		DIO_enuInput_PU,	     /*PINB3 */
		DIO_enuInput_PU,	     /*PINB4 */
		DIO_enuInput_PU,	     /*PINB5 */
		DIO_enuInput_PU,	     /*PINB6 */
		DIO_enuInput_PU,	     /*PINB7 */
		DIO_enuInput_PU,	     /*PINC0 */
		DIO_enuInput_PU,	     /*PINC1 */
		DIO_enuInput_PU,	     /*PINC2 */
		DIO_enuOutput_LOW,	     /*PINC3 */
		DIO_enuOutput_LOW,	     /*PINC4 */
		DIO_enuOutput_LOW,	     /*PINC5 */
		DIO_enuOutput_LOW,	     /*PINC6 */
		DIO_enuOutput_LOW,	     /*PINC7 */
		DIO_enuOutput_LOW,	     /*PIND0 */
		DIO_enuOutput_LOW,	     /*PIND1 */
		DIO_enuOutput_High,	     /*PIND2 */
		DIO_enuOutput_High,       /*PIND3 */
		DIO_enuOutput_High,       /*PIND4 */
		DIO_enuOutput_High,       /*PIND5 */
		DIO_enuOutput_High,       /*PIND6 */
		DIO_enuOutput_High        /*PIND7 */
						   
};							   
#endif	