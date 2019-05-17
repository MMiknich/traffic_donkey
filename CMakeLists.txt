cmake_minimum_required(VERSION 3.12)
project(traffic_donkey)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(traffic_donkey
        main.cpp
        car.cpp car.h road.cpp road.h graph.cpp graph.h traffic_on_one_road.cpp)
