cmake_minimum_required(VERSION 3.0)

project(sdlgame)

include_directories(include)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(sdlgame src/main.cpp src/screen.cpp)

target_link_libraries(sdlgame ${SDL2_LIBRARIES})