#include "MPU6050.h"
#include "stm32f4xx_hal.h"


#define ACCEL_SCALE_2G   16384.0f//sensativity
#define GYRO_SCALE_250   131.0f

void MPU6050_Init(void)//one time stuff
{
    i2c_write_reg(MPU6050_ADDRESS, PWR_MGMT_1, 0x00);// power on
    i2c_write_reg(MPU6050_ADDRESS, CONFIG, 0x03); //DLPF
    i2c_write_reg(MPU6050_ADDRESS, GYRO_CONFIG, 0b00000000);//250/s
    i2c_write_reg(MPU6050_ADDRESS, ACCEL_CONFIG, 0b00000000);//2g
}

void MPU6050_ReadAll(float *accel_x, float *accel_y, float *accel_z,
                      float *gyro_x, float *gyro_y, float *gyro_z) // so main can have teh varbuls
{
    uint8_t buf[14];// grabs 14 bytes to read (all of them)
    i2c_read_regs(MPU6050_ADDRESS, ACCEL_XOUT_H, buf, 14);

    int16_t ax = (buf[0] << 8) | buf[1]; //accell bytes lsb and msb shift
    int16_t ay = (buf[2] << 8) | buf[3];
    int16_t az = (buf[4] << 8) | buf[5];
    
    int16_t gx = (buf[8] << 8) | buf[9];//gyro bytes lsb and msb shift
    int16_t gy = (buf[10] << 8) | buf[11];
    int16_t gz = (buf[12] << 8) | buf[13];

    *accel_x = ax / ACCEL_SCALE_2G; //accell scaling
    *accel_y = ay / ACCEL_SCALE_2G;
    *accel_z = az / ACCEL_SCALE_2G;
    
    *gyro_x  = gx / GYRO_SCALE_250;//gyro scaling
    *gyro_y  = gy / GYRO_SCALE_250;
    *gyro_z  = gz / GYRO_SCALE_250;
}
