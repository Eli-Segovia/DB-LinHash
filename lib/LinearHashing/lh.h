//
// Created by Eli Segovia on 10/25/21.
//

#ifndef DB_LINHASH_LINEARHASHING_HPP
#define DB_LINHASH_LINEARHASHING_HPP

#include <ostream>
#include <vector>
#include <iostream>
#include <math.h>
#include <functional>
#include <exception>
#include <string>


struct LinearHashing_InvalidParameter : public std::exception {
    const char * what () const throw () {
        return "Error with the paramaters provided to LinearHashing";
    }
};

class LinearHashingStats {

private:

    /*
     * The number of integers currently being stored
     * in the hashtable
     */
    int _Count;

    /*
     * The number of buckets in the hash table
     */
    int _Buckets;

    /*
     * the total number of pages in the hash table
     */
    int _Pages;

private:
    /*
     * The total number of overflow buckets
     */
    int _OverflowBuckets;

    /*
     * The number of pages (including overflow buckets)
     * accessed since the creation of the hashtable
     * (read and write of the same page are considered
     * two accesses)
     */
    int _Access;

private:

    /*
     * Number of buckets accessed during insertion
     */
    int _AccessInsertOnly;

    /*
     * num of splits that have occured
     */
    int _SplitCount;


public:

    LinearHashingStats();
    /* basically just getters */

    int Count();

    int Buckets();

    int Pages();

    int OverflowBuckets();

    int Access();

    int AccessInsertOnly();

    int SplitCount();

    friend class LinearHashing;

};


class LinearHashing {

// private members
private:
    unsigned int mod_factor;   // maintains level of hashtable

    unsigned int level;

    bool split_flag;         // flag to see if bucket is split

    unsigned int next_split;   // tells what bucket is going to be split

    unsigned int pageSize;     // bucket size

    unsigned int maxoverflow;

    float sizelimit;

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

    void update_bucket_state();

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
