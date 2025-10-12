/*
 * Copyright (C) 2020-2025 OpenRTX Contributors
 *
 * This file is part of OpenRTX.
 *
 * OpenRTX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenRTX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "interfaces/radio.h"


void radio_init(const rtxStatus_t *rtxState)
{
    (void) rtxState;
}

void radio_terminate()
{

}

void radio_setOpmode(const enum opmode mode)
{
    (void) mode;
}

bool radio_checkRxDigitalSquelch()
{
    return false;
}

void radio_enableAfOutput()
{

}

void radio_disableAfOutput()
{

}

void radio_enableRx()
{

}

void radio_enableTx()
{

}

void radio_disableRtx()
{

}

void radio_updateConfiguration()
{

}

rssi_t radio_getRssi()
{
    return -121.0f;  // S1 level: -121dBm
}

enum opstatus radio_getStatus()
{
    return OFF;
}
