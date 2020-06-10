cmake_minimum_required(VERSION 3.16)
project(UNO_Server)
set(CMAKE_INCLUDE_CURRENT_DIR)
set(CMAKE_CXX_STANDARD 11)

add_executable(UNO_Server message.cpp main.cpp)