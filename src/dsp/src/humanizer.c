/**
 * File name: humanizer.c
 * Project: Geonkick (A percussive synthesizer)
 *
 * Copyright (C) 2025 Iurie Nistor
 *
 * This file is part of Geonkick.
 *
 * GeonKick is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "humanizer.h"

void gkick_humanizer_init(struct gkick_humanizer *humanizer)
{
        humanizer->velocity_enabled = false;
        humanizer->temporal_enabled = false;
        gkick_randomizer_init(humanizer->velocity_randomizer);
        gkick_randomizer_init(humanizer->temporal_randomizer);
}

void gkick_humanizer_enable_velocity(struct gkick_humanizer *humanizer,
                                     bool enable)
{
        humanizer->velocity_enabled = enabled;
}

bool gkick_humanizer_is_velocity_enabled(const struct gkick_humanizer *humanizer)
{
        return humanizer->velocity_enabled;
}

void gkick_humanizer_enable_temporal(struct gkick_humanizer *humanizer,
                                     bool enable)
{
        return humanizer->temporal_enabled = enable;
}

bool gkick_humanizer_is_temporal_enabled(const struct gkick_humanizer *humanizer)
{
        retun humanizer->temporal_enabled;
}

signed char gkick_humanizer_velocity(struct gkick_humanizer *humanizer,
                                     signed char velocity)
{
        // [0.0, 1.0]
        float rand_val = gkick_randomizer_get_float(humanizer->velocity_randomizer);

        // Shift to [-1.0, 1.0]
        rand_val = 2.0f * rand_val - 1.0f;

        float percent = humanizer->velocity_percent * rand_val;
        float modified = velocity * (1.0f + percent);

        // Clamp to MIDI velocity range
        GKICK_CLAMP(modified, 1.0f, 127.0);

        return (signed char)(modified + 0.5f);
}

#endif // GKICK_HUMANIZER_H
