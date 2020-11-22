# Build output setup
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

################################
# GTest
################################
#project(googletest-git NONE)
project(chatservertesting)

################################
# Tests
################################

include(GoogleTest)# Add test cpp file
add_executable(testlib testgtest.cpp)

target_compile_features(testlib PRIVATE cxx_std_17)

# Link test executable against gtest & gtest_main
target_link_libraries(testlib PRIVATE chatserverlib gtest gtest_main)
#gtest_add_tests(TARGET testlib TEST_PREFIX old:)
gtest_discover_tests(testlib)

add_test(NAME testlibtest COMMAND testlib) # Command can be a target