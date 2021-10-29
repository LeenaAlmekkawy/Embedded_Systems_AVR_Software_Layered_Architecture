#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


void (*Global_pvInt0NotificationFunction)(void)=NULL;
void (*Global_pvInt1NotificationFunction)(void)=NULL;
void (*Global_pvInt2NotificationFunction)(void)=NULL;


void EXTI_voidIntInit(void)
{
  #if EXTI_INT0_ENABLE==ENABLE
	 SET_BIT(GICR,GICR_INT0);

      #if EXTI_INT0_SENSE_CONTROL==FALLING_EDGE
	       SET_BIT(MCUCR,MCUCR_ISC01);
		   CLR_BIT(MCUCR,MCUCR_ISC00);
      #elif EXTI_INT0_SENSE_CONTROL==RISING_EDGE
		   SET_BIT(MCUCR,MCUCR_ISC01);
	       SET_BIT(MCUCR,MCUCR_ISC00);
      #elif EXTI_INT0_SENSE_CONTROL==ON_CHANGE
		    CLR_BIT(MCUCR,MCUCR_ISC01);
	    	 SET_BIT(MCUCR,MCUCR_ISC00);
      #elif EXTI_INT0_SENSE_CONTROL==LOW_LEVEL
			  	 CLR_BIT(MCUCR,MCUCR_ISC01);
			 	     CLR_BIT(MCUCR,MCUCR_ISC00);
     #else
      #error  "EXTI_INT0_SENSE_CONTROL ERROR Configuration"
     #endif

  #elif  EXTI_INT0_ENABLE==DISABLE
	 CLR_BIT(GICR,GICR_INT0);

   #else
        #error  "EXTI_INT0_ENABLE ERROR Configuration"
  #endif
	 //INT1
#if EXTI_INT1_ENABLE==ENABLE
	 SET_BIT(GICR,GICR_INT1);

    #if EXTI_INT1_SENSE_CONTROL==FALLING_EDGE
	  SET_BIT(MCUCR,MCUCR_ISC11);
	 CLR_BIT(MCUCR,MCUCR_ISC10);
    #elif EXTI_INT1_SENSE_CONTROL==RISING_EDGE
	 SET_BIT(MCUCR,MCUCR_ISC11);
	  SET_BIT(MCUCR,MCUCR_ISC10);
    #elif EXTI_INT1_SENSE_CONTROL==ON_CHANGE
	  CLR_BIT(MCUCR,MCUCR_ISC11);
		 SET_BIT(MCUCR,MCUCR_ISC10);
    #elif EXTI_INT1_SENSE_CONTROL==LOW_LEVEL
			  	 CLR_BIT(MCUCR,MCUCR_ISC11);
			 	     CLR_BIT(MCUCR,MCUCR_ISC10);
   #else
    #error  "EXTI_INT1_SENSE_CONTROL ERROR Configuration"
   #endif

#elif  EXTI_INT1_ENABLE==DISABLE
	 CLR_BIT(GICR,GICR_INT1);

 #else
      #error  "EXTI_INT1_ENABLE ERROR Configuration"
#endif

	 //INT2
#if EXTI_INT2_ENABLE==ENABLE
	 SET_BIT(GICR,GICR_INT2);

      #if EXTI_INT2_SENSE_CONTROL==FALLING_EDGE
	  CLR_BIT(MCUCSR,MCUCSR_ISC2);
      #elif EXTI_INT2_SENSE_CONTROL==RISING_EDGE
	  SET_BIT(MCUCSR,MCUCSR_ISC2);

     #else
      #error  "EXTI_INT2_SENSE_CONTROL ERROR Configuration"
     #endif

  #elif  EXTI_INT2_ENABLE==DISABLE
	 CLR_BIT(GICR,GICR_INT2);

   #else
        #error  "EXTI_INT2_ENABLE ERROR Configuration"
  #endif

}
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





void EXTI_voidInt0SetCallBack(void *(Copy_pvNotificationFunction)(void))
{
	Global_pvInt0NotificationFunction=	Copy_pvNotificationFunction;
}
void EXTI_voidInt1SetCallBack(void *(Copy_pvNotificationFunction)(void))
{
	Global_pvInt1NotificationFunction=	Copy_pvNotificationFunction;
}
void EXTI_voidInt2SetCallBack(void *(Copy_pvNotificationFunction)(void))
{
	Global_pvInt2NotificationFunction=	Copy_pvNotificationFunction;
}


void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
  if(Global_pvInt0NotificationFunction!=NULL)
  {
	  Global_pvInt0NotificationFunction();
  }
  else
  {
	  /*Do Nothing*/
  }


}
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
  if(Global_pvInt1NotificationFunction!=NULL)
  {
	  Global_pvInt1NotificationFunction();
  }
  else
  {
	  /*Do Nothing*/
  }


}
void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)
{
  if(Global_pvInt2NotificationFunction!=NULL)
  {
	  Global_pvInt2NotificationFunction();
  }
  else
  {
	  /*Do Nothing*/
  }


}





