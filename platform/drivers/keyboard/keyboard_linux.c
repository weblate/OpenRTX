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
#include <stdint.h>
#include "interfaces/keyboard.h"
#include "emulator/sdl_engine.h"
#include "emulator/emulator.h"

void kbd_init()
{
}

keyboard_t kbd_getKeys()
{
    keyboard_t keys = 0;

    //this pulls in emulated keypresses from the command shell
    keys |= emulator_getKeys();
    keys |= sdlEngine_getKeys();

    return keys;
}

