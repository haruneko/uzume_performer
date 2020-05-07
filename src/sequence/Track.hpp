// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_SEQUENCE_TRACK_HPP
#define UZUME_SEQUENCE_TRACK_HPP
#include <memory>
#include <vector>
#include <unordered_map>

namespace uzume { namespace sequence {

class Expression;
class Note;

class Track final {
public:
    Track() = default;

    std::vector<std::unique_ptr<Note>> notes;
    std::unordered_map<int, std::unique_ptr<Expression>> expressions;
};

} }
#endif //UZUME_SEQUENCE_TRACK_HPP
