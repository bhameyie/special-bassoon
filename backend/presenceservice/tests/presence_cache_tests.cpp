#include "gtest/gtest.h"
#include "utils.cpp"
#include "presence_cache.cpp"
#include <thread>
#include <optional>
#include <algorithm>
#include <vector>

long currentTime = getCurrentTimestamp();

TEST(PresenceCacheShould, HoldNoDataInitially)
{
    PresenceCacheImpl sut;

    EXPECT_EQ(0, sut.Get()->size());
}

TEST(PresenceCacheShould, RecordInserts)
{
    const PresenceUpdate update{
        "kaboom", "elDevice", 1, currentTime};

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
        "Remy", "elDevice", 2, currentTime};

    const PresenceUpdate leDevice_updated{
        "Remy", "leDevice", 2, currentTime};

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
        "Remy", "elDevice", 3, currentTime + 1000};

    const PresenceUpdate leDevice_updated{
        "Remy", "leDevice", 2, currentTime};

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
        "kaboom", "elDevice", 1, currentTime};

    const PresenceUpdate leDevice{
        "Remy", "leDevice", 1, currentTime};

    const PresenceUpdate leDevice_updated{
        "Remy", "leDevice", 2, currentTime};

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

class PresenceCacheRetrievalShould : public ::testing::Test
{
protected:
    void SetUp() override
    {
        const PresenceUpdate c3{
            "kaboom", "c3", 1, currentTime};

        const PresenceUpdate a1{
            "Remy", "a1", 1, currentTime};

        const PresenceUpdate b2{
            "Remy", "b2", 2, currentTime+1000};

        const PresenceUpdate e5{
            "Remy", "e5", 2, currentTime - 5*60*1000 - 1};

        const PresenceUpdate e6{
            "Ray", "e6", 2, currentTime - 5*60*1000 - 1};

        sutRetrieval_.UpdatePresence(c3);
        sutRetrieval_.UpdatePresence(b2);
        sutRetrieval_.UpdatePresence(a1);
        sutRetrieval_.UpdatePresence(e5);
        sutRetrieval_.UpdatePresence(e6);
    }

    PresenceCacheImpl sutRetrieval_;
};

TEST_F(PresenceCacheRetrievalShould, RetrieveEmptyVectorWhenNoUserRecordMatchesOnGetAllByUserId)
{

    const auto statuses = sutRetrieval_.GetAllByUserId("Yo");

    EXPECT_EQ(0, statuses.size());
}

TEST_F(PresenceCacheRetrievalShould, ReturnsMostRecentOnGetLatestById)
{

    const auto found = sutRetrieval_.GetLatestById("Remy");
    EXPECT_TRUE(found.has_value());

    const auto inner = found.value();
    EXPECT_EQ("Remy", inner.user_id);
    EXPECT_EQ("b2", inner.device_id);
    EXPECT_EQ(2, inner.status_id);
}

TEST_F(PresenceCacheRetrievalShould, ReturnAllStatusesFromUserDevices)
{

    const auto statuses = sutRetrieval_.GetAllByUserId("Remy");

    EXPECT_EQ(2, statuses.size());

    EXPECT_EQ("a1", statuses[0]->device_id);
    EXPECT_EQ("b2", statuses[1]->device_id);

    for (auto const &el : statuses)
    {
        EXPECT_EQ("Remy", el->user_id);
    }
}

TEST_F(PresenceCacheRetrievalShould, RetrieveSingleStatusByDeviceIdWhenOneExists)
{
    const std::optional<RecordedPresence> found = sutRetrieval_.Get("kaboom", "c3");
    EXPECT_TRUE(found.has_value());

    const auto inner = found.value();
    EXPECT_EQ("kaboom", inner.user_id);
    EXPECT_EQ("c3", inner.device_id);
    EXPECT_EQ(1, inner.status_id);
    EXPECT_EQ(currentTime, inner.last_seen_timestamp);
}

TEST_F(PresenceCacheRetrievalShould, ReturnNothingWhenRetrieveSingleStatusByDeviceIdAndNoneExists)
{
    EXPECT_FALSE(sutRetrieval_.GetLatestById("nada").has_value());
    EXPECT_FALSE(sutRetrieval_.Get("nada", "c3").has_value());
    EXPECT_FALSE(sutRetrieval_.Get("kaboom", "boom").has_value());
}

TEST_F(PresenceCacheRetrievalShould, RemovesUserCompletelyWhenAllDevicesInactiveOnGetLatestById)
{
    EXPECT_EQ(1, sutRetrieval_.Get()->at("Ray").size());
    EXPECT_FALSE( sutRetrieval_.GetLatestById("Ray").has_value());
}

TEST_F(PresenceCacheRetrievalShould, EvictDevicesWhenDataIsOlderThan5MinutesOnGetLatestById)
{
    EXPECT_EQ(3, sutRetrieval_.Get()->at("Remy").size());
    sutRetrieval_.GetLatestById("Remy");
    EXPECT_EQ(2, sutRetrieval_.Get()->at("Remy").size());
}

TEST_F(PresenceCacheRetrievalShould, RemovesUserCompletelyWhenAllDevicesInactiveOnGet)
{
    EXPECT_FALSE( sutRetrieval_.Get("Ray", "e6").has_value());
}

TEST_F(PresenceCacheRetrievalShould, EvictDevicesWhenDataIsOlderThan5MinutesOnGet)
{
    EXPECT_FALSE( sutRetrieval_.Get("Remy", "e5").has_value());
}
