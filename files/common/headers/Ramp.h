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
 * Ramp.h
 *
 *  Created on: 09.11.2018
 *      Author: LK
 */

#ifndef TMC_RAMP_RAMP_H_
#define TMC_RAMP_RAMP_H_

#include "LinearRamp1.h"

typedef enum {
	TMC_RAMP_TYPE_LINEAR
} TMC_RampType;

// Initializes ramp parameters for given type
void tmc_ramp_init(void *ramp, TMC_RampType type);

// Computes new ramp state after delta ticks have passed
// Note: To call this function periodically with a fixed delta-time, use delta = 1 and
// define the units of acceleration as v/delta-time. If you want to specify a different unit,
// change delta to your preference.
void tmc_ramp_compute(void *ramp, TMC_RampType type, uint32_t delta);

// Returns the current ramp velocity computed by the given ramp
int32_t tmc_ramp_get_rampVelocity(void *ramp, TMC_RampType type);

// Returns the current ramp position computed by the given ramp
int32_t tmc_ramp_get_rampPosition(void *ramp, TMC_RampType type);

// Enable/disable ramps
bool tmc_ramp_get_enabled(void *ramp, TMC_RampType type);
void tmc_ramp_set_enabled(void *ramp, TMC_RampType type, bool enabled);
void tmc_ramp_toggle_enabled(void *ramp, TMC_RampType type);

// Get the position change for last delta time frame
int32_t tmc_ramp_get_dx(void *ramp, TMC_RampType type);

// Resets dx value between computing deltas
void tmc_ramp_reset_dx(void *ramp, TMC_RampType type);

#endif /* TMC_RAMP_RAMP_H_ */
