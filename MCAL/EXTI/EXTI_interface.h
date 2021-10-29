#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define FALLING_EDGE   0
#define RISING_EDGE    1
#define ON_CHANGE      2
#define LOW_LEVEL      3

#define ENABLE         1
#define DISABLE        0

void EXTI_voidSetInt0SenseControl(u8 Copy_u8SenseControl);

void EXTI_voidSetInt1SenseControl(u8 Copy_u8SenseControl);

void EXTI_voidSetInt2SenseControl(u8 Copy_u8SenseControl);

void EXTI_voidINT2Control(u8 Copy_u8Int0State);

void EXTI_voidINT1Control(u8 Copy_u8Int1State);

void EXTI_voidINT0Control(u8 Copy_u8Int2State);

void EXTI_voidInt0SetCallBack(void *(Copy_pvNotificationFunction)(void));

void EXTI_voidInt1SetCallBack(void *(Copy_pvNotificationFunction)(void));

void EXTI_voidInt2SetCallBack(void *(Copy_pvNotificationFunction)(void));


void EXTI_voidIntInit();

#endif
