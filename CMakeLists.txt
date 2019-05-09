cmake_minimum_required(VERSION 3.12)
project(traffic_donkey)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(traffic_donkey
        main.cpp
        Car.cpp Car.h road.cpp road.h)
