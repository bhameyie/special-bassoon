#ifndef __SERVICE_MODELS_H__
#define __SERVICE_MODELS_H__

#include <string>

struct UpdatedPresence
{
    std::string user_id;
    unsigned int status_id;
};

struct RecordedPresence{
    std::string user_id;
    std::string device_id;
    unsigned int status_id;
    long last_seen_timestamp;
};

struct PresenceUpdate
{
    std::string user_id;
    std::string device_id;
    unsigned int status_id;
    long last_seen_timestamp;
};

#endif // __SERVICE_MODELS_H__
