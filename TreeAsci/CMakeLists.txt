cmake_minimum_required(VERSION 3.10)
project(TreeAsci)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/TreeUtils.cpp
    src/Node.cpp

)

add_executable(TreeAsci ${SOURCES})