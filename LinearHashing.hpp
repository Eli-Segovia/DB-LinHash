//
// Created by Eli Segovia on 10/25/21.
//

#ifndef DB_LINHASH_LINEARHASHING_HPP
#define DB_LINHASH_LINEARHASHING_HPP

#include <ostream>
#include <vector>
#include "LinearHashing.hpp"


class LinearHashing {
private:
    int pagesize;
    LinearHashingStats* LHStats = new LinearHashinStats();

public:
    LinearHashing(int pagesize, int policy, int maxoverflow, float sizelimit);

    bool Insert(int x);

    int Search(int x);

    void Print(std::ostream& os);

    int Count();

    std::vector<int> ListBucket(int x);

    LinearHashingStats GetStats();





};


#endif //DB_LINHASH_LINEARHASHING_HPP
