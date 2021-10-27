//
// Created by Eli Segovia on 10/25/21.
//

#ifndef DB_LINHASH_LINEARHASHING_HPP
#define DB_LINHASH_LINEARHASHING_HPP

#include <ostream>
#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <exception>
#include <string>
#include <bitset>
#include "LinearHashingStats.hpp"


struct LinearHashing_InvalidParameter : public std::exception {
    const char * what () const throw () {
        return "Error with the paramaters provided to LinearHashing";
    }
};


class LinearHashing {

// private members
private:
    unsigned int mod_factor;   // maintains level of hashtable

    bool split_factor;         // flag to see if bucket is split

    unsigned int next_split;   // tells what bucket is going to be split

    unsigned int pageSize;     // bucket size

    LinearHashingStats LHStats;                                        // object that stores some stats

    std::vector< std::vector<int>* > Buckets;                          // the hash table itself

    std::function<bool(LinearHashing&, int inserted_bucket)> Split;    // the function object to perform splits


// private methods
private:
    bool split0(int bucket_idx);

    bool split1(int bucket_idx);

    bool split2(int bucket_idx);

    bool split3(int bucket_idx);


    void do_split();

    int get_bucket_idx(int x) const;

    void update_state();

    void print_bin(std::ostream& os, int idx, bool is_split);





public:
    LinearHashing(int pagesize, int policy = 0, int maxoverflow = 0, float sizelimit = 1.0f);

    bool Insert(int x);

    int Search(int x);

    void Print(std::ostream& os);

    int Count();

    std::vector<int> ListBucket(int x);

    LinearHashingStats GetStats();





};


#endif //DB_LINHASH_LINEARHASHING_HPP
