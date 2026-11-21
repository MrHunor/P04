cmake_minimum_required(VERSION 3.20)

project(P04_Library LANGUAGES CXX)

add_library(P04_Library STATIC
src/imposter.cpp
)

target_include_directories(P04_Library
PUBLIC include/
)

target_compile_features(P04_Library PUBLIC cxx_std_20)