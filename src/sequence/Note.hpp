// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_SEQUENCE_NOTE_HPP
#define UZUME_SEQUENCE_NOTE_HPP
#include <string>

namespace uzume { namespace sequence {

class Note final {
public:
    const char key;
    const char velocity;
    const int ticks;
    const int duration;

    const std::string pronounce;
};

} }
#endif //UZUME_SEQUENCE_NOTE_HPP
