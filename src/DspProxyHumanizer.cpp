/**
 * File name: DspProxyHumanizer.cpp
 * Project: Geonkick (A percussive synthesizer)
 *
 * Copyright (C) 2025 Iurie Nistor
 *
 * This file is part of Geonkick.
 *
 * Geonkick is free software; you can redistribute it and/or modify
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

#include "DspProxyHumanizer.h"

DspProxyHumanizer::DspProxyHumanizer(geonkick *dsp)
        :geonkickDsp{dsp}
{
}

bool DspProxyHumanizer::enable(bool b)
{
        auto res = geonkick_humanizer_enable(geonkickDsp, b);
        return res == GEONKICK_OK;
}

bool DspProxyHumanizer::isEnabled() const
{
        return geonkick_humanizer_is_enabled(geonkickDsp);
}

bool DspProxyHumanizer::setVelocityPercent(double value)
{
        auto res = geonkick_humanizer_set_velocity(geonkickDsp,
                                                   static_cast<float>(value));
        return res == GEONKICK_OK;
}

double DspProxyHumanizer::getVelocityPercent() const
{
        return geonkick_humanizer_get_velocity(geonkickDsp);
}

bool DspProxyHumanizer::setTiming(double value)
{
        auto res = geonkick_humanizer_set_timing(geonkickDsp,
                                                 static_cast<float>(value));
        return res == GEONKICK_OK;
}

double DspProxyHumanizer::getTiming() const
{
        return geonkick_humanizer_get_timing(geonkickDsp);
}
