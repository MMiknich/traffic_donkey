cmake_minimum_required(VERSION 3.12)
project(traffic_donkey)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
set(SOURCE_FILES
        main.cpp
        car.cpp car.h road.cpp road.h graph.cpp graph.h traffic_on_one_road.cpp all_the_roads.cpp)

set(PYTHON_FILES Plot.py)
add_executable(traffic_donkey
        main.cpp
        car.cpp car.h road.cpp road.h graph.cpp graph.h traffic_on_one_road.cpp all_the_roads.cpp Plot.py)

include_directories(
        glfw-3.1.2/include/GLFW/
        glew-1.13.0/include/
        glut37/glut-3.7/include/
        /usr/include/python3.7m/Python.h


)
target_link_libraries(traffic_donkey -lglut -lGL -lGLU -lpython3.7m -lpython2.7)
