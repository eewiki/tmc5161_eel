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
 * TMC5161_Constants.h
 *
 *  Created on: 13.06.2018
 *      Author: LK
 */

#ifndef TMC_IC_TMC5161_TMC5161_CONSTANTS_H_
#define TMC_IC_TMC5161_TMC5161_CONSTANTS_H_

#include "Constants.h"

#define TMC5161_REGISTER_COUNT   TMC_REGISTER_COUNT
#define TMC5161_MOTORS           1
#define TMC5161_WRITE_BIT        TMC_WRITE_BIT
#define TMC5161_ADDRESS_MASK     TMC_ADDRESS_MASK
#define TMC5161_MAX_VELOCITY     8388096
#define TMC5161_MAX_ACCELERATION u16_MAX

// ramp modes (Register TMC5161_RAMPMODE)
#define TMC5161_MODE_POSITION  0
#define TMC5161_MODE_VELPOS    1
#define TMC5161_MODE_VELNEG    2
#define TMC5161_MODE_HOLD      3

// limit switch mode bits (Register TMC5161_SWMODE)
#define TMC5161_SW_STOPL_ENABLE    0x0001
#define TMC5161_SW_STOPR_ENABLE    0x0002
#define TMC5161_SW STOPL_POLARITY  0x0004
#define TMC5161_SW_STOPR_POLARITY  0x0008
#define TMC5161_SW_SWAP_LR         0x0010
#define TMC5161_SW_LATCH_L_ACT     0x0020
#define TMC5161_SW_LATCH_L_INACT   0x0040
#define TMC5161_SW_LATCH_R_ACT     0x0080
#define TMC5161_SW_LATCH_R_INACT   0x0100
#define TMC5161_SW_LATCH_ENC       0x0200
#define TMC5161_SW_SG_STOP         0x0400
#define TMC5161_SW_SOFTSTOP        0x0800

// Status bits (Register TMC5161_RAMPSTAT)
#define TMC5161_RS_STOPL          0x0001
#define TMC5161_RS_STOPR          0x0002
#define TMC5161_RS_LATCHL         0x0004
#define TMC5161_RS_LATCHR         0x0008
#define TMC5161_RS_EV_STOPL       0x0010
#define TMC5161_RS_EV_STOPR       0x0020
#define TMC5161_RS_EV_STOP_SG     0x0040
#define TMC5161_RS_EV_POSREACHED  0x0080
#define TMC5161_RS_VELREACHED     0x0100
#define TMC5161_RS_POSREACHED     0x0200
#define TMC5161_RS_VZERO          0x0400
#define TMC5161_RS_ZEROWAIT       0x0800
#define TMC5161_RS_SECONDMOVE     0x1000
#define TMC5161_RS_SG             0x2000

// Encoderbits (Register TMC5161_ENCMODE)
#define TMC5161_EM_DECIMAL     0x0400
#define TMC5161_EM_LATCH_XACT  0x0200
#define TMC5161_EM_CLR_XENC    0x0100
#define TMC5161_EM_NEG_EDGE    0x0080
#define TMC5161_EM_POS_EDGE    0x0040
#define TMC5161_EM_CLR_ONCE    0x0020
#define TMC5161_EM_CLR_CONT    0x0010
#define TMC5161_EM_IGNORE_AB   0x0008
#define TMC5161_EM_POL_N       0x0004
#define TMC5161_EM_POL_B       0x0002
#define TMC5161_EM_POL_A       0x0001

#endif /* TMC_IC_TMC5161_TMC5161_CONSTANTS_H_ */
