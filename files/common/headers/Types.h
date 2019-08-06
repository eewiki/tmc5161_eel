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
 * Types.h
 *
 *  Created on: 29.09.2016
 *      Author: ed
 */

#ifndef TMC_TYPES_H_
#define TMC_TYPES_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef TMC_TYPES_INTEGERS
#define TMC_TYPES_INTEGERS

// todo: change to standard ISO C99 types (ED)

// www.open-std.org/JTC1/SC22/WG14/www/docs/n1256.pdf
// ISO C99: 7.18 Integer types 8, 16, 32, or 64 bits
// intN_t = two’s complement signed integer type with width N, no padding bits.
// uintN_t = an unsigned integer type with width N.
// floatN_t = N bit IEE 754 float.
// INT8_MIN, INT8_MAX, INT16_MIN, INT16_MAX, INT32_MIN, INT32_MAX, .... UINT32_MAX

typedef float float32_t;
typedef double float64_t;

#ifndef TMC_TYPES_INTEGERS_UNSIGNED
#define TMC_TYPES_INTEGERS_UNSIGNED

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef uint8_t       uint8;
typedef uint16_t      uint16;
typedef uint32_t      uint32;

#define u8_MAX   (uint8_t)   255
#define u10_MAX  (uint16_t)  1023
#define u12_MAX  (uint16_t)  4095
#define u15_MAX  (uint16_t)  32767
#define u16_MAX  (uint16_t)  65535
#define u18_MAX  (uint32_t)  262143uL
#define u20_MAX  (uint32_t)  1048575uL
#define u22_MAX  (uint32_t)  4194303uL
#define u24_MAX  (uint32_t)  16777215uL
#define u32_MAX  (uint32_t)  4294967295uL

#endif

#ifndef TMC_TYPES_INTEGERS_SIGNED
#define TMC_TYPES_INTEGERS_SIGNED

typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;

typedef int8_t       int8;
typedef int16_t      int16;
typedef int32_t      int32;

#define s8_MAX   (int8_t)   127
#define s8_MIN   (int8_t)   -128
#define s16_MAX  (int16_t)  32767
#define s16_MIN  (int16_t)  -32768
#define s24_MAX  (int32_t)  8388607
#define s24_MIN  (int32_t)  -8388608
#define s32_MAX  (int32_t)  2147483647
#define s32_MIN  (int32_t)  -2147483648

#endif

#endif

#ifndef TMC_TYPES_NULL
#define TMC_TYPES_NULL

#ifndef NULL
#define NULL ((void *) 0)
#endif

#endif

#endif /* TMC_TYPES_H_ */
