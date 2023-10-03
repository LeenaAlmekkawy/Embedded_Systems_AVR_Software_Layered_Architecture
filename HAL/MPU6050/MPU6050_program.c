////https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/#comments
#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/TWI/TWI_interface.h"

#include "MPU6050_interface.h"
#include "MPU6050_private.h"

#include "MPU6050_config.h"


#include <util/delay.h>
#include <math.h>





#define COMPLEMENTARY_FILTER_ALPHA  .98

f32 gyro_scale_factor;
f32 accel_scale_factor;





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
	TWI_MasterWriteDataByte(GYRO_FULL_SCALE_RANGE);//+-500
	TWI_SendStopCondition();

	//This is from data sheet if you changne scale range you should change it
	gyro_scale_factor = (1.0 / 65.5);

	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);

	TWI_MasterWriteDataByte(MPU6050_ACCEL_CONFIG);  //  Write to accelerometer configuration register
	TWI_MasterWriteDataByte(ACCEL_FULL_SCALE_RANGE);
	TWI_SendStopCondition();
	//This is from data sheet if you changne scale range you should change it
	accel_scale_factor = (1.0/ 4096.0); // LSB/g  +-8







}
f32 MPU6050_u32GetAccelXValue(void)
{  //forward &backWard
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_ACCEL_XOUT_H);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(MPU6050_DEFAULT_ADDRESS);

	s16 Local_s16accel_x = (((u16)TWI_u8ReadAck()<<8) | (u16)TWI_u8ReadNack());
	TWI_SendStopCondition();

	f32 Local_f32ReturnValue=(f32)Local_s16accel_x*accel_scale_factor;


	return  Local_f32ReturnValue;


}

f32 MPU6050_u32GetAccelYValue(void)
{  //Left&right
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_ACCEL_YOUT_H);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(MPU6050_DEFAULT_ADDRESS);

	s16 Local_s16accel_y = (((u16)TWI_u8ReadAck()<<8) | (u16)TWI_u8ReadNack() );
	TWI_SendStopCondition();
	f32 Local_f32ReturnValue=(f32)Local_s16accel_y*accel_scale_factor;

	return   Local_f32ReturnValue;

}
f32 MPU6050_u32GetAccelZValue(void)
{  //Up& Down
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_ACCEL_ZOUT_H);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(MPU6050_DEFAULT_ADDRESS);

	s16 Local_s16accel_z = (((u16)TWI_u8ReadAck()<<8) | (u16)TWI_u8ReadNack() );
	TWI_SendStopCondition();

	f32 Local_f32ReturnValue=(f32)Local_s16accel_z*accel_scale_factor;
	return   Local_f32ReturnValue;



}


f32 MPU6050_u32GetGyroXValue(void)
{  //up and down
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_GYRO_XOUT_H);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(MPU6050_DEFAULT_ADDRESS);

	s16 Local_s16Gyro_x = (((u16)TWI_u8ReadAck()<<8) | (u16)TWI_u8ReadNack() );
	TWI_SendStopCondition();

	f32 Local_f32ReturnValue=(f32)Local_s16Gyro_x*gyro_scale_factor;

	return   Local_f32ReturnValue;


}

f32 MPU6050_u32GetGyroYValue(void)
{  //ROTATION
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_GYRO_YOUT_H );
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(MPU6050_DEFAULT_ADDRESS);

	s16 Local_s16Gyro_y = (((u16)TWI_u8ReadAck()<<8) | (u16)TWI_u8ReadNack() );
	TWI_SendStopCondition();

	f32 Local_f32ReturnValue=(f32)Local_s16Gyro_y*gyro_scale_factor;

	return   Local_f32ReturnValue;



}
f32 MPU6050_u32GetGyroZValue(void)
{  //Left&right
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(MPU6050_DEFAULT_ADDRESS);
	TWI_MasterWriteDataByte(MPU6050_GYRO_ZOUT_H);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(MPU6050_DEFAULT_ADDRESS);

	s16 Local_s16Gyro_z = (((u16)TWI_u8ReadAck()<<8) | (u16)TWI_u8ReadNack() );
	TWI_SendStopCondition();

	f32 Local_f32ReturnValue=(f32)Local_s16Gyro_z*gyro_scale_factor;;

	return   Local_f32ReturnValue;




}

void  MPU6050_CalculateAngles_RawPitchYaw(MPU6050_Angles* Copy_pstMPU6050_AnglesInfo)
{
	f32 AccX=MPU6050_u32GetAccelXValue();
	f32 AccY=MPU6050_u32GetAccelYValue();
    f32 AccZ=MPU6050_u32GetAccelZValue();
    Copy_pstMPU6050_AnglesInfo->Roll=(atan(AccY / sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180 / 3.14);
    Copy_pstMPU6050_AnglesInfo->Pitch = (atan(-1 * AccX / sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180 / 3.14) ;

}

void  MPU6050_CalculateRollAngle(void)
{

}

void  MPU6050_CalculatePitchAngle(void)
{

}




