/**
 * File name: main.cpp
 * Project: Geonkick (A percussiove synthesizer)
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

#include "MainWindow.h"
#include "DspProxy.h"

#include "RkMain.h"

#ifdef GEONKICK_OS_GNU
#include <sys/mman.h>
#endif // GEONKICK_OS_GNU

static geonkick* createDSP()
{
        geonkick* dspProxy = nullptr;
        if (geonkick_create(&dspProxy, Geonkick::defaultSampleRate) != GEONKICK_OK) {
                GEONKICK_LOG_ERROR("can't create geonkick API");
                return nullptr;
        }

        return dspProxy;
}

int main(int argc, char *argv[])
{
        auto dsp = createDSP();
	if (!dsp) {
                GEONKICK_LOG_ERROR("can't create DSP");
		exit(EXIT_FAILURE);
	}

#ifdef GEONKICK_OS_GNU
	if (mlockall(MCL_CURRENT) == -1) {
	        GEONKICK_LOG_INFO("can't lock memory. Please, check your "
                                  << "system settings reladed locked memory"
                                  << "(https://jackaudio.org/faq/linux_rt_config.html)");
        }
#endif // GEONKICK_OS_GNU

        RkMain app(argc, argv);
        std::string preset;
        if (argc == 2)
                preset = argv[1];

        auto dspProxy = new DspProxy(Geonkick::defaultSampleRate,
                                     DspProxy::InstanceType::Standalone,
                                     dsp);
        dspProxy->setEventQueue(app.eventQueue());
        dspProxy->setStandalone(true);
        if (!dspProxy->init()) {
                GEONKICK_LOG_ERROR("can't init DSP");
                delete dspProxy;
                exit(EXIT_FAILURE);
        }

        auto window = new MainWindow(app, dspProxy, preset);
        if (!window->init()) {
                GEONKICK_LOG_ERROR("can't init main window");
                exit(EXIT_FAILURE);
        }

        auto res = app.exec();
#ifdef GEONKICK_OS_GNU
        munlockall();
#endif // GEONKICK_OS_GNU

        return res;
}
