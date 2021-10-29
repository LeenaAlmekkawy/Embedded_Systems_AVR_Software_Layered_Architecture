#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX        *((volatile u8 *)0x27) //Status Register

#define ADMUX_ADLAR  5
#define ADMUX_REFS0  6
#define ADMUX_REFS1  7


#define ADCSRA        *((volatile u8 *)0x26)
#define ADCSRA_ADBS0  0
#define ADCSRA_ADBS1  1
#define ADCSRA_ADBS2  2
#define ADCSRA_ADIE   3
#define ADCSRA_ADIF   4
#define ADCSRA_ADATE  5
#define ADCSRA_ADSC   6
#define ADCSRA_ADEN   7

#define ADCH     *((volatile u8 *)0x25)
#define ADCL     *((volatile u8 *)0x24)
#define AVCC       1
#define ENABLE     1
#define DISABLE    0

#define PRESCALER_DIV_BY_2    1
#define PRESCALER_DIV_BY_4    2
#define PRESCALER_DIV_BY_8    3
#define PRESCALER_DIV_BY_16   4
#define PRESCALER_DIV_BY_32   5
#define PRESCALER_DIV_BY_64   6
#define PRESCALER_DIV_BY_128  7


#endif
