//
// Created by Eli Segovia on 10/25/21.
//

#ifndef DB_LINHASH_LINEARHASHINGSTATS_HPP
#define DB_LINHASH_LINEARHASHINGSTATS_HPP


class LinearHashingStats {

private:

    /*
     * The number of integers currently being stored
     * in the hashtable
     */
    unsigned int _Count;

    /*
     * The number of buckets in the hash table
     */
    unsigned int _Buckets;

    /*
     * the total number of pages in the hash table
     */
    unsigned int _Pages;

private:
    /*
     * The total number of overflow buckets
     */
    unsigned int _OverflowBuckets;

    /*
     * The number of pages (including overflow buckets)
     * accessed since the creation of the hashtable
     * (read and write of the same page are considered
     * two accesses)
     */
    unsigned int _Access;

private:

    /*
     * Number of buckets accessed during insertion
     */
    unsigned int _AccessInsertOnly;

    /*
     * num of splits that have occured
     */
    unsigned int _SplitCount;



public:

    LinearHashingStats();
    /* basically just getters */

    unsigned int Count();

    unsigned int Buckets();

    unsigned int Pages();

    unsigned int OverflowBuckets();

    unsigned int Access();

    unsigned int AccessInsertOnly();

    unsigned int SplitCount();


    friend class LinearHashing;


};


#endif //DB_LINHASH_LINEARHASHINGSTATS_HPP
