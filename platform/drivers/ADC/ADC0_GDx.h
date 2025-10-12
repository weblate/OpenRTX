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

#ifndef ADC0_H
#define ADC0_H

#include <stdint.h>

/**
 * Initialise and start ADC0.
 */
void adc0_init();

/**
 * Turn off ADC0.
 */
void adc0_terminate();

/**
 * Get current measurement of a given channel returning the raw ADC value.
 * @param ch: channel number.
 * @return current value of the specified channel, in ADC counts.
 */
uint16_t adc0_getRawSample(uint8_t ch);

/**
 * Get current measurement of a given channel.
 * @param ch: channel number.
 * @return current value of the specified channel in mV.
 */
uint16_t adc0_getMeasurement(uint8_t ch);

#endif /* ADC0_H */
