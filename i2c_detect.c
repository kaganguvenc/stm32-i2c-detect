/**
 * @file    i2c_detect.c
 * @author  Ferenc Nemeth
 * @date    6 Oct 2018
 * @brief   This file contains the functions to detect and print the I2C devices.
 *
 *          Copyright (c) 2018 Ferenc Nemeth - https://github.com/ferenc-nemeth
 */

#include "i2c_detect.h"

/**
 * @brief   Scans trough the I2C for valid addresses, then prints the out with printf().
 * @param   void
 * @return  void
 */
void i2c_detect(uint8_t limit) {
	uint8_t devices = 0;
	extern I2C_HandleTypeDef hi2c1;

	printf("Searching for I2C devices on the bus...\n");
	printf("Searching form 0x00 to 0x%02X \n", limit);
	/* Values outside 0x03 and 0x77 are invalid. */
	for (uint8_t i = 0x00u; i < limit; i++) {
		uint8_t address = i;
		/* In case there is a positive feedback, print it out. */
		if (HAL_OK == HAL_I2C_IsDeviceReady(&hi2c1, address, 3u, 10u)) {
			printf("Device found: 0x%02X \n", address);
			devices++;
		} else {
			//printf("No Device found at 0x%02X \n", address);
		}
	}
	/* Feedback of the total number of devices. */
	if (0u == devices) {
		printf("No device found.\n");
	} else {
		printf("Total found devices: %d\n", devices);
	}
}

