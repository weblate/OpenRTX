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

#include "core/crc.h"

uint16_t crc_ccitt(const void *data, const size_t len)
{
    uint16_t x   = 0;
    uint16_t crc = 0;
    const uint8_t *buf = ((const uint8_t *) data);

    for(size_t i = 0; i < len; i++)
    {
        x   = (crc >> 8) ^ buf[i];
        x  ^= x >> 4;
        crc = (crc << 8) ^ (x << 12) ^ (x << 5) ^ x;
    }

    return crc;
}
