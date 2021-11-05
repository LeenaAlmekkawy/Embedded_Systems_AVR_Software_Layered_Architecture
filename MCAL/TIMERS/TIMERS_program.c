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

void Timer_voidCounter(void)
{
	static u16 Local_u16Counter=0;
		Local_u16Counter++;
	if(Local_u16Counter==Global_time)
	{
		Local_u16Counter=0;
		Global_flag=1;
		return ;
	}

}

void TIMERS_voidTimer0CTCSetCallBackFunction(void (*Copy_pvCTCFunction)(void))
{
	Global_pvCTCFunction =Copy_pvCTCFunction;
}





void TIMERS_voidSetBusyWait(u16 Copy_u16Time_ms)
{
   Global_time=(10)*Copy_u16Time_ms;
   while(Global_flag==0)
   {
  TIMERS_voidTimer0CTCSetCallBackFunction(&Timer_voidCounter);
   }

	  Global_flag=0;



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



