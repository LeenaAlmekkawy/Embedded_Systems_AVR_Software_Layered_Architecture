#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"




void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState)
{
    switch(Copy_u8PortName)
    {
    case PORTA:
        switch(Copy_u8PinState)
        {
        case INPUT:
            CLR_BIT(DIO_DDRA,Copy_u8PinNumber);
            break;
        case OUTPUT:
            SET_BIT(DIO_DDRA,Copy_u8PinNumber);
            break;

       }
        break;

    case PORTB:
        switch(Copy_u8PinState)
        {
        case INPUT:
            CLR_BIT(DIO_DDRB,Copy_u8PinNumber);
            break;
        case OUTPUT:
            SET_BIT(DIO_DDRB,Copy_u8PinNumber);
            break;

        }
        break;
    case PORTC:
        switch(Copy_u8PinState)
        {
        case INPUT:
            CLR_BIT(DIO_DDRC,Copy_u8PinNumber);
            break;
        case OUTPUT:
            SET_BIT(DIO_DDRC,Copy_u8PinNumber);
            break;

        }
        break;
    case PORTD:
        switch(Copy_u8PinState)
        {
        case INPUT:
            CLR_BIT(DIO_DDRD,Copy_u8PinNumber);
            break;
        case OUTPUT:
            SET_BIT(DIO_DDRD,Copy_u8PinNumber);
            break;

        }
        break;
    }
}




void DIO_voidSetPinVlaue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    switch(Copy_u8PortName)
    {
    case PORTA:
        switch(Copy_u8PinValue)
        {
        case LOW:
            CLR_BIT(DIO_PORTA,Copy_u8PinNumber);
            break;
        case HIGH:
            SET_BIT(DIO_PORTA,Copy_u8PinNumber);
            break;

        }
        break;

    case PORTB:
        switch(Copy_u8PinValue)
        {
        case LOW:
            CLR_BIT(DIO_PORTB,Copy_u8PinNumber);
            break;
        case HIGH:
            SET_BIT(DIO_PORTB,Copy_u8PinNumber);
            break;

        }
        break;
    case PORTC:
        switch(Copy_u8PinValue)
        {
        case LOW:
            CLR_BIT(DIO_PORTC,Copy_u8PinNumber);
            break;
        case HIGH:
            SET_BIT(DIO_PORTC,Copy_u8PinNumber);
            break;

        }
        break;
    case PORTD:
        switch(Copy_u8PinValue)
        {
        case LOW:
            CLR_BIT(DIO_PORTD,Copy_u8PinNumber);
            break;
        case HIGH:
            SET_BIT(DIO_PORTD,Copy_u8PinNumber);
            break;

        }

    }
}




u8 DIO_u8GetPinvlaue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{    u8 Local_PinValue;
    switch(Copy_u8PortName)
    {
    case PORTA:
             Local_PinValue= GET_BIT(DIO_PINA,Copy_u8PinNumber);
           break;
    case PORTB:
         Local_PinValue= GET_BIT(DIO_PINB,Copy_u8PinNumber);
           break;
    case PORTC:
         Local_PinValue= GET_BIT(DIO_PINC,Copy_u8PinNumber);
           break;
    case PORTD:
         Local_PinValue= GET_BIT(DIO_PIND,Copy_u8PinNumber);
           break;         
   }
    return  Local_PinValue;
}





void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortState)
{
    switch(Copy_u8PortName)
    {
    case PORTA:
        switch(Copy_u8PortState)
        {
        case INPUT:
            DIO_DDRA=0X0;
            break;
        case OUTPUT:
            DIO_DDRA=0XFF;
            break;

        }
        break;
    case PORTB:
        switch(Copy_u8PortState)
        {
        case INPUT:
            DIO_DDRB=0X0;
            break;
        case OUTPUT:
            DIO_DDRB=0XFF;
            break;

        }
        break;
    case PORTC:
        switch(Copy_u8PortState)
        {
        case INPUT:
            DIO_DDRC=0X0;
            break;
        case OUTPUT:
            DIO_DDRC=0XFF;
            break;

        }
        break;
    case PORTD:
        switch(Copy_u8PortState)
        {
        case INPUT:
            DIO_DDRD=0X0;
            break;
        case OUTPUT:
            DIO_DDRD=0XFF;
            break;

        }
        break;
    }
}




void DIO_voidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
    switch(Copy_u8PortName)
    {
    case PORTA:
        switch(Copy_u8PortValue)
        {
        case LOW:
            DIO_PORTA=0X0;
            break;
        case HIGH:
            DIO_PORTA=0XFF;
            break;

        }
        break;
    case PORTB:
        switch(Copy_u8PortValue)
        {
        case LOW:
            DIO_PORTB=0X0;
            break;
        case HIGH:
            DIO_PORTB=0XFF;
            break;

        }
        break;
    case PORTC:
        switch(Copy_u8PortValue)
        {
        case LOW:
            DIO_PORTC=0X0;
            break;
        case HIGH:
            DIO_PORTC=0XFF;
            break;

        }
        break;
    case PORTD:
        switch(Copy_u8PortValue)
        {
        case LOW:
            DIO_PORTD=0X0;
            break;
        case HIGH:
            DIO_PORTD=0XFF;
            break;

        }
        break;
    }
}




void DIO_voidSetSpecificPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortState)
{
    switch(Copy_u8PortName)
    {
    case PORTA:
        DIO_DDRA=Copy_u8PortState;
        break;
    case PORTB:
        DIO_DDRB=Copy_u8PortState;
        break;
    case PORTC:
        DIO_DDRC=Copy_u8PortState;
        break;
    case PORTD:
        DIO_DDRD=Copy_u8PortState;
        break;
    }

}



u8 DIO_u8GetPortValue(u8 Copy_u8PortName)
{   u8 Local_PortValue;
      switch(Copy_u8PortName)
    {
    case PORTA:
        Local_PortValue= DIO_PORTA;
        break;
    case PORTB:
        Local_PortValue= DIO_PORTB;
        break;
    case PORTC:
        Local_PortValue= DIO_PORTC;
        break;
    case PORTD:
        Local_PortValue= DIO_PORTD;
        break;
    }
      return Local_PortValue;
}




void DIO_voidSetSpecificPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
    switch(Copy_u8PortName)
    {
    case PORTA:
        DIO_PORTA=Copy_u8PortValue;
        break;
    case PORTB:
        DIO_PORTB=Copy_u8PortValue;
        break;
    case PORTC:
        DIO_PORTC=Copy_u8PortValue;
        break;
    case PORTD:
        DIO_PORTD=Copy_u8PortValue;
        break;
    }

}
