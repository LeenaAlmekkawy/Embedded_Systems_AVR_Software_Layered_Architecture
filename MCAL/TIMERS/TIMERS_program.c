#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
void (*Global_pvCTCFunction)(void)=NULL;
u8 Global_flag=0;
u16 Global_time=0;
void TIMERS_voidInit(void)
{


	/*set PWM Mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	//ENABLE compare interrupt
	// SET_BIT(TIMSK,TIMSK_OCIE0);

	 SET_BIT(TCCR0,TCCR0_COM01);
	 CLR_BIT(TCCR0,TCCR0_COM00);
   //Prescaler 8
	 CLR_BIT(TCCR0,TCCR0_CS00);
	 SET_BIT(TCCR0,TCCR0_CS01);
	 CLR_BIT(TCCR0,TCCR0_CS02);

	 //set CTC mode for timer 2
	 CLR_BIT(TCCR2,TCCR2_WGM20);
	 SET_BIT(TCCR2,TCCR2_WGM21);

	 //disconnect OC2
	 CLR_BIT(TCCR2,TCCR2_COM20);
	 CLR_BIT(TCCR2,TCCR2_COM21);

	 //Prescaler 8 for timer 2
	 CLR_BIT(TCCR2,TCCR2_CS20);
	 SET_BIT(TCCR2,TCCR2_CS21);
	 CLR_BIT(TCCR2,TCCR2_CS22);









}

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{
	OCR0=Copy_u8CompareMatchValue;
}

void TIMERS_voidTimer2SetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{
	OCR2=Copy_u8CompareMatchValue;
}

void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8PreLoadValue)
{
	TCNT0=Copy_u8PreLoadValue;
}

void TIMERS_voidTimer2SetPreLoadValue(u8 Copy_u8PreLoadValue)
{
	TCNT2=Copy_u8PreLoadValue;
}



void TIMERS_voidTimer0CTCSetCallBackFunction(void (*Copy_pvCTCFunction)(void))
{
	Global_pvCTCFunction =Copy_pvCTCFunction;
}



void TIMERS_voidSetBusyWaitTimer2_ms(u32 Copy_u32Time_ms)
{
	TIMERS_voidTimer2SetCompareMatchValue(250);
	for(u32 Local_counter1=1; Local_counter1<=Copy_u32Time_ms;Local_counter1++ )
	{
		for(u32 Local_counter2=1; Local_counter2<=4;Local_counter2++ )
			{
			   while(GET_BIT(TIFR,TIFR_OCF2)==0)
			   {
				   /*do nothing
				     */
			   }
			   SET_BIT(TIFR,TIFR_OCF2);

			}
	}


}

void __vector_10 (void)  __attribute__((signal));
void __vector_10 (void)
{
  if(Global_pvCTCFunction!=NULL)
  {
	  Global_pvCTCFunction();
  }
  else
  {
	  /*Do Nothing*/
  }


}



