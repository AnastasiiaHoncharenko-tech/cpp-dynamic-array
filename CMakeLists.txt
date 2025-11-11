cmake_minimum_required(VERSION 3.29)
project(Project)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads)

include_directories(${CMAKE_BINARY_DIR}/googletest/include)
add_subdirectory(googletest)

add_executable(Project
        ArrayBase.h
        ArrayBase.cpp
        ArrayUtils.h
        ArrayUtils.cpp
        ArraySorting.h
        ArraySorting.cpp
        ArrayFileIO.h
        ArrayFileIO.cpp
        ArrayAdvanced.h
        ArrayAdvanced.cpp
        ArrayFull.h
        ArrayFull.cpp
        testArrayBase.cpp
        testArrayUtils.cpp
        testArraySorting.cpp
        testArrayFileIO.cpp
        testArrayAdvanced.cpp
        testArrayFull.cpp
)

target_link_libraries(Project gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
