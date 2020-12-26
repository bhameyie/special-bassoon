#include "gtest/gtest.h"
#include "presence_cache.cpp"

class PresenceCacheShould : public testing::Test
{
protected:
    void SetUp() override
    {
        
    }

    void TearDown() override{

    }

    PresenceCacheImpl sut_;
};

TEST_F(PresenceCacheShould, HoldNoDataInitially){
    
}