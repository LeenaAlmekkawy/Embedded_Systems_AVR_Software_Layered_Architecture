#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
void (*Global_pvCTCFunction)(void)=NULL;

void TIMERS_voidInit(void)
{


	/*set CTC Mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	//ENABLE compare interrupt
	 SET_BIT(TIMSK,TIMSK_OCIE0);


//prescaler 8
	 CLR_BIT(TCCR0,TCCR0_CS00);
	 SET_BIT(TCCR0,TCCR0_CS01);
	 CLR_BIT(TCCR0,TCCR0_CS02);





}

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{
	OCR0=Copy_u8CompareMatchValue;
}

void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8PreLoadValue)
{
	TCNT0=Copy_u8PreLoadValue;
}

void TIMERS_voidTimer0CTCSetCallBackFunction(void (*Copy_pvCTCFunction)(void))
{ if(Copy_pvCTCFunction!=NULL)
	Global_pvCTCFunction =Copy_pvCTCFunction;
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

