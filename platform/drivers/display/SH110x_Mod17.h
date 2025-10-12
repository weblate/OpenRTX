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

#ifndef SH110X_MOD17_H
#define SH110X_MOD17_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize the SH110x display driver.
 */
void SH110x_init();

/**
 * Shut down the SH110x display driver.
 */
void SH110x_terminate();

/**
 * Do a partial framebuffer render.
 *
 * @param startRow: first row of the partial render.
 * @param endRow: last row of the partial render.
 * @param fb: pointer to framebuffer.
 */
void SH110x_renderRows(uint8_t startRow, uint8_t endRow, void *fb);

/**
 * Render the framebuffer on the screen.
 *
 * @param fb: pointer to framebuffer.
 */
void SH110x_render(void *fb);

/**
 * Set display contrast.
 *
 * @param contrast: display contrast level, 0 to 63.
 */
void SH110x_setContrast(uint8_t contrast);

#ifdef __cplusplus
}
#endif

#endif /* SH110X_MOD17_H */
