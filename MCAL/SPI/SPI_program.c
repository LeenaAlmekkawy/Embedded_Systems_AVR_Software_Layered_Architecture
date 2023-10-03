#include <avr/io.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "SPI_interface.h"

void SPI_voidInitMaster(void)
{//Master initialization
	SET_BIT(SPCR,4);

	//Clock prescaler divide by 16
	SET_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
  //Enable SPI
	SET_BIT(SPCR,6);

}

void SPI_voidInitSlave(void)
{  //slave initialization
	CLR_BIT(SPCR,4);

	//Enable SPI
		SET_BIT(SPCR,6);
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
//send the data
	SPDR=Copy_u8Data;
	//wait until transfer is complete
	while(GET_BIT(SPSR,7)==0);

	//Get the exchanged data;
	return SPDR;
}
