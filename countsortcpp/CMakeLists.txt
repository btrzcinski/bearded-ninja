cmake_minimum_required(VERSION 3.0.2)
project(Countsortcpp)
add_executable(countsortcpp.out countsort.cpp)
target_compile_features(countsortcpp.out PRIVATE cxx_auto_type cxx_uniform_initialization)
