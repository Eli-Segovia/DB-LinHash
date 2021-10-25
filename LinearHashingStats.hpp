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




};


#endif //DB_LINHASH_LINEARHASHINGSTATS_HPP
