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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "core/state.h"
#include "core/settings.h"

extern bool _ui_checkStandby(long long);
extern state_t state;

void assert_display_timer(display_timer_t conf,
                          long long time_sec,
                          bool expected)
{
    state.settings.brightness_timer = conf;

    long long ticks = time_sec * 1000;

    if (_ui_checkStandby(ticks) != expected)
    {
        printf("FAILED! enum value %d - time %lld sec - expected %d\n",
               conf, time_sec, expected);
        exit(1);
    }
}

void test_timer_threshold(display_timer_t conf, long long time_sec)
{
    assert_display_timer(conf, time_sec -1, false);
    assert_display_timer(conf, time_sec, true);
}

int main() {
    printf("Backlight timer test\n");

    test_timer_threshold(TIMER_5S, 5);
    test_timer_threshold(TIMER_10S, 10);
    test_timer_threshold(TIMER_15S, 15);
    test_timer_threshold(TIMER_20S, 20);
    test_timer_threshold(TIMER_25S, 25);
    test_timer_threshold(TIMER_30S, 30);

    test_timer_threshold(TIMER_1M, 1 * 60);
    test_timer_threshold(TIMER_2M, 2 * 60);
    test_timer_threshold(TIMER_3M, 3 * 60);
    test_timer_threshold(TIMER_4M, 4 * 60);
    test_timer_threshold(TIMER_5M, 5 * 60);


    test_timer_threshold(TIMER_15M, 15 * 60);
    test_timer_threshold(TIMER_30M, 30 * 60);
    test_timer_threshold(TIMER_45M, 45 * 60);

    test_timer_threshold(TIMER_1H, 60 * 60);

    assert_display_timer(TIMER_OFF, 0, false);
    assert_display_timer(TIMER_OFF, 60 * 60 * 24, false);

    printf("PASS\n");

    return 0;
}
