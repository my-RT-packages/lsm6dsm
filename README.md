# LSM6DSM

## 1、介绍
LSM6DSM 是RT-Thread传感器驱动包，适配RT-Thread传感器驱动框架，开发者可以通过RT-Thread传感器驱动框架提供的上层API直接访问LSM6DSM，读取和配置LSM6DSM相关参数。

RT-Thread传感器驱动框架相关文档参考：[https://www.rt-thread.org/document/site/development-guide/sensor/sensor_driver/](https://www.rt-thread.org/document/site/development-guide/sensor/sensor_driver/)

### 1.1 LSM6DSM传感器简介
LSM6DSM是STMicroelectronics推出的iNEMO 6DoF惯性测量单元（IMU），用于具有OIS / EIS和AR/VR系统的智能手机。超低功耗、高精度和稳定性，配备 3D 数字加速度计和 3D 数字陀螺仪，在高性能模式下以 0.65 mA 的速度工作，并始终启用低功耗功能，为消费者提供最佳的运动体验。

详细参考：[https://www.st.com/zh/mems-and-sensors/lsm6dsm.html](https://www.st.com/zh/mems-and-sensors/lsm6dsm.html)

### 1.2 功能介绍

- 通讯接口
  - [x] I2C
  - [ ] SPI

- 支持的功能
  - [x] 加速度计
  - [x] 陀螺仪
  - [x] 计步
  - [x] 温度
  
  **适配情况**

  | 功能         | 加速度计 | 陀螺仪 | 计步 | 温度 |
  | ---------------- | -------- | ------ | ------ | ------ |
  | **工作模式**     |          |        |        |        |
  | 轮询             | √        | √      | √      | √ |
  | 中断             |          |        |        |        |
  | FIFO             |          |        |        |        |
  | **电源模式**     |          |        |        |        |
  | 掉电             | √        | √      | √（加速度计掉电） | √（加速度计掉电） |
  | 低功耗           | √ | √ | √（加速度计低功耗） | √（加速度计低功耗） |
  | 普通             | √        | √      | √      | √ |
  | 高性能       | √        | √      | √（加速度计高性能） | √（加速度计高性能） |
  | **数据输出速率** | √        | √      |  |  |
  | **测量范围**     | √        | √      |        |        |
  
  **注意：当开启计步后，加速计数据输出速率被强制到26Hz**

### 1.3 目录结构


| 名称 | 说明 |
| ---- | ---- |
| drivers  | ST（意法半导体）提供的LSM6DSM通用C版本驱动库 |


### 1.4 许可证

遵循 Apache license v2.0 许可，详见 `LICENSE` 文件。

### 1.5 依赖

- RT-Thread 4.0+
- I2C驱动
- RT-Thread传感器驱动框架

## 2、如何开启

 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

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

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

**注意：你需要明确你所用的LSM6DSM的SA0的连接方式，如果接到地，需要选择`I2C device address type`为`I2C address low`，否则选择`I2C address high`**

## 3、如何使用 


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

**示例**

```
msh />sensor probe acce_lsm
01-01 00:00:00 I/LSM6DSM tshell: LSM6DSM acce enter normal power mode,ODR:3330.00
01-01 00:00:00 I/sensor.cmd tshell: device id: 0x6a!
msh />sensor read
01-01 00:00:00 I/sensor.cmd tshell: num:  0, x:  -53, y:  284, z: -954 mg, timestamp:1261597
01-01 00:00:00 I/sensor.cmd tshell: num:  1, x:  -52, y:  281, z: -963 mg, timestamp:1261708
01-01 00:00:00 I/sensor.cmd tshell: num:  2, x:  -51, y:  285, z: -966 mg, timestamp:1261819
01-01 00:00:00 I/sensor.cmd tshell: num:  3, x:  -56, y:  276, z: -959 mg, timestamp:1261930
01-01 00:00:00 I/sensor.cmd tshell: num:  4, x:  -53, y:  278, z: -953 mg, timestamp:1262041
msh />sensor probe gyro_lsm 
01-01 00:00:00 I/LSM6DSM tshell: LSM6DSM gyro enter normal power mode,ODR:3330.00
01-01 00:00:00 I/sensor.cmd tshell: device id: 0x6a!
msh />sensor read
01-01 00:00:00 I/sensor.cmd tshell: num:  0, x:    -210, y:     -70, z:    -490 dps, timestamp:1275010
01-01 00:00:00 I/sensor.cmd tshell: num:  1, x:     210, y:     140, z:     490 dps, timestamp:1275122
01-01 00:00:00 I/sensor.cmd tshell: num:  2, x:     280, y:     350, z:     280 dps, timestamp:1275234
01-01 00:00:00 I/sensor.cmd tshell: num:  3, x:     140, y:      70, z:       0 dps, timestamp:1275346
01-01 00:00:00 I/sensor.cmd tshell: num:  4, x:     -70, y:     140, z:     280 dps, timestamp:1275458
msh />sensor probe step_lsm 
01-01 00:00:00 I/LSM6DSM tshell: LSM6DSM step enter normal power mode,acce ODR: 26Hz
01-01 00:00:00 I/sensor.cmd tshell: device id: 0x6a!
msh />sensor read
01-01 00:00:00 I/sensor.cmd tshell: num:  0, step:    9, timestamp:1304269
01-01 00:00:00 I/sensor.cmd tshell: num:  1, step:    9, timestamp:1304377
01-01 00:00:00 I/sensor.cmd tshell: num:  2, step:    9, timestamp:1304486
01-01 00:00:00 I/sensor.cmd tshell: num:  3, step:    9, timestamp:1304595
01-01 00:00:00 I/sensor.cmd tshell: num:  4, step:    9, timestamp:1304704
msh />sensor probe temp_lsm 
01-01 00:00:00 I/LSM6DSM tshell: LSM6DSM acce enter normal power mode,ODR:3330.00
01-01 00:00:00 I/sensor.cmd tshell: device id: 0x6a!
msh />sensor read
01-01 00:00:00 I/sensor.cmd tshell: num:  0, temp: 24.1 C, timestamp:1314257
01-01 00:00:00 I/sensor.cmd tshell: num:  1, temp: 24.1 C, timestamp:1314365
01-01 00:00:00 I/sensor.cmd tshell: num:  2, temp: 24.1 C, timestamp:1314474
01-01 00:00:00 I/sensor.cmd tshell: num:  3, temp: 24.2 C, timestamp:1314583
01-01 00:00:00 I/sensor.cmd tshell: num:  4, temp: 24.1 C, timestamp:1314692
msh />
```

## 4、注意事项



## 5、联系方式 & 感谢

* 维护：chuckie
* 主页：[https://github.com/my-RT-packages/lsm6dsm#readme](https://github.com/my-RT-packages/lsm6dsm#readme)
