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
#include "HumanizerModel.h"
#include "knob.h"
#include "geonkick_button.h"
#include "ViewState.h"

#include "RkContainer.h"
#include "RkLabel.h"

RK_DECLARE_IMAGE_RC(knob);
RK_DECLARE_IMAGE_RC(knob_bk_image);
RK_DECLARE_IMAGE_RC(effect_view_bk);
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

HumanizerView::HumanizerView(GeonkickWidget *parent, HumanizerModel *model)
        : AbstractView(parent, model)
        , velocityKnob {nullptr}
        , timingKnob {nullptr}
        , velocityValueLabel {nullptr}
        , timingValueLabel {nullptr}
{
        setFixedSize(224, 115);
        setBackgroundImage(RK_RC_IMAGE(effect_view_bk));
        createView();
        bindModel();
}

void HumanizerView::createView()
{
        auto mainContainer = new RkContainer(this, Rk::Orientation::Horizontal);
        auto velocityKnob = createVelocityKnob();
        auto timingKnob = createTimingKnob();
        mainContainer->addSpace((width() - velocityKnob->width() - timingKnob->width() - 10) / 2);
        mainContainer->addContainer(velocityKnob);
        mainContainer->addSpace(10);
        mainContainer->addContainer(timingKnob);
        updateView();
}

void HumanizerView::updateView()
{
        auto model = static_cast<HumanizerModel*>(getModel());
        if (!model)
                return;

        auto val = model->getVelocityPercent();
        velocityKnob->setCurrentValue(val);
        velocityValueLabel->setText(Geonkick::doubleToStr(val, 1) + " %");

        val = model->getTiming();
        timingKnob->setCurrentValue(val);
        timingValueLabel->setText(Geonkick::doubleToStr(val, 1) + " ms");
}

void HumanizerView::bindModel()
{
        auto model = static_cast<HumanizerModel*>(getModel());
        if (!model)
                return;

        RK_ACT_BIND(velocityKnob,
                    valueUpdated,
                    RK_ACT_ARGS(double val),
                    model,
                    setVelocityPercent(val));
        RK_ACT_BIND(timingKnob,
                    valueUpdated,
                    RK_ACT_ARGS(double val),
                    model,
                    setTiming(val));
        RK_ACT_BIND(model,
                    velocityPercentUpdated,
                    RK_ACT_ARGS(double val),
                    velocityValueLabel,
                    setText(Geonkick::doubleToStr(val, 1) + " %"));
        RK_ACT_BIND(model,
                    timingUpdated,
                    RK_ACT_ARGS(double val),
                    timingValueLabel,
                    setText(Geonkick::doubleToStr(val, 1) + " ms"));
}

void HumanizerView::unbindModel()
{
        unbindObject(getModel());
        velocityKnob->unbindObject(getModel());
        timingKnob->unbindObject(getModel());
        velocityValueLabel->unbindObject(getModel());
        timingValueLabel->unbindObject(getModel());
}

RkContainer* HumanizerView::createVelocityKnob()
{
        auto label = new RkLabel(this, RK_RC_IMAGE(humanizer_velocity_knob_label));
        label->show();

        velocityKnob = new Knob(this);
        velocityKnob->setKnobBackgroundImage(RK_RC_IMAGE(knob_bk_image));
        velocityKnob->setKnobImage(RK_RC_IMAGE(knob));
        velocityKnob->setRange(0.0, 30.0);

        auto container = new RkContainer(this, Rk::Orientation::Vertical);
        container->setSize({std::max(velocityKnob->width(), label->width()),
                        height() - 10});
        container->addWidget(label);
        container->addSpace(3);
        container->addWidget(velocityKnob);

        velocityValueLabel = new RkLabel(this);
        velocityValueLabel->setBackgroundColor(background());
        auto font = label->font();
        font.setWeight(RkFont::Weight::Bold);
        velocityValueLabel->setTextColor({160, 160, 160});
        velocityValueLabel->setFont(font);
        velocityValueLabel->setSize({50, font.size()});
        velocityValueLabel->show();
        container->addWidget(velocityValueLabel);

        return container;
}

RkContainer* HumanizerView::createTimingKnob()
{
        auto label = new RkLabel(this, RK_RC_IMAGE(humanizer_timing_knob_label));
        label->show();

        timingKnob = new Knob(this);
        timingKnob->setKnobBackgroundImage(RK_RC_IMAGE(knob_bk_image));
        timingKnob->setKnobImage(RK_RC_IMAGE(knob));
        timingKnob->setRange(0.0, 30);

        auto container = new RkContainer(this, Rk::Orientation::Vertical);
        container->setSize({std::max(timingKnob->width(), label->width()),
                           height() - 10});
        container->addWidget(label);
        container->addSpace(3);
        container->addWidget(timingKnob);

        timingValueLabel = new RkLabel(this);
        timingValueLabel->setBackgroundColor(background());
        auto font = timingValueLabel->font();
        font.setWeight(RkFont::Weight::Bold);
        timingValueLabel->setTextColor({160, 160, 160});
        timingValueLabel->setFont(font);
        timingValueLabel->setSize({50, font.size()});
        timingValueLabel->show();
        container->addWidget(timingValueLabel);

        return container;
}

