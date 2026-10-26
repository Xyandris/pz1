cmake_minimum_required(VERSION 4.3)
project(pz1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pz1
        DoublyLinkedList.cpp
        DoublyLinkedList.h
        Iterator.cpp
        Iterator.h
        ListFactory.cpp
        ListFactory.h
        main.cpp
        Node.cpp
        Node.h)
