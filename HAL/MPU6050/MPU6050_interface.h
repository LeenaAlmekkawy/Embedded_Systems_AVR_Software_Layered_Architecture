#ifndef MPU6050_INTERFACE_H
#define MPU6050_INTERFACE_H


typedef struct
{
	s16 Roll;
	s16  Pitch;


}MPU6050_Angles;




#define MPU6050_CLOCK_PLL_XGYRO    0X09   //& Disable temperature sensor:bit3 is cleared
#define MPU6050_DEFAULT_ADDRESS    0x68   // MPU6050 7-bit adress = 0x68, 8-bit adress = 0xD0;

void MPU6050_voidInit(void);

f32 MPU6050_u32GetAccelXValue(void);

f32 MPU6050_u32GetAccelYValue(void);

f32 MPU6050_u32GetAccelZValue(void);

f32 MPU6050_u32GetGyroXValue(void);

f32 MPU6050_u32GetGyroYValue(void);

f32 MPU6050_u32GetGyroZValue(void);

u32 MPU6050_u32GetRotationValue(void);

void  MPU6050_CalculateRollAngle(void);

void  MPU6050_CalculatePitchAngle(void);

void  MPU6050_CalculateAngles_RawPitchYaw(MPU6050_Angles* Copy_pstMPU6050_AnglesInfo);


#endif
