cmake_minimum_required(VERSION 3.24)
project(racing_team)

set(CMAKE_CXX_STANDARD 17)

#source_group(src/*.*)
include_directories(inc/*.*)
include_directories(./src)

add_executable(racing_team src/main.cpp inc/Point.h inc/Line.h inc/Triangle.h inc/Vector2D.h src/Point.cpp src/Vector2D.cpp src/Line.cpp src/Triangle.cpp inc/test.h src/test.cpp)
#add_subdirectory(etl)
#add_executable(foo main.cpp)
#target_link_libraries(foo PRIVATE etl::etl)