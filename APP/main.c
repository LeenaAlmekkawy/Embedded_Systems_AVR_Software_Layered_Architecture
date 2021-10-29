#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"

#include"../MCAL/DIO/DIO_interface.h"
#include"../MCAL/EXTI/EXTI_interface.h"
#include"../MCAL/GIE/GIE_interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include"../HAL/KPD/KPD_interface.h"
#include <util/delay.h>
u8 Global_RedLedState=0;
u8 Global_YellowLedState=0;
u8 Global_GreenLedState=0;
void Toggle_RedLed(void);
void Toggle_YellowLed(void);
void Toggle_GreenLed (void);

u8 LEDon1[] = {
	  0x01,
	  0x02,
	  0x04,
	  0x04,
	  0x02,
	  0x01,
	  0x01,
	  0x00
	};
	u8 LEDon2[] = {
			 0x10,
			  0x08,
			  0x04,
			  0x04,
			  0x08,
			  0x10,
			  0x10,
			  0x00
		};
	u8 LEDoff1[] = {
			 0x01,
			  0x03,
			  0x07,
			  0x07,
			  0x03,
			  0x01,
			  0x01,
			  0x00
		};
		u8 LEDoff2[] = {
				0x10,
				  0x18,
				  0x1C,
				  0x1C,
				  0x18,
				  0x10,
				  0x10,
				  0x00
			};
void main(void)
{
	LCD_voidInit();
	LCD_voidSendString("GREEN YELLOW RED");

	LCD_voidSendCustomCharacter(LEDon1,1, 1, 1 );
	LCD_voidSendCustomCharacter(LEDon2,2, 1, 2 );

	LCD_voidSendCustomCharacter(LEDon1,1, 1, 8 );
  LCD_voidSendCustomCharacter(LEDon2,2, 1, 9 );

  LCD_voidSendCustomCharacter(LEDon1,1, 1, 14 );
    LCD_voidSendCustomCharacter(LEDon2,2, 1, 15 );



	DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN2,OUTPUT);

DIO_voidSetPinDirection(PORTD,PIN3,INPUT);
DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
DIO_voidSetPinDirection(PORTB,PIN2,INPUT);

DIO_voidSetPinValue(PORTD,PIN3,HIGH);
DIO_voidSetPinValue(PORTD,PIN2,HIGH);
DIO_voidSetPinValue(PORTB,PIN2,HIGH);
	/*EXTI_voidSetInt0SenseControl(FALLING_EDGE);
	EXTI_voidINT0Control(ENABLE );*/
	GIE_voidEnableGlobalInterrupt();
    EXTI_voidIntInit();

EXTI_voidInt0SetCallBack(&Toggle_RedLed );
EXTI_voidInt1SetCallBack(&Toggle_YellowLed);
EXTI_voidInt2SetCallBack(&Toggle_GreenLed);

 while(1)
 {

 }

}

void Toggle_RedLed (void)
{
	 if(Global_RedLedState==0)
	{    LCD_voidSendCustomCharacter(LEDoff1,3, 1, 14 );
	       LCD_voidSendCustomCharacter(LEDoff2,4, 1, 15 );
		DIO_voidSetPinValue(PORTA,PIN0,HIGH);
		Global_RedLedState=1;

	}
	else if(Global_RedLedState==1)
	{  LCD_voidSendCustomCharacter(LEDon1,1, 1, 14 );
    LCD_voidSendCustomCharacter(LEDon2,2, 1, 15 );
		DIO_voidSetPinValue(PORTA,PIN0,LOW);
		Global_RedLedState=0;

	}

}
void Toggle_YellowLed (void)
{
	 if(Global_YellowLedState==0)
	{LCD_voidSendCustomCharacter(LEDoff1,3, 1, 8 );
	  LCD_voidSendCustomCharacter(LEDoff2,4, 1, 9 );

		DIO_voidSetPinValue(PORTA,PIN1,HIGH);
		Global_YellowLedState=1;

	}
	else if(Global_YellowLedState==1)
	{LCD_voidSendCustomCharacter(LEDon1,1, 1, 8 );
	  LCD_voidSendCustomCharacter(LEDon2,2, 1, 9 );

		DIO_voidSetPinValue(PORTA,PIN1,LOW);
		Global_YellowLedState=0;

	}

}
void Toggle_GreenLed (void)
{
	 if(Global_GreenLedState==0)
	{LCD_voidSendCustomCharacter(LEDoff1,3, 1, 1 );
	LCD_voidSendCustomCharacter(LEDoff2,4, 1, 2 );

		DIO_voidSetPinValue(PORTA,PIN2,HIGH);
		Global_GreenLedState=1;

	}
	else if(Global_GreenLedState==1)
	{LCD_voidSendCustomCharacter(LEDon1,1, 1, 1 );
	LCD_voidSendCustomCharacter(LEDon2,2, 1, 2 );

		DIO_voidSetPinValue(PORTA,PIN2,LOW);
		Global_GreenLedState=0;

	}

}



