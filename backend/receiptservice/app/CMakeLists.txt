cmake_minimum_required(VERSION 3.17)
project(receiptservice)

set(CMAKE_CXX_STANDARD 17)

add_executable(receiptservice main.cpp)

target_compile_features(receiptservice PRIVATE cxx_std_17)

target_link_libraries(receiptservice PRIVATE receiptservicelib fmt::fmt)
