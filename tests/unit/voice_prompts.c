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

// Test private methods
#define private public

#include "core/state.h"
#include "core/voicePromptUtils.h"

/**
 * Test voice prompts playback
 */

int main()
{
    state.settings.vpLevel = 3;
	vpQueueFlags_t flags = vp_getVoiceLevelQueueFlags();

    vp_init();
    vp_flush();
    vp_queueStringTableEntry(&currentLanguage->allChannels);
    vp_play();
    while(true)
    {
        vp_tick();
    }
}
