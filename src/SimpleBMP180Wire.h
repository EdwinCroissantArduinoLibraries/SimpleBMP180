/*
 * BMP180 barometric pressure sensor library for the Arduino
 * microcontroller.
 *
 * Uses the Wire library
 *
 * Copyright (C) 2016 Edwin Croissant
 *
 *  This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * See the README.md file for additional information.
 */

#ifndef SIMPLEBMP180Wire_H
#define SIMPLEBMP180Wire_H

#include "Arduino.h"
#include "Wire.h"

class SimpleBMP180Wire {
public:
	SimpleBMP180Wire();
	boolean begin();
	int32_t getPressure(uint8_t = 1);
	int16_t getLastTemperature(void);

private:
	int16_t _lastTemp;

	union {
		uint8_t calArray[22];
		struct {
			int16_t ac1, ac2, ac3;
			uint16_t ac4, ac5, ac6;
			int16_t b1, b2, mb, mc, md;
		};
	} _calData;

	enum BMP180registers {
		calData = 0xAA, id = 0xD0, control = 0xF4, data = 0xF6
	};

	enum BMP180commands {
		readTemp = 0x2E, readPress = 0x34
	};

	enum BMP180constants {
		I2CAddr = 0x77, deviceId = 0x55
	};

	void writeCmd(uint8_t);
	uint8_t retrieveData(BMP180registers, int8_t);
};

#endif //  SIMPLEBMP180Wire_H
