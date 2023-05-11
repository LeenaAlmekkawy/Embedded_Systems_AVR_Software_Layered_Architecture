#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"



void TWI_voidMasterInit(u8 Copy_u8MasterAddress)
{
	// set clock frequency to 400kbps
	// set TWBR to 2
	TWI_TWBR=2;

	// clear the 2 bits of TWPS
	CLR_BIT(TWI_TWSR,TWSR_TWPS0);
	CLR_BIT(TWI_TWSR,TWSR_TWPS1);

	//Master will not recognize general call,if you want to recognize it write 0 in bit0
	if(Copy_u8MasterAddress!=0)
	{
		TWI_TWAR=(Copy_u8MasterAddress<<1);
	}

	//Enable TWI
	SET_BIT(TWI_TWCR,TWCR_TWEN);

}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	// initialize the node address
	TWI_TWAR=(Copy_u8SlaveAddress<<1);

	//Enable TWI
	SET_BIT(TWI_TWCR,TWCR_TWEN);

}
TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Local_ErrStatus=NoError;
	//Set start condition bit

	SET_BIT(TWI_TWCR,TWCR_TWSTA);

	//Clear the interrupt flag to start the previous operation
	SET_BIT(TWI_TWCR,TWCR_TWINT);
	// Wait until the interrupt flag is raised again and the previous operation in complete
	while(GET_BIT(TWI_TWCR,TWCR_TWINT)==0);

	//check the operation status in the status register
	if( (TWI_TWSR &0xF8)!= START_ACK)
	{
		Local_ErrStatus=StartConditionError;
	}
	else
	{
		//do nothing
	}

	return  Local_ErrStatus;
}

TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrStatus Local_ErrStatus=NoError;
	//Set start condition bit

	SET_BIT(TWI_TWCR,TWCR_TWSTA);

	//Clear the interrupt flag to start the previous operation
	SET_BIT(TWI_TWCR,TWCR_TWINT);
	// Wait until the interrupt flag is raised again and the previous operation in complete
	while(GET_BIT(TWI_TWCR,TWCR_TWINT)==0);

	//check the operation status in the status register

	if( (TWI_TWSR &0xF8)!= REPEATED_START_ACK )
	{
		Local_ErrStatus=RepeatedStartConditionError;
	}
	else
	{
		//do nothing
	}

	return  Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus=NoError;

	//Clear start condition bit
	CLR_BIT(TWI_TWCR,TWCR_TWSTA);

	//Set the slave address in the 7 MSB in the data register

	TWI_TWDR=(Copy_u8SlaveAddress<<1);
	CLR_BIT(TWI_TWDR,0); //Write request



	//Clear the interrupt flag to start the previous operation
	SET_BIT(TWI_TWCR,TWCR_TWINT);

	// Wait until the interrupt flag is raised again and the previous operation in complete
	while(GET_BIT(TWI_TWCR,TWCR_TWINT)==0);

	//check the operation status in the status register
	if( (TWI_TWSR &0xF8)!= SLA_W_TX_WITH_ACK )
	{
		Local_ErrStatus=SlaveAddressWithWriteError;
	}
	else
	{
		//do nothing
	}


	return  Local_ErrStatus;

}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus=NoError;

	//Clear start condition bit
	CLR_BIT(TWI_TWCR,TWCR_TWSTA);

	TWI_TWDR=(Copy_u8SlaveAddress<<1);
	SET_BIT(TWI_TWDR,0); //read request

	//Clear the interrupt flag to start the previous operation
	SET_BIT(TWI_TWCR,TWCR_TWINT);
	// Wait until the interrupt flag is raised again and the previous operation in complete
	while(GET_BIT(TWI_TWCR,TWCR_TWINT)==0);

	//check the operation status in the status register
	if( (TWI_TWSR &0xF8)!= SLA_R_TX_WIHT_ACK  )
	{
		Local_ErrStatus=SlaveAddressWithReadError;
	}
	else
	{
		//do nothing
	}



	return  Local_ErrStatus;

}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{

	TWI_ErrStatus Local_ErrStatus=NoError;

	//write the data type
	TWI_TWDR=Copy_u8DataByte;

	//Clear the interrupt flag to start the previous operation
	SET_BIT(TWI_TWCR,TWCR_TWINT);
	// Wait until the interrupt flag is raised again and the previous operation is complete
	while(GET_BIT(TWI_TWCR,TWCR_TWINT)==0);

	//check the operation status in the status register
	if( (TWI_TWSR &0xF8)!= DATA_TX_WIHT_ACK  )
	{
		Local_ErrStatus=MaterWriteDataByteError;
	}
	else
	{
		//do nothing
	}


	return  Local_ErrStatus;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrStatus Local_ErrStatus=NoError;

	//enable master generating acknowledge bit after receiving the data
	SET_BIT(TWI_TWCR,TWCR_TWEA);

	//Clear the interrupt flag to start the slave sending data
	SET_BIT(TWI_TWCR,TWCR_TWINT);
	// Wait until the interrupt flag is raised again and the previous operation is complete
	while(GET_BIT(TWI_TWCR,TWCR_TWINT)==0);

	//check the operation status in the status register
	if( (TWI_TWSR &0xF8)!= DATA_R_RX_WIHT_ACK  )
	{
		Local_ErrStatus=MaterReadDataByteError;
	}
	else
	{
		//read the data type
		*Copy_pu8DataByte=TWI_TWDR;
	}


	return  Local_ErrStatus;
}

void TWI_SendStopCondition(void)
{


	//Set stop condition bit

	SET_BIT(TWI_TWCR,TWCR_TWSTO);
	//Clear the interrupt flag to start the previous operation
	SET_BIT(TWI_TWCR,TWCR_TWINT);

}

