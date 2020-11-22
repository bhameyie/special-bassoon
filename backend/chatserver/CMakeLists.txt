cmake_minimum_required(VERSION 3.17)

project(chatserverapp 
    VERSION 0.1
    DESCRIPTION "Chat Server Service"
    LANGUAGES CXX)

find_package(Boost REQUIRED)
#find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 5.3.0)

FetchContent_MakeAvailable(fmtlib)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
  enable_testing()
endif()

