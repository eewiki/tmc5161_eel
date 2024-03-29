/*
MIT License

Copyright (c) 2019 Trinamic Motion Control GmbH & Co. KG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
 * TMC5161.c
 *
 *  Created on: 13.06.2017
 *      Author: LK
 */

#include "TMC5161.h"

// => SPI wrapper
extern void tmc5161_readWriteArray(uint8_t channel, uint8_t *data, size_t length);
// <= SPI wrapper

void tmc5161_writeDatagram(uint8_t channel, uint8_t address, uint8_t x1, uint8_t x2, uint8_t x3, uint8_t x4)
{
	uint8_t data[5] = { address | TMC5161_WRITE_BIT, x1, x2, x3, x4 };
	tmc5161_readWriteArray(channel, &data[0], 5);
}

void tmc5161_writeInt(uint8_t channel, uint8_t address, int32_t value)
{
	tmc5161_writeDatagram(channel, address, BYTE(value, 3), BYTE(value, 2), BYTE(value, 1), BYTE(value, 0));
}

int32_t tmc5161_readInt(uint8_t channel, uint8_t address)
{
	address = TMC_ADDRESS(address);

	uint8_t data[5];

	data[0] = address;
	tmc5161_readWriteArray(channel, &data[0], 5);

	data[0] = address;
	tmc5161_readWriteArray(channel, &data[0], 5);

	return _8_32(data[1], data[2], data[3], data[4]);
}

void tmc5161_init(void)
{

}

void tmc5161_rotate(uint8_t channel, int32_t velocity)
{
	// set absolute velocity, independent from direction
	tmc5161_writeInt(channel, TMC5161_VMAX, abs(velocity));
	// signdedness defines velocity mode direction bit in rampmode register
	tmc5161_writeInt(channel, TMC5161_RAMPMODE, (velocity >= 0) ? TMC5161_MODE_VELPOS : TMC5161_MODE_VELNEG);
}

void tmc5161_right(uint8_t channel, uint32_t velocity)
{
	return tmc5161_rotate(channel, velocity);
}

void tmc5161_left(uint8_t channel, uint32_t velocity)
{
	return tmc5161_rotate(channel, -velocity);
}

void tmc5161_stop(uint8_t channel)
{
	return tmc5161_rotate(channel, 0);
}

void tmc5161_moveTo(uint8_t channel, int32_t position, uint32_t velocity)
{
	tmc5161_writeInt(channel, TMC5161_RAMPMODE, TMC5161_MODE_POSITION);
	tmc5161_writeInt(channel, TMC5161_VMAX, velocity); // Not written to register while in rampVelocity mode -> write copy when switching
	tmc5161_writeInt(channel, TMC5161_XTARGET, position);
}

void tmc5161_moveBy(uint8_t channel, int32_t ticks, uint32_t velocity)
{
	// determine actual position and add numbers of ticks to move
	ticks += tmc5161_readInt(channel, TMC5161_XACTUAL);

	tmc5161_moveTo(channel, ticks, velocity);
}
