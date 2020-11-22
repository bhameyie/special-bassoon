#include "gtest/gtest.h"
#include <receiptservice/Yello.hpp>

TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(4,  meh(2));
}

/*
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <receiptservice/Yello.hpp>

TEST_CASE( "Quick check", "[main]" ) {
    REQUIRE( meh(2) == 2.0 );
}
*/