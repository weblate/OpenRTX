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

#include "peripherals/rng.h"
#include <random>
#include <limits>

static std::mt19937 rng;

void rng_init()
{
    std::random_device seed;
    rng.seed(seed());
}

void rng_terminate()
{

}

uint32_t rng_get()
{
    std::uniform_int_distribution< uint32_t >
    distribution(0, std::numeric_limits<uint32_t>::max());

    return distribution(rng);
}
