cmake_minimum_required(VERSION 3.28.1)

set(PROJECT_NAME projectiles)
project(${PROJECT_NAME} VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} src/main.cpp src/particle.cpp src/simulation.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "include")
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
