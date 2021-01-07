#ifndef __PRESENCE_CACHE_H__
#define __PRESENCE_CACHE_H__

#include <string>
#include <map>
#include <utility>
#include <memory>
#include "service_models.h"

using namespace std;

typedef pair<unsigned int, long> StatusTimestamp;

typedef map<string, StatusTimestamp> DeviceMapping;

typedef map<string, DeviceMapping> MemoryCache;

class PresenceCache {

 public:
  virtual ~PresenceCache() = default;
 [[nodiscard]] virtual UpdatedPresence UpdatePresence(const PresenceUpdate &update) const = 0;

  //TODO: find how to make things "internal" like in C#
  [[nodiscard]] virtual shared_ptr<MemoryCache> Get() const = 0;
  [[nodiscard]] virtual std::vector<std::unique_ptr<RecordedPresence>> GetAllByUserId(const string &userId) = 0;
  [[nodiscard]] virtual optional<RecordedPresence> GetLatestById(const string &userId) const = 0;
  [[nodiscard]] virtual optional<RecordedPresence> Get(const string &userId, const string &deviceId) const = 0;

 protected:
  shared_ptr<MemoryCache> cache_;
};
#endif // __PRESENCE_CACHE_H__
