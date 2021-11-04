#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"

#include"../MCAL/DIO/DIO_interface.h"
#include"../MCAL/EXTI/EXTI_interface.h"
#include"../MCAL/GIE/GIE_interface.h"
#include"../MCAL/ADC/ADC_interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include"../HAL/KPD/KPD_interface.h"
#include <util/delay.h>
u8 Global_RedLedState=0;
u8 Global_YellowLedState=0;
u8 Global_GreenLedState=0;

void main(void)
{   DIO_voidSetPinDirection (PORTA, PIN0, INPUT);
    DIO_voidSetPortDirection(PORTD, OUTPUT);
 DIO_voidSetPinValue     (PORTA, PIN0, LOW);
	LCD_voidInit();
	//LCD_voidSendString("0 LEDs are on");
   ADC_voidInit();





 while(1)
 {
	 u32 digital;
	   digital=ADC_voidStartConversionSynchronous(0);
	   // LCD_voidWriteNumber(digital, 1,0);
	    if(digital<140)
	    {  LCD_voidClear();
	    	 LCD_voidSendString("6 LEDs are on");
	    	  DIO_voidSetSpecificPortValue (PORTD, 0b11011011);
	    }
	    else if(digital<160 && digital>150)
	  	    {  LCD_voidClear();
	  	    	 LCD_voidSendString("4 LEDs are on");
	  	    	 DIO_voidSetSpecificPortValue (PORTD, 0b00011011);
	  	    }
	    else if(digital<170 && digital>160)
	    	  	    {  LCD_voidClear();
	    	  	    	 LCD_voidSendString("3 LEDs are on");
	    	  	    	 DIO_voidSetSpecificPortValue (PORTD, 0b00001011);
	    	  	    }
	    else if(digital<182 && digital>170)
	  	    	  	    {  LCD_voidClear();
	  	    	  	    	 LCD_voidSendString("2 LEDs are on");
	  	    	  	    	 DIO_voidSetSpecificPortValue (PORTD, 0b00000011);
	  	    	  	    }
	    else if(digital>183)
	    	  	     {  LCD_voidClear();
	    	  	    	  	   LCD_voidSendString("1 LED is on");
	    	  	    	  	DIO_voidSetSpecificPortValue (PORTD, 0b00000001);
	    	  	    	  }


	_delay_ms(500);

 }

}

