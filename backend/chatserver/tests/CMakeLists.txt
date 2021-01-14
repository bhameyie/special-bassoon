# Build output setup
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

################################
# GTest
################################
#project(googletest-git NONE)
project(chatservertesting C CXX)
cmake_policy(SET CMP0079 NEW)

################################
# Tests
################################

include(GoogleTest)# Add test cpp file
add_executable(chatservertest testgtest.cpp)

target_compile_features(chatservertest PRIVATE cxx_std_17)

# Link test executable against gtest & gtest_main
target_link_libraries(chatservertest PRIVATE chatserverlib
        gtest gmock gtest_main gmock_main)

gtest_discover_tests(chatservertest)
