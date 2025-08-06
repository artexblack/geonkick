/**
 * File name: HumanizerModel.cpp
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

#include "HumanizerModel.h"
#include "InstrumentModel.h"
#include "kit_model.h"
#include "DspProxy.h"
//#include "DspProxyHumanizer.h"

HumanizerModel::HumanizerModel(PercussionModel *parent)
        : AbstractModel(parent)
          //        , dspProxyHumanizer{parent->parentModel()->getDspProxy()->getHumanizer()}
{
}

void HumanizerModel::enable(bool b)
{
        //if (dspProxyHumanizer->isEnabled())
        //        action enabled(b);
}

bool HumanizerModel::isEnabled() const
{
        return 0.0;//dspProxyHumanizer->isEnabled();
}

void HumanizerModel::setVelocityPercent(double value)
{
        //if (dspProxyHumanizer->setVelocityPercent(value))
        action velocityPercentUpdated(value);
}

double HumanizerModel::getVelocityPercent() const
{
        return 0;//dspProxyHumanizer->getVelocityPercent();
}

void HumanizerModel::setTimingPercent(double value)
{
        //if (dspProxyHumanizer->setTimingPercent(value))
        action timingPercentUpdated(value);
}

double HumanizerModel::getTimingPercent() const
{
        return 0;//dspProxyHumanizer->getVelocityPercent(value);
}
