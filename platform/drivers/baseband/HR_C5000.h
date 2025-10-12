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

#ifndef HRC5000_H
#define HRC5000_H

#include "drivers/baseband/HR_Cx000.h"

enum class C5000_SpiOpModes : uint8_t
{
    CONFIG = 0,     ///< Main configuration registers.
    AUX    = 1,     ///< Auxiliary configuration registers.
    DATA   = 2,     ///< Data register.
    SOUND  = 3,     ///< Voice prompt sample register.
    CMX638 = 4,     ///< CMX638 configuration register.
    AMBE3K = 5      ///< AMBE3000 configuration register.
};

using HR_C5000 = HR_Cx000 < C5000_SpiOpModes >;

#endif // HRC5000_H
