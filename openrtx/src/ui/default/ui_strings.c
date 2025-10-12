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

#include <stdint.h>
#include <string.h>
#include "ui/ui_strings.h"
#include "ui/EnglishStrings.h"
#include "ui/SpanishStrings.h"

const stringsTable_t languages[NUM_LANGUAGES] = {englishStrings,spanishStrings};
const stringsTable_t* currentLanguage = &languages[0];

int GetEnglishStringTableOffset(const char* text)
{
    if ((text == NULL) || (*text == '\0'))
        return -1;

    uint8_t stringCount = sizeof(stringsTable_t) / sizeof(char *);

    for (uint8_t i = 0; i < stringCount; ++i)
    {
        const char* strPtr = ((const char **)&englishStrings)[i];

        if (strcmp(text, strPtr) == 0)
        {
            return i;
        }
    }

    return -1;
}
