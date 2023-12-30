/*
 * Port_Cfg.h
 *
 * Created: 02/12/2023 17:11:53
 *  Author: Rania
 */ 


#ifndef PORT_CFG_H_
#define PORT_CFG_H_

#include "Port.h"
#include "DIO_RegAdd.h"

/*************** POST_COMPILATION_MODE ******************/
#define Num_Pins       32
#define PINS_PER_PORT  8

#define CFG_MODE                 2 /* Chnage it */
#define POST_BUILD_CFG_MODE      1
#define PRE_BUILD_CFG_MODE       2
usint8_t Loc_U8PinNum;



typedef enum {
	
	/* The ports Type of the AVR Atmega32*/
	DIO_enumPort_A,
	DIO_enumPort_B,
	DIO_enumPort_C,
	DIO_enumPort_D
	
}DIO_enumPortst;


typedef enum {

	DIO_enuInput_PU,
	DIO_enuInput_PD,
	DIO_enuOutput_High,
	DIO_enuOutput_LOW
}DIO_enuPinOpt_t;



DIO_enumPortst Loc_U8PortNum;
DIO_enuPinOpt_t DIO_PinCfg[Num_Pins]; //0


/*************** PRE_COMPILATION_MODE ******************/


//for output Configuration
#define INIT_LOW  0
#define INIT_HIGH 1

//for choose output or input (and its cfg in Input )
#define INIT_OUTPUT_HIGH          1
#define INIT_OUTPUT_LOW           1
#define INIT_INPUT_PULL_DOWN      0
#define INIT_INPUT_PULL_UP        0

/* choose no of ports in your target */
#define NUM_PORTS                3
#define TWO_PORTS                1
#define THREE_PORTS              2
#define FOUR_PORTS               3


/*initate your pins */ 
#define	DIO_PIN_A_0 					INIT_OUTPUT_LOW /*put PIN0  initialization from the prev Options */
#define	DIO_PIN_A_1 			     	INIT_OUTPUT_LOW /*put PIN1  initialization from the prev Options */
#define	DIO_PIN_A_2 			     	INIT_OUTPUT_LOW /*put PIN2  initialization from the prev Options */
#define	DIO_PIN_A_3 			     	INIT_OUTPUT_LOW /*put PIN3  initialization from the prev Options */
#define	DIO_PIN_A_4 			     	INIT_OUTPUT_LOW /*put PIN4  initialization from the prev Options */
#define	DIO_PIN_A_5 			        INIT_OUTPUT_HIGH/*put PIN5  initialization from the prev Options */
#define	DIO_PIN_A_6 			     	INIT_OUTPUT_HIGH/*put PIN6  initialization from the prev Options */
#define	DIO_PIN_A_7 			     	INIT_OUTPUT_HIGH/*put PIN7  initialization from the prev Options */
#define	DIO_PIN_B_0 			     	INIT_INPUT_PULL_UP /*put PIN8  initialization from the prev Options */
#define	DIO_PIN_B_1 			     	INIT_INPUT_PULL_UP/*put PIN9  initialization from the prev Options */
#define	DIO_PIN_B_2 			        INIT_INPUT_PULL_UP/*put PIN10 initialization from the prev Options */
#define	DIO_PIN_B_3 			     	INIT_INPUT_PULL_UP/*put PIN11 initialization from the prev Options */
#define	DIO_PIN_B_4 			     	INIT_INPUT_PULL_UP/*put PIN12 initialization from the prev Options */
#define	DIO_PIN_B_5 			     	INIT_INPUT_PULL_UP/*put PIN13 initialization from the prev Options */
#define	DIO_PIN_B_6 			     	INIT_INPUT_PULL_UP/*put PIN14 initialization from the prev Options */
#define	DIO_PIN_B_7 			     	INIT_INPUT_PULL_UP/*put PIN15 initialization from the prev Options */
#define	DIO_PIN_C_0 			     	INIT_INPUT_PULL_UP/*put PIN16 initialization from the prev Options */
#define	DIO_PIN_C_1 			     	INIT_INPUT_PULL_UP/*put PIN17 initialization from the prev Options */
#define	DIO_PIN_C_2 			     	INIT_OUTPUT_HIGH/*put PIN18 initialization from the prev Options */
#define	DIO_PIN_C_3 			     	INIT_OUTPUT_HIGH/*put PIN19 initialization from the prev Options */
#define	DIO_PIN_C_4 			     	INIT_OUTPUT_HIGH/*put PIN20 initialization from the prev Options */
#define	DIO_PIN_C_5 			     	INIT_OUTPUT_HIGH/*put PIN21 initialization from the prev Options */
#define	DIO_PIN_C_6 			     	INIT_OUTPUT_HIGH/*put PIN22 initialization from the prev Options */
#define	DIO_PIN_C_7 			     	INIT_OUTPUT_HIGH/*put PIN23 initialization from the prev Options */
#define	DIO_PIN_D_0 			     	INIT_OUTPUT_HIGH/*put PIN24 initialization from the prev Options */
#define	DIO_PIN_D_1 			     	INIT_OUTPUT_HIGH/*put PIN25 initialization from the prev Options */
#define	DIO_PIN_D_2 			     	INIT_OUTPUT_HIGH/*put PIN26 initialization from the prev Options */
#define	DIO_PIN_D_3 			     	INIT_OUTPUT_HIGH/*put PIN27 initialization from the prev Options */
#define	DIO_PIN_D_4 			     	INIT_OUTPUT_HIGH/*put PIN28 initialization from the prev Options */
#define	DIO_PIN_D_5 			     	INIT_OUTPUT_HIGH/*put PIN29 initialization from the prev Options */
#define	DIO_PIN_D_6 			     	INIT_OUTPUT_HIGH/*put PIN30 initialization from the prev Options */
#define	DIO_PIN_D_7 			     	INIT_OUTPUT_HIGH/*put PIN31 initialization from the prev Options */
										
		
/* PORT DIRECTION */
#define	PORT_PIN_A_0 			(0x00)		//PIN0
#define	PORT_PIN_A_1 			(0x01)     	//PIN1
#define	PORT_PIN_A_2 			(0x02)     	//PIN2
#define	PORT_PIN_A_3 			(0x03)     	//PIN3
#define	PORT_PIN_A_4 			(0x04)     	//PIN4
#define	PORT_PIN_A_5 			(0x05)     	//PIN5
#define	PORT_PIN_A_6 			(0x06)     	//PIN6
#define	PORT_PIN_A_7 			(0x07)     	//PIN7
#define	PORT_PIN_B_0 			(0x08)     	//PIN8
#define	PORT_PIN_B_1 			(0x09)     	//PIN9
#define	PORT_PIN_B_2 			(0x0A)     	//PIN10
#define	PORT_PIN_B_3 			(0x0B)     	//PIN11
#define	PORT_PIN_B_4 			(0x0C)     	//PIN12
#define	PORT_PIN_B_5 			(0x0D)     	//PIN13
#define	PORT_PIN_B_6 			(0x0E)     	//PIN14
#define	PORT_PIN_B_7 			(0x0F)     	//PIN15
#define	PORT_PIN_C_0 			(0x10)     	//PIN16
#define	PORT_PIN_C_1 			(0x11)     	//PIN17
#define	PORT_PIN_C_2 			(0x12)     	//PIN18
#define	PORT_PIN_C_3 			(0x13)     	//PIN19
#define	PORT_PIN_C_4 			(0x14)     	//PIN20
#define	PORT_PIN_C_5 			(0x15)     	//PIN21
#define	PORT_PIN_C_6 			(0x16)     	//PIN22
#define	PORT_PIN_C_7 			(0x17)     	//PIN23
#define	PORT_PIN_D_0 			(0x18)     	//PIN24
#define	PORT_PIN_D_1 			(0x19)     	//PIN25
#define	PORT_PIN_D_2 			(0x1A)     	//PIN26
#define	PORT_PIN_D_3 			(0x1B)     	//PIN27
#define	PORT_PIN_D_4 			(0x1C)     	//PIN28
#define	PORT_PIN_D_5 			(0x1D)     	//PIN29
#define	PORT_PIN_D_6 			(0x1E)     	//PIN30
#define	PORT_PIN_D_7 			(0x1F)     	//PIN31


/*PIN DIRECTION */
#define	DDR_PIN_A_0 		(0x1F)			//PIN0
#define	DDR_PIN_A_1 		(0x20)	     	//PIN1
#define	DDR_PIN_A_2 		(0x22)	     	//PIN2
#define	DDR_PIN_A_3 		(0x23)	     	//PIN3
#define	DDR_PIN_A_4 		(0x24)	     	//PIN4
#define	DDR_PIN_A_5 		(0x25)	     	//PIN5
#define	DDR_PIN_A_6 		(0x26)	     	//PIN6
#define	DDR_PIN_A_7 		(0x27)	     	//PIN7
#define	DDR_PIN_B_0 		(0x28)	     	//PIN8
#define	DDR_PIN_B_1 		(0x29)	     	//PIN9
#define	DDR_PIN_B_2 		(0x2A)	     	//PIN10
#define	DDR_PIN_B_3 		(0x2B)	     	//PIN11
#define	DDR_PIN_B_4 		(0x2C)	     	//PIN12
#define	DDR_PIN_B_5 		(0x2D)	     	//PIN13
#define	DDR_PIN_B_6 		(0x2E)	     	//PIN14
#define	DDR_PIN_B_7 		(0x2F)	     	//PIN15
#define	DDR_PIN_C_0 		(0x30)	     	//PIN16
#define	DDR_PIN_C_1 		(0x31)	     	//PIN17
#define	DDR_PIN_C_2 		(0x32)	     	//PIN18
#define	DDR_PIN_C_3 		(0x33)	     	//PIN19
#define	DDR_PIN_C_4 		(0x34)	     	//PIN20
#define	DDR_PIN_C_5 		(0x35)	     	//PIN21
#define	DDR_PIN_C_6 		(0x36)	     	//PIN22
#define	DDR_PIN_C_7 		(0x37)	     	//PIN23
#define	DDR_PIN_D_0 		(0x38)	     	//PIN24
#define	DDR_PIN_D_1 		(0x39)	     	//PIN25
#define	DDR_PIN_D_2 		(0x3A)	     	//PIN26
#define	DDR_PIN_D_3 		(0x3B)	     	//PIN27
#define	DDR_PIN_D_4 		(0x3C)	     	//PIN28
#define	DDR_PIN_D_5 		(0x3D)	     	//PIN29
#define	DDR_PIN_D_6 		(0x3E)	     	//PIN30
#define	DDR_PIN_D_7 		(0x3F)	     	//PIN31








#endif /* PORT_CFG_H_ */