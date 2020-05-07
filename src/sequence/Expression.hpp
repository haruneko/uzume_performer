// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_SEQUENCE_EXPRESSION_HPP
#define UZUME_SEQUENCE_EXPRESSION_HPP

#include <vector>

namespace uzume { namespace sequence {

class ExpressionEvent final {
public:
    ExpressionEvent() = delete;

    ExpressionEvent(int ticks, double value);

    int ticks;
    double value;
};

class Expression final {
public:
    Expression(double defaultValue);
    Expression(const Expression &) = delete;

    double at(int ticks) const;
    void insert(int ticks, double value);
    void deleteBetween(int begin, int end);

private:
    std::vector<ExpressionEvent> events;
    double defaultValue;
};

} }

#endif //SEQUENCE_EXPRESSION_HPP
