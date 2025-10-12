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

#include <errno.h>
#include "spi_custom.h"

int spiCustom_transfer(const struct spiDevice *dev, const void *txBuf,
                       void *rxBuf, const size_t size)
{
    const struct spiCustomDevice *spiDev = (const struct spiCustomDevice *) dev;
    const uint8_t *txData = (const uint8_t *) txBuf;
    uint8_t       *rxData = (uint8_t *) rxBuf;

    if(spiDev->spiFunc == NULL)
        return -EIO;

    // Send only
    if(rxBuf == NULL)
    {
        for(size_t i = 0; i < size; i++)
            spiDev->spiFunc(dev->priv, txData[i]);

        return 0;
    }

    // Receive only
    if(txBuf == NULL)
    {
        for(size_t i = 0; i < size; i++)
            rxData[i] = spiDev->spiFunc(dev->priv, 0x00);

        return 0;
    }

    // Transmit and receive, only symmetric transfer is supported
    for(size_t i = 0; i < size; i++)
        rxData[i] = spiDev->spiFunc(dev->priv, txData[i]);

    return 0;
}
