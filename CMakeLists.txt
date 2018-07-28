cmake_minimum_required(VERSION 3.10)
project(AlgorithmCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test test.cpp)
add_executable(TeX_Test Chapter5_String/TeX_Test.c)
add_executable(CycleString Chapter5_String/CycleString.cpp)
add_executable(Chain Version2/DataStructureBasic/LinkedList/ChainNode.cpp Version2/DataStructureBasic/LinkedList/ChainNode.h Version2/DataStructureBasic/LinkedList/Chain.cpp Version2/DataStructureBasic/LinkedList/Chain.h Version2/DataStructureBasic/LinkedList/ChainIterator.cpp Version2/DataStructureBasic/LinkedList/ChainIterator.h)
add_executable(IndirectList Version2/DataStructureBasic/IndirectList/IndirectList.cpp Version2/DataStructureBasic/IndirectList/IndirectList.h Version2/DataStructureBasic/IndirectList/ChainIterator.cpp Version2/DataStructureBasic/IndirectList/ChainIterator.h Version2/DataStructureBasic/IndirectList/IndirectListTest.cpp)
add_executable(StackAndHeap Version2/StackAndHeap/Stack.h Version2/StackAndHeap/Stack.cpp Version2/StackAndHeap/LinkedStack.h Version2/StackAndHeap/LinkedStack.cpp Version2/StackAndHeap/Node.cpp Version2/StackAndHeap/Node.h)
add_executable(Queue Version2/Queue/Queue.cpp Version2/Queue/Queue.h)
