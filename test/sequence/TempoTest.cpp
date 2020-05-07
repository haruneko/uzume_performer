// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include <gtest/gtest.h>

#include "sequence/Tempo.hpp"

using namespace uzume::sequence;

TEST(TempoTest, msAtAndTicksAt) {
    Tempo t(120.0, 480);
    t.insert(960, 120.0);
    t.insert(1440, 60.0);
    t.insert(480, 60.0);
    ASSERT_DOUBLE_EQ(t.msAt(360), 375.0);
    ASSERT_DOUBLE_EQ(t.ticksAt(375.0), 360);
    ASSERT_DOUBLE_EQ(t.msAt(480), 500.0);
    ASSERT_DOUBLE_EQ(t.ticksAt(500.0), 480);
    ASSERT_DOUBLE_EQ(t.msAt(600), 750.0);
    ASSERT_DOUBLE_EQ(t.ticksAt(750.0), 600);
    ASSERT_DOUBLE_EQ(t.msAt(720), 1000.0);
    ASSERT_DOUBLE_EQ(t.ticksAt(1000.0), 720);
    ASSERT_DOUBLE_EQ(t.msAt(960), 1500.0);
    ASSERT_DOUBLE_EQ(t.ticksAt(1500.0), 960);
    ASSERT_DOUBLE_EQ(t.msAt(1200), 1750.0);
    ASSERT_DOUBLE_EQ(t.ticksAt(1750.0), 1200);
    ASSERT_DOUBLE_EQ(t.msAt(1440), 2000.0);
    ASSERT_DOUBLE_EQ(t.ticksAt(2000.0), 1440);
    ASSERT_DOUBLE_EQ(t.msAt(1920), 3000.0);
    ASSERT_DOUBLE_EQ(t.ticksAt(3000.0), 1920);
}

TEST(TempoTest, delteBetween) {
    Tempo t(60.0, 480);
    t.insert(120, 120.0);
    t.insert(240, 240.0);
    t.insert(360, 360.0);
    t.insert(480, 480.0);

    ASSERT_DOUBLE_EQ(t.at(60), 60.0);
    ASSERT_DOUBLE_EQ(t.at(120), 120.0);
    ASSERT_DOUBLE_EQ(t.at(180), 120.0);
    ASSERT_DOUBLE_EQ(t.at(240), 240.0);
    ASSERT_DOUBLE_EQ(t.at(300), 240.0);
    ASSERT_DOUBLE_EQ(t.at(360), 360.0);
    ASSERT_DOUBLE_EQ(t.at(420), 360.0);
    ASSERT_DOUBLE_EQ(t.at(480), 480.0);
    ASSERT_DOUBLE_EQ(t.at(540), 480.0);

    t.deleteBetween(180, 420);

    ASSERT_DOUBLE_EQ(t.at(60), 60.0);
    ASSERT_DOUBLE_EQ(t.at(120), 120.0);
    ASSERT_DOUBLE_EQ(t.at(180), 120.0);
    ASSERT_DOUBLE_EQ(t.at(240), 120.0);
    ASSERT_DOUBLE_EQ(t.at(300), 120.0);
    ASSERT_DOUBLE_EQ(t.at(360), 120.0);
    ASSERT_DOUBLE_EQ(t.at(420), 120.0);
    ASSERT_DOUBLE_EQ(t.at(480), 480.0);
    ASSERT_DOUBLE_EQ(t.at(540), 480.0);
}
