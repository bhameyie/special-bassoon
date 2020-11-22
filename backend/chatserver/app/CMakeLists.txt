cmake_minimum_required(VERSION 3.17)
project(chatserver)

set(CMAKE_CXX_STANDARD 17)

add_executable(chatserver main.cpp)

target_compile_features(chatserver PRIVATE cxx_std_17)

target_link_libraries(chatserver PRIVATE chatserverlib fmt::fmt)
