# Copyright 2020 Hal@shurabaP.  All rights reserved.
# Use of this source code is governed by a MIT style
# license that can be found in the LICENSE file.
cmake_minimum_required(VERSION 3.16)

project(uzume_performer VERSION 0.0.1 LANGUAGES CXX)

add_library(uzume_performer STATIC)
set(CMAKE_CXX_STANDARD 17)

target_compile_options(uzume_performer
        PRIVATE
        -Wall -Wextra -Wno-long-long -pedantic)
target_sources(uzume_performer
        PRIVATE
        sequence/Expression.cpp
        sequence/Note.cpp
        sequence/Sequence.cpp
        sequence/Tempo.cpp
        sequence/Track.cpp
        )
set_property(TARGET
        PROPERTY PUBLIC_HEADER
        sequence/Expression.hpp
        sequence/Note.hpp
        sequence/Sequence.hpp
        sequence/Tempo.hpp
        sequence/Track.hpp)
target_include_directories(uzume_performer
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>)

install(TARGETS uzume_performer
        EXPORT libuzume_performer
        ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
        LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
        PUBLIC_HEADER DESTINATION ${CMAKE_INCLUDE_CURRENT_DIR}/include)
