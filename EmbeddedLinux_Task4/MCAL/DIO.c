/*
 * DIO.c
 *
 * Created: 28/11/2023 11:29:59
 *  Author: Rania
 */ 

#include "DIO.h"

DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum ,DIO_enumPins_t Copy_enumPinNum , DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk;
	if (Copy_enumPortNum >DIO_enumPortD) {Ret_enumErrorStatus= DIO_enumWrongPort; }
     else if (Copy_enumPinNum >DIO_enumPin7) {Ret_enumErrorStatus=  DIO_enumWrongPin; }
	   else if (Copy_enumConfig >DIO_enumInputExternalPD) {Ret_enumErrorStatus =  DIO_enumWrongConfig;}
		   else {  
			   switch(Copy_enumPortNum)
			   {
				   case DIO_enumPortA:
				   switch(Copy_enumConfig){
					   case DIO_enumOutput:
					   /*set port A(0:7) as ouput mode*/
					   SET_BIT(DDRA,Copy_enumPinNum) ;
					   break;
					   case DIO_enumInputInternalPU:
					   /*set this bit as input */
					   CLR_BIT(DDRA,Copy_enumPinNum) ;
					   /*Enable pull up resistor for this pin*/
					   SET_BIT(PORTA,Copy_enumPinNum) ;
					   break;
					   case DIO_enumInputExternalPD:
					   /*set this bit as input*/
					   CLR_BIT(DDRA,Copy_enumPinNum) ;
					   /*diable pull up resistors*/
					   CLR_BIT(PORTA,Copy_enumPinNum);
					   break;
					   default:
					   break;
				   }//switch2
				   break;
				   case DIO_enumPortB:
				   switch(Copy_enumConfig){
					   case DIO_enumOutput:
					   /*set port A(0:7) as ouput mode*/
					   SET_BIT(DDRB,Copy_enumPinNum) ;
					   break;
					   case DIO_enumInputInternalPU:
					   /*set this bit as input */
					   CLR_BIT(DDRB,Copy_enumPinNum) ;
					   /*Enable pull up resistor for this pin*/
					   SET_BIT(PORTB,Copy_enumPinNum) ;
					   break;
					   case DIO_enumInputExternalPD:
					   /*set this bit as input*/
					   CLR_BIT(DDRB,Copy_enumPinNum) ;
					   /*diable pull up resistors*/
					   CLR_BIT(PORTB,Copy_enumPinNum);
					   break;
					   default:
					   break;
				   }//switch2
				   break;
				   case DIO_enumPortC:
				   switch(Copy_enumConfig){
					   case DIO_enumOutput:
					   /*set port A(0:7) as ouput mode*/
					   SET_BIT(DDRC,Copy_enumPinNum) ;
					   break;
					   case DIO_enumInputInternalPU:
					   /*set this bit as input */
					   CLR_BIT(DDRC,Copy_enumPinNum) ;
					   /*Enable pull up resistor for this pin*/
					   SET_BIT(PORTC,Copy_enumPinNum) ;
					   break;
					   case DIO_enumInputExternalPD:
					   /*set this bit as input*/
					   CLR_BIT(DDRC,Copy_enumPinNum) ;
					   /*diable pull up resistors*/
					   CLR_BIT(PORTC,Copy_enumPinNum);
					   break;
					   default:
					   break;
				   }//switch2
				   break;
				   case DIO_enumPortD:
				   switch(Copy_enumConfig){
					   case DIO_enumOutput:
					   /*set port A(0:7) as ouput mode*/
					   SET_BIT(DDRD,Copy_enumPinNum) ;
					   break;
					   case DIO_enumInputInternalPU:
					   /*set this bit as input */
					   CLR_BIT(DDRD,Copy_enumPinNum) ;
					   /*Enable pull up resistor for this pin*/
					   SET_BIT(PORTD,Copy_enumPinNum) ;
					   break;
					   case DIO_enumInputExternalPD:
					   /*set this bit as input*/
					   CLR_BIT(DDRD,Copy_enumPinNum) ;
					   /*diable pull up resistors*/
					   CLR_BIT(PORTD,Copy_enumPinNum);
					   break;
					   default:
					   break;
				   }
				   break;
				   default: break;
			  }
		   
	}//else
	return Ret_enumErrorStatus ;
	
}  
	
DIO_enumError_t DIO_enumSetPortConfig (DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk;
	if (Copy_enumPortNum >DIO_enumPortD) {Ret_enumErrorStatus= DIO_enumWrongPort;}
		else if (Copy_enumConfig >DIO_enumInputExternalPD) {Ret_enumErrorStatus =  DIO_enumWrongConfig;}
	      
		   else{
			  
			   
			   switch(Copy_enumPortNum)
			   {
				   case DIO_enumPortA:
				   {
					   switch(Copy_enumConfig)
				   {
					   case DIO_enumOutput:
					   DDRA=0xff;
					   break;
					   case DIO_enumInputInternalPU:
					   DDRA=0x00;
					   PORTA=0xff;
					   break;
					   case DIO_enumInputExternalPD:
					   DDRA=0x00;
					   PORTA=0x00;
					   break;
					   default: break;
				   }
				   }
				   break;
				   case DIO_enumPortB:
				   { switch(Copy_enumConfig)
				   {
					   case DIO_enumOutput:
					   DDRB=0xff;
					   break;
					   case DIO_enumInputInternalPU:
					   DDRB=0x00;
					   PORTB=0xff;
					   break;
					   case DIO_enumInputExternalPD:
					   DDRB=0x00;
					   PORTB=0x00;
					   break;
					   default: break;
				   }
				  }
				   break;
				  case DIO_enumPortC:
				  { switch(Copy_enumConfig)
				   {
					   case DIO_enumOutput:
					   DDRC=0xff;
					   break;
					   case DIO_enumInputInternalPU:
					   DDRC=0x00;
					   PORTC=0xff;
					   break;
					   case DIO_enumInputExternalPD:
					   DDRC=0x00;
					   PORTC=0x00;
					   break;
					   default: break;
				   }
				  }
				   break;
				  case DIO_enumPortD:
				  {
					   switch(Copy_enumConfig)
				   {
					   case DIO_enumOutput:
					   DDRD=0xff;
					   break;
					   case DIO_enumInputInternalPU:
					   DDRD=0x00;
					   PORTD=0xff;
					   break;
					   case DIO_enumInputExternalPD:
					   DDRD=0x00;
					   PORTD=0x00;
					   break;
					   default: break;
				   }
				    break;
				  }
			
				  default: break;  
			     }
				 
	  }//else
	  return Ret_enumErrorStatus;
}

DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk;
if (Copy_enumPortNum >DIO_enumPortD) {Ret_enumErrorStatus= DIO_enumWrongPort; }
else if (Copy_enumPinNum >DIO_enumPin7) {Ret_enumErrorStatus=  DIO_enumWrongPin; }
else if (Copy_enumLogicState >DIO_enumLogicHigh) {Ret_enumErrorStatus =  DIO_enumWrongConfig;}
else {

			   switch(Copy_enumPortNum)
			   {
				   case DIO_enumPortA:
				   switch(Copy_enumLogicState)
				   {   
					   case DIO_enumLogicLow:
					   CLR_BIT(PORTA,Copy_enumPinNum) ;
					   break;
					   case DIO_enumLogicHigh:
					   SET_BIT(PORTA,Copy_enumPinNum) ;
					   break;
					   default:
					   break;
				   }
				   break;
				   case DIO_enumPortB:
				   switch(Copy_enumLogicState)
				   {
					   case DIO_enumLogicLow:
					   CLR_BIT(PORTB,Copy_enumPinNum) ;
					   break;
					   case DIO_enumLogicHigh:
					   SET_BIT(PORTB,Copy_enumPinNum) ;
					   break;
					   default:
					   break;
				   }
				   break;
				   case DIO_enumPortC:
				   switch(Copy_enumLogicState)
				   {
					   case DIO_enumLogicLow:
					   CLR_BIT(PORTC,Copy_enumPinNum) ;
					   break;
					   case DIO_enumLogicHigh:
					   SET_BIT(PORTC,Copy_enumPinNum) ;
					   break;
					   default:
					   break;
				   }
				   break;
				   case DIO_enumPortD:
				   switch(Copy_enumLogicState)
				   {
					   case DIO_enumLogicLow:
					   CLR_BIT(PORTD,Copy_enumPinNum) ;
					   break;
					   case DIO_enumLogicHigh:
					   SET_BIT(PORTD,Copy_enumPinNum) ;
					   break;
					   default:
					   break;
				   }
				   break;
				  default: break;
				   
			   }	
}//eslse
	return Ret_enumErrorStatus ;	
}


DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk;
	if (Copy_enumPortNum >DIO_enumPortD) {Ret_enumErrorStatus= DIO_enumWrongPort; }
    else if (Copy_enumLogicState >DIO_enumLogicHigh) {Ret_enumErrorStatus =  DIO_enumWrongConfig;}
	else{
		switch(Copy_enumPortNum)
		{
		case DIO_enumPortA:
	    switch(Copy_enumLogicState)
		 {
			case DIO_enumLogicLow:
			PORTA=0x00;
			break;
			case DIO_enumLogicHigh:
			PORTA=0xff;
			break;
			default: break;
		}
		break;
		case DIO_enumPortB:
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicLow:
			PORTB=0x00;
			break;
			case DIO_enumLogicHigh:
			PORTB=0xff;
			break;
			default: break;
		}
		break;
		case DIO_enumPortC:
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicLow:
			PORTC=0x00;
			break;
			case DIO_enumLogicHigh:
			PORTC=0xff;
			break;
			default: break;
		}
		break;
		case DIO_enumPortD:
		switch(Copy_enumLogicState)
		{
			case DIO_enumLogicLow:
			PORTD=0x00;
			break;
			case DIO_enumLogicHigh:
			PORTD=0xff;
			break;
			default: break;
		}
		break;
		default: break;
		}
		
	}//else
	return Ret_enumErrorStatus;
}

DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk;
	if (Copy_enumPortNum >DIO_enumPortD) {Ret_enumErrorStatus= DIO_enumWrongPort; }
    else if (Copy_enumPinNum >DIO_enumPin7) {Ret_enumErrorStatus=  DIO_enumWrongPin; }
	else
	{
		switch(Copy_enumPortNum){
		case DIO_enumPortA:
		switch(Copy_enumPinNum)
		{
			case DIO_enumPin0: 
			*Add_Pu8PinValue =READ_BIT(PINA,DIO_enumPin0);
			break;
			case DIO_enumPin1: 
			*Add_Pu8PinValue =READ_BIT(PINA,DIO_enumPin1);
			break;
			case DIO_enumPin2:
			*Add_Pu8PinValue =READ_BIT(PINA,DIO_enumPin2);
			break;
			case DIO_enumPin3:
			*Add_Pu8PinValue =READ_BIT(PINA,DIO_enumPin3);
			break;
			case DIO_enumPin4:
			*Add_Pu8PinValue =READ_BIT(PINA,DIO_enumPin4);
			break;
			case DIO_enumPin5:
			*Add_Pu8PinValue =READ_BIT(PINA,DIO_enumPin5);
			break;
			case DIO_enumPin6:
			*Add_Pu8PinValue =READ_BIT(PINA,DIO_enumPin6);
			break;
			case DIO_enumPin7:
			*Add_Pu8PinValue =READ_BIT(PINA,DIO_enumPin7);
			break;
			default: break;
		}
		break;
		case DIO_enumPortB:
		switch(Copy_enumPinNum)
		{
			case DIO_enumPin0:
			*Add_Pu8PinValue =READ_BIT(PINB,DIO_enumPin0);
			break;
			case DIO_enumPin1:
			*Add_Pu8PinValue =READ_BIT(PINB,DIO_enumPin1);
			break;
			case DIO_enumPin2:
			*Add_Pu8PinValue =READ_BIT(PINB,DIO_enumPin2);
			break;
			case DIO_enumPin3:
			*Add_Pu8PinValue =READ_BIT(PINB,DIO_enumPin3);
			break;
			case DIO_enumPin4:
			*Add_Pu8PinValue =READ_BIT(PINB,DIO_enumPin4);
			break;
			case DIO_enumPin5:
			*Add_Pu8PinValue =READ_BIT(PINB,DIO_enumPin5);
			break;
			case DIO_enumPin6:
			*Add_Pu8PinValue =READ_BIT(PINB,DIO_enumPin6);
			break;
			case DIO_enumPin7:
			*Add_Pu8PinValue =READ_BIT(PINB,DIO_enumPin7);
			break;
			default: break;
		}
		break;		
		case DIO_enumPortC:
		switch(Copy_enumPinNum)
		{
			case DIO_enumPin0:
			*Add_Pu8PinValue =READ_BIT(PINC,DIO_enumPin0);
			break;
			case DIO_enumPin1:
			*Add_Pu8PinValue =READ_BIT(PINC,DIO_enumPin1);
			break;
			case DIO_enumPin2:
			*Add_Pu8PinValue =READ_BIT(PINC,DIO_enumPin2);
			break;
			case DIO_enumPin3:
			*Add_Pu8PinValue =READ_BIT(PINC,DIO_enumPin3);
			break;
			case DIO_enumPin4:
			*Add_Pu8PinValue =READ_BIT(PINC,DIO_enumPin4);
			break;
			case DIO_enumPin5:
			*Add_Pu8PinValue =READ_BIT(PINC,DIO_enumPin5);
			break;
			case DIO_enumPin6:
			*Add_Pu8PinValue =READ_BIT(PINC,DIO_enumPin6);
			break;
			case DIO_enumPin7:
			*Add_Pu8PinValue =READ_BIT(PINC,DIO_enumPin7);
			break;
			default: break;
		}
		break;		
		case DIO_enumPortD:
		switch(Copy_enumPinNum)
		{
			case DIO_enumPin0:
			*Add_Pu8PinValue =READ_BIT(PIND,DIO_enumPin0);
			break;
			case DIO_enumPin1:
			*Add_Pu8PinValue =READ_BIT(PIND,DIO_enumPin1);
			break;
			case DIO_enumPin2:
			*Add_Pu8PinValue =READ_BIT(PIND,DIO_enumPin2);
			break;
			case DIO_enumPin3:
			*Add_Pu8PinValue =READ_BIT(PIND,DIO_enumPin3);
			break;
			case DIO_enumPin4:
			*Add_Pu8PinValue =READ_BIT(PIND,DIO_enumPin4);
			break;
			case DIO_enumPin5:
			*Add_Pu8PinValue =READ_BIT(PIND,DIO_enumPin5);
			break;
			case DIO_enumPin6:
			*Add_Pu8PinValue =READ_BIT(PIND,DIO_enumPin6);
			break;
			case DIO_enumPin7:
			*Add_Pu8PinValue =READ_BIT(PIND,DIO_enumPin7);
			break;
			default: break;
		}
		break;
		default: break;             
		}
	}//else
	return Ret_enumErrorStatus;
}