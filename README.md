# Rover-lidar
Autonomous ground rover (STM32F411 + ESP32-S3) with a homemade LIDAR sensor, encoders, GPS and camera module while being controlled wirelessly via nRF24L01. Working toward SLAM-based mapping and AprilTag-guided precision positioning. Personal project, ongoing.

currently motors and encoders interfaced with:
https://youtube.com/shorts/xxfjAQOBqmc?si=hJcHVLtkVV-ht2d

and have designed and 3d printed a socket for 20mm back ball baring wheel with 0.4mm tolorance

radio modues implments arcade drive controls that is send over nRF24L01 to the esp witch then sends to stm32 via uart sending direct pwm values for each motor

currently have joystick directional control over the motors allwoing backwards and  forwards and turn control
currently designing base:
<img width="747" height="380" alt="image" src="https://github.com/user-attachments/assets/031e9d2e-b13d-4e56-95f7-da4fceb2998e" />
<img width="1537" height="792" alt="image" src="https://github.com/user-attachments/assets/449c1530-063e-442c-8c7f-489e9c955abb" />
<img width="826" height="592" alt="image" src="https://github.com/user-attachments/assets/3d8868b2-aee9-4851-a088-d4759470f9f0" />


