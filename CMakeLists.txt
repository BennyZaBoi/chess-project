CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runGame
    main.cpp
    source/chessvictory.cpp
    source/chesswelcome.cpp
    source/Player.cpp
    source/chessboard.cpp
    source/squares.cpp
    source/Piece.cpp
    source/SpecialPiece.cpp
    source/Pawn.cpp
    source/King.cpp
    source/Knight.cpp
    source/Rook.cpp
    source/Bishop.cpp
)
ADD_EXECUTABLE(runAllTests
    tests/allTests.cpp
    source/chessvictory.cpp
    source/chesswelcome.cpp
    source/Player.cpp
    source/chessboard.cpp
    source/squares.cpp
    source/Piece.cpp
    source/SpecialPiece.cpp
    source/Pawn.cpp
    source/King.cpp
    source/Knight.cpp
    source/Rook.cpp
    source/Bishop.cpp
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)