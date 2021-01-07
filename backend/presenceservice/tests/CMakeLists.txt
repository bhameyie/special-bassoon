
project(presenceservicetesting C CXX)
cmake_policy(SET CMP0079 NEW)

################################
# Tests
################################
include(GoogleTest)# Add test cpp file

include_directories("../src")
include_directories("../src/gen")

add_executable(presenceservicetest
        presence_cache_tests.cpp
        presence_retriever_service_tests.cpp
        presence_recorder_service_tests.cpp
        presence_cache_mock.h)

#include_directories("g")
target_compile_features(presenceservicetest PRIVATE cxx_std_17)

# Link test executable against gtest & gtest_main
target_link_libraries(presenceservicetest PUBLIC
        presenceservicelib
        gtest gmock gtest_main gmock_main
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
        )

gtest_discover_tests(presenceservicetest)
add_test(NAME presenceservicecheck COMMAND presenceservicetest) # Command can be a target
