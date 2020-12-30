
#include <memory>
#include <iostream>
#include "presence_cache.h"

#include "presence.pb.h"
#include "presence.grpc.pb.h"
#include "presence_recorder_service.h"

PresenceRecorderService::PresenceRecorderService(std::shared_ptr<PresenceCache> cache)
{
    presence_cache_ = cache;
}

PresenceRecorderService::~PresenceRecorderService()
{
}

grpc::Status PresenceRecorderService::PresenceRecorderService::UpdateStatus(const ::presence::UpdateUserConnectionRequest *request,
                                                                            ::presence::UpdateUserConnectionReply *response) const
{
    /*TODO: Fire event and other niceties
    - send an event in a topic of somekind for analysis of when the user typically comes on
        - should be done in a separate task/thread so to not hold anything up
    */
    return grpc::Status::OK;
}
