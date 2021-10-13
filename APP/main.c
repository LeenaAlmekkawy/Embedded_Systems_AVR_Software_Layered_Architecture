#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"

#include"../MCAL/DIO/DIO_interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include"../HAL/KPD/KPD_interface.h"
#include <util/delay.h>

void main(void)
{

	DIO_voidSetPinDirection(PORTA ,PIN0,OUTPUT);
	while(1)
	{   DIO_voidSetPinValue(PORTA ,PIN0,HIGH);
	    _delay_ms(3000);

		DIO_voidSetPinValue(PORTA ,PIN0,LOW);
		 _delay_ms(1000);
	}


}



