// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_SEQUENCE_SEQUENCE_HPP
#define UZUME_SEQUENCE_SEQUENCE_HPP
#include <functional>
#include <memory>
#include <vector>

namespace uzume { namespace sequence {

class Tempo;
class Track;

class Sequence final {
public:
    Sequence() = delete;
    ~Sequence() = default;

    std::unique_ptr<Tempo> tempo;
    std::vector<std::unique_ptr<Track>> tracks;
};

} }

#endif //UZUME_SEQUENCE_SEQUENCE_HPP
