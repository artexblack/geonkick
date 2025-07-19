/**
 * File name: InstrumentDistortionModel.cpp
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

#include "InstrumentDistortionModel.h"
#include "percussion_model.h"
#include "kit_model.h"
#include "DspProxy.h"

InstrumentDistortionModel::InstrumentDistortionModel(PercussionModel *parent)
        : DistortionModel(parent)
        , dspProxy{parent->parentModel()->getDspProxy()}
{
}

void InstrumentDistortionModel::enable(bool b)
{
        if (dspProxy->enableDistortion(b))
                action enabled(b);
}

bool InstrumentDistortionModel::isEnabled() const
{
        return dspProxy->isDistortionEnabled();
}

void InstrumentDistortionModel::setDistortionType(DistortionType type)
{
        if (dspProxy->setDistortionType(type))
                action distortionTypeChanged(type);
}

DistortionModel::DistortionType
InstrumentDistortionModel::getDistortionType() const
{
        return dspProxy->getDistortionType();
}

void InstrumentDistortionModel::setInLimiter(double value)
{
        if (dspProxy->setDistortionInLimiter(value))
                action inLimiterChanged(value);
}

double InstrumentDistortionModel::getInLimiter() const
{
        return dspProxy->getDistortionInLimiter();
}

void InstrumentDistortionModel::setOutLimiter(double value)
{
        if (dspProxy->setDistortionOutLimiter(value))
                action outLimiterChanged(value);
}

double InstrumentDistortionModel::getOutLimiter() const
{
        return dspProxy->getDistortionOutLimiter();
}

void InstrumentDistortionModel::setDrive(double drive)
{
        if (dspProxy->setDistortionDrive(drive))
                action driveChanged(drive);
}

double InstrumentDistortionModel::getDrive() const
{
        return dspProxy->getDistortionDrive();
}

Envelope::Category InstrumentDistortionModel::envelopeCategory() const
{
        return Envelope::Category::InstrumentGlobal;
}
