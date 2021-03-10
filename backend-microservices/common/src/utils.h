#ifndef __UTILS_H__
#define __UTILS_H__

#include <grpc/grpc.h>
#include <grpcpp/impl/codegen/status_code_enum.h>
#include "operation_models.h"

namespace bassoon {
namespace common {

long GetCurrentTimestamp();

grpc::StatusCode FailureCodeToStatusCode(OperationFailureCode code);

}
}
#endif // __UTILS_H__