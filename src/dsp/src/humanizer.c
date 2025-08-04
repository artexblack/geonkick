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

#include "qx_math.h"

void gkick_humanizer_init(struct gkick_humanizer *humanizer)
{
        humanizer->velocity_enabled = false;
        humanizer->temporal_enabled = false;
        qx_randomizer_init(&humanizer->velocity_randomizer,
                           -10.0f, 10.0f, 0.5f);
        qx_randomizer_init(&humanizer->temporal_randomizer,
                           -10.0f, 10.0f, 0.5f);
}

void gkick_humanizer_enable_velocity(struct gkick_humanizer *humanizer,
                                     bool enable)
{
        humanizer->velocity_enabled = enable;
}

bool gkick_humanizer_is_velocity_enabled(const struct gkick_humanizer *humanizer)
{
        return humanizer->velocity_enabled;
}

void gkick_humanizer_set_velocity_percent(struct gkick_humanizer *humanizer,
                                          float percent)
{
        humanizer->velocity_percent = percent;
        qx_randomizer_set_range(&humanizer->velocity_randomizer,
                                -humanizer->velocity_percent / 100.0f,
                                humanizer->velocity_percent / 100.0f);
}

float gkick_humanizer_get_velocity_percent(const struct gkick_humanizer *humanizer)
{
        return humanizer->velocity_percent;
}

signed char gkick_humanizer_velocity(struct gkick_humanizer *humanizer,
                                     signed char velocity)
{
        float r = qx_randomizer_get_float(&humanizer->velocity_randomizer);
        float v = qx_clamp_float((1 + r) * velocity, 1.0f, 127.0);
        return (signed char)v;
}

void gkick_humanizer_enable_temporal(struct gkick_humanizer *humanizer,
                                     bool enable)
{
        humanizer->temporal_enabled = enable;
}

bool gkick_humanizer_is_temporal_enabled(const struct gkick_humanizer *humanizer)
{
        return humanizer->temporal_enabled;
}

void gkick_humanizer_set_temporal_percent(struct gkick_humanizer *humanizer,
                                          float percent)
{
        humanizer->temporal_percent = percent;
}

float gkick_humanizer_get_temporal_percent(const struct gkick_humanizer *humanizer)
{
        return  humanizer->temporal_percent;
}

float gkick_humanizer_temporal(struct gkick_humanizer *humanizer,
                               float temp)
{
        return 0.0f;
}

