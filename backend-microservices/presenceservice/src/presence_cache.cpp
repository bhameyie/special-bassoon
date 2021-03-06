#include "presence_cache.h"
#include "service_models.h"
#include "utils.h"
#include <shared_mutex>
#include <memory>
#include <optional>
#include <vector>
#include <unordered_set>

using namespace std;

class PresenceCacheImpl : public PresenceCache {
 private:
  mutable std::shared_mutex mutex_;

  static bool ShouldEvict(const long &timestamp) {
    int threshold = 5 * 60 * 1000; //5 minutes
    return timestamp < bassoon::common::GetCurrentTimestamp() - threshold;
  }

 public:
  PresenceCacheImpl() {
    cache_ = std::make_shared<MemoryCache>();
  }


  UpdatedPresence UpdatePresence(const PresenceUpdate &update) const override {
    std::unique_lock lock(mutex_);

    auto existingItem = cache_->find(update.user_id);
    if (existingItem == cache_->end()) {
      StatusTimestamp statusPair{update.status_id, update.last_seen_timestamp};

      DeviceMapping deviceMap;
      deviceMap.insert({update.device_id, statusPair});

      cache_->insert({update.user_id, deviceMap});
    } else {
      existingItem->second.insert_or_assign(update.device_id,
                                            StatusTimestamp{update.status_id, update.last_seen_timestamp});

      int deviceCount = existingItem->second.size();
      if (deviceCount > 1) {
        long max = -1;
        unsigned int status = 0;
        for (auto const &[key, val] : existingItem->second) {
          if (val.second > max) {
            status = val.first;
            max = val.second;
          }
        }

        return UpdatedPresence{
            update.user_id,
            status
        };
      }
    }

    return UpdatedPresence{
        update.user_id,
        update.status_id
    };
  }

  std::vector<std::unique_ptr<RecordedPresence>> GetAllByUserId(const string &userId) override {
    std::shared_lock lock(mutex_);

    std::vector<std::unique_ptr<RecordedPresence>> items;

    auto existingItem = cache_->find(userId);

    if (existingItem != cache_->end()) {
      std::unordered_set<std::string> devicesForEviction;
      for (auto const &x : existingItem->second) {
        if (ShouldEvict(x.second.second)) {
          devicesForEviction.insert(x.first);
        } else {
          items.push_back(std::make_unique<RecordedPresence>(RecordedPresence{
              existingItem->first,
              x.first,
              x.second.first,
              x.second.second
          }));
        }
      }
      for (auto const &deviceName : devicesForEviction) {
        auto forEviction = existingItem->second.find(deviceName);
        existingItem->second.erase(forEviction);
      }
      if (existingItem->second.empty()) {
        cache_->erase(existingItem);
      }

    }

    return items;
  }

  optional<RecordedPresence> GetLatestById(const string &userId) const override {
    std::shared_lock lock(mutex_);

    auto existingItem = cache_->find(userId);

    if (existingItem != cache_->end()) {
      std::unordered_set<std::string> devicesForEviction;

      long max = -1;
      string device;

      for (auto const &[key, val] : existingItem->second) {
        if (ShouldEvict(val.second)) {
          devicesForEviction.insert(key);
        } else if (val.second > max) {
          device = key;
          max = val.second;
        }
      }

      for (auto const &deviceName : devicesForEviction) {
        auto forEviction = existingItem->second.find(deviceName);
        existingItem->second.erase(forEviction);
      }

      if (existingItem->second.empty()) {
        cache_->erase(existingItem);
      }

      if (max == -1) {
        return {};
      }

      RecordedPresence record;
      record.device_id = device;
      record.user_id = existingItem->first;
      record.last_seen_timestamp = max;
      record.status_id = existingItem->second[device].first;

      return record;
    }

    return {};
  }

  optional<RecordedPresence> Get(const string &userId, const string &deviceId) const override {
    std::shared_lock lock(mutex_);
    auto userDictionary = cache_->find(userId);
    if (userDictionary != cache_->end()) {
      auto deviceRecord = userDictionary->second.find(deviceId);

      if (deviceRecord != userDictionary->second.end()) {
        if (ShouldEvict(deviceRecord->second.second)) {
          userDictionary->second.erase(deviceRecord);
          if (userDictionary->second.empty()) {
            cache_->erase(userDictionary);
          }
          return {};
        }

        RecordedPresence record;
        record.device_id = deviceId;
        record.user_id = userId;
        record.last_seen_timestamp = deviceRecord->second.second;
        record.status_id = deviceRecord->second.first;

        return record;
      }
    }
    return {};
  }

  /**
* @brief returns the inner cache dictonary [Testing ONLY].
* can result in deadlocks in theory
*
* @return shared_ptr<MemoryCache>
*/
  shared_ptr<MemoryCache> Get() const override {
    //todo: leverage redis and eventing
    return cache_;
  }
};