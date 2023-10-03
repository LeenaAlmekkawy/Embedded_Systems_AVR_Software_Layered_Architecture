#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

#include "FLEX_config.h"
#include "FLEX_interface.h"
#include "FLEX_private.h"

void FLEX_voidInit(void)
{   DIO_voidSetPortDirection(PORTA,INPUT);
	ADC_voidInit();
}
u8 FLEX_u8ReadPinkyFlex(void)
{
	u8 Local_u8ReadPinky=ADC_voidStartConversionSynchronous(FLEX_PINKEY_PIN);
	return Local_u8ReadPinky;
}
u8 FLEX_u8ReadRingFlex(void)
{
	u8 Local_u8ReadRing=ADC_voidStartConversionSynchronous(FLEX_RING_PIN);
	return Local_u8ReadRing;
}
u8 FLEX_u8ReadMiddleFlex(void)
{
	u8 Local_u8ReadMiddle=ADC_voidStartConversionSynchronous(FLEX_MIDDLE_PIN);
	return Local_u8ReadMiddle;
}
u8 FLEX_u8ReadIndexFlex(void)
{
	u8 Local_u8ReadIndex=ADC_voidStartConversionSynchronous(FLEX_INDEX_PIN);
	return Local_u8ReadIndex;
}
u8 FLEX_u8ReadThumbFlex(void)
{
	u8 Local_u8ReadThumb=ADC_voidStartConversionSynchronous(FLEX_THUMB_PIN);
	return Local_u8ReadThumb;
}
