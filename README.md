# Rover-lidar
Autonomous ground rover (STM32F411 + ESP32-S3) with a homemade LIDAR sensor, encoders, GPS and camera module while being controlled wirelessly via nRF24L01. Working toward SLAM-based mapping and AprilTag-guided precision positioning. Personal project, ongoing.

first motors and encoders interfaced with:
https://youtube.com/shorts/xxfjAQOBqmc?si=hJcHVLtkVV-ht2d



radio modues implments arcade drive controls that is send over nRF24L01 to the esp witch then sends to stm32 via uart sending direct pwm values for each motor

currently:
testing odometry from encoder and imus and its accuracy 
wrote a MPU6050 driver from scratch scaled accell to 2-+g and gyro 250/s at 44hz(accel), 42hz(gyro)

# forward back:

https://youtu.be/2wB4GNMTBnc?si=adaVEpXKmh2rM6IY

# turning:

https://youtube.com/shorts/7JuXVSnX-N0?si=-uGhH5tF0-UNR2Y7

<img width="1472" height="680" alt="image" src="https://github.com/user-attachments/assets/7493af66-1782-4187-95f3-8ee24d875ccb" />

<img width="922" height="546" alt="image" src="https://github.com/user-attachments/assets/3fe412a6-a0b1-4b2d-883f-ce1c1539fa8d" />


