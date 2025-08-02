/**
 * File name: humanizer.h
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

#ifndef GKICK_HUMANIZER_H
#define GKICK_HUMANIZER_H

struct gkick_humanizer {
        atomic_bool velocity_enabled;
        atomic_bool temporal_enabled;
        atomic_float velocity_percent;
        atomic_float temporal_percent;
        struct gkick_randomizer velocity_randomizer;
        struct gkick_randomizer temporal_randomizer;
};

void gkick_humanizer_init(struct gkick_humanizer *humanizer);
void gkick_humanizer_enable_velocity(struct gkick_humanizer *humanizer,
                                     bool enable);
bool gkick_humanizer_is_velocity_enabled(struct gkick_humanizer *humanizer);
void gkick_humanizer_enable_temporal(struct gkick_humanizer *humanizer,
                                     bool enable);
bool gkick_humanizer_is_temporal_enabled(struct gkick_humanizer *humanizer);

bool gkick_humanize_velocity(struct gkick_humanizer *humanizer, signed char velocity);

#endif // GKICK_HUMANIZER_H
