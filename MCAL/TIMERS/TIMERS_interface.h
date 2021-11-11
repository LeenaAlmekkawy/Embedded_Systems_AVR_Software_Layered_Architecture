#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidInit(void);

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue);

void TIMERS_voidTimer2SetCompareMatchValue(u8 Copy_u8CompareMatchValue);

void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8PreLoadValue);

void TIMERS_voidTimer2SetPreLoadValue(u8 Copy_u8PreLoadValue);

void TIMERS_voidTimer0CTCSetCallBackFunction(void(*Copy_pvCTCFunction)(void));

void TIMERS_voidSetBusyWaitTimer2_ms(u32 Copy_u32Time_ms);

#endif
