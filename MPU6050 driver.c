/*
 * MPU6050.c
 *
 *  Created on: 12 Aug 2026
 *      Author: tate
 */


//HAL_I2C_Mem_Read(&hi2c1, device_address << 1, ACCEL_XOUT_H, 1, buf, 14, 100);


//uint8_t data = 0x00;
//HAL_I2C_Mem_Write(&hi2c1, device_address << 1, power_mangment_1, 1, &data, 1, 100);


#include "stm32f4xx_hal.h"
#include "MPU6050.h"
extern I2C_HandleTypeDef hi2c1;

#define device_address  0x68

#define power_mangment_1 0x6B

#define clock_select  0x6B

#define who_am_i  0x75

#define config  0x1A
#define gyro_config  0x1B
#define accel_config  0x1C

#define ACCEL_XOUT_H  0x3B
#define ACCEL_XOUT_L  0x3c
#define ACCEL_YOUT_H  0x3d
#define ACCEL_YOUT_L  0x3e
#define ACCEL_ZOUT_H  0x3f
#define ACCEL_ZOUT_L  0x40

#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L  0x44
#define GYRO_YOUT_H  0x45
#define GYRO_YOUT_L  0x46
#define GYRO_ZOUT_H  0x47
#define GYRO_ZOUT_L  0x48

float  accel_scale = 16384.0f;
float gyro_scale = 131.0f;


//clock selct 2b

void MPU6050_init(){
 
 
 uint8_t data = 0x00;
 HAL_I2C_Mem_Write(&hi2c1, device_address << 1, power_mangment_1, 1, &data, 1, 100);

//gyro config 1b
 //accelrometer 1c
  data = 0x03;
 HAL_I2C_Mem_Write(&hi2c1, device_address << 1, config, 1, &data, 1, 100);// DLPF_CFG = 3  44Hz accel, 42Hz gyro


 data = 0b00000000;
 HAL_I2C_Mem_Write(&hi2c1,  device_address << 1,gyro_config, 1, &data, 1, 100);// DLPF_CFG = 3  44Hz accel, 42Hz gyro

 
 data = 0b00000000;
 HAL_I2C_Mem_Write(&hi2c1, device_address << 1, accel_config, 1, &data, 1, 100);// DLPF_CFG = 3  44Hz accel, 42Hz gyro

}




void MPU6050_data(){
uint8_t buf[14];// reads 14 bytes (everything)
HAL_I2C_Mem_Read(&hi2c1, device_address << 1, ACCEL_XOUT_H, 1, buf, 14, 100);

//msb/lsb shifting
//accell
int16_t ax = (buf[0]  << 8) | buf[1];
int16_t ay = (buf[2]  << 8) | buf[3];
int16_t az = (buf[4]  << 8) | buf[5];


//temp
int16_t t = (buf[6]  << 8) | buf[7];

//gyrp
int16_t gx = (buf[8]  << 8) | buf[9];
int16_t gy = (buf[10]  << 8) | buf[11];
int16_t gz = (buf[12]  << 8) | buf[13];

float accel_x = ax / accel_scale;  
float accel_y = ay / accel_scale; 
float accel_z = az / accel_scale; //  +-2g

float gyro_x  = gx / gyro_scale;  
float gyro_y  = gy / gyro_scale; 
float gyro_z  = gz / gyro_scale; // +-250°/s
}
