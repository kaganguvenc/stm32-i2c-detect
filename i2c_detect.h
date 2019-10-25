/**
 * @file    i2c_detect.h
 * @author  Ferenc Nemeth
 * @date    6 Oct 2018
 * @brief   This file contains the functions to detect and print the I2C devices.
 *
 *          Copyright (c) 2018 Ferenc Nemeth - https://github.com/ferenc-nemeth
 */

#ifndef I2C_DETECT_H_
#define I2C_DETECT_H_

#include "stm32f4xx_hal.h"
#include <stdio.h>

void i2c_detect(uint8_t);

#endif /* I2C_DETECT_H_ */
