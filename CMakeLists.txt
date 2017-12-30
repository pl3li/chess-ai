cmake_minimum_required(VERSION 3.8)
project(ChessAI)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    src/bishop.cpp
    src/evaluate.cpp
    src/execute.cpp
    src/king.cpp
    src/knight.cpp
    src/main.cpp
    src/main.h
    src/minimax.cpp
    src/move.cpp
    src/pawn.cpp
    src/print.cpp
    src/queen.cpp
    src/rook.cpp
    src/tree.cpp
)

add_executable(ChessAI ${SOURCE_FILES})
