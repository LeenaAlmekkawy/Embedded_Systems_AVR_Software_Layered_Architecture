#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void (*Global_pvNotificationFunction)(void)=NULL;
u8 ADC_u8Result;
u8 ADC_u8BusyState=0;
void ADC_voidInit(void)
{//voltage reference
	//Set AREF TO be AVCC
	CLR_BIT(ADMUX  ,ADMUX_REFS1);
     SET_BIT(ADMUX  ,ADMUX_REFS0);

    //set the left Adjust
      SET_BIT(ADMUX  ,ADMUX_ADLAR);

  //ADC_PRESCALER selection
      ADCSRA&=PRESCALER_MASK;
    	ADCSRA|=ADC_PRESCALER;


//ADC enable
#if ADC_ENABLE==ENABLE
    SET_BIT(ADCSRA,ADCSRA_ADEN);
 #elif ADC_ENABLE==DISABLE
    CLR_BIT(ADCSRA,ADCSRA_ADEN);
 #else
       #error "ADC_ENABLE Configuration Error"
  #endif



}

u8 ADC_voidStartConversionSynchronous(u8 copy_u8ChannelNumber)
{  if(ADC_u8BusyState==BUSY)
{
	return 0;
}
else
{//set ADC peripheral to busy
	ADC_u8BusyState=BUSY;
	//ADC_Channel Selection
	    	ADMUX&=CHANNEL_MASK;
	    	ADMUX|=copy_u8ChannelNumber;

	 //start the conversion
	    	SET_BIT(ADCSRA,ADCSRA_ADSC);

	 //polling until the conversion complete

	  while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	  //clear the flag
	     SET_BIT(ADCSRA,ADCSRA_ADIF);
	     //set ADC peripheral to unbusy
	     ADC_u8BusyState=NOTBUSY;
	  return ADCH;
}



}

u8 ADC_voidStartConversionAsynchronous(u8 copy_u8ChannelNumber,void(*Copy_pvCallBackFunction(void)))
{   if(ADC_u8BusyState==BUSY)
{
	return 0;
}
else
{//set ADC peripheral to be busy
	ADC_u8BusyState=BUSY;
	//ADC_Channel Selection
	    	ADMUX&=CHANNEL_MASK;
	    	ADMUX|=ADC_INPUT_CHANNEL;

	    	Global_pvNotificationFunction=Copy_pvCallBackFunction;
	 //start the conversion
	    	SET_BIT(ADCSRA,ADCSRA_ADSC);

	    //ADC interrupt enable

	    	SET_BIT(ADCSRA,ADCSRA_ADIE);
//return the data

	    	return ADC_u8Result;
}

}

void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
	//read the result
	ADC_u8Result=ADCH;
  if(Global_pvNotificationFunction!=NULL)
  {
	  Global_pvNotificationFunction();
	  //set ADC peripheral to be unbusy
	  ADC_u8BusyState=NOTBUSY;
	  //Disable ADC interrupt
		CLR_BIT(ADCSRA,ADCSRA_ADIE);//-->IN THE INIT FUN
  }
  else
  {
	  /*Do Nothing*/
  }


}


