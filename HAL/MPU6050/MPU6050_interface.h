#ifndef MPU6050_INTERFACE_H
#define MPU6050_INTERFACE_H


#define MPU6050_CLOCK_PLL_XGYRO    0X09   //& Disable temperature sensor:bit3 is cleared
#define MPU6050_DEFAULT_ADDRESS    0x68   // MPU6050 7-bit adress = 0x68, 8-bit adress = 0xD0;

void MPU6050_voidInit(void);




#endif
