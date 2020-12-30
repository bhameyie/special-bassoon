#include "presence_cache.h"
#include "service_models.h"
#include <shared_mutex>
#include <memory>
#include <optional>

using namespace std;

class PresenceCacheImpl : public PresenceCache
{
private:
    mutable std::shared_mutex mutex_;

public:
    PresenceCacheImpl()
    {
        cache_ = std::make_shared<MemoryCache>();
    }

    UpdatedPresence UpdatePresence(const PresenceUpdate update) const override
    {
        return UpdatedPresence();
    }

    unique_ptr<vector<RecordedPresence>> GetAllByUserId(const string userId) const override
    {
        return nullptr;
    }
    
    optional<RecordedPresence> Get(const string userId, const string deviceId) const override
    {
        return {};
    }

    shared_ptr<MemoryCache> Get() const override
    {
        return cache_;
    }
};