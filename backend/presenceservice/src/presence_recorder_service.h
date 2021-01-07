#ifndef __PRESENCE_RECORDER_SERVICE_H__
#define __PRESENCE_RECORDER_SERVICE_H__

#include <memory>
#include <iostream>
#include "presence_cache.h"
#include <variant>
#include "presence.pb.h"
#include "presence.grpc.pb.h"

class PresenceRecorderService
{
private:
    std::shared_ptr<PresenceCache> presence_cache_;

public:
    explicit PresenceRecorderService(std::shared_ptr<PresenceCache> cache);
    ~PresenceRecorderService();

  [[nodiscard]] std::variant<UpdatedPresence,OperationFailure> UpdateStatus(const ::presence::UpdateUserConnectionRequest &request) const;
};
#endif // __PRESENCE_RECORDER_SERVICE_H__