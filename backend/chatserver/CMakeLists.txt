cmake_minimum_required(VERSION 3.17)

project(chatserverapp 
    VERSION 0.1
    DESCRIPTION "Chat Server Service"
    LANGUAGES CXX)

find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 5.3.0)
  
FetchContent_MakeAvailable(fmtlib)


#inner lib
# project(src)
add_subdirectory(src)

#build source
# project(app 
#    VERSION  0.1.0)
add_subdirectory(app)

#build tests
# project(chatservertesting)

add_subdirectory(tests)
enable_testing()

# add_test(${CHATSERVERTESTNAME} ${CHATSERVERTESTNAME})
