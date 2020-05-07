// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include <algorithm>
#include <cstdio>

#include "Tempo.hpp"

using namespace uzume::sequence;

TempoEvent::TempoEvent(int ticks, double value)
        : ticks(ticks), value(value) {
}

Tempo::Tempo(double defaultValue, int timebase)
        : defaultValue(defaultValue), timebase(timebase) {
}

void Tempo::insert(int ticks, double value) {
    auto i = std::find_if(events.begin(), events.end(), [ticks](const TempoEvent &e) { return ticks < e.ticks; });
    if(i == events.end()) {
        events.emplace_back(ticks, value);
    } else {
        if(i->ticks == ticks) {
            i->value = value;
        } else {
            events.insert(i, TempoEvent(ticks, value));
        }
    }
}

void Tempo::deleteBetween(int begin, int end) {
    auto result = std::remove_if(events.begin(), events.end(),
                                 [begin, end](const TempoEvent &e) { return begin <= e.ticks && e.ticks <= end; });
    events.erase(result, events.end());
}

double Tempo::at(int ticks) const {
    auto i(std::find_if(events.begin(), events.end(), [ticks](const TempoEvent &e) { return e.ticks > ticks; }));
    if(i == events.begin()) {
        return defaultValue;
    } else {
        return (i - 1)->value;
    }
}

namespace {
    double getMs(int ticksLength, int timebase, double tempo) {
        return (double)ticksLength / timebase * 60 * 1000.0 / tempo;
    }
    int getTicks(double ms, int timebase, double tempo) {
        return (int)(ms * tempo / 60 / 1000.0 * timebase);
    }
}

double Tempo::msAt(int ticks) const {
    if(ticks < 0 || events.empty()) {
        return getMs(ticks, timebase, defaultValue);
    }
    double ms = 0.0;
    double currentTempo = defaultValue;
    int currentTicks = 0;
    for(auto event : events) {
        if(ticks < event.ticks) {
            break;
        }
        ms += getMs(event.ticks - currentTicks, timebase, currentTempo);
        currentTicks = event.ticks;
        currentTempo = event.value;
    }
    ms += getMs(ticks - currentTicks, timebase, currentTempo);
    return ms;
}

int Tempo::ticksAt(double ms) const {
    if(ms < 0 || events.empty()) {
        return getTicks(ms, timebase, defaultValue);
    }
    int ticks = 0;
    double currentTempo = defaultValue;
    double currentMs = 0.0;
    for(auto event: events) {
        double nextMs = currentMs + getMs(event.ticks - ticks, timebase, currentTempo);
        if(ms < nextMs) {
            break;
        }
        ticks = event.ticks;
        currentMs = nextMs;
        currentTempo = event.value;
    }
    ticks += getTicks(ms - currentMs, timebase, currentTempo);
    return ticks;
}
