cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(backuper)

add_executable(backuper src/main.cpp)
target_link_libraries(backuper stdc++fs)

target_compile_features(backuper PRIVATE cxx_std_17)
