#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

//Status Codes p181
//R--->Read ,W--->Write,SLA--->Slave address
#define START_ACK                  0x08   //A START condition has been transmitted
#define REPEATED_START_ACK         0x10   //A repeated START condition has been transmitted
#define SLA_W_TX_WITH_ACK          0x18   //SLA+W has been transmitted; ACK has been received
#define SLA_W_TX_WITH_NO_ACK       0x20   //SLA+W has been transmitted; NOT ACK has been received
#define SLA_R_TX_WIHT_ACK          0x40   // SLA+R has been transmitted; ACK has been received
#define DATA_R_RX_WIHT_ACK         0x50   //Data byte has been received;ACK has been returned
#define SLA_R_RX_WIHT_ACK		   0xA8   //Own SLA+R has been received; ACK has been returned
#define SLA_W_RX_WIHT_ACK		   0x60   //Own SLA+W has been received; ACK has been returned
#define DATA_RX_WIHT_ACK		   0x80   //Previously addressed with ownSLA+W; data has been received ACK has been returned
#define SLAVE_BYTE_TX              0xB8   //Data byte in TWDR has been  transmitted; ACK has been  received
#define DATA_TX_WIHT_ACK           0x28   //Data byte has been transmitted; ACK has been received
#define DATA_TX_WITH_NO_ACK        0x30   //Data byte has been transmitted; NOT ACK has been received
#define ARBITATION_LOST            0x38   //Arbitration lost in SLA+W or data bytes



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
