/*
 * port.c
 *
 * Created: 02/12/2023 17:12:28
 *  Author: Rania
 */ 


#include "Port.h"
#include "Port_Cfg.h"


#define CONCAT(b7, b6, b5, b4, b3, b2, b1, b0)  Helper(b7, b6, b5, b4, b3, b2, b1, b0)
#define Helper(b7, b6, b5, b4, b3, b2, b1, b0)  ((b7<<7) | (b6<<6) | (b5<<5) | (b4<<4) | (b3<<3) | (b2<<2) | (b1<<1) | b0)


extern DIO_enuPinOpt_t DIO_PinCfg[Num_Pins];

#if (CFG_MODE == POST_BUILD_CFG_MODE)
  void Port_Init( )
  {
	for(usint8_t i=0 ; i <Num_Pins ;i++)
	{
		Loc_U8PortNum = i/PINS_PER_PORT;
		Loc_U8PinNum = (usint8_t)i%PINS_PER_PORT;
		switch(Loc_U8PortNum)
		{
			case DIO_enumPort_A: 
			{
				switch(DIO_PinCfg[i]) //which pin 
				{
					case DIO_enuInput_PU: 
					CLR_BIT(DDRA, Loc_U8PinNum);
					SET_BIT(PORTA,Loc_U8PinNum);
					break;
					case DIO_enuInput_PD:
					CLR_BIT(DDRA, Loc_U8PinNum);
					CLR_BIT(PORTA,Loc_U8PinNum);
					break;
					case DIO_enuOutput_High:
					SET_BIT(DDRA, Loc_U8PinNum);
					SET_BIT(PORTA,Loc_U8PinNum);
					break;
					case DIO_enuOutput_LOW:
					SET_BIT( DDRA, Loc_U8PinNum);
					CLR_BIT(PORTA,Loc_U8PinNum);
					break;
					default: break;
					 
				}
				
			}
			break;
			case DIO_enumPort_B: //01234567
			{
				switch(DIO_PinCfg[i]) //which pin
				{
					case DIO_enuInput_PU:
					CLR_BIT(DDRB, Loc_U8PinNum);
					SET_BIT(PORTB,Loc_U8PinNum);
					break;
					case DIO_enuInput_PD:
					CLR_BIT(DDRB, Loc_U8PinNum);
					CLR_BIT(PORTB,Loc_U8PinNum);
					break;
					case DIO_enuOutput_High:
					SET_BIT(DDRB, Loc_U8PinNum);
					SET_BIT(PORTB,Loc_U8PinNum);
					break;
					case DIO_enuOutput_LOW:
					SET_BIT(DDRB, Loc_U8PinNum);
					CLR_BIT(PORTB,Loc_U8PinNum);
					break;
					default: break;
					
				}
				
			}
			break;
			case DIO_enumPort_C: //01234567
			{
				switch(DIO_PinCfg[i]) //which pin
				{
					case DIO_enuInput_PU:
					CLR_BIT(DDRC, Loc_U8PinNum);
					SET_BIT(PORTC,Loc_U8PinNum);
					break;
					case DIO_enuInput_PD:
					CLR_BIT(DDRC, Loc_U8PinNum);
					CLR_BIT(PORTC,Loc_U8PinNum);
					break;
					case DIO_enuOutput_High:
					SET_BIT(DDRC, Loc_U8PinNum);
					SET_BIT(PORTC,Loc_U8PinNum);
					break;
					case DIO_enuOutput_LOW:
					SET_BIT(DDRC, Loc_U8PinNum);
					CLR_BIT(PORTC,Loc_U8PinNum);
					break;
					default: break;
					
				}
				
			}
			break;
			case DIO_enumPort_D: //01234567
			{
				switch(DIO_PinCfg[i]) //which pin
				{
					case DIO_enuInput_PU:
					CLR_BIT(DDRD, Loc_U8PinNum);
					SET_BIT(PORTD,Loc_U8PinNum);
					break;
					case DIO_enuInput_PD:
					CLR_BIT(DDRD, Loc_U8PinNum);
					CLR_BIT(PORTD,Loc_U8PinNum);
					break;
					case DIO_enuOutput_High:
					SET_BIT(DDRD, Loc_U8PinNum);
					SET_BIT(PORTD,Loc_U8PinNum);
					break;
					case DIO_enuOutput_LOW:
					SET_BIT(DDRD, Loc_U8PinNum);
					CLR_BIT(PORTD,Loc_U8PinNum);
					break;
					default: break;
					
				}
				
			}
			break;
			default: break;
		}//switch
	}
  }
 

#elif (CFG_MODE == PRE_BUILD_CFG_MODE)

void Port_Init( )
{
#if    (DIO_PIN_A_0 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_A_0  INIT_LOW     /*DDRA for PIN0 is 0*/
#define PORTA_PINA0  INIT_LOW    /*PORTA for PIN0 is 0*/
#elif (PORT_PIN_A_0 == INIT_INPUT_PULL_UP)
#define DDR_PIN_A_0  INIT_LOW     /*DDRA for PIN0 is 0*/
#define PORTA_PINA0  INIT_HIGH   /*PORTA for PIN0 is 1*/
#elif (PORT_PIN_A_0 == INIT_OUTPUT_HIGH)
#define DDR_PIN_A_0  INIT_HIGH    /*DDRA for PIN0 is 1*/
#define PORTA_PINA0  INIT_HIGH   /*PORTA for PIN0 is 1*/
#elif (PORT_PIN_A_0 == INIT_OUTPUT_LOW)
#define DDR_PIN_A_0  INIT_HIGH   /*DDRA for PIN0 is 1*/
#define PORTA_PINA0  INIT_LOW   /*PORTA for PIN0 is 0*/
#endif
#if    (DIO_PIN_A_1 == INIT_INPUT_PULL_DOWN) 
#define DDR_PIN_A_1  INIT_LOW     /*DDRA for PIN1 is 0*/
#define PORTA_PINA1  INIT_LOW    /*PORTA for PIN1 is 0*/
#elif (PORT_PIN_A_1 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_A_1  INIT_LOW     /*DDRA for PIN1 is 0*/
#define PORTA_PINA1  INIT_HIGH   /*PORTA for PIN1 is 1*/
#elif (PORT_PIN_A_1 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_A_1  INIT_HIGH    /*DDRA for PIN1 is 1*/
#define PORTA_PINA1  INIT_HIGH   /*PORTA for PIN1 is 1*/
#elif (PORT_PIN_A_1 == INIT_OUTPUT_LOW)			
#define DDR_PIN_A_1  INIT_HIGH    /*DDRA for PIN1 is 1*/
#define PORTA_PINA1  INIT_LOW    /*PORTA for PIN1 is 0*/
#endif
#if    (DIO_PIN_A_2 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_A_2  INIT_LOW     /*DDRA for PIN2 is 0*/
#define PORTA_PINA2  INIT_LOW    /*PORTA for PIN2 is 0*/
#elif (PORT_PIN_A_2 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_A_2  INIT_LOW     /*DDRA for PIN2 is 0*/
#define PORTA_PINA2  INIT_HIGH   /*PORTA for PIN2 is 1*/
#elif (PORT_PIN_A_2 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_A_2  INIT_HIGH    /*DDRA for PIN2 is 1*/
#define PORTA_PINA2  INIT_HIGH   /*PORTA for PIN2 is 1*/
#elif (PORT_PIN_A_2 == INIT_OUTPUT_LOW)			
#define DDR_PIN_A_2  INIT_HIGH    /*DDRA for PIN2 is 1*/
#define PORTA_PINA2  INIT_LOW    /*PORTA for PIN2 is 0*/
#endif				  
#if    (DIO_PIN_A_3 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_A_3  INIT_LOW     /*DDRA for PIN3 is 0*/
#define PORTA_PINA3  INIT_LOW    /*PORTA for PIN3 is 0*/
#elif (PORT_PIN_A_3 == INIT_INPUT_PULL_UP)
#define DDR_PIN_A_3  INIT_LOW     /*DDRA for PIN3 is 0*/
#define PORTA_PINA3  INIT_HIGH   /*PORTA for PIN3 is 1*/
#elif (PORT_PIN_A_3 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_A_3  INIT_HIGH    /*DDRA for PIN3 is 1*/
#define PORTA_PINA3  INIT_HIGH   /*PORTA for PIN3 is 1*/
#elif (PORT_PIN_A_3 == INIT_OUTPUT_LOW)			
#define DDR_PIN_A_3  INIT_HIGH    /*DDRA for PIN3 is 1*/
#define PORTA_PINA3  INIT_LOW    /*PORTA for PIN3 is 0*/
#endif	
#if    (DIO_PIN_A_4 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_A_4  INIT_LOW     /*DDRA for PIN4 is 0*/
#define PORTA_PINA4  INIT_LOW    /*PORTA for PIN4 is 0*/
#elif (PORT_PIN_A_4 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_A_4  INIT_LOW     /*DDRA for PIN4 is 0*/
#define PORTA_PINA4  INIT_HIGH   /*PORTA for PIN4 is 1*/
#elif (PORT_PIN_A_4 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_A_4  INIT_HIGH    /*DDRA for PIN4 is 1*/
#define PORTA_PINA4  INIT_HIGH   /*PORTA for PIN4 is 1*/
#elif (PORT_PIN_A_4 == INIT_OUTPUT_LOW)			
#define DDR_PIN_A_4  INIT_HIGH    /*DDRA for PIN4 is 1*/
#define PORTA_PINA4  INIT_LOW    /*PORTA for PIN4 is 0*/
#endif	
#if    (DIO_PIN_A_5 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_A_5  INIT_LOW     /*DDRA for PIN5 is 0*/
#define PORTA_PINA5  INIT_LOW    /*PORTA for PIN5 is 0*/
#elif (PORT_PIN_A_5 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_A_5  INIT_LOW     /*DDRA for PIN5 is 0*/
#define PORTA_PINA5  INIT_HIGH   /*PORTA for PIN5 is 1*/
#elif (PORT_PIN_A_5 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_A_5  INIT_HIGH    /*DDRA for PIN5 is 1*/
#define PORTA_PINA5  INIT_HIGH   /*PORTA for PIN5 is 1*/
#elif (PORT_PIN_A_5 == INIT_OUTPUT_LOW)			
#define DDR_PIN_A_5  INIT_HIGH    /*DDRA for PIN5 is 1*/
#define PORTA_PINA5  INIT_LOW    /*PORTA for PIN5 is 0*/
#endif  
#if    (DIO_PIN_A_6 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_A_6  INIT_LOW     /*DDRA for PIN6 is 0*/
#define PORTA_PINA6  INIT_LOW    /*PORTA for PIN6 is 0*/
#elif (PORT_PIN_A_6 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_A_6  INIT_LOW     /*DDRA for PIN6 is 0*/
#define PORTA_PINA6  INIT_HIGH   /*PORTA for PIN6 is 1*/
#elif (PORT_PIN_A_6 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_A_6  INIT_HIGH    /*DDRA for PIN6 is 1*/
#define PORTA_PINA6  INIT_HIGH   /*PORTA for PIN6 is 1*/
#elif (PORT_PIN_A_6 == INIT_OUTPUT_LOW)			
#define DDR_PIN_A_6  INIT_HIGH    /*DDRA for PIN6 is 1*/
#define PORTA_PINA6  INIT_LOW    /*PORTA for PIN6 is 0*/
#endif
#if    (DIO_PIN_A_7 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_A_7  INIT_LOW     /*DDRA for PIN7 is 0*/
#define PORTA_PINA7  INIT_LOW    /*PORTA for PIN7 is 0*/
#elif (PORT_PIN_A_7 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_A_7  INIT_LOW     /*DDRA for PIN7 is 0*/
#define PORTA_PINA7  INIT_HIGH   /*PORTA for PIN7 is 1*/
#elif (PORT_PIN_A_7 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_A_7  INIT_HIGH    /*DDRA for PIN7 is 1*/
#define PORTA_PINA7  INIT_HIGH   /*PORTA for PIN7 is 1*/
#elif (PORT_PIN_A_7 == INIT_OUTPUT_LOW)			
#define DDR_PIN_A_7  INIT_HIGH    /*DDRA for PIN7 is 1*/
#define PORTA_PINA7  INIT_LOW    /*PORTA for PIN7 is 0*/
#endif

#if    (DIO_PIN_B_0 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_B_0  INIT_LOW     /*DDRB for PIN0 is 0*/
#define PORTB_PINB0  INIT_LOW    /*PORTB for PIN0 is 0*/
#elif (PORT_PIN_B_0 == INIT_INPUT_PULL_UP)
#define DDR_PIN_B_0  INIT_LOW     /*DDRB for PIN0 is 0*/
#define PORTB_PINB0  INIT_HIGH   /*PORTB for PIN0 is 1*/
#elif (PORT_PIN_B_0 == INIT_OUTPUT_HIGH)
#define DDR_PIN_B_0  INIT_HIGH    /*DDRB for PIN0 is 1*/
#define PORTB_PINB0  INIT_HIGH   /*PORTB for PIN0 is 1*/
#elif (PORT_PIN_B_0 == INIT_OUTPUT_LOW)
#define DDR_PIN_B_0  INIT_HIGH    /*DDRB for PIN0 is 1*/
#define PORTB_PINB0  INIT_LOW    /*PORTB for PIN0 is 0*/
#endif
#if    (DIO_PIN_B_1 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_B_1  INIT_LOW     /*DDRB for PIN1 is 0*/
#define PORTB_PINB1  INIT_LOW    /*PORTB for PIN1 is 0*/
#elif (PORT_PIN_B_1 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_B_1  INIT_LOW     /*DDRB for PIN1 is 0*/
#define PORTB_PINB1  INIT_HIGH   /*PORTB for PIN1 is 1*/
#elif (PORT_PIN_B_1 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_B_1  INIT_HIGH    /*DDRB for PIN1 is 1*/
#define PORTB_PINB1  INIT_HIGH   /*PORTB for PIN1 is 1*/
#elif (PORT_PIN_B_1 == INIT_OUTPUT_LOW)			
#define DDR_PIN_B_1  INIT_HIGH    /*DDRB for PIN1 is 1*/
#define PORTB_PINB1  INIT_LOW    /*PORTB for PIN1 is 0*/
#endif	
#if    (DIO_PIN_B_2 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_B_2  INIT_LOW     /*DDRB for PIN2 is 0*/
#define PORTB_PINB2  INIT_LOW    /*PORTB for PIN2 is 0*/
#elif (PORT_PIN_B_2 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_B_2  INIT_LOW     /*DDRB for PIN2 is 0*/
#define PORTB_PINB2  INIT_HIGH   /*PORTB for PIN2 is 1*/
#elif (PORT_PIN_B_2 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_B_2  INIT_HIGH    /*DDRB for PIN2 is 1*/
#define PORTB_PINB2  INIT_HIGH   /*PORTB for PIN2 is 1*/
#elif (PORT_PIN_B_2 == INIT_OUTPUT_LOW)			
#define DDR_PIN_B_2  INIT_HIGH    /*DDRB for PIN2 is 1*/
#define PORTB_PINB2  INIT_LOW    /*PORTB for PIN2 is 0*/
#endif
#if    (DIO_PIN_B_3 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_B_3  INIT_LOW     /*DDRB for PIN3 is 0*/
#define PORTB_PINB3  INIT_LOW    /*PORTB for PIN3 is 0*/
#elif (PORT_PIN_B_3 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_B_3  INIT_LOW     /*DDRB for PIN3 is 0*/
#define PORTB_PINB3  INIT_HIGH   /*PORTB for PIN3 is 1*/
#elif (PORT_PIN_B_3 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_B_3  INIT_HIGH    /*DDRB for PIN3 is 1*/
#define PORTB_PINB3  INIT_HIGH   /*PORTB for PIN3 is 1*/
#elif (PORT_PIN_B_3 == INIT_OUTPUT_LOW)			
#define DDR_PIN_B_3  INIT_HIGH    /*DDRB for PIN3 is 1*/
#define PORTB_PINB3  INIT_LOW    /*PORTB for PIN3 is 0*/
#endif
#if    (DIO_PIN_B_4 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_B_4  INIT_LOW     /*DDRB for PIN4 is 0*/
#define PORTB_PINB4  INIT_LOW    /*PORTB for PIN4 is 0*/
#elif (PORT_PIN_B_4 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_B_4  INIT_LOW     /*DDRB for PIN4 is 0*/
#define PORTB_PINB4  INIT_HIGH   /*PORTB for PIN4 is 1*/
#elif (PORT_PIN_B_4 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_B_4  INIT_HIGH    /*DDRB for PIN4 is 1*/
#define PORTB_PINB4  INIT_HIGH   /*PORTB for PIN4 is 1*/
#elif (PORT_PIN_B_4 == INIT_OUTPUT_LOW)			
#define DDR_PIN_B_4  INIT_HIGH    /*DDRB for PIN4 is 1*/
#define PORTB_PINB4  INIT_LOW    /*PORTB for PIN4 is 0*/
#endif	
#if    (DIO_PIN_B_5== INIT_INPUT_PULL_DOWN)
#define DDR_PIN_B_5 INIT_LOW     /*DDRB for PIN5 is 0*/
#define PORTB_PINB5 INIT_LOW    /*PORTB for PIN5 is 0*/
#elif (PORT_PIN_B_5== INIT_INPUT_PULL_UP)	   
#define DDR_PIN_B_5 INIT_LOW     /*DDRB for PIN5 is 0*/
#define PORTB_PINB5 INIT_HIGH   /*PORTB for PIN5 is 1*/
#elif (PORT_PIN_B_5== INIT_OUTPUT_HIGH)		   
#define DDR_PIN_B_5 INIT_HIGH    /*DDRB for PIN5 is 1*/
#define PORTB_PINB5 INIT_HIGH   /*PORTB for PIN5 is 1*/
#elif (PORT_PIN_B_5== INIT_OUTPUT_LOW)		   
#define DDR_PIN_B_5 INIT_HIGH    /*DDRB for PIN5 is 1*/
#define PORTB_PINB5 INIT_LOW    /*PORTB for PIN5 is 0*/
#endif	
#if    (DIO_PIN_B_6== INIT_INPUT_PULL_DOWN)
#define DDR_PIN_B_6 INIT_LOW     /*DDRB for PIN6 is 0*/
#define PORTB_PINB6 INIT_LOW    /*PORTB for PIN6 is 0*/
#elif (PORT_PIN_B_6== INIT_INPUT_PULL_UP)	   
#define DDR_PIN_B_6 INIT_LOW     /*DDRB for PIN6 is 0*/
#define PORTB_PINB6 INIT_HIGH   /*PORTB for PIN6 is 1*/
#elif (PORT_PIN_B_6== INIT_OUTPUT_HIGH)		   
#define DDR_PIN_B_6 INIT_HIGH    /*DDRB for PIN6 is 1*/
#define PORTB_PINB6 INIT_HIGH   /*PORTB for PIN6 is 1*/
#elif (PORT_PIN_B_6== INIT_OUTPUT_LOW)		   
#define DDR_PIN_B_6 INIT_HIGH    /*DDRB for PIN6 is 1*/
#define PORTB_PINB6 INIT_LOW    /*PORTB for PIN6 is 0*/
#endif	
#if    (DIO_PIN_B_7== INIT_INPUT_PULL_DOWN)
#define DDR_PIN_B_7 INIT_LOW     /*DDRB for PIN7 is 0*/
#define PORTB_PINB7 INIT_LOW    /*PORTB for PIN7 is 0*/
#elif (PORT_PIN_B_7== INIT_INPUT_PULL_UP)	   
#define DDR_PIN_B_7 INIT_LOW     /*DDRB for PIN7 is 0*/
#define PORTB_PINB7 INIT_HIGH   /*PORTB for PIN7 is 1*/
#elif (PORT_PIN_B_7== INIT_OUTPUT_HIGH)		   
#define DDR_PIN_B_7 INIT_HIGH    /*DDRB for PIN7 is 1*/
#define PORTB_PINB7 INIT_HIGH   /*PORTB for PIN7 is 1*/
#elif (PORT_PIN_B_7== INIT_OUTPUT_LOW)		   
#define DDR_PIN_B_7 INIT_HIGH    /*DDRB for PIN7 is 1*/
#define PORTB_PINB7 INIT_LOW    /*PORTB for PIN7 is 0*/

/* AAssign values into the two Ports */
#define PORTA_DIR  CONCAT(DDR_PIN_A_7,DDR_PIN_A_6,DDR_PIN_A_5,DDR_PIN_A_4,DDR_PIN_A_3,DDR_PIN_A_2,DDR_PIN_A_1,DDR_PIN_A_0);
#define PORTB_DIR  CONCAT(DDR_PIN_B_7,DDR_PIN_B_6,DDR_PIN_B_5,DDR_PIN_B_4,DDR_PIN_B_3,DDR_PIN_B_2,DDR_PIN_B_1,DDR_PIN_B_0);
#define PORTA_INITIAL_VALUE CONCAT(PORTA_PINA7,PORTA_PINA6,PORTA_PINA5,PORTA_PINA4,PORTA_PINA3,PORTA_PINA2,PORTA_PINA1,PORTA_PINA0);
#define PORTB_INITIAL_VALUE CONCAT(PORTB_PINB7,PORTB_PINB6,PORTB_PINB5,PORTB_PINB4,PORTB_PINB3,PORTB_PINB2,PORTB_PINB1,PORTB_PINB0);

DDRA=PORTA_DIR;
DDRB=PORTB_DIR;
PORTA=PORTA_INITIAL_VALUE;
PORTB=PORTB_INITIAL_VALUE;
#endif

/* check port nums */	
#if (NUM_PORTS == THREE_PORTS)
#if    (DIO_PIN_C_0 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_0  INIT_LOW     /*DDRC for PIN0 is 0*/
#define PORTC_PINC0  INIT_LOW    /*PORTC for PIN0 is 0*/
#elif (PORT_PIN_C_0 == INIT_INPUT_PULL_UP)
#define DDR_PIN_C_0  INIT_LOW     /*DDRC for PIN0 is 0*/
#define PORTC_PINC0  INIT_HIGH   /*PORTC for PIN0 is 1*/
#elif (PORT_PIN_C_0 == INIT_OUTPUT_HIGH)
#define DDR_PIN_C_0  INIT_HIGH    /*DDRC for PIN0 is 1*/
#define PORTC_PINC0  INIT_HIGH   /*PORTC for PIN0 is 1*/
#elif (PORT_PIN_C_0 == INIT_OUTPUT_LOW)
#define DDR_PIN_C_0  INIT_HIGH    /*DDRC for PIN0 is 1*/
#define PORTC_PINC0  INIT_LOW    /*PORTC for PIN0 is 0*/
#endif	
#if    (DIO_PIN_C_1 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_1  INIT_LOW     /*DDRC for PIN1 is 0*/
#define PORTC_PINC1  INIT_LOW    /*PORTC for PIN1 is 0*/
#elif (PORT_PIN_C_1 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_C_1  INIT_LOW     /*DDRC for PIN1 is 0*/
#define PORTC_PINC1  INIT_HIGH   /*PORTC for PIN1 is 1*/
#elif (PORT_PIN_C_1 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_C_1  INIT_HIGH    /*DDRC for PIN1 is 1*/
#define PORTC_PINC1  INIT_HIGH   /*PORTC for PIN1 is 1*/
#elif (PORT_PIN_C_1 == INIT_OUTPUT_LOW)			
#define DDR_PIN_C_1  INIT_HIGH    /*DDRC for PIN1 is 1*/
#define PORTC_PINC1  INIT_LOW    /*PORTC for PIN1 is 0*/
#endif
#if    (DIO_PIN_C_2 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_2  INIT_LOW     /*DDRC for PIN2 is 0*/
#define PORTC_PINC2  INIT_LOW    /*PORTC for PIN2 is 0*/
#elif (PORT_PIN_C_2 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_C_2  INIT_LOW     /*DDRC for PIN2 is 0*/
#define PORTC_PINC2  INIT_HIGH   /*PORTC for PIN2 is 1*/
#elif (PORT_PIN_C_2 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_C_2  INIT_HIGH    /*DDRC for PIN2 is 1*/
#define PORTC_PINC2  INIT_HIGH   /*PORTC for PIN2 is 1*/
#elif (PORT_PIN_C_2 == INIT_OUTPUT_LOW)			
#define DDR_PIN_C_2  INIT_HIGH    /*DDRC for PIN2 is 1*/
#define PORTC_PINC2  INIT_LOW    /*PORTC for PIN2 is 0*/
#endif	
#if    (DIO_PIN_C_3 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_3  INIT_LOW     /*DDRC for PIN3 is 0*/
#define PORTC_PINC3  INIT_LOW    /*PORTC for PIN3 is 0*/
#elif (PORT_PIN_C_3 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_C_3  INIT_LOW     /*DDRC for PIN3 is 0*/
#define PORTC_PINC3  INIT_HIGH   /*PORTC for PIN3 is 1*/
#elif (PORT_PIN_C_3 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_C_3  INIT_HIGH    /*DDRC for PIN3 is 1*/
#define PORTC_PINC3  INIT_HIGH   /*PORTC for PIN3 is 1*/
#elif (PORT_PIN_C_3 == INIT_OUTPUT_LOW)			
#define DDR_PIN_C_3  INIT_HIGH    /*DDRC for PIN3 is 1*/
#define PORTC_PINC3  INIT_LOW    /*PORTC for PIN3 is 0*/
#endif	
#if    (DIO_PIN_C_4 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_4  INIT_LOW     /*DDRC for PIN4 is 0*/
#define PORTC_PINC4  INIT_LOW    /*PORTC for PIN4 is 0*/
#elif (PORT_PIN_C_4 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_C_4  INIT_LOW     /*DDRC for PIN4 is 0*/
#define PORTC_PINC4  INIT_HIGH   /*PORTC for PIN4 is 1*/
#elif (PORT_PIN_C_4 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_C_4  INIT_HIGH    /*DDRC for PIN4 is 1*/
#define PORTC_PINC4  INIT_HIGH   /*PORTC for PIN4 is 1*/
#elif (PORT_PIN_C_4 == INIT_OUTPUT_LOW)			
#define DDR_PIN_C_4  INIT_HIGH    /*DDRC for PIN4 is 1*/
#define PORTC_PINC4  INIT_LOW    /*PORTC for PIN4 is 0*/
#endif	
#if    (DIO_PIN_C_5 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_5  INIT_LOW     /*DDRC for PIN5 is 0*/
#define PORTC_PINC5  INIT_LOW    /*PORTC for PIN5 is 0*/
#elif (PORT_PIN_C_5 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_C_5  INIT_LOW     /*DDRC for PIN5 is 0*/
#define PORTC_PINC5  INIT_HIGH   /*PORTC for PIN5 is 1*/
#elif (PORT_PIN_C_5 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_C_5  INIT_HIGH    /*DDRC for PIN5 is 1*/
#define PORTC_PINC5  INIT_HIGH   /*PORTC for PIN5 is 1*/
#elif (PORT_PIN_C_5 == INIT_OUTPUT_LOW)			
#define DDR_PIN_C_5  INIT_HIGH    /*DDRC for PIN5 is 1*/
#define PORTC_PINC5  INIT_LOW    /*PORTC for PIN5 is 0*/
#endif	
#if    (DIO_PIN_C_6 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_6  INIT_LOW     /*DDRC for PIN6 is 0*/
#define PORTC_PINC6  INIT_LOW    /*PORTC for PIN6 is 0*/
#elif (PORT_PIN_C_6 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_C_6  INIT_LOW     /*DDRC for PIN6 is 0*/
#define PORTC_PINC6  INIT_HIGH   /*PORTC for PIN6 is 1*/
#elif (PORT_PIN_C_6 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_C_6  INIT_HIGH    /*DDRC for PIN6 is 1*/
#define PORTC_PINC6  INIT_HIGH   /*PORTC for PIN6 is 1*/
#elif (PORT_PIN_C_6 == INIT_OUTPUT_LOW)			
#define DDR_PIN_C_6  INIT_HIGH    /*DDRC for PIN6 is 1*/
#define PORTC_PINC6  INIT_LOW    /*PORTC for PIN6 is 0*/
#endif	
#if    (DIO_PIN_C_7 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_7  INIT_LOW     /*DDRC for PIN7 is 0*/
#define PORTC_PINC7  INIT_LOW    /*PORTC for PIN7 is 0*/
#elif (PORT_PIN_C_7 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_C_7  INIT_LOW     /*DDRC for PIN7 is 0*/
#define PORTC_PINC7  INIT_HIGH   /*PORTC for PIN7 is 1*/
#elif (PORT_PIN_C_7 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_C_7  INIT_HIGH    /*DDRC for PIN7 is 1*/
#define PORTC_PINC7  INIT_HIGH   /*PORTC for PIN7 is 1*/
#elif (PORT_PIN_C_7 == INIT_OUTPUT_LOW)			
#define DDR_PIN_C_7  INIT_HIGH    /*DDRC for PIN7 is 1*/
#define PORTC_PINC7  INIT_LOW    /*PORTC for PIN7 is 0*/

/*Assign values to the third Port*/
#define PORTC_DIR  CONCAT(DDR_PIN_C_7,DDR_PIN_C_6,DDR_PIN_C_5,DDR_PIN_C_4,DDR_PIN_C_3,DDR_PIN_C_2,DDR_PIN_C_1,DDR_PIN_C_0);
#define PORTC_INITIAL_VALUE CONCAT(PORTC_PINC7,PORTC_PINC6,PORTC_PINC5,PORTC_PINC4,PORTC_PINC3,PORTC_PINC2,PORTC_PINC1,PORTC_PINC0);
DDRC=PORTC_DIR;
PORTC=PORTC_INITIAL_VALUE;
#endif
#endif




/* check port nums */	
#if  (NUM_PORTS == FOUR_PORTS)
#if    (DIO_PIN_C_0 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_0  INIT_LOW     /*DDRC for PIN0 is 0*/
#define PORTC_PINC0  INIT_LOW    /*PORTC for PIN0 is 0*/
#elif (PORT_PIN_C_0 == INIT_INPUT_PULL_UP)
#define DDR_PIN_C_0  INIT_LOW     /*DDRC for PIN0 is 0*/
#define PORTC_PINC0  INIT_HIGH   /*PORTC for PIN0 is 1*/
#elif (PORT_PIN_C_0 == INIT_OUTPUT_HIGH)
#define DDR_PIN_C_0  INIT_HIGH    /*DDRC for PIN0 is 1*/
#define PORTC_PINC0  INIT_HIGH   /*PORTC for PIN0 is 1*/
#elif (PORT_PIN_C_0 == INIT_OUTPUT_LOW)
#define DDR_PIN_C_0  INIT_HIGH    /*DDRC for PIN0 is 1*/
#define PORTC_PINC0  INIT_LOW    /*PORTC for PIN0 is 0*/
#endif
#if    (DIO_PIN_C_1 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_1  INIT_LOW     /*DDRC for PIN1 is 0*/
#define PORTC_PINC1  INIT_LOW    /*PORTC for PIN1 is 0*/
#elif (PORT_PIN_C_1 == INIT_INPUT_PULL_UP)
#define DDR_PIN_C_1  INIT_LOW     /*DDRC for PIN1 is 0*/
#define PORTC_PINC1  INIT_HIGH   /*PORTC for PIN1 is 1*/
#elif (PORT_PIN_C_1 == INIT_OUTPUT_HIGH)
#define DDR_PIN_C_1  INIT_HIGH    /*DDRC for PIN1 is 1*/
#define PORTC_PINC1  INIT_HIGH   /*PORTC for PIN1 is 1*/
#elif (PORT_PIN_C_1 == INIT_OUTPUT_LOW)
#define DDR_PIN_C_1  INIT_HIGH    /*DDRC for PIN1 is 1*/
#define PORTC_PINC1  INIT_LOW    /*PORTC for PIN1 is 0*/
#endif
#if    (DIO_PIN_C_2 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_2  INIT_LOW     /*DDRC for PIN2 is 0*/
#define PORTC_PINC2  INIT_LOW    /*PORTC for PIN2 is 0*/
#elif (PORT_PIN_C_2 == INIT_INPUT_PULL_UP)
#define DDR_PIN_C_2  INIT_LOW     /*DDRC for PIN2 is 0*/
#define PORTC_PINC2  INIT_HIGH   /*PORTC for PIN2 is 1*/
#elif (PORT_PIN_C_2 == INIT_OUTPUT_HIGH)
#define DDR_PIN_C_2  INIT_HIGH    /*DDRC for PIN2 is 1*/
#define PORTC_PINC2  INIT_HIGH   /*PORTC for PIN2 is 1*/
#elif (PORT_PIN_C_2 == INIT_OUTPUT_LOW)
#define DDR_PIN_C_2  INIT_HIGH    /*DDRC for PIN2 is 1*/
#define PORTC_PINC2  INIT_LOW    /*PORTC for PIN2 is 0*/
#endif
#if    (DIO_PIN_C_3 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_3  INIT_LOW     /*DDRC for PIN3 is 0*/
#define PORTC_PINC3  INIT_LOW    /*PORTC for PIN3 is 0*/
#elif (PORT_PIN_C_3 == INIT_INPUT_PULL_UP)
#define DDR_PIN_C_3  INIT_LOW     /*DDRC for PIN3 is 0*/
#define PORTC_PINC3  INIT_HIGH   /*PORTC for PIN3 is 1*/
#elif (PORT_PIN_C_3 == INIT_OUTPUT_HIGH)
#define DDR_PIN_C_3  INIT_HIGH    /*DDRC for PIN3 is 1*/
#define PORTC_PINC3  INIT_HIGH   /*PORTC for PIN3 is 1*/
#elif (PORT_PIN_C_3 == INIT_OUTPUT_LOW)
#define DDR_PIN_C_3  INIT_HIGH    /*DDRC for PIN3 is 1*/
#define PORTC_PINC3  INIT_LOW    /*PORTC for PIN3 is 0*/
#endif
#if    (DIO_PIN_C_4 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_4  INIT_LOW     /*DDRC for PIN4 is 0*/
#define PORTC_PINC4  INIT_LOW    /*PORTC for PIN4 is 0*/
#elif (PORT_PIN_C_4 == INIT_INPUT_PULL_UP)
#define DDR_PIN_C_4  INIT_LOW     /*DDRC for PIN4 is 0*/
#define PORTC_PINC4  INIT_HIGH   /*PORTC for PIN4 is 1*/
#elif (PORT_PIN_C_4 == INIT_OUTPUT_HIGH)
#define DDR_PIN_C_4  INIT_HIGH    /*DDRC for PIN4 is 1*/
#define PORTC_PINC4  INIT_HIGH   /*PORTC for PIN4 is 1*/
#elif (PORT_PIN_C_4 == INIT_OUTPUT_LOW)
#define DDR_PIN_C_4  INIT_HIGH    /*DDRC for PIN4 is 1*/
#define PORTC_PINC4  INIT_LOW    /*PORTC for PIN4 is 0*/
#endif
#if    (DIO_PIN_C_5 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_5  INIT_LOW     /*DDRC for PIN5 is 0*/
#define PORTC_PINC5  INIT_LOW    /*PORTC for PIN5 is 0*/
#elif (PORT_PIN_C_5 == INIT_INPUT_PULL_UP)
#define DDR_PIN_C_5  INIT_LOW     /*DDRC for PIN5 is 0*/
#define PORTC_PINC5  INIT_HIGH   /*PORTC for PIN5 is 1*/
#elif (PORT_PIN_C_5 == INIT_OUTPUT_HIGH)
#define DDR_PIN_C_5  INIT_HIGH    /*DDRC for PIN5 is 1*/
#define PORTC_PINC5  INIT_HIGH   /*PORTC for PIN5 is 1*/
#elif (PORT_PIN_C_5 == INIT_OUTPUT_LOW)
#define DDR_PIN_C_5  INIT_HIGH    /*DDRC for PIN5 is 1*/
#define PORTC_PINC5  INIT_LOW    /*PORTC for PIN5 is 0*/
#endif
#if    (DIO_PIN_C_6 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_6  INIT_LOW     /*DDRC for PIN6 is 0*/
#define PORTC_PINC6  INIT_LOW    /*PORTC for PIN6 is 0*/
#elif (PORT_PIN_C_6 == INIT_INPUT_PULL_UP)
#define DDR_PIN_C_6  INIT_LOW     /*DDRC for PIN6 is 0*/
#define PORTC_PINC6  INIT_HIGH   /*PORTC for PIN6 is 1*/
#elif (PORT_PIN_C_6 == INIT_OUTPUT_HIGH)
#define DDR_PIN_C_6  INIT_HIGH    /*DDRC for PIN6 is 1*/
#define PORTC_PINC6  INIT_HIGH   /*PORTC for PIN6 is 1*/
#elif (PORT_PIN_C_6 == INIT_OUTPUT_LOW)
#define DDR_PIN_C_6  INIT_HIGH    /*DDRC for PIN6 is 1*/
#define PORTC_PINC6  INIT_LOW    /*PORTC for PIN6 is 0*/
#endif
#if    (DIO_PIN_C_7 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_C_7  INIT_LOW     /*DDRC for PIN7 is 0*/
#define PORTC_PINC7  INIT_LOW    /*PORTC for PIN7 is 0*/
#elif (PORT_PIN_C_7 == INIT_INPUT_PULL_UP)
#define DDR_PIN_C_7  INIT_LOW     /*DDRC for PIN7 is 0*/
#define PORTC_PINC7  INIT_HIGH   /*PORTC for PIN7 is 1*/
#elif (PORT_PIN_C_7 == INIT_OUTPUT_HIGH)
#define DDR_PIN_C_7  INIT_HIGH    /*DDRC for PIN7 is 1*/
#define PORTC_PINC7  INIT_HIGH   /*PORTC for PIN7 is 1*/
#elif (PORT_PIN_C_7 == INIT_OUTPUT_LOW)
#define DDR_PIN_C_7  INIT_HIGH    /*DDRC for PIN7 is 1*/
#define PORTC_PINC7  INIT_LOW    /*PORTC for PIN7 is 0*/
#endif
#if    (DIO_PIN_D_0 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_D_0  INIT_LOW     /*DDRD for PIN0 is 0*/
#define PORTD_PIND0  INIT_LOW    /*PORTD for PIN0 is 0*/
#elif (PORT_PIN_D_0 == INIT_INPUT_PULL_UP)
#define DDR_PIN_D_0  INIT_LOW     /*DDRD for PIN0 is 0*/
#define PORTD_PIND0  INIT_HIGH   /*PORTD for PIN0 is 1*/
#elif (PORT_PIN_D_0 == INIT_OUTPUT_HIGH)
#define DDR_PIN_D_0  INIT_HIGH    /*DDRD for PIN0 is 1*/
#define PORTD_PIND0  INIT_HIGH   /*PORTD for PIN0 is 1*/
#elif (PORT_PIN_D_0 == INIT_OUTPUT_LOW)
#define DDR_PIN_D_0  INIT_HIGH    /*DDRD for PIN0 is 1*/
#define PORTD_PIND0  INIT_LOW    /*PORTD for PIN0 is 0*/
#endif
#if    (DIO_PIN_D_1 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_D_1  INIT_LOW     /*DDRD for PIN1 is 0*/
#define PORTD_PIND1  INIT_LOW    /*PORTD for PIN1 is 0*/
#elif (PORT_PIN_D_1 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_D_1  INIT_LOW     /*DDRD for PIN1 is 0*/
#define PORTD_PIND1  INIT_HIGH   /*PORTD for PIN1 is 1*/
#elif (PORT_PIN_D_1 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_D_1  INIT_HIGH    /*DDRD for PIN1 is 1*/
#define PORTD_PIND1  INIT_HIGH   /*PORTD for PIN1 is 1*/
#elif (PORT_PIN_D_1 == INIT_OUTPUT_LOW)			
#define DDR_PIN_D_1  INIT_HIGH    /*DDRD for PIN1 is 1*/
#define PORTD_PIND1  INIT_LOW    /*PORTD for PIN1 is 0*/
#endif
#if    (DIO_PIN_D_2 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_D_2  INIT_LOW     /*DDRD for PIN2 is 0*/
#define PORTD_PIND2  INIT_LOW    /*PORTD for PIN2 is 0*/
#elif (PORT_PIN_D_2 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_D_2  INIT_LOW     /*DDRD for PIN2 is 0*/
#define PORTD_PIND2  INIT_HIGH   /*PORTD for PIN2 is 1*/
#elif (PORT_PIN_D_2 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_D_2  INIT_HIGH    /*DDRD for PIN2 is 1*/
#define PORTD_PIND2  INIT_HIGH   /*PORTD for PIN2 is 1*/
#elif (PORT_PIN_D_2 == INIT_OUTPUT_LOW)			
#define DDR_PIN_D_2  INIT_HIGH    /*DDRD for PIN2 is 1*/
#define PORTD_PIND2  INIT_LOW    /*PORTD for PIN2 is 0*/
#endif
#if    (DIO_PIN_D_3 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_D_3  INIT_LOW     /*DDRD for PIN3 is 0*/
#define PORTD_PIND3  INIT_LOW    /*PORTD for PIN3 is 0*/
#elif (PORT_PIN_D_3 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_D_3  INIT_LOW     /*DDRD for PIN3 is 0*/
#define PORTD_PIND3  INIT_HIGH   /*PORTD for PIN3 is 1*/
#elif (PORT_PIN_D_3 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_D_3  INIT_HIGH    /*DDRD for PIN3 is 1*/
#define PORTD_PIND3  INIT_HIGH   /*PORTD for PIN3 is 1*/
#elif (PORT_PIN_D_3 == INIT_OUTPUT_LOW)			
#define DDR_PIN_D_3  INIT_HIGH    /*DDRD for PIN3 is 1*/
#define PORTD_PIND3  INIT_LOW    /*PORTD for PIN3 is 0*/
#endif
#if    (DIO_PIN_D_4 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_D_4  INIT_LOW     /*DDRD for PIN4 is 0*/
#define PORTD_PIND4  INIT_LOW    /*PORTD for PIN4 is 0*/
#elif (PORT_PIN_D_4 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_D_4  INIT_LOW     /*DDRD for PIN4 is 0*/
#define PORTD_PIND4  INIT_HIGH   /*PORTD for PIN4 is 1*/
#elif (PORT_PIN_D_4 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_D_4  INIT_HIGH    /*DDRD for PIN4 is 1*/
#define PORTD_PIND4  INIT_HIGH   /*PORTD for PIN4 is 1*/
#elif (PORT_PIN_D_4 == INIT_OUTPUT_LOW)			
#define DDR_PIN_D_4  INIT_HIGH    /*DDRD for PIN4 is 1*/
#define PORTD_PIND4  INIT_LOW    /*PORTD for PIN4 is 0*/
#endif	
#if    (DIO_PIN_D_5 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_D_5  INIT_LOW     /*DDRD for PIN5 is 0*/
#define PORTD_PIND5  INIT_LOW    /*PORTD for PIN5 is 0*/
#elif (PORT_PIN_D_5 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_D_5  INIT_LOW     /*DDRD for PIN5 is 0*/
#define PORTD_PIND5  INIT_HIGH   /*PORTD for PIN5 is 1*/
#elif (PORT_PIN_D_5 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_D_5  INIT_HIGH    /*DDRD for PIN5 is 1*/
#define PORTD_PIND5  INIT_HIGH   /*PORTD for PIN5 is 1*/
#elif (PORT_PIN_D_5 == INIT_OUTPUT_LOW)			
#define DDR_PIN_D_5  INIT_HIGH    /*DDRD for PIN5 is 1*/
#define PORTD_PIND5  INIT_LOW    /*PORTD for PIN5 is 0*/
#endif
#if    (DIO_PIN_D_6 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_D_6  INIT_LOW     /*DDRD for PIN6 is 0*/
#define PORTD_PIND6  INIT_LOW    /*PORTD for PIN6 is 0*/
#elif (PORT_PIN_D_6 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_D_6  INIT_LOW     /*DDRD for PIN6 is 0*/
#define PORTD_PIND6  INIT_HIGH   /*PORTD for PIN6 is 1*/
#elif (PORT_PIN_D_6 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_D_6  INIT_HIGH    /*DDRD for PIN6 is 1*/
#define PORTD_PIND6  INIT_HIGH   /*PORTD for PIN6 is 1*/
#elif (PORT_PIN_D_6 == INIT_OUTPUT_LOW)			
#define DDR_PIN_D_6  INIT_HIGH    /*DDRD for PIN6 is 1*/
#define PORTD_PIND6  INIT_LOW    /*PORTD for PIN6 is 0*/
#endif	
#if    (DIO_PIN_D_7 == INIT_INPUT_PULL_DOWN)
#define DDR_PIN_D_7  INIT_LOW     /*DDRD for PIN7 is 0*/
#define PORTD_PIND7  INIT_LOW    /*PORTD for PIN7 is 0*/
#elif (PORT_PIN_D_7 == INIT_INPUT_PULL_UP)		
#define DDR_PIN_D_7  INIT_LOW     /*DDRD for PIN7 is 0*/
#define PORTD_PIND7  INIT_HIGH   /*PORTD for PIN7 is 1*/
#elif (PORT_PIN_D_7 == INIT_OUTPUT_HIGH)		
#define DDR_PIN_D_7  INIT_HIGH    /*DDRD for PIN7 is 1*/
#define PORTD_PIND7  INIT_HIGH   /*PORTD for PIN7 is 1*/
#elif (PORT_PIN_D_7 == INIT_OUTPUT_LOW)			
#define DDR_PIN_D_7  INIT_HIGH    /*DDRD for PIN7 is 1*/
#define PORTD_PIND7  INIT_LOW    /*PORTD for PIN7 is 0*/
/*Assign values to the Fourth Port*/
#define PORTD_DIR CONCAT(DDR_PIN_D_7,DDR_PIN_D_6,DDR_PIN_D_5,DDR_PIN_D_4,DDR_PIN_D_3,DDR_PIN_D_2,DDR_PIN_D_1,DDR_PIN_D_0);
#define PORTD_INITIAL_VALUE CONCAT(PORTD_PIND7,PORTD_PIND6,PORTD_PIND5,PORTD_PIND4,PORTD_PIND3,PORTD_PIND2,PORTD_PIND1,PORTD_PIND0);
DDRD=PORTD_DIR;
PORTD=PORTD_INITIAL_VALUE;
/*Assign values to the third Port*/
#define PORTC_DIR  CONCAT(DDR_PIN_C_7,DDR_PIN_C_6,DDR_PIN_C_5,DDR_PIN_C_4,DDR_PIN_C_3,DDR_PIN_C_2,DDR_PIN_C_1,DDR_PIN_C_0);
#define PORTC_INITIAL_VALUE CONCAT(PORTC_PINC7,PORTC_PINC6,PORTC_PINC5,PORTC_PINC4,PORTC_PINC3,PORTC_PINC2,PORTC_PINC1,PORTC_PINC0);
DDRC=PORTC_DIR;
PORTC=PORTC_INITIAL_VALUE;
#endif	  	  
#endif

		
}
#endif

