// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include <algorithm>
#include "Expression.hpp"

using namespace uzume::sequence;

ExpressionEvent::ExpressionEvent(int ticks, double value)
    : ticks(ticks), value(value) {
}

Expression::Expression(double defaultValue)
    : defaultValue(defaultValue) {
}

void Expression::insert(int ticks, double value) {
    auto i = std::find_if(events.begin(), events.end(), [ticks](const ExpressionEvent &e) { return e.ticks <= ticks; });
    if(i == events.end()) {
        events.emplace_back(ticks, value);
    } else {
        if(i->ticks == ticks) {
            i->value = value;
        } else {
            events.insert(i, ExpressionEvent(ticks, value));
        }
    }
}

void Expression::deleteBetween(int begin, int end) {
    auto result = std::remove_if(events.begin(), events.end(),
            [begin, end](const ExpressionEvent &e) { return begin <= e.ticks && e.ticks <= end; });
    events.erase(result, events.end());
}

double Expression::at(int ticks) const {
    auto i(std::find_if(events.begin(), events.end(), [ticks](const ExpressionEvent &e) { return e.ticks > ticks; }));
    if(i == events.begin()) {
        return defaultValue;
    } else {
        return (i - 1)->value;
    }
}
