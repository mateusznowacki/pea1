cmake_minimum_required(VERSION 3.29)
project(pea11)

set(CMAKE_CXX_STANDARD 23)
MATH(EXPR stack_size "16 * 1024 * 1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,16777216")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")


add_executable(pea11 service/main.cpp
        service/FileController.cpp
        service/Graph.cpp
        service/Graph.h
        service/Filecontroller.h
        service/Bruteforce.cpp
        service/Bruteforce.h


)
