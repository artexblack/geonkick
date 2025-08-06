/**
 * File name: HumanizerModel.h
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

#ifndef INSTRUEMNT_HUMANIZER_MODEL_H
#define INSTRUEMNT_HUMANIZER_MODEL_H

#include "AbstractModel.h"

class PercussionModel;
class DspProxyHumanizer;

class HumanizerModel: public AbstractModel
{
 public:
        explicit HumanizerModel(PercussionModel *parent);
        void enable(bool b);
        bool isEnabled() const;
        void setVelocityPercent(double value);
        double getVelocityPercent() const;
        void setTimingPercent(double value);
        double getTimingPercent() const;
        RK_DECL_ACT(enabled,
                    enabled(bool b),
                    RK_ARG_TYPE(bool),
                    RK_ARG_VAL(b));
        RK_DECL_ACT(velocityPercentUpdated,
                    velocityPercentUpdated(double value),
                    RK_ARG_TYPE(double),
                    RK_ARG_VAL(value));
        RK_DECL_ACT(timingPercentUpdated,
                    timingPercentUpdated(double value),
                    RK_ARG_TYPE(double),
                    RK_ARG_VAL(value));

private:
        DspProxyHumanizer *dspPoxyHumanizer;
};

#endif // INSTRUEMNT_HUMANIZER_MODEL_H
