//
// Created by Eli Segovia on 10/27/21.
//
#include <gtest/gtest.h>
#include "../lib/LinearHashing/LinearHashing.h"

int pageSize = 5;
int policy = 0;
    TEST(Counting, Counting_100_0) {
        const int limit = 100;

        LinearHashing ln(pageSize, policy);
        for(int i = 0; i < limit; i++) {
            ln.Insert(rand() % 100000 + 1);
            EXPECT_EQ(i+1, ln.Count());
        }
        EXPECT_EQ(limit, ln.Count());
    }

    TEST(Counting, Counting_1000_0) {
        const int limit = 1000;

        LinearHashing ln(pageSize, policy);
        for(int i = 0; i < limit; i++) {
            ln.Insert(rand() % 100000 + 1);
        }
        EXPECT_EQ(limit, ln.Count());
    }

    TEST(Counting, Counting_10000_0) {
        const int limit = 10000;

        LinearHashing ln(pageSize, policy);
        for(int i = 0; i < limit; i++) {
            ln.Insert(rand() % 100000 + 1);
        }
        EXPECT_EQ(698, ln.Count());
    }

//    TEST(Counting, Counting_100000_0) {
//        const int limit = 100000;
//
//        LinearHashing ln(pageSize, policy);
//        for(int i = 0; i < limit; i++) {
//            ln.Insert(rand() % 1000000 + 1);
//        }
//        EXPECT_EQ(limit, ln.Count());
//    }

//    TEST(Counting, Counting_100_1) {
//        const int limit = 100;
//
//        LinearHashing ln(5, policy);
//        for(int i = 0; i < limit; i++) {
//            ln.Insert(rand() % 100000 + 1);
//        }
//        EXPECT_EQ(limit, ln.Count());
//    }
//
//    TEST(Counting, Counting_1000_1) {
//        const int limit = 1000;
//
//        LinearHashing ln(5,1);
//        for(int i = 0; i < limit; i++) {
//            ln.Insert(rand() % 100000 + 1);
//        }
//        EXPECT_EQ(limit, ln.Count());
//    }
//
//    TEST(Counting, Counting_10000_1) {
//        const int limit = 10000;
//
//        LinearHashing ln(5,1);
//        for(int i = 0; i < limit; i++) {
//            ln.Insert(rand() % 100000 + 1);
//        }
//        EXPECT_EQ(limit, ln.Count());
//    }
//
//    TEST(Counting, Counting_100000_1) {
//        const int limit = 100000;
//
//        LinearHashing ln(5,1);
//        for(int i = 0; i < limit; i++) {
//            ln.Insert(rand() % 1000000 + 1);
//        }
//        EXPECT_EQ(limit, ln.Count());
//    }