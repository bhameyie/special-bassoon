#ifndef __PRESENCE_CACHE_H__
#define __PRESENCE_CACHE_H__

#include <string>
#include <map>
#include <utility>
#include <memory>
#include "service_models.h"
#include <optional>


using namespace std;

typedef map<string, map<string, pair<unsigned int, long>>> MemoryCache;


class PresenceCache
{

public:
    virtual ~PresenceCache(){}
    virtual UpdatedPresence UpdatePresence(const PresenceUpdate update) const = 0;
    
    //TODO: find how to make things "internal" like in C#
    virtual shared_ptr<MemoryCache> Get() const = 0;
    virtual unique_ptr<vector<RecordedPresence>> GetAllByUserId(const string userId) const = 0;
    virtual optional<RecordedPresence> Get(const string userId, const string deviceId) const = 0;

protected:
    shared_ptr<MemoryCache> cache_;
};
#endif // __PRESENCE_CACHE_H__
