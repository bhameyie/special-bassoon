#ifndef __SERVICE_MODELS_H__
#define __SERVICE_MODELS_H__

#include <string>

struct UpdatedPresence
{
    unsigned int status_id;
    std::string user_id;
};

struct PresenceUpdate
{
    std::string device_id;
    std::string user_id;
    unsigned int status_id;
    long last_seen_timestamp;
};


#endif // __SERVICE_MODELS_H__