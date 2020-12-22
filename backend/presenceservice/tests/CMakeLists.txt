# Build output setup
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

################################
# GTest
################################
#project(googletest-git NONE)
project(presenceservicetesting)
cmake_policy(SET CMP0079 NEW)

################################
# Tests
################################
include(GoogleTest)# Add test cpp file
add_executable(presenceservicetest testgtest.cpp  )

target_compile_features(presenceservicetest PRIVATE cxx_std_17)

# Link test executable against gtest & gtest_main
target_link_libraries(presenceservicetest PRIVATE presenceservicelib gtest gtest_main  ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})
#gtest_add_tests(TARGET presenceservicetest TEST_PREFIX old:)
gtest_discover_tests(presenceservicetest)

add_test(NAME presenceservicetesttest COMMAND presenceservicetest) # Command can be a target

#FetchContent_Declare(
#  Catch2
#  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#  GIT_TAG        v2.13.1)
#
#FetchContent_MakeAvailable(Catch2)
#
#add_executable(presenceservicetest testgtest.cpp)
#
#target_compile_features(presenceservicetest PRIVATE cxx_std_17)
#
## Link test executable against gtest & gtest_main
#target_link_libraries(presenceservicetest PRIVATE presenceservicelib Catch2::Catch2)
##gtest_add_tests(TARGET presenceservicetest TEST_PREFIX old:)
#
#add_test(NAME presenceservicetesttest COMMAND presenceservicetest) # Command can be a target