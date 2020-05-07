// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_SEQUENCE_TEMPO_HPP
#define UZUME_SEQUENCE_TEMPO_HPP
#include <vector>

namespace uzume { namespace sequence {

class TempoEvent final {
public:
    TempoEvent(int ticks, double value);
    TempoEvent() = delete;
    int ticks;
    double value;
};

class Tempo final {
public:
    Tempo(double defaultValue, int timebase);

    double msAt(int ticks) const;
    int ticksAt(double ms) const;
    double at(int ticks) const;

    void insert(int ticks, double value);
    void deleteBetween(int begin, int end);

//private:
    std::vector<TempoEvent> events;
    double defaultValue;
    int timebase;
};

} }

#endif //UZUME_SEQUENCE_TEMPO_HPP
