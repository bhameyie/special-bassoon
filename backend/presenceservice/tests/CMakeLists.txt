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

add_executable(presenceservicetest testgtest.cpp presence_cache_tests  )

target_compile_features(presenceservicetest PRIVATE cxx_std_17)

add_test(NAME presenceservicecheck COMMAND presenceservicetest) # Command can be a target
set_tests_properties(presenceservicecheck PROPERTIES
    ENVIRONMENT "TEST_FILE=all"
)
target_include_directories (
    presenceservicetest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/gen
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)
# Link test executable against gtest & gtest_main
target_link_libraries(presenceservicetest PRIVATE gtest gtest_main  ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})
#gtest_add_tests(TARGET presenceservicetest TEST_PREFIX old:)
gtest_discover_tests(presenceservicetest)
