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

#ifndef EMULATOR_H
#define EMULATOR_H

#include "interfaces/keyboard.h"
#include <stdbool.h>
#include <stdint.h>
#include "SDL2/SDL.h"

#ifndef CONFIG_SCREEN_WIDTH
#define CONFIG_SCREEN_WIDTH 160
#endif

#ifndef CONFIG_SCREEN_HEIGHT
#define CONFIG_SCREEN_HEIGHT 128
#endif

enum choices
{
    VAL_RSSI=1,
    VAL_BAT,
    VAL_MIC,
    VAL_VOL,
    VAL_CH,
    VAL_PTT,
    PRINT_STATE,
    EXIT
};

typedef struct
{
    float RSSI;
    float vbat;
    float micLevel;
    float volumeLevel;
    float chSelector;
    bool  PTTstatus;
    bool  powerOff;
}
emulator_state_t;

extern emulator_state_t emulator_state;

void emulator_start();

keyboard_t emulator_getKeys();

#endif /* EMULATOR_H */
