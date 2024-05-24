cmake_minimum_required(VERSION 3.11)
project(game)
set(SRC ./src/game.cpp
        ./src/computer.cpp
        ./src/human.cpp)
include_directories(./include)
add_library(game STATIC ${SRC})
