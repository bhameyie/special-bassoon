cmake_minimum_required(VERSION 3.17)

project(receiptservicelib)

set(CMAKE_CXX_STANDARD 17)

#set(HEADER_LIST, 
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "../include/receiptservice/*.hpp")

add_library(receiptservicelib Yello.cpp ${HEADER_LIST})

target_include_directories(receiptservicelib PUBLIC ../include)

target_link_libraries(receiptservicelib PRIVATE Boost::boost)
