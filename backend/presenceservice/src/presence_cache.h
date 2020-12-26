#ifndef __PRESENCE_CACHE_H__
#define __PRESENCE_CACHE_H__

#include <string>
#include <shared_mutex>
#include <map>
#include <utility>
#include "service_models.h"

typedef std::map<std::string, std::map<std::string, std::pair<unsigned int, long>>> MemoryCache;

class PresenceCache
{

public:
    virtual ~PresenceCache(){}
    virtual UpdatedPresence UpdatePresence(const PresenceUpdate update) const = 0;

private:
    mutable std::shared_mutex mutex_;
    MemoryCache cache_;
};

#endif // __PRESENCE_CACHE_H__