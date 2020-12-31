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
        std::unique_lock lock(mutex_);

        auto existingItem = cache_->find(update.user_id);
        if (existingItem == cache_->end())
        {
            StatusTimestamp statusPair{update.status_id, update.last_seen_timestamp};

            DeviceMapping deviceMap;
            deviceMap.insert({update.device_id, statusPair});

            cache_->insert({update.user_id, deviceMap});
        }
        else
        {
            auto existingDeviceMapping = existingItem->second.find(update.user_id);

            existingItem->second.insert_or_assign(update.device_id, StatusTimestamp{update.status_id, update.last_seen_timestamp});

            int deviceCount = existingItem->second.size();
            if (deviceCount > 1)
            {
                long max = -1;
                unsigned int status = 0;
                for (auto const &[key, val] : existingItem->second)
                {
                    if (val.second > max)
                    {
                        status = val.first;
                        max = val.second;
                    }
                }

                return UpdatedPresence{
                    update.user_id,
                    status};
            }
        }

        return UpdatedPresence{
            update.user_id,
            update.status_id};
    }

    unique_ptr<vector<RecordedPresence>> GetAllByUserId(const string userId) const override
    {
        std::shared_lock lock(mutex_);
        return nullptr;
    }

    optional<RecordedPresence> Get(const string userId, const string deviceId) const override
    {
        std::shared_lock lock(mutex_);
        return {};
    }

    /**
 * @brief returns the inner cache dictonary [Testing ONLY]. 
 * can result in deadlocks in theory
 * 
 * @return shared_ptr<MemoryCache> 
 */
    shared_ptr<MemoryCache> Get() const override
    {
        return cache_;
    }
};