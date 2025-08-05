/**
 * File name: HumanizerView.h
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


#include "HumanizerView.h"
#include "InstrumentModel.h"
#include "knob.h"
#include "geonkick_button.h"
#include "ViewState.h"

#include "RkContainer.h"
#include "RkLabel.h"

RK_DECLARE_IMAGE_RC(humanizer_label);
RK_DECLARE_IMAGE_RC(humanizer_enable);
RK_DECLARE_IMAGE_RC(humanizer_enable_on);
RK_DECLARE_IMAGE_RC(humanizer_enable_hover);
RK_DECLARE_IMAGE_RC(humanizer_velocity_knob_label);
RK_DECLARE_IMAGE_RC(humanizer_velocity_knob_bk);
RK_DECLARE_IMAGE_RC(humanizer_velocity_knob);
RK_DECLARE_IMAGE_RC(humanizer_timing_knob_label);
RK_DECLARE_IMAGE_RC(humanizer_timing_knob_bk);
RK_DECLARE_IMAGE_RC(humanizer_timing_knob);

HumanizerView::HumanizerView(GeonkickWidget *parent, PercussionModel *model)
        : AbstractView(parent, model)
{
        setFixedSize(110, 65);
        //        setBackgroundColor({0, 99, 0});
        createView();
        bindModel();
}

void HumanizerView::createView()
{
        auto mainContainer = new RkContainer(this, Rk::Orientation::Vertical);

        auto label = new RkLabel(this, RK_RC_IMAGE(humanizer_label));
        label->show();
        mainContainer->addWidget(label);

        auto horizontalContainer = new RkContainer(this);
        auto velocityKnob = createVelocityKnob();
        auto timingKnob = createTimingKnob();
        horizontalContainer->addSpace(8);
        horizontalContainer->addContainer(velocityKnob);
        horizontalContainer->addSpace(10);
        horizontalContainer->addContainer(timingKnob);
        mainContainer->addContainer(horizontalContainer);
}

void HumanizerView::updateView()
{
        auto model = static_cast<PercussionModel*>(getModel());
        if (!model)
                return;
        //        instrumentAmplitudeKnob->setCurrentValue(model->getAmplitude());
        //        instrumentLengthKnob->setCurrentValue(model->getLength());
}

void HumanizerView::bindModel()
{
        /*auto model = static_cast<PercussionModel*>(getModel());
        if (!model)
                return;
        RK_ACT_BIND(instrumentLengthKnob,
                    valueUpdated,
                    RK_ACT_ARGS(double val),
                    model,
                    setLength(val));
        RK_ACT_BIND(instrumentAmplitudeKnob,
                    valueUpdated,
                    RK_ACT_ARGS(double val),
                    model,
                    setAmplitude(val));*/
}

void HumanizerView::unbindModel()
{
        //instrumentLengthKnob->unbindObject(getModel());
        //        instrumentAmplitudeKnob->unbindObject(getModel());
}

RkContainer* HumanizerView::createVelocityKnob()
{
        auto label = new RkLabel(this, RK_RC_IMAGE(humanizer_velocity_knob_label));
        label->show();

        auto enableVelocityButton = new GeonkickButton(this);
        enableVelocityButton->setType(RkButton::ButtonType::ButtonCheckable);
        enableVelocityButton->setImage(RK_RC_IMAGE(humanizer_enable),
                                 RkButton::State::Unpressed);
        enableVelocityButton->setImage(RK_RC_IMAGE(humanizer_enable_hover),
                                 RkButton::State::UnpressedHover);
        enableVelocityButton->setImage(RK_RC_IMAGE(humanizer_enable_on),
                                 RkButton::State::Pressed);
        enableVelocityButton->setImage(RK_RC_IMAGE(humanizer_enable_hover),
                                 RkButton::State::PressedHover);

        auto velocityKnob = new Knob(this);
        velocityKnob->setKnobBackgroundImage(RK_RC_IMAGE(humanizer_velocity_knob_bk));
        velocityKnob->setKnobImage(RK_RC_IMAGE(humanizer_velocity_knob));

        auto labelContainer = new RkContainer(this);
        labelContainer->setSize({velocityKnob->width(), label->height()});
        labelContainer->addWidget(enableVelocityButton);
        labelContainer->addSpace(3);
        labelContainer->addWidget(label);

        auto container = new RkContainer(this, Rk::Orientation::Vertical);
        container->setSize({velocityKnob->width(),
                        labelContainer->height() + velocityKnob->height()});
        container->addContainer(labelContainer);
        container->addSpace(3);
        container->addWidget(velocityKnob);

        return container;
}

RkContainer* HumanizerView::createTimingKnob()
{
        auto label = new RkLabel(this, RK_RC_IMAGE(humanizer_timing_knob_label));
        label->show();

        auto enableTimingButton = new GeonkickButton(this);
        enableTimingButton->setType(RkButton::ButtonType::ButtonCheckable);
        enableTimingButton->setImage(RK_RC_IMAGE(humanizer_enable),
                                       RkButton::State::Unpressed);
        enableTimingButton->setImage(RK_RC_IMAGE(humanizer_enable_hover),
                                       RkButton::State::UnpressedHover);
        enableTimingButton->setImage(RK_RC_IMAGE(humanizer_enable_on),
                                       RkButton::State::Pressed);
        enableTimingButton->setImage(RK_RC_IMAGE(humanizer_enable_hover),
                                       RkButton::State::PressedHover);

        auto timingKnob = new Knob(this);
        timingKnob->setKnobBackgroundImage(RK_RC_IMAGE(humanizer_timing_knob_bk));
        timingKnob->setKnobImage(RK_RC_IMAGE(humanizer_timing_knob));

        auto labelContainer = new RkContainer(this);
        labelContainer->setSize({timingKnob->width(), label->height()});
        labelContainer->addWidget(enableTimingButton);
        labelContainer->addSpace(3);
        labelContainer->addWidget(label);

        auto container = new RkContainer(this, Rk::Orientation::Vertical);
        container->setSize({timingKnob->width(),
                           labelContainer->height() + timingKnob->height()});
        container->addContainer(labelContainer);
        container->addSpace(3);
        container->addWidget(timingKnob);

        return container;
}

