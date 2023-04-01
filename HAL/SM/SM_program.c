#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMERS/TIMERS_interface.h"

#include "SM_interface.h"
#include "SM_private.h"
#include "SM_config.h"

void SM_voidInit(void)
{
	TIMERS_voidInit();
	DIO_voidSetPinDirection(SM_PORT,BLUE_WIRE_PIN,OUTPUT);
	DIO_voidSetPinDirection(SM_PORT,PINK_WIRE_PIN,OUTPUT);
	DIO_voidSetPinDirection(SM_PORT,YELLOW_WIRE_PIN,OUTPUT);
	DIO_voidSetPinDirection(SM_PORT,ORANGE_WIRE_PIN,OUTPUT);
}

void SM_VoidRotate(u8 Copy_u8Direction ,u16 Copy_u16Angle)
{
	if(Copy_u16Angle>360)
	{
		Copy_u16Angle-=360;
	}
	u32 Local_Steps= (Copy_u16Angle*2048UL)/360;
	u16 Local_Iterations=Local_Steps/4;
	u16 Local_Counter;

	if (Copy_u8Direction==COUNTER_CLOCKWISE)
	{
		for( Local_Counter=1 ; Local_Counter<=Local_Iterations ; Local_Counter++)
		{   DIO_voidSetPinValue(SM_PORT,BLUE_WIRE_PIN,HIGH);
		DIO_voidSetPinValue(SM_PORT,PINK_WIRE_PIN,HIGH);
		DIO_voidSetPinValue(SM_PORT,YELLOW_WIRE_PIN,HIGH);
		DIO_voidSetPinValue(SM_PORT,ORANGE_WIRE_PIN,LOW);
		TIMERS_voidSetBusyWaitTimer2_ms(10);


		DIO_voidSetPinValue(SM_PORT,BLUE_WIRE_PIN,HIGH);
		DIO_voidSetPinValue(SM_PORT,PINK_WIRE_PIN,HIGH);
		DIO_voidSetPinValue(SM_PORT,YELLOW_WIRE_PIN,LOW);
		DIO_voidSetPinValue(SM_PORT,ORANGE_WIRE_PIN,HIGH);
		TIMERS_voidSetBusyWaitTimer2_ms(10);


		DIO_voidSetPinValue(SM_PORT,BLUE_WIRE_PIN,HIGH);
		DIO_voidSetPinValue(SM_PORT,PINK_WIRE_PIN,LOW);
		DIO_voidSetPinValue(SM_PORT,YELLOW_WIRE_PIN,HIGH);
		DIO_voidSetPinValue(SM_PORT,ORANGE_WIRE_PIN,HIGH);
		TIMERS_voidSetBusyWaitTimer2_ms(10);


		DIO_voidSetPinValue(SM_PORT,BLUE_WIRE_PIN,LOW);
		DIO_voidSetPinValue(SM_PORT,PINK_WIRE_PIN,HIGH);
		DIO_voidSetPinValue(SM_PORT,YELLOW_WIRE_PIN,HIGH);
		DIO_voidSetPinValue(SM_PORT,ORANGE_WIRE_PIN,HIGH);
		TIMERS_voidSetBusyWaitTimer2_ms(10);


		}
	}


	else if(Copy_u8Direction==CLOCKWISE)
	{
		for( Local_Counter=1 ; Local_Counter<=Local_Iterations ; Local_Counter++)
		{

			DIO_voidSetPinValue(SM_PORT,BLUE_WIRE_PIN,LOW);
			DIO_voidSetPinValue(SM_PORT,PINK_WIRE_PIN,HIGH);
			DIO_voidSetPinValue(SM_PORT,YELLOW_WIRE_PIN,HIGH);
			DIO_voidSetPinValue(SM_PORT,ORANGE_WIRE_PIN,HIGH);
			TIMERS_voidSetBusyWaitTimer2_ms(10);

			DIO_voidSetPinValue(SM_PORT,BLUE_WIRE_PIN,HIGH);
			DIO_voidSetPinValue(SM_PORT,PINK_WIRE_PIN,LOW);
			DIO_voidSetPinValue(SM_PORT,YELLOW_WIRE_PIN,HIGH);
			DIO_voidSetPinValue(SM_PORT,ORANGE_WIRE_PIN,HIGH);
			TIMERS_voidSetBusyWaitTimer2_ms(10);


			DIO_voidSetPinValue(SM_PORT,BLUE_WIRE_PIN,HIGH);
			DIO_voidSetPinValue(SM_PORT,PINK_WIRE_PIN,HIGH);
			DIO_voidSetPinValue(SM_PORT,YELLOW_WIRE_PIN,LOW);
			DIO_voidSetPinValue(SM_PORT,ORANGE_WIRE_PIN,HIGH);
			TIMERS_voidSetBusyWaitTimer2_ms(10);

			DIO_voidSetPinValue(SM_PORT,BLUE_WIRE_PIN,HIGH);
			DIO_voidSetPinValue(SM_PORT,PINK_WIRE_PIN,HIGH);
			DIO_voidSetPinValue(SM_PORT,YELLOW_WIRE_PIN,HIGH);
			DIO_voidSetPinValue(SM_PORT,ORANGE_WIRE_PIN,LOW);
			TIMERS_voidSetBusyWaitTimer2_ms(10);

		}
	}
}
