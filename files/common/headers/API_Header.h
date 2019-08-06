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
 * tmc_header.h
 *
 *  Created on: 29.09.2016
 *      Author: ed
 */

#ifndef TMC_API_HEADER_H_
#define TMC_API_HEADER_H_

	#include "Config.h"
	#include "Macros.h"
	#include "Constants.h"
	#include "Bits.h"
	#include "CRC.h"
	#include "RegisterAccess.h"
	#include <stdlib.h>
	#include "Types.h"

	// TODO: Restructure these.
	/*
	 * Goal: Just give these values here as status back to the IDE when used with EvalSystem.
	 * Currently, this is obtained by just leaving out implementation specific error bits here.
	 */
	typedef enum {
		TMC_ERROR_NONE      = 0x00,
		TMC_ERROR_GENERIC   = 0x01,
		TMC_ERROR_FUNCTION  = 0x02,
		TMC_ERROR_MOTOR     = 0x08,
		TMC_ERROR_VALUE     = 0x10,
		TMC_ERROR_CHIP      = 0x40
	} TMCError;

#endif /* TMC_API_HEADER_H_ */
