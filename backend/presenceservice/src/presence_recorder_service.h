#ifndef __PRESENCE_RECORDER_SERVICE_H__
#define __PRESENCE_RECORDER_SERVICE_H__

#include <memory>
#include <iostream>
#include "presence_cache.h"

#include "presence.pb.h"
#include "presence.grpc.pb.h"

class PresenceRecorderService
{
private:
    std::shared_ptr<PresenceCache> presence_cache_;

public:
    PresenceRecorderService(std::shared_ptr<PresenceCache> cache);
    ~PresenceRecorderService();
   
    grpc::Status UpdateStatus(const ::presence::UpdateUserConnectionRequest *request,
                                ::presence::UpdateUserConnectionReply *response) const;
};
#endif // __PRESENCE_RECORDER_SERVICE_H__