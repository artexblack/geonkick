/**
 * File name: InstrumentFilterModel.cpp
 * Project: Geonkick (A percussive synthesizer)
 *
 * Copyright (C) 2024 Iurie Nistor
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

#include "InstrumentFilterModel.h"
#include "percussion_model.h"
#include "DspProxy.h"
#include "kit_model.h"

InstrumentFilterModel::InstrumentFilterModel(PercussionModel *parent)
        : FilterModel(parent)
        , dspProxy{parent->parentModel()->getDspProxy()}
{
}

void InstrumentFilterModel::enable(bool b)
{
        if (dspProxy->enableKickFilter(b))
                action enabled(b);
}

bool InstrumentFilterModel::isEnabled() const
{
        return dspProxy->isKickFilterEnabled();
}

void InstrumentFilterModel::setCutOff(double val)
{
        if (dspProxy->setKickFilterFrequency(val))
                action cutOffChanged(val);
}

double InstrumentFilterModel::cutOff() const
{
        return dspProxy->kickFilterFrequency();
}

void InstrumentFilterModel::setResonance(double val)
{
         if (dspProxy->setKickFilterQFactor(val))
                 action resonanceChanged(val);
}

double InstrumentFilterModel::resonance() const
{
        return dspProxy->kickFilterQFactor();
}

void InstrumentFilterModel::setType(FilterModel::FilterType type)
{
         if (dspProxy->setKickFilterType(type))
                 action typeChanged(type);
}

FilterModel::FilterType InstrumentFilterModel::type() const
{
        return dspProxy->kickFilterType();
}

void InstrumentFilterModel::setCutOffRange(const std::pair<double, double>& range)
{
}

std::pair<double, double> InstrumentFilterModel::cutOffRange() const
{
        return {};
}

void InstrumentFilterModel::setResonanceRange(const std::pair<double, double>& range)
{
}

std::pair<double, double> InstrumentFilterModel::resonanceRange() const
{
        return {};
}

Envelope::Category InstrumentFilterModel::envelopeCategory() const
{
        return Envelope::Category::InstrumentGlobal;
}
