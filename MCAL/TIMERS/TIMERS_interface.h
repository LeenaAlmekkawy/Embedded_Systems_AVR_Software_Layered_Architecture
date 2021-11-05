#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidInit(void);

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue);

void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8PreLoadValue);

void TIMERS_voidTimer0CTCSetCallBackFunction(void(*Copy_pvCTCFunction)(void));

void Timer_voidCounter(void);

void TIMERS_voidSetBusyWait(u16 Copy_u16Time_ms);

#endif
