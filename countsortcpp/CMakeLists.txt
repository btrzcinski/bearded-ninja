cmake_minimum_required(VERSION 3.2)
project(Countsort)
add_executable(countsort.out countsort.cpp)
target_compile_features(countsort.out PRIVATE cxx_auto_type cxx_uniform_initialization)