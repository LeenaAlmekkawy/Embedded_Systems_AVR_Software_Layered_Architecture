#ifndef MPU6050_PRIVATE_H
#define MPU6050_PRIVATE_H

#define MPU6050_PWR_MGMT_1               0x6B  //controls the power mode and clock source.
#define MPU6050_CONFIG                   0x1A  //configures the digital low-pass filter (DLPF) and the full-scale range of the gyroscope.
#define MPU6050_GYRO_CONFIG              0x1B  //This register configures the full-scale range of the gyroscope.
#define MPU6050_ACCEL_CONFIG             0x1C  //This register configures the full-scale range of the accelerometer.
#define MPU6050_INT_ENABLE               0x38  //This register enables or disables the generation of interrupts based on certain event
#define MPU6050_INT_STATUS               0x3A  // This register indicates which interrupts have been triggered.


//(Addresses 0x3B-0x40):This register contains the raw temperature sensor data in two's complement format.
#define MPU6050_ACCEL_XOUT_H             0x3B
#define MPU6050_ACCEL_XOUT_L             0x3C
#define MPU6050_ACCEL_YOUT_H             0x3D
#define MPU6050_ACCEL_YOUT_L             0x3E
#define MPU6050_ACCEL_ZOUT_H             0x3F
#define MPU6050_ACCEL_ZOUT_L             0x40

#define MPU6050_TEMP_OUT_H               0x41
#define MPU6050_TEMP_OUT_L               0x42


//Addresses 0x43-0x48): These registers contain the raw gyroscope data in two's complement format.
#define MPU6050_GYRO_XOUT_H              0x43  
#define MPU6050_GYRO_XOUT_L              0x44
#define MPU6050_GYRO_YOUT_H              0x45
#define MPU6050_GYRO_YOUT_L              0x46
#define MPU6050_GYRO_ZOUT_H              0x47
#define MPU6050_GYRO_ZOUT_L              0x48



#define GYRO_250                         0x00
#define GYRO_500                         0x08
#define GYRO_1000                        0x10
#define GYRO_2000                        0x18


#define ACCEL_2                          0x00
#define ACCEL_4                          0x08
#define ACCEL_8                          0x10
#define ACCEL_16                         0x18







#endif
