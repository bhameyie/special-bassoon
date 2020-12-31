#include "gtest/gtest.h"
#include "presence_cache.cpp"
#include <thread>

class PresenCacheOnRetrievalShould : public testing::Test
{
};

TEST(PresenceCacheShould, HoldNoDataInitially)
{
    PresenceCacheImpl sut;

    EXPECT_EQ(0, sut.Get()->size());
}

TEST(PresenceCacheShould, RecordInserts)
{
    const PresenceUpdate update{
        "kaboom", "elDevice", 1, 1609378878117};

    const UpdatedPresence expected{
        "kaboom", 1};

    PresenceCacheImpl sut;
    auto result = sut.UpdatePresence(update);
    EXPECT_EQ(expected.status_id, result.status_id);
    EXPECT_EQ(expected.user_id, result.user_id);
    EXPECT_EQ(1, sut.Get()->size());
}

TEST(PresenceCacheShould, AllowForMultipleDevicesPerUserWithTheSameStatus)
{
    const PresenceUpdate elDevice{
        "Remy", "elDevice", 2, 1609378878117};

    const PresenceUpdate leDevice_updated{
        "Remy", "leDevice", 2, 1609378878117};

    const UpdatedPresence expected{
        "Remy", 2};

    PresenceCacheImpl sut;
    auto result = sut.UpdatePresence(leDevice_updated);
    sut.UpdatePresence(elDevice);

    EXPECT_EQ(expected.status_id, result.status_id);
    EXPECT_EQ(expected.user_id, result.user_id);
    EXPECT_EQ(1, sut.Get()->size());
    EXPECT_EQ(2, sut.Get()->at("Remy").size());
}

TEST(PresenceCacheShould, AlwaysReturnTheMostRecentTimestamp)
{
    const PresenceUpdate elDevice{
        "Remy", "elDevice", 3, 1619378879117};

    const PresenceUpdate leDevice_updated{
        "Remy", "leDevice", 2, 1609378878207};

    const UpdatedPresence expected{
        "Remy", 3};

    PresenceCacheImpl sut;
    sut.UpdatePresence(elDevice);
    auto result = sut.UpdatePresence(leDevice_updated);

    EXPECT_EQ(expected.status_id, result.status_id);
    EXPECT_EQ(expected.user_id, result.user_id);
}

TEST(PresenceCacheShould, ReplaceAlreadyExistingRecords)
{
    const PresenceUpdate elDevice{
        "kaboom", "elDevice", 1, 1609378878117};

    const PresenceUpdate leDevice{
        "Remy", "leDevice", 1, 1609378878117};

    const PresenceUpdate leDevice_updated{
        "Remy", "leDevice", 2, 1609378878117};

    const UpdatedPresence expected{
        "Remy", 2};

    PresenceCacheImpl sut;
    sut.UpdatePresence(leDevice);
    auto result = sut.UpdatePresence(leDevice_updated);
    sut.UpdatePresence(elDevice);

    EXPECT_EQ(expected.status_id, result.status_id);
    EXPECT_EQ(expected.user_id, result.user_id);
    EXPECT_EQ(2, sut.Get()->size());
    EXPECT_EQ(1, sut.Get()->at("Remy").size());

}
