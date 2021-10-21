#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
u8 Global_LedState=0;
void EXTI_voidSetInt0SenseControl(u8 Copy_u8SenseControl)
{
   switch(Copy_u8SenseControl)
   {
   case FALLING_EDGE:
	   SET_BIT(MCUCR,MCUCR_ISC01);
	   CLR_BIT(MCUCR,MCUCR_ISC00);

	   break;

   case RISING_EDGE:
	   SET_BIT(MCUCR,MCUCR_ISC01);
	  	 SET_BIT(MCUCR,MCUCR_ISC00);
  	   break;

   case ON_CHANGE:
	   CLR_BIT(MCUCR,MCUCR_ISC01);
	 	 SET_BIT(MCUCR,MCUCR_ISC00);
  	   break;

   case LOW_LEVEL:
	   CLR_BIT(MCUCR,MCUCR_ISC01);
	 	 CLR_BIT(MCUCR,MCUCR_ISC00);
  	   break;

   }
}

void EXTI_voidSetInt1SenseControl(u8 Copy_u8SenseControl)
{
	  switch(Copy_u8SenseControl)
	   {
	   case FALLING_EDGE:
		   SET_BIT(MCUCR,MCUCR_ISC11);
		   CLR_BIT(MCUCR,MCUCR_ISC10);

		   break;

	   case RISING_EDGE:
		   SET_BIT(MCUCR,MCUCR_ISC11);
		  	 SET_BIT(MCUCR,MCUCR_ISC10);
	  	   break;

	   case ON_CHANGE:
		   CLR_BIT(MCUCR,MCUCR_ISC11);
		 	 SET_BIT(MCUCR,MCUCR_ISC10);
	  	   break;

	   case LOW_LEVEL:
		   CLR_BIT(MCUCR,MCUCR_ISC11);
		 	 CLR_BIT(MCUCR,MCUCR_ISC10);
	  	   break;

	   }

}

void EXTI_voidSetInt2SenseControl(u8 Copy_u8SenseControl)
{
	  switch(Copy_u8SenseControl)
		   {
		   case FALLING_EDGE:
			   CLR_BIT(MCUCSR,MCUCSR_ISC2);

			   break;

		   case RISING_EDGE:
			  	 SET_BIT(MCUCSR,MCUCSR_ISC2);
		  	   break;



		   }
}

void EXTI_voidINT0Control(u8 Copy_u8Int0State)
{
	switch(Copy_u8Int0State)
	{
	case ENABLE:
		   SET_BIT(GICR,GICR_INT0);
		   break;
	case DISABLE:
			   CLR_BIT(GICR,GICR_INT0);
			   break;
	}
}
void EXTI_voidINT1Control(u8 Copy_u8Int1State)
{
	switch(Copy_u8Int1State)
	{
	case ENABLE:
		   SET_BIT(GICR,GICR_INT1);
		   break;
	case DISABLE:
			   CLR_BIT(GICR,GICR_INT1);
			   break;
	}
}
void EXTI_voidINT2Control(u8 Copy_u8Int2State)
{
	switch(Copy_u8Int2State)
	{
	case ENABLE:
		   SET_BIT(GICR,GICR_INT2);
		   break;
	case DISABLE:
			   CLR_BIT(GICR,GICR_INT2);
			   break;
	}
}

void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{   if(Global_LedState==0)
{
	DIO_voidSetPinValue(PORTA,PIN1,HIGH);
	Global_LedState=1;

}
else if(Global_LedState==1)
{
	DIO_voidSetPinValue(PORTA,PIN1,LOW);
	Global_LedState=0;

}



}






