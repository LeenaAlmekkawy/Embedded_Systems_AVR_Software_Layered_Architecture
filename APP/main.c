#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"

#include"../MCAL/DIO/DIO_interface.h"
#include"../MCAL/EXTI/EXTI_interface.h"
#include"../MCAL/TIMERS/TIMERS_interface.h"
#include"../MCAL/GIE/GIE_interface.h"
#include"../HAL/LCD/LCD_interface.h"



void main(void)
{  DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
TIMERS_voidInit();
    while(1)
    {
    	DIO_voidSetPinValue(PORTA,PIN0,HIGH);
    	TIMERS_voidSetBusyWaitTimer2_ms(500);
    	DIO_voidSetPinValue(PORTA,PIN0,LOW);
    	 TIMERS_voidSetBusyWaitTimer2_ms(500);





    }


}



