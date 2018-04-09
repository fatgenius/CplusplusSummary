cmake_minimum_required(VERSION 3.8)
project(Lecture_05)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

#set (CMAKE_CXX_FLAGS "-m64")

set(SOURCE_FILES vector.h main.cpp Number.h container.h)
add_executable(Lecture_05 ${SOURCE_FILES})