
cmake_minimum_required(VERSION 3.17)

project(presenceservicelib C CXX)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(hw_proto "../../protos/helloworld.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)

set(hw_proto_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gen/helloworld.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/gen/helloworld.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gen/helloworld.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/gen/helloworld.grpc.pb.h")

add_custom_command(
        PRE_BUILD
        OUTPUT "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}/gen"
        --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}/gen"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hw_proto}"
        DEPENDS "${hw_proto}")


include_directories("gen")

#set(HEADER_LIST,
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "../include/presenceservice/*.hpp")
file(GLOB GEN_HEADER_LIST CONFIGURE_DEPENDS "../include/presenceservice/gen/*.h")

add_library(presenceservicelib Yello.cpp ${GEN_HEADER_LIST} ${HEADER_LIST} ${hw_proto_srcs} ${hw_grpc_srcs})

target_include_directories(presenceservicelib PUBLIC ../include)

target_link_libraries(presenceservicelib PRIVATE Boost::boost
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}) #grpc++)
