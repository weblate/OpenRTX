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

#include "protocols/M17/M17DSP.hpp"
#include "hwconfig.h"

#ifdef CONFIG_M17
Fir< std::tuple_size< decltype(M17::rrc_taps_48k) >::value > M17::rrc_48k(M17::rrc_taps_48k);
Fir< std::tuple_size< decltype(M17::rrc_taps_24k) >::value > M17::rrc_24k(M17::rrc_taps_24k);
#endif
