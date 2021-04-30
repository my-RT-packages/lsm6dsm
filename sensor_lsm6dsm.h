/*
*  Copyright (c) 2006-2020, Chukie
*  
*  SPDX-License-Identifier: Apache-2.0
*  
*  @file     : 
*  
*  @brief    : 
*  Website   : https://gitee.com/zcj20080882
*  
*  
*  Change Logs:
*  Date           Author          Notes
*  2021-03-21     zhaocj       The first version
*/
/* Define to prevent recursive inclusion ------------------------------------*/
#ifndef __SENSOR_LSM6DSM_H__
#define __SENSOR_LSM6DSM_H__
/* Includes -----------------------------------------------------------------*/
#include "sensor.h"
#include "lsm6dsm_reg.h"
/* Exported types -----------------------------------------------------------*/
/* Exported constants -------------------------------------------------------*/
/* Exported macro -----------------------------------------------------------*/
/* Exported functions -------------------------------------------------------*/
int rt_hw_lsm6dsm_init(const char *name, struct rt_sensor_config *cfg);

#endif /*__SENSOR_LSM6DSM_H__*/
/* End of file****************************************************************/
