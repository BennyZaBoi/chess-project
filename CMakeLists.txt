CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(FinalChessProject)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runGame
    main.cpp
    source/chessvictory.cpp
    source/chesswelcome.cpp
    source/chessInstructions.cpp
    source/Player.cpp
    source/customize.cpp
    source/chessboard.cpp
    source/squares.cpp
    source/Piece.cpp
    source/SpecialPiece.cpp
    source/Pawn.cpp
    source/King.cpp
    source/Queen.cpp
    source/Knight.cpp
    source/Rook.cpp
    source/Bishop.cpp
)
ADD_EXECUTABLE(runAllTests
    tests/allTests.cpp
    source/chessvictory.cpp
    source/chesswelcome.cpp
    source/displaychessboard.cpp
    source/chessInstructions.cpp
    source/Player.cpp
    source/customize.cpp
    source/chessboard.cpp
    source/squares.cpp
    source/Piece.cpp
    source/SpecialPiece.cpp
    source/Pawn.cpp
    source/King.cpp
    source/Queen.cpp
    source/Knight.cpp
    source/Rook.cpp
    source/Bishop.cpp
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)