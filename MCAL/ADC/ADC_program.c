#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit(void)
{//voltage reference
	CLR_BIT(ADMUX  ,ADMUX_REFS1 );
      SET_BIT(ADMUX  ,ADMUX_REFS0 );

  //ADC_PRESCALER selection
      ADCSRA&=0b11111000;
    	ADCSRA|=ADC_PRESCALER;

    	//ADC_Channel Selection
    	ADMUX&=0b11100000;
    	ADMUX|=ADC_INPUT_CHANNEL;

//ADC enable
#if ADC_ENABLE==ENABLE
    SET_BIT(ADCSRA,ADCSRA_ADEN);
 #elif ADC_ENABLE==DISABLE
    CLR_BIT(ADCSRA,ADCSRA_ADEN);
 #else
       #error "ADC_ENABLE Configuration Error"
  #endif






}
