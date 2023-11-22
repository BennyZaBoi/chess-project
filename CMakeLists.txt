CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runAllTests
    tests/allTests.cpp
    source/Piece.cpp
    source/SpecialPiece.cpp
    source/Pawn.cpp
    source/King.cpp
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)