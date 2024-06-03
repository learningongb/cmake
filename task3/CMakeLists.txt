cmake_minimum_required(VERSION 3.6)
project(tic_tac_toe CXX)

SET(SRC src/client.cpp src/consolegame.cpp src/consoleplayer.cpp src/gamemanager.cpp src/simpleboard.cpp)
# SET(INCL board.h consolegame.h consoleplayer.h game.h gamemanager.h player.h simpleboard.h)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(tic_tac_toe ${SRC})