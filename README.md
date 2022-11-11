# WiringPi_LM75
A Temperature Recoder with LM75A(TI) using wiringPi/wiringOP I2C library.

# Requirements
Install wiringPi on your Raspberry or wiringOP on your orangePi.
* relative link:
+ [https://github.com/orangepi-xunlong/wiringOP.git](https://github.com/orangepi-xunlong/wiringOP)
+ http://wiringpi.com/download-and-install/

# Quick Test
The following command should show you a pin table which means library works well.
`gpio readAll
The following command will give you a LED blinker at *pin 2* that defined in *Pi's pin map*.
```bash
make blinker
sudo ./blinker
   ```
# Run the code
* connect LM75 VCC3.3/VCC5.0 GND I2C SDA pins and
```
make lm75
sudo ./blinker
```
* Caution: we are using SDA.1 SCL.1 (I2C port 2) by default.
# 搞完
