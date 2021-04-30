# LSM6DSM

## 1、Introduction

LSM6DSM is the RT-Thread sensor driver package, adapted to the RT-Thread sensor driver framework. Developers can directly access LSM6DSM through the upper-level API provided by the RT-Thread sensor driver framework to read and configure LSM6DSM related parameters.

RT-Thread sensor driver framework related documents reference: [https://www.rt-thread.org/document/site/development-guide/sensor/sensor_driver/](https://www.rt-thread.org/document/site/development-guide/sensor/sensor_driver/)

### 1.1 Introduction to LSM6DSM sensor
LSM6DSM is the iNEMO 6DoF inertial measurement unit (IMU) launched by STMicroelectronics for use in smartphones with OIS/EIS and AR/VR systems. Ultra-low power consumption, high accuracy and stability, equipped with 3D digital accelerometer and 3D digital gyroscope, work at 0.65 mA in high performance mode, and always enable low power consumption to provide consumers with the best exercise Experience.

Reference: [https://www.st.com/zh/mems-and-sensors/lsm6dsm.html](https://www.st.com/zh/mems-and-sensors/lsm6dsm.html)

### 1.2 Features

- Interface
  - [x] I2C
  - [ ] SPI

- Functions
  - [x] Accelerometer
  - [x] Gyroscope
  - [x] Pedometer
  - [x] Temperature
  
  **Supports**

  | Function         | Accelerometer | Gyroscope | Pedometer | Temperature |
  | ---------------- | -------- | ------ | ------ | ------ |
  | **Work Mode**     |          |        |        |        |
  | Polling             | √        | √      | √      | √ |
  | Interrupt             |          |        |        |        |
  | FIFO             |          |        |        |        |
  | **Power Mode**     |          |        |        |        |
  | Power Down             | √        | √      | √(Power down accelerometer) | √(Power down accelerometer) |
  | Low Power           | √ | √ | √(Accelerometer low power) | √(Accelerometer low power) |
  | Normal             | √        | √      | √      | √ |
  | High Performance       | √        | √      | √(Accelerometer high Performance) | √(Accelerometer high Performance) |
  | **Data Out Rate** | √        | √      |  |  |
  | **Measuring range**     | √        | √      |        |        |
  
  **Note: When enabling a pedometer, accelerometer data output rate is forced to 26Hz**

### 1.3 Structure


| name | Description |
| ---- | ---- |
| drivers  | LSM6DSM universal C version driver library |


### 1.4 License

Apache license v2.0

### 1.5 Depends

- RT-Thread 4.0+
- I2C Driver
- RT-Thread sensor framework

## 2、How to open

 It needs to be selected in the package manager of RT-Thread, the specific path is as follows：

```
RT-Thread online packages
    peripheral libraries and drivers  --->
    	 [*] sensors drivers  --->
         	 [*]   LSM6DSM sensor driver package, support: accelerometer, gyroscope, step, temperature.  --->
```

```
 --- LSM6DSM sensor driver package, support: accelerometer, gyroscope, step, temperature.                   
      [*]   Enable LSM6DSM Accelerometer                                                                           [*]   Enable LSM6DSM gyro                                                                                   [*]   Enable LSM6DSM temperature                                                                             [*]   Enable LSM6DSM step count                                                                             I2C device address type (I2C address low. if SA0 pad connect to GND, select me)  --->                       Version (v1.0.0)  --->
```

Then let RT-Thread's package manager automatically update, or use command `pkgs --update` to update package to BSP.

**Note: You need to be clear about the SA0 connection mode of the LSM6DSM you are using. If it is connected to the ground, you need to choose`I2C address low` from `I2C device address type`，otherwise choose`I2C address high`**

## 3、How to use

```c
#if defined(PKG_USING_LSM6DSM)
#include "sensor_lsm6dsm.h"

int lsm6dsm_port(void)
{
    struct rt_sensor_config cfg;
    cfg.intf.dev_name = "i2c4";
    rt_hw_lsm6dsm_init("lsm6dsm", &cfg);
    return 0;
}
INIT_APP_EXPORT(lsm6dsm_port);
#endif /*PKG_USING_LSM6DSl*/
```



## 4、Contact & thanks

* Maintainer：chuckie
* Homepage：[https://gitee.com/my-rt-packages/lsm6dsm.git](https://gitee.com/my-rt-packages/lsm6dsm.git)