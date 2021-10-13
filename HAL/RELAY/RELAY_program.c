#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "RELAY_interface.h"
#include "RELAY_private.h"
#include "RELAY_config.h"


void RELAY_voidSetNormallyClosed(void)
{
	DIO_voidSetPinValue (RELAY_PORT,RELAY_PIN,LOW);
}

void RELAY_voidSetNormallyOpen(void)
{
	DIO_voidSetPinValue (RELAY_PORT,RELAY_PIN,HIGH);
}

void RELAY_voidInit(void)
{
	DIO_voidSetPinDirection(RELAY_PORT,RELAY_PIN,OUTPUT);
}
