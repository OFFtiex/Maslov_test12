cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME lab02.2)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 20)

add_executable("${PROJECT_NAME}" main.cpp auto.cpp auto.hpp)