cmake_minimum_required(VERSION 3.6)
project(ChessAI)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    bishop.cpp
    evaluate.cpp
    execute.cpp
    king.cpp
    knight.cpp
    main.cpp
    main.h
    minimax.cpp
    move.cpp
    pawn.cpp
    print.cpp
    queen.cpp
    rook.cpp
    tree.cpp)

add_executable(ChessAI ${SOURCE_FILES})