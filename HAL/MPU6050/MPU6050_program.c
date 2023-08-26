#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "../../MCAL/TWI/TWI_interface.h"

#include "MPU6050_interface.h"
#include "MPU6050_private.h"
#include "MPU6050_config.h"
#include <util/delay.h>

void MPU6050_voidInit(void)
{
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_PWR_MGMT_1); // Write to power management register
	TWI_MasterWriteDataByte(0);      // Set MPU6050 to sleep mode
	TWI_SendStopCondition();
	_delay_ms(50);                    // Wait for sensor to stabilize

	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_PWR_MGMT_1);  // Write to power management register
	TWI_MasterWriteDataByte(MPU6050_CLOCK_PLL_XGYRO);  // Set MPU6050 to be clocked by the gyro reference
	TWI_SendStopCondition();


	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_GYRO_CONFIG);  //  Write to gyroscope configuration register
	TWI_MasterWriteDataByte(GYRO_FULL_SCALE_RANGE);
	TWI_SendStopCondition();

	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_ACCEL_CONFIG);  //  Write to accelerometer configuration register
	TWI_MasterWriteDataByte(ACCEL_FULL_SCALE_RANGE);
	TWI_SendStopCondition();


}




