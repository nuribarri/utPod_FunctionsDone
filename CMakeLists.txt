cmake_minimum_required(VERSION 3.15)
project(utPod)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(.)

add_executable(utPod
        Song.cpp
        Song.h
        utPod.cpp
        utPod.h
        utPod_driver.cpp)
