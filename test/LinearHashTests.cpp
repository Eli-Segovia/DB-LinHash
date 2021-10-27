//
// Created by Eli Segovia on 10/27/21.
//
#include <gtest/gtest.h>
#include "../lib/LinearHashing/LinearHashing.hpp"

TEST(LinearHashTests, Counting_100) {

    LinearHashing ln(5,0);
    for(int i = 0; i < 100; i++) {
        ln.Insert(rand() % 1000 + 1);
    }
    EXPECT_EQ(100, ln.Count());
}

TEST(LinearHashTests, Counting_1000) {

    LinearHashing ln(5,0);
    for(int i = 0; i < 1000; i++) {
        ln.Insert(rand() % 1000 + 1);
    }
    EXPECT_EQ(1000, ln.Count());
}

