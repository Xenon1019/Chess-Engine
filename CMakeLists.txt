cmake_minimum_required(VERSION 3.20)
project(Chess_Engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Chess_Engine
        board.cpp
        main.cpp
        pieces.cpp
        Move.cpp utils.cpp)
