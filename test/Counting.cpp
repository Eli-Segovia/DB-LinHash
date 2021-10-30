//
// Created by Eli Segovia on 10/27/21.
//
#include <gtest/gtest.h>
#include "../lib/LinearHashing/LinearHashing.h"

struct helper{
public:
    int policy = 0;
    int pageSize = 5;
public:
    void Policy(int a) {this->policy = a;}
    void PageSize(int a) {this->pageSize = a;}
};

helper h = helper();

TEST(Counting, Counting_100_0) {
    const int limit = 100;

    LinearHashing ln(h.pageSize, h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
        EXPECT_EQ(i+1, ln.Count());
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_1000_0) {
    const int limit = 1000;

    LinearHashing ln(h.pageSize, h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_10000_0) {
    const int limit = 10000;

    LinearHashing ln(h.pageSize, h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_100000_0) {
    const int limit = 100000;

    LinearHashing ln(h.pageSize, h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 1000000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}


TEST(Counting, Counting_100_1) {
    h.Policy(1);
    const int limit = 100;

    LinearHashing ln(h.pageSize, h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_1000_1) {
    const int limit = 1000;

    LinearHashing ln(h.pageSize, h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_10000_1) {
    const int limit = 10000;

    LinearHashing ln(h.pageSize,h.pageSize);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_100000_1) {
    const int limit = 100000;

    LinearHashing ln(h.pageSize,h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 1000000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}


TEST(Counting, Counting_100_2) {
    h.Policy(2);
    const int limit = 100;

    LinearHashing ln(h.pageSize, h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_1000_2) {
    const int limit = 1000;

    LinearHashing ln(h.pageSize,h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_10000_2) {
    const int limit = 10000;

    LinearHashing ln(h.pageSize,h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_100000_2) {
    const int limit = 100000;

    LinearHashing ln(h.pageSize,h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 1000000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_100_3) {
    h.Policy(3);
    const int limit = 100;

    LinearHashing ln(h.pageSize, h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_1000_3) {
    const int limit = 1000;

    LinearHashing ln(h.pageSize,h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_10000_3) {
    const int limit = 10000;

    LinearHashing ln(h.pageSize,h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 100000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}

TEST(Counting, Counting_100000_3) {
    const int limit = 100000;

    LinearHashing ln(h.pageSize,h.policy);
    for(int i = 0; i < limit; i++) {
        ln.Insert(rand() % 1000000 + 1);
    }
    EXPECT_EQ(limit, ln.Count());
}
