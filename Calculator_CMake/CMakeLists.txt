cmake_minimum_required(VERSION 2.4)
project(Calcultor)
set(srcFiles main.cpp Lib/Calculator.cpp)
add_executable(Calc_CMake ${srcFiles})
target_include_directories(Calc_CMake PUBLIC include/)

