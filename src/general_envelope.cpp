/**
 * File name: general_envelope.h
 * Project: Geonkick (A percussive synthesizer)
 *
 * Copyright (C) 2017 Iurie Nistor
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

#include "general_envelope.h"

GeneralEnvelope::GeneralEnvelope(DspProxy *dsp, const RkRect &area)
        : Envelope(area)
        , dspProxy{dsp}
{
        removeSupportedType(Envelope::Type::Frequency);
        removeSupportedType(Envelope::Type::PitchShift);
        RK_ACT_BIND(dspProxy, kickLengthUpdated, RK_ACT_ARGS(double val), this, envelopeUpdated());
        RK_ACT_BIND(dspProxy, kickAmplitudeUpdated, RK_ACT_ARGS(double val), this, envelopeUpdated());
        setType(Envelope::Type::Amplitude);
        setPoints(dspProxy->getKickEnvelopePoints(type()));
}

void GeneralEnvelope::pointAddedEvent(const EnvelopePoint &point)
{
        dspProxy->addKickEnvelopePoint(type(), point);
}

void GeneralEnvelope::pointUpdatedEvent(unsigned int index, const EnvelopePoint &point)
{
        dspProxy->updateKickEnvelopePoint(type(), index, point);
}

void GeneralEnvelope::pointRemovedEvent(unsigned int index)
{
        dspProxy->removeKickEnvelopePoint(type(), index);
}

double GeneralEnvelope::envelopeLength(void) const
{
        return dspProxy->kickLength();
}

void GeneralEnvelope::setEnvelopeLengh(double len)
{
        dspProxy->setKickLength(len);
}

double GeneralEnvelope::envelopeAmplitude(void) const
{
        if (type() == Envelope::Type::Amplitude)
                return dspProxy->kickAmplitude();
        else if (type() == Envelope::Type::FilterCutOff)
                return dspProxy->kickFilterFrequency();
	else if (type() == Envelope::Type::FilterQFactor)
                return dspProxy->kickFilterQFactor();
	else if (type() == Envelope::Type::DistortionDrive)
		return dspProxy->getDistortionDrive() / pow(10, 36.0 / 20);
        else if (type() == Envelope::Type::DistortionVolume)
		return dspProxy->getDistortionOutLimiter();

        return 0;
}

void GeneralEnvelope::updateEnvelope()
{
	auto applyType = dspProxy->getKickEnvelopeApplyType(type());
	setApplyType(applyType);
	updatePoints();
}

void GeneralEnvelope::updatePoints()
{
        setPoints(dspProxy->getKickEnvelopePoints(type()));
}
