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

#ifndef USB_H
#define USB_H

#include <stdint.h>
#include <unistd.h>
#include "tusb.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialise the USB driver.
 */
void usb_init();

/**
 * Shut down the USB driver.
 */
void usb_terminate();

#ifdef __cplusplus
}
#endif

#endif /* USB_H */
