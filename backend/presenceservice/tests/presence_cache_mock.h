#ifndef __PRESENCE_CACHE_MOCK_H__
#define __PRESENCE_CACHE_MOCK_H__

#include <gmock/gmock.h>
#include "presence_cache.h"
#include "service_models.h"
#include <optional>
#include <memory>

using namespace std;

class PresenceCacheMock : public PresenceCache {
 public:
  MOCK_METHOD(UpdatedPresence, UpdatePresence, (const PresenceUpdate &update), (const,override));
  MOCK_METHOD(shared_ptr<MemoryCache>, Get,(), (const,override));
  MOCK_METHOD(std::vector<std::unique_ptr<RecordedPresence>>, GetAllByUserId, (const string &userId), ( override) );
  MOCK_METHOD(optional<RecordedPresence>, Get, (const string &userId, const string &deviceId), (const override) );
  MOCK_METHOD(optional<RecordedPresence>, GetLatestById, (const string &userId), (const override) );

};


#endif // __PRESENCE_CACHE_MOCK_H__