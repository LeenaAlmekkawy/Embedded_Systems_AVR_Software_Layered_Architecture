#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include"LCD_interface.h"
#include"LCD_private.h"
#include"LCD_config.h"
#include <util/delay.h>

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,LOW);

	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
   //Set the port value 
   DIO_voidSetSpecificPortValue(LCD_DATA_PORT,Copy_u8Command);

   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,HIGH);
   _delay_ms(2);
   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);

   
}




void LCD_voidSendData(u8 Copy_u8Data)
{
   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,HIGH);

   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);
   //Set the port value 
   DIO_voidSetSpecificPortValue(LCD_DATA_PORT,Copy_u8Data);

   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,HIGH);
   _delay_ms(2);
   DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);

}



void LCD_voidInit(void)
{
 DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);

 DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,OUTPUT);

 DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,OUTPUT);

 DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_EN_PIN,OUTPUT);

 _delay_ms(40);

 LCD_voidSendCommand(0x38);

 LCD_voidSendCommand(0b00001100);

 LCD_voidSendCommand(0x01);


}

void LCD_voidGoToXY(u8 Copy_u8XPos ,u8 Copy_u8YPos)
{
	u8 Local_u8Address =0;
	if(Copy_u8XPos==0)
	{
		Local_u8Address=Copy_u8YPos;
	}

	else if(Copy_u8XPos==1)
	{
		Local_u8Address= DDRAM_OFFSET + Copy_u8YPos;
	}
	SET_BIT(Local_u8Address,7);
	LCD_voidSendCommand(Local_u8Address);


}
void LCD_voidClear(void)
{
	 LCD_voidSendCommand(0b00000001);
}

void LCD_voidSendCustomCharacter(u8*Copy_pu8CharacterArray,u8 Copy_u8PatternNum, u8 Copy_u8XPos,u8 Copy_u8YPos )
{   u8 Local_u8LoopCounter;
	u8 Local_u8CGRAMAddress=0;
	Local_u8CGRAMAddress=Copy_u8PatternNum*8;
	SET_BIT(Local_u8CGRAMAddress,6);
	LCD_voidSendCommand(Local_u8CGRAMAddress);
     for(Local_u8LoopCounter=0 ;Local_u8LoopCounter<8 ;Local_u8LoopCounter++)
     {
    	 LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);

     }
     LCD_voidGoToXY(Copy_u8XPos , Copy_u8YPos);
     LCD_voidSendData(Copy_u8PatternNum);

}

void LCD_voidSendString(const char* Copy_pcString)
{
  u8 Local_u8Counter=0;
  while(Copy_pcString[Local_u8Counter]!='\0')
  {
	  LCD_voidSendData(Copy_pcString[Local_u8Counter]);
	  Local_u8Counter++;
  }
}
void LCD_voidWriteNumber(u32 Copy_u32num, u8 Copy_u8XPos,u8 Copy_u8Ypos)
{ u8 Local_Digit=0;
  u8 Local_Counter=0;


   u8 Digits[MAX_SIZE];
	while(Copy_u32num>0)
	{
		Local_Digit=Copy_u32num%10;
		Digits[Local_Counter]=Local_Digit;
		Local_Counter++;

		Copy_u32num/=10;
	}

	 u8 Local_Iterator;
	 u8 Local_Iterator2=Local_Counter-1;

    for(Local_Iterator=0;Local_Iterator<Local_Counter ; Local_Iterator++)
	{
		 LCD_voidGoToXY(Copy_u8XPos,Copy_u8Ypos+Local_Iterator2);
		 u8 Data=Digits[Local_Iterator]+48;
		 LCD_voidSendData(Data);
		 Local_Iterator2--;

	}
}

void LCD_void4BitInit(void)
{
	DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);

	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,OUTPUT);

	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,OUTPUT);

	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_EN_PIN,OUTPUT);

	 _delay_ms(40);

	 LCD_voidSendCommand(0b00101111);
	 LCD_voidSendCommand(0b00101111);
	 LCD_voidSendCommand(0b10111111);
	 //Display on/off control
	 LCD_voidSendCommand(0b00001111);
	 LCD_voidSendCommand(0b10001111);
	 //Display Clear
	 LCD_voidSendCommand(0b00001111);
	 LCD_voidSendCommand(0b00011111);


}
