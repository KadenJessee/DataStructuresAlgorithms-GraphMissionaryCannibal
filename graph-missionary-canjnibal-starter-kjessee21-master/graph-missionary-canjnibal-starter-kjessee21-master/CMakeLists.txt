cmake_minimum_required(VERSION 3.14)
project(graphs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(inc)

add_executable(graphs
        inc/GameState.h
        inc/Graph.h
        inc/MC.h
        src/GraphTest.cpp)
