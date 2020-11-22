cmake_minimum_required(VERSION 3.17)

project(chatserverlib)

set(CMAKE_CXX_STANDARD 17)

#set(HEADER_LIST, 
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "../include/chatserver/*.hpp")

add_library(chatserverlib Yello.cpp ${HEADER_LIST})

target_include_directories(chatserverlib PUBLIC ../include)

target_link_libraries(chatserverlib PRIVATE Boost::boost)

