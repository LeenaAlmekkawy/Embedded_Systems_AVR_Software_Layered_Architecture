#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "OPC_interface.h"
#include "OPC_private.h"
#include "OPC_config.h"

void OPC_voidSetCutOffMode(void)
{
	DIO_voidSetPinValue (OPC_PORT,OPC_PIN,LOW);

}

void OPC_voidSetSaturationMode(void)
{
	DIO_voidSetPinValue (OPC_PORT,OPC_PIN,HIGH);

}

void OPC_voidInit(void)
{
	DIO_voidSetPinDirection(OPC_PORT,OPC_PIN,OUTPUT);
}

