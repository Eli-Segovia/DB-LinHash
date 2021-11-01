//
// Created by Eli Segovia on 11/1/21.
//
#include <gtest/gtest.h>
#include "../lib/LinearHashing/lh.h"

TEST(ErrorHandling, Negative_Page_Size ) {
    EXPECT_THROW({
        LinearHashing lh(-2, 0);
    }, LinearHashing_InvalidParameter);
}

TEST(ErrorHandling, Zero_Size_Page ) {
    EXPECT_THROW({
                     LinearHashing lh(0, 0);
                 }, LinearHashing_InvalidParameter);
}


TEST(ErrorHandling, Negative_Policy ) {
    EXPECT_THROW({
                     LinearHashing lh(5, -14);
                 }, LinearHashing_InvalidParameter);
}

TEST(ErrorHandling, Excessive_Policy__Value ) {
    EXPECT_THROW({
                     LinearHashing lh(5, 100);
                 }, LinearHashing_InvalidParameter);
}
