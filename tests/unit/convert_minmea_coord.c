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

#include <minmea.h>
#include <stdio.h>
#include <stdlib.h>
#include "core/gps.h"

static void assert_conversion(struct minmea_float *f, int32_t expected)
{
    int32_t result = minmea_tofixedpoint(f);
    if (result != expected)
    {
        printf("FAILED! result value %d - expected %d\n",
               result, expected);
        exit(1);
    }
}

int main() {
    printf("minmea coordinate conversion test\n");
    struct minmea_float test = {5333735, 1000};
    assert_conversion(&test, 53562250);
    test.scale = 1;
    test.value = 0;
    assert_conversion(&test, 0);
    test.scale = 1000;
    test.value = -5333735;
    assert_conversion(&test, -53562250);
    test.scale = 1000;
    test.value = -330;
    assert_conversion(&test, -5500);
    test.scale = 1000;
    test.value = -3296;
    assert_conversion(&test, -54933);
    printf("PASS\n");

    return 0;
}
