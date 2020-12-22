//
// Created by Boguste Hameyie on 11/21/20.
//

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
//#include "helloworld.grpc.pb.h"
#endif

#include <presenceservice/Yello.hpp>
//#include "helloworld.grpc.pb.h"

int meh(int d){
    return d*5;
}

