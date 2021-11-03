//
// Created by Eli Segovia on 10/25/21.
//

#include "lh.h"


/* Linear Hashing Stats */
LinearHashingStats::LinearHashingStats(){
    this->_Count = 0;
    this->_Buckets = 0;
    this->_Pages = 0;
    this->_OverflowBuckets = 0;
    this->_Access = 0;
    this->_AccessInsertOnly = 0;
    this->_SplitCount = 0;
}

int LinearHashingStats::Count(){
    return this->_Count;
}

int LinearHashingStats::Buckets(){
    return this->_Buckets;
}

int LinearHashingStats::Pages(){
    return this->_Pages;
}

int LinearHashingStats::OverflowBuckets(){
    return this->_OverflowBuckets;
}

int LinearHashingStats::Access(){
    return this->_Access + this->_AccessInsertOnly;
}

int LinearHashingStats::AccessInsertOnly(){
    return this->_AccessInsertOnly;
}

int LinearHashingStats::SplitCount(){
    return this->_SplitCount;
}






/* Linear Hashing */

/*
 * There is a difference between a bucket and a bucket collection.
 *
 * A bucket is essentially just a set of data. Its size is limited by the size of one page in this project.
 * In this project, buckets and pages are essentially interchangeable. Although, I imagine in the real world
 * a Bucket could potentially contain more than just one page. In this example, buckets hold only on page, and therefore,
 * both are essentially the same thing.
 *
 *
 * In this project, I am using a vector of vectors to hold all the buckets. The nested vectors are supposed to represent
 * the buckets. However, the nested vector can overflow, thereafter holding more than just one bucket. To these nested
 * vectors, I will refer as "Bucket collections", because they can potentially hold more than one bucket.
 */



LinearHashing::LinearHashing(int pagesize, int policy, int maxoverflow , float sizelimit)
    : LHStats(), Buckets(1), mod_factor(1), next_split(0), split_flag(0), level(0){

    this->maxoverflow = maxoverflow;
    this->sizelimit   = sizelimit;

    this->LHStats._Buckets = this->Buckets.size();

    // set Split function depending on what policy we have. If invalid parameters, then we throw a custom error msg
    this->pageSize = pagesize > 0? pagesize : throw LinearHashing_InvalidParameter();
    switch (policy) {
        case 0 : this->Split = &LinearHashing::split0;
            break;
        case 1 : this->Split = &LinearHashing::split1;
            break;
        case 2 : this->Split = &LinearHashing::split2;
            break;
        case 3 : this->Split = &LinearHashing::split3;
            break;
        default : throw LinearHashing_InvalidParameter();
    }

    this->Buckets[0] = new std::vector<int>;
}


bool LinearHashing::Insert(int x) {

    // get the corresponding bucket index of the inserted value.      ex: 00: [a, b, c] - [d, e, f] - [3]
    const int bucket_idx = get_bucket_idx(x);


    // push the value into the corresponding bucket collection. Since this is a vector, we will have to access N
    // items before we are able to append the new item. therefore, we have to access ceil(N / pageSize) buckets.
    this->Buckets[bucket_idx]->push_back(x);
    this->LHStats._AccessInsertOnly += ceil((this->Buckets[bucket_idx]->size() + 0.0) / pageSize);

    // finally we will simply write to the final page. So this is only one write.
    this->LHStats._AccessInsertOnly += 1;


    // increase the count of total integers since we have added one to the table.
    this->LHStats._Count++;

    // Update the total amount of pages in the table. Simply get the total count and divide by page size.
    this->LHStats._Pages = std::ceil((this->LHStats.Count() + 0.0) / this->pageSize);

    // update the bucket states to work with.
    update_bucket_state();

    // do the split
    bool has_split = this->Split(*this, bucket_idx);

    //update the state of hash table.
    update_state();

    return has_split;
}


int LinearHashing::Search(int x) {

    // get the bucket collection that the value should be inside.
    auto curr_bucket_collection = this->Buckets[this->get_bucket_idx(x)];

    // if empty, return 0.
    if (curr_bucket_collection->empty()) return 0;

    // go through the bucket collection. if we find the correct bucket, return count of pages accessed.
    for(int i = 0; i < curr_bucket_collection->size(); i++) {
        if(curr_bucket_collection->at(i) == x) {

            // if we find the right value, we update the total accesses and return
            this->LHStats._Access += ceil((i + 1.0)/ this->pageSize);
            return ceil((i + 1.0)/ this->pageSize);

        }
    }
    // if we never find it, that means we accessed all the pages in the bucket idx location.
    // therefore, we update the access stat and we simply return the negation of that.
    this->LHStats._Access += ceil((curr_bucket_collection->size()+0.0)/ this->pageSize);

    return 0 - ceil((curr_bucket_collection->size()+0.0)/ this->pageSize);
}


void LinearHashing::Print(std::ostream& os) {
    // get the total count of split buckets.
    const int split_buckets = this->Buckets.size() - (this->mod_factor);

    // go through the hashtable of buckets
    for (int i = 0; i < this->Buckets.size(); i++) {

        // print the index in binary form.
        print_bin(os, i,i < split_buckets);
        os << ": ";

        // go through each bucket and overflow bucket in the index.
        for (int j = 0; j < this->Buckets.at(i)->size(); j++) {

            // print the value.
            os << this->Buckets.at(i)->at(j);

            // print a dash if it's the end of the bucket.
            if (j % pageSize == pageSize - 1 && j != this->Buckets.at(i)->size() - 1) {
                os << " - ";
            }
            else
                os << " ";
        }
        os << std::endl;

    }

    // other stuff...
    os << "level: " << this->level << std::endl;
    os << "ptr: ";
    print_bin(os, this->next_split, this->next_split < split_buckets);
    os << std::endl;
}


int LinearHashing::Count() {
    return LHStats.Count();
}


std::vector<int> LinearHashing::ListBucket(int x) {
    return *this->Buckets[x];
}


LinearHashingStats LinearHashing::GetStats() {
    return this->LHStats;
}



/* private methods
 * ----------------------------------------------------------------------------------
 */

/*
 * Gets the corresponding bucket of the value that we pass in.
 */
int LinearHashing::get_bucket_idx(int x) const {
    int bucket_idx = split_flag?
            x % (this->mod_factor * (split_flag * 2) ) :
            x % this->mod_factor;

    if (bucket_idx >= this->Buckets.size()) {     // correct if we have wrong...
        bucket_idx = x % this->mod_factor;
    }
    return bucket_idx;
}

/*
 * Updates the state of some of the class variables. Also updates the buckets states.
 */
void LinearHashing::update_state() {
    if (this->mod_factor * 2 == this->Buckets.size()) {
        this->mod_factor *= 2;
        this->level++;
        this->split_flag = 0;
        this->next_split = 0;
    }
    update_bucket_state();
}

/*
 * updates the count of some class variables we use to keep tabs on the buckets.
 */
void LinearHashing::update_bucket_state() {
    this->LHStats._OverflowBuckets = 0;
    for (auto bucket : this->Buckets) {
        if (bucket->size() > pageSize) {
            this->LHStats._OverflowBuckets += ceil((double)(bucket->size() - pageSize) / pageSize);
        }
    }
    this->LHStats._Buckets = this->Buckets.size() + this->LHStats._OverflowBuckets;
}


/*
 * prints binary value of the number pass, as well as the considers whther the value is split so that it can add an
 * extra zero for padding.
 */
void LinearHashing::print_bin(std::ostream& os, int idx, bool is_split) {
    std::vector<bool> bool_arr;

    // convert to bin
    do {
        bool_arr.push_back(idx % 2);
        idx = idx / 2;
    } while (idx != 0);

    // fill to the level
    for (int i = bool_arr.size(); i < this->level; i++) os << "0";

    if(is_split) os << "0"; // fill if it is split

    // print the bin val
    for (int i = bool_arr.size() - 1; i >=0; i--){
        os << bool_arr[i];
    }

}

/*
 * actually does the split
 */
void LinearHashing::do_split() {
    if (!this->split_flag) {       // set split flag to 1
        this->split_flag = 1;
    }

    this->Buckets.push_back(new std::vector<int>);  // push new bucket collection

    // update the split count
    this->LHStats._SplitCount++;

    auto split_bucket_collection = this->Buckets[this->next_split];  // get the split bucket collection
    auto new_bucket_collection  = this->Buckets.back();              // get the new bucket collection


    // iterate through the split bucket collection
    // update the total number of pages read. We are iterating through all of the split bucket collection, so we can
    // assume that we are accessing all of the pages in the split bucket collection.
    this->LHStats._Access += ceil((split_bucket_collection->size() + 0.0) / this->pageSize);

    for (int i = 0; i < split_bucket_collection->size();) {
        const int new_bucket_idx = get_bucket_idx(split_bucket_collection->at(i));      // get value new bucket hash

        // if the bucket does not belong in the current index, then we need to add it to the next location.
        if(new_bucket_idx != this->next_split) {

            // swap the current index with the last index
            std::swap(split_bucket_collection->at(i), split_bucket_collection->back());

            // get the value of the integer that needs to move to the new bucket collection
            int rehashed_value = split_bucket_collection->back();

            // remove the integer from the old bucket. this counts as a "write" to one page
            this->LHStats._Access++;
            split_bucket_collection->pop_back();

            // write the integer into the new bucket. This counts as a write to the new page
            this->LHStats._Access++;
            new_bucket_collection->push_back(rehashed_value);
        }
        else {
            i++;
        }
    }
    this->next_split++;
}




/* Splitting Functions
 * --------------------------------------------------------
 * splitting functions all do about the same thing and call the main split function based on the criteria of the
 * policy provided in the constructor...
 */

bool LinearHashing::split0(int bucket_idx) {
    auto curr_bucket = this->Buckets[bucket_idx];    // current bucket that we inserted into

    if (curr_bucket->size() > this->pageSize) {      // split if curr_bucket overflows.
        do_split();
    }

    return this->split_flag;
}


bool LinearHashing::split1(int bucket_idx) {

    if (this->LHStats.OverflowBuckets() != 0 &&  this->LHStats.OverflowBuckets() >= this->maxoverflow) {    // if overflow buckets exceeds provided value, split
        do_split();
    }

    return this->split_flag;
}

bool LinearHashing::split2(int bucket_idx) {
    const int capacity = this->LHStats.Buckets() * this->pageSize;    // total capacity is amount of buckets * pageSize
                                                                      // ex. 2 Buckets (incl. overflow) of pageSize 3:
                                                                      // 0: [1, 2, 3] - [1,_,_] this is total capacity of 6.


    const int limit = floor(this->sizelimit * capacity);           // limit is floor of sizeLimit provided * capacity
                                                                     // ex. .75 * 6 => floor(4.5) = 4
    if (this->LHStats.Count() > limit) {
        do_split();
    }

    return this->split_flag;
}


bool LinearHashing::split3(int bucket_idx) {
    if (this->Buckets[this->next_split]->size() > pageSize) {        // simply get the size of the next_split bucket
        do_split();                                                  // if it bigger than pagesize, split
    }
    return this->split_flag;
}