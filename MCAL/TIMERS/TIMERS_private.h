#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

#define TCCR0        *((volatile u8*)0x53)
#define TCCR0_CS00   0
#define TCCR0_CS01   1
#define TCCR0_CS02   2
#define TCCR0_WGM01  3
#define TCCR0_COM00  4
#define TCCR0_COM01  5
#define TCCR0_WGM00  6
#define TCCR0_FOC0   7

#define TCNT0        *((volatile u8*)0x52)

#define OCR0         *((volatile u8*)0x5C)

#define TIMSK        *((volatile u8*)0x59)
#define TIMSK_TOIE0  0
#define TIMSK_OCIE0  1

#define TIFR        *((volatile u8*)0x58)
#define TIFR_TOV0    0
#define TIFR_OCF0    1



#define TCCR2       *((volatile u8*)0x45)
#define TCCR2_CS20   0
#define TCCR2_CS21   1
#define TCCR2_CS22   2
#define TCCR2_WGM21  3
#define TCCR2_COM20  4
#define TCCR2_COM21  5
#define TCCR2_WGM20  6
#define TCCR2_FOC2   7

#define TCNT2        *((volatile u8*)0x44)

#define OCR2         *((volatile u8*)0x43)

#define TIMSK_TOIE2  6
#define TIMSK_OCIE2  7

#define TIFR_TOV2    6
#define TIFR_OCF2    7

#define NULL    (void *)0

#endif
