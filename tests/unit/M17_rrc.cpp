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

#include <limits.h>
#include <inttypes.h>
#include <stdio.h>
#include "protocols/M17/M17DSP.hpp"

#define IMPULSE_SIZE 4096

using namespace std;

/**
 * Test the different demodulation steps
 */

int main()
{
    // Open file
    FILE *baseband_out = fopen("M17_rrc_impulse_response.raw", "wb");
    if (!baseband_out)
    {
        perror("Error in opening output file");
        return -1;
    }

    // Allocate impulse signal
    int16_t impulse[IMPULSE_SIZE] = { 0 };
    impulse[0] = SHRT_MAX;

    // Apply RRC on impulse signal
    int16_t filtered_impulse[IMPULSE_SIZE] = { 0 };
    for(size_t i = 0; i < IMPULSE_SIZE; i++)
    {
        float elem = static_cast< float >(impulse[i]);
        filtered_impulse[i] = static_cast< int16_t >(M17::rrc_48k(0.10 * elem));
    }
    fwrite(filtered_impulse, IMPULSE_SIZE, 1, baseband_out);
    fclose(baseband_out);
    return 0;
}
