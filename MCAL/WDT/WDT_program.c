#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"
#define   WDT_16_MSEC     0
void WDT_voidSleep(u8 Copy_u8TimeOut)
{   if(Copy_u8TimeOut<=7)
	{
		WDTCR &=0b11111000;
	    WDTCR |=Copy_u8TimeOut;
	}
	else 
	{
		/*do nothing
		*/
	}
	 

}
void WDT_voidEnable(void)
{   
	 
 SET_BIT(WDTCR,WDTCR_WDE);
}
void WDT_voidDisanable(void)
{   
    WDTCR=((1<<WDTCR_WDE)|(1<<WDTCR_WDE));	 
    WDTCR=0X00;
}
