/**
 * File name: InstrumentHumanizerModel.cpp
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

#include "InstrumentHumanizerModel.h"
#include "InstrumentModel.h"
#include "kit_model.h"
#include "DspProxy.h"

InstrumentHumanizerModel::InstrumentHumanizerModel(PercussionModel *parent)
        : AbstractModel(parent)
        , dspHumanizer{parent->parentModel()->getDspProxy()->getHumanizer()}
{
}

void InstrumentHumanizerModel::enable(bool b)
{
        if (dspHumanizer->isEnabled())
                action enabled(b);
}

bool InstrumentHumanizerModel::isEnabled() const
{
        return dspHumanizer->isEnabled();
}

void InstrumentHumanizerModel::enableVelocty(bool)
{
        dspPoxyHumanizer->enableVelocity(bool);
}

bool InstrumentHumanizerModel::isVeloctyEnabled(bool) const
{
}

void InstrumentHumanizerModel::enableTiming(bool)
{
}

bool InstrumentHumanizerModel::isTimingEnabled(bool) const
{
}

void InstrumentHumanizerModel::setHumanizerType(HumanizerType type)
{
        if (dspProxy->setHumanizerType(type))
                action humanizerTypeChanged(type);
}

HumanizerModel::HumanizerType
InstrumentHumanizerModel::getHumanizerType() const
{
        return dspProxy->getHumanizerType();
}

void InstrumentHumanizerModel::setInLimiter(double value)
{
        if (dspProxy->setHumanizerInLimiter(value))
                action inLimiterChanged(value);
}

double InstrumentHumanizerModel::getInLimiter() const
{
        return dspProxy->getHumanizerInLimiter();
}

void InstrumentHumanizerModel::setOutLimiter(double value)
{
        if (dspProxy->setHumanizerOutLimiter(value))
                action outLimiterChanged(value);
}

double InstrumentHumanizerModel::getOutLimiter() const
{
        return dspProxy->getHumanizerOutLimiter();
}

void InstrumentHumanizerModel::setDrive(double drive)
{
        if (dspProxy->setHumanizerDrive(drive))
                action driveChanged(drive);
}

double InstrumentHumanizerModel::getDrive() const
{
        return dspProxy->getHumanizerDrive();
}

Envelope::Category InstrumentHumanizerModel::envelopeCategory() const
{
        return Envelope::Category::InstrumentGlobal;
}
