cmake_minimum_required(VERSION 3.17)

project(commonlib C CXX)

add_library(commonlib SHARED utils.cpp
        utils.h operation_models.h)

#set_target_properties(commonlib PROPERTIES PUBLIC_HEADER  include/commonlib.h)
target_include_directories(commonlib PUBLIC .)

target_link_libraries(commonlib PUBLIC ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})
