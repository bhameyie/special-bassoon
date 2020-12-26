#include "presence_cache.h"
#include "service_models.h"


class PresenceCacheImpl : public PresenceCache
{
public:
    UpdatedPresence UpdatePresence(const PresenceUpdate update) const override
    {
        return UpdatedPresence();
    }
};