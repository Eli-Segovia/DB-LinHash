//
// Created by Eli Segovia on 10/25/21.
//

#include "LinearHashing.hpp"


LinearHashing::LinearHashing(int pagesize, int policy, int maxoverflow , float sizelimit)
    : LHStats(), Buckets(1), mod_factor(1), next_split(0), split_factor(0) {

    this->maxoverflow = maxoverflow;
    this->sizelimit   = sizelimit;

    this->LHStats._Buckets = this->Buckets.size();

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
    const int bucket_idx = get_bucket_idx(x);

    this->Buckets[bucket_idx]->push_back(x);

    this->LHStats._AccessInsertOnly += 2; // read and write to the inserted bucket...


    this->LHStats._Count++;
    this->LHStats._Pages = std::ceil((this->LHStats.Count() + 0.0) / this->pageSize);
    update_bucket_state();
    bool has_split = this->Split(*this, bucket_idx);
    update_state();


    return has_split;
}


int LinearHashing::Search(int x) {
    auto curr_bucket = this->Buckets[this->get_bucket_idx(x)];
    this->LHStats._Access++;    // read bucket

    if (curr_bucket->size() == 0) return 0;

    for(int i = 0; i < curr_bucket->size(); i++) {
        if(curr_bucket->at(i) == x) {
            return ceil((i + 1.0)/this->pageSize);
        }
    }
    return 0 - ceil((curr_bucket->size()+0.0)/ this->pageSize);
}


void LinearHashing::Print(std::ostream& os) {
    const int split_buckets = this->Buckets.size() - (this->mod_factor);
    const int level = this->mod_factor / 2;
    int pg_cnt = 0;
    for (int i = 0; i < this->Buckets.size(); i++) {
        print_bin(os, i,i < split_buckets);
        os << ": ";
        for (int j = 0; j < this->Buckets.at(i)->size(); j++) {
            os << this->Buckets.at(i)->at(j);
            if (j % pageSize == pageSize - 1 && j != this->Buckets.at(i)->size() - 1) {
                os << " - ";
            }
            else
                os << " ";
        }
        os << std::endl;

    }
    os << "level: " << level << std::endl;
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
int LinearHashing::get_bucket_idx(int x) const {
    int bucket_idx = split_factor?
            x % (this->mod_factor * (split_factor * 2) ) :
            x % this->mod_factor;

    if (bucket_idx >= this->Buckets.size()) {     // correct if we have wrong...
        bucket_idx = x % this->mod_factor;
    }
    return bucket_idx;
}


void LinearHashing::update_state() {
    if (this->mod_factor * 2 == this->Buckets.size()) {
        this->mod_factor *= 2;
        this->split_factor = 0;
        this->next_split = 0;
    }
    update_bucket_state();
}


void LinearHashing::update_bucket_state() {
    this->LHStats._Buckets = ceil((this->LHStats.Count()+0.0) / pageSize);
    this->LHStats._OverflowBuckets = 0;
    for (auto bucket : this->Buckets) {
        if (bucket->size() > pageSize) {
            this->LHStats._OverflowBuckets += ceil((double)(bucket->size() - pageSize) / pageSize);
        }
    }
}



void LinearHashing::print_bin(std::ostream& os, int idx, bool is_split) {
    std::vector<bool> bool_arr;
    if (idx < mod_factor / 2) {
        for (int i = 0; i < mod_factor / 4; i++){
            os << "0";
        }
    }
    if(is_split) os << "0";
    do {
        bool_arr.push_back(idx % 2);
        idx = idx / 2;
    } while (idx != 0);

    for (int i = bool_arr.size() - 1; i >=0; i--){
        os << bool_arr[i];
    }

}


void LinearHashing::do_split() {
//    std::cout << " a split has occurred" << std::endl;
    if (!this->split_factor) {       // set split flag to 1
        this->split_factor = 1;
    }

    this->Buckets.push_back(new std::vector<int>);  // push new bucket
    this->LHStats._SplitCount++;

    auto split_bucket = this->Buckets[this->next_split];  // read the split bucket
    auto new_bucket  = this->Buckets.back();              // read the new bucket

    this->LHStats._AccessInsertOnly += 2; // read both new and split buckets

    for (int i = 0; i < split_bucket->size();) {

        const int new_bucket_idx = get_bucket_idx(split_bucket->at(i));      // get value new bucket hash

        if(new_bucket_idx != this->next_split) {                           // if it's in a new bucket, move it.
            std::swap(split_bucket->at(i), split_bucket->back());

            int rehashed_value = split_bucket->back();

            this->LHStats._AccessInsertOnly++;  // delete from split bucket.
            split_bucket->pop_back();

            this->LHStats._AccessInsertOnly++;  // write into the new bucket.
            new_bucket->push_back(rehashed_value);
        }
        else {
            i++;
        }
    }
    this->next_split++;
}


bool LinearHashing::split0(int bucket_idx) {
    auto curr_bucket = this->Buckets[bucket_idx];    // current bucket that we inserted into

    if (curr_bucket->size() > this->pageSize) {      // split if curr_bucket overflows.
        do_split();
    }

    return this->split_factor;
}


bool LinearHashing::split1(int bucket_idx) {

    if (this->LHStats.OverflowBuckets() >= this->maxoverflow) {    // if overflow buckets exceeds provided value, split
        do_split();
    }

    return this->split_factor;
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

    return this->split_factor;
}


bool LinearHashing::split3(int bucket_idx) {
    if (this->Buckets[this->next_split]->size() > pageSize) {        // simply get the size of the next_split bucket
        do_split();                                                  // if it bigger than pagesize, split
    }
    return this->split_factor;
}