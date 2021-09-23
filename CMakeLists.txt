cmake_minimum_required(VERSION 3.20)
project(Chess_Engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chess_Engine
        board.cpp
        board.h
        main.cpp
        pieces.cpp
        pieces.h Move.cpp cmake-build-debug/moves.h)
