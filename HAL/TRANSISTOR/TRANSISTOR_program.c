#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "TRANSISTOR_interface.h"
#include "TRANSISTOR_private.h"
#include "TRANSISTOR_config.h"

void TRANSISTOR_voidSetCutOffMode(void)
{
	DIO_voidSetPinValue (TRANSISTOR_PORT,TRANSISTOR_PIN,LOW);

}

void TRANSISTOR_voidSetSaturationMode(void)
{
	DIO_voidSetPinValue (TRANSISTOR_PORT,TRANSISTOR_PIN,HIGH);

}

void TRANSISTOR_voidInit(void)
{
	DIO_voidSetPinDirection(TRANSISTOR_PORT,TRANSISTOR_PIN,OUTPUT);
}

