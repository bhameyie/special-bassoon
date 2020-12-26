#include "gtest/gtest.h"
//#include <presenceservice/Yello.hpp>
#include <iostream>
#include "Yello.cpp"
//#include <memory>
#include <string>


TEST(sample_test_case, sample_test)
{
    //GreeterClient greeter(grpc::CreateChannel(
    //        "localhost:50051", grpc::InsecureChannelCredentials()));

    EXPECT_EQ(10,  meh(2));
}

/*
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <presenceservice/Yello.hpp>

TEST_CASE( "Quick check", "[main]" ) {
    REQUIRE( meh(2) == 2.0 );
}
*/