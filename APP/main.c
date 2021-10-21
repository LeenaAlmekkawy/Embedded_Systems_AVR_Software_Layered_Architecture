#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"

#include"../MCAL/DIO/DIO_interface.h"
#include"../MCAL/EXTI/EXTI_interface.h"
#include"../MCAL/GIE/GIE_interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include"../HAL/KPD/KPD_interface.h"
#include <util/delay.h>

void main(void)
{    DIO_voidSetPinDirection(PORTA,PIN1,OUTPUT);
DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
DIO_voidSetPinValue(PORTD,PIN2,HIGH);
	EXTI_voidSetInt0SenseControl(FALLING_EDGE);
	EXTI_voidINT0Control(ENABLE );
	GIE_voidEnableGlobalInterrupt();

 while(1)
 {

 }

}





