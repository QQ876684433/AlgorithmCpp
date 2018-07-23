cmake_minimum_required(VERSION 3.10)
project(AlgorithmCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test test.cpp)
add_executable(TeX_Test Chapter5_String/TeX_Test.c)
add_executable(CycleString Chapter5_String/CycleString.cpp)
add_executable(Chain Version2/Chapter6_DataStructureBasic/ChainNode.cpp Version2/Chapter6_DataStructureBasic/ChainNode.h Version2/Chapter6_DataStructureBasic/Chain.cpp Version2/Chapter6_DataStructureBasic/Chain.h Version2/Chapter6_DataStructureBasic/ChainIterator.cpp Version2/Chapter6_DataStructureBasic/ChainIterator.h)