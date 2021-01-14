#ifndef __UTILS_H__
#define __UTILS_H__

#include <grpc/grpc.h>
#include <presence.grpc.pb.h>
#include "service_models.h"

long GetCurrentTimestamp();

grpc::StatusCode FailureCodeToStatusCode(OperationFailureCode code);

#endif // __UTILS_H__