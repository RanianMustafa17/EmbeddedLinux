/*
 * DIO.h
 *
 * Created: 27/11/2023 15:39:23
 *  Author: Rania
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "DIO_RegAdd.h"
#include "std_types.h"
#include "Bit_Math.h"

typedef enum {

	/*Everything Ok, Function had Performed Correctly.*/
	DIO_enumOk,
	 
	/*Everything NOk, initial value. */
	DIO_enumNOk,
	 
	/*if value passed to function out of range. */
	DIO_enumLogicalValueError,  
	                  
	/*NULL Pointer is passed.*/
	DIO_enumNullPointer,
	
	/*Select Port Not exist ! .*/    
	DIO_enumWrongPort,
	      
	/* Select Pin Not exist ! .*/
	DIO_enumWrongPin, 
	
	/* Select Configuration type Not Found .*/     
	DIO_enumWrongConfig    
		
}DIO_enumError_t ;


typedef enum
{	
	/*Select Pin Configuration to be Output*/
	DIO_enumOutput,
	/*Select Pin Configuration to be Input Internal PullUp*/             
	DIO_enumInputInternalPU,
	/*Select Pin Configuration to be Input External PullDown*/    
	DIO_enumInputExternalPD   
	
}DIO_enumConfig_t;

typedef enum
{	

/*Logic State Type : HIGH (5V) or LOW(0V)*/
   DIO_enumLogicLow,
   DIO_enumLogicHigh
   
}DIO_enumLogicState_t;


typedef enum {	
		
/* The ports Type of the AVR Atmega32*/
   DIO_enumPortA,
   DIO_enumPortB,
   DIO_enumPortC,
   DIO_enumPortD	
   
}DIO_enumPorts_t;


typedef enum
{
	/*Pins Type */
	DIO_enumPin0,
	DIO_enumPin1,
	DIO_enumPin2,
	DIO_enumPin3,
	DIO_enumPin4,
	DIO_enumPin5,
	DIO_enumPin6,
	DIO_enumPin7
	
}DIO_enumPins_t;



/*
 *@brief  : Function to Configure the Pins to be INPUT(Internal Pull Up or External Pull Down pin) or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum ,DIO_enumPins_t Copy_enumPinNum , DIO_enumConfig_t Copy_enumConfig);



/*
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input(Internal Pull Up or External Pull Down pin)/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig);



/*
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState);



/*
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState); 



/*
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue);



/*
 *@brief  : Function to toggle the logic state of the pin.
 *@param  : Port Number & Pin Number.
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumTogglePinState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum);



/*
 *@brief  : Function to set the port to a specific value.
 *@param  : Port Number and value to be assigned to port .
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumAssignPortLogicalStatus(DIO_enumPorts_t Copy_enumPortNum, usint8_t LogicalValueOfPins);





#endif /* DIO_H_ */
