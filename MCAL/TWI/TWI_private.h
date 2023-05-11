#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

#define TWI_TWBR *((volatile u8*) 0x20)


#define TWI_TWCR *((volatile u8*) 0x56)
#define TWCR_TWINT      7    
#define TWCR_TWEA       6
#define TWCR_TWSTA      5
#define TWCR_TWSTO      4
#define TWCR_TWWC       3
#define TWCR_TWEN       2
#define TWCR_TWIE       0


#define TWI_TWSR *((volatile u8*) 0x21)
#define TWSR_TWPS0      0
#define TWSR_TWPS1      1


#define TWI_TWDR *((volatile u8*) 0x23)


#define TWI_TWAR *((volatile u8*) 0x22)
#define TWAR_TWGCE     0






#endif
