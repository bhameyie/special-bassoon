# Build output setup
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

################################
# GTest
################################
#project(googletest-git NONE)
project(receiptservicetesting)
cmake_policy(SET CMP0079 NEW)

################################
# Tests
################################
include(GoogleTest)# Add test cpp file
add_executable(receiptservicetest testgtest.cpp)

target_compile_features(receiptservicetest PRIVATE cxx_std_17)

# Link test executable against gtest & gtest_main
target_link_libraries(receiptservicetest PRIVATE receiptservicelib gtest gtest_main)
#gtest_add_tests(TARGET receiptservicetest TEST_PREFIX old:)
gtest_discover_tests(receiptservicetest)

add_test(NAME receiptservicetesttest COMMAND receiptservicetest) # Command can be a target

#FetchContent_Declare(
#  Catch2
#  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#  GIT_TAG        v2.13.1)
#
#FetchContent_MakeAvailable(Catch2)
#
#add_executable(receiptservicetest testgtest.cpp)
#
#target_compile_features(receiptservicetest PRIVATE cxx_std_17)
#
## Link test executable against gtest & gtest_main
#target_link_libraries(receiptservicetest PRIVATE receiptservicelib Catch2::Catch2)
##gtest_add_tests(TARGET receiptservicetest TEST_PREFIX old:)
#
#add_test(NAME receiptservicetesttest COMMAND receiptservicetest) # Command can be a target