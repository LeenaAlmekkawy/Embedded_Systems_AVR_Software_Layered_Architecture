#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

#define WDTCR     *((volatile u8 *)0x41) 
#define WDTCR_WDP0   0
#define WDTCR_WDP1   1
#define WDTCR_WDP2   2
#define WDTCR_WDE    3
#define WDTCR_WDPTOE 4

#endif