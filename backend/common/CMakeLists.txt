cmake_minimum_required(VERSION 3.17)

project(common_libs
        VERSION 0.1
        DESCRIPTION "Common classes"
        LANGUAGES CXX)

add_subdirectory(src)
#add_subdirectory(tests)
#if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
#    include(CTest)
#    enable_testing()
#endif()
