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
 * Ramp.c
 *
 *  Created on: 09.11.2018
 *      Author: LK
 */

#include "Ramp.h"

void tmc_ramp_init(void *ramp, TMC_RampType type)
{
	switch(type) {
	case TMC_RAMP_TYPE_LINEAR:
	default:
		tmc_ramp_linear_init((TMC_LinearRamp *)ramp);
		break;
	}
}

void tmc_ramp_compute(void *ramp, TMC_RampType type, uint32_t delta)
{
	switch(type) {
	case TMC_RAMP_TYPE_LINEAR:
	default:
		tmc_ramp_linear_compute((TMC_LinearRamp *)ramp, delta);
		break;
	}
}

int32_t tmc_ramp_get_rampVelocity(void *ramp, TMC_RampType type)
{
	int32_t v = 0;
	switch(type) {
	case TMC_RAMP_TYPE_LINEAR:
		v = tmc_ramp_linear_get_rampVelocity((TMC_LinearRamp *)ramp);
		break;
	}
	return v;
}

int32_t tmc_ramp_get_rampPosition(void *ramp, TMC_RampType type)
{
	int32_t x = 0;
	switch(type) {
	case TMC_RAMP_TYPE_LINEAR:
		x = tmc_ramp_linear_get_rampPosition((TMC_LinearRamp *)ramp);
		break;
	}
	return x;
}

bool tmc_ramp_get_enabled(void *ramp, TMC_RampType type)
{
	bool enabled = false;
	switch(type) {
	case TMC_RAMP_TYPE_LINEAR:
		enabled = tmc_ramp_linear_get_enabled((TMC_LinearRamp *)ramp);
		break;
	}
	return enabled;
}

void tmc_ramp_set_enabled(void *ramp, TMC_RampType type, bool enabled)
{
	switch(type) {
	case TMC_RAMP_TYPE_LINEAR:
	default:
		tmc_ramp_linear_set_enabled((TMC_LinearRamp *)ramp, enabled);
		break;
	}
}

void tmc_ramp_toggle_enabled(void *ramp, TMC_RampType type)
{
	switch(type) {
	case TMC_RAMP_TYPE_LINEAR:
	default:
		tmc_ramp_linear_set_enabled((TMC_LinearRamp *)ramp, !tmc_ramp_get_enabled(ramp, type));
		break;
	}
}

int32_t tmc_ramp_get_dx(void *ramp, TMC_RampType type)
{
	int32_t dx = 0;
	switch(type) {
	case TMC_RAMP_TYPE_LINEAR:
	default:
		dx = tmc_ramp_linear_get_dx((TMC_LinearRamp *)ramp);
		break;
	}
	return dx;
}

void tmc_ramp_reset_dx(void *ramp, TMC_RampType type)
{
	switch(type) {
	case TMC_RAMP_TYPE_LINEAR:
	default:
		tmc_ramp_linear_reset_dx((TMC_LinearRamp *)ramp);
		break;
	}
}
