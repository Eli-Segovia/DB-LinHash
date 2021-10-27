//
// Created by Eli Segovia on 10/25/21.
//

#include "LinearHashing.hpp"


LinearHashing::LinearHashing(int pagesize, int policy, int maxoverflow , float sizelimit)
    : LHStats(), Buckets(1), mod_factor(1), next_split(0), split_factor(0) {

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

    bool has_split = this->Split(*this, bucket_idx);
    update_state();

    this->LHStats._Count++;

    return has_split;
}


int LinearHashing::Search(int x) { /* TODO */
    return 3;
}


void LinearHashing::Print(std::ostream& os) {
    const int split_buckets = this->Buckets.size() - (this->mod_factor);
    const int level = this->mod_factor - 1;
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


// split and move ints around...
void LinearHashing::do_split() {
//    std::cout << " a split has occurred" << std::endl;
    if (!this->split_factor) {       // set split flag to 1
        this->split_factor = 1;
    }

    this->Buckets.push_back(new std::vector<int>);  // push new bucket

    auto split_bucket = this->Buckets[this->next_split];  // reference to the split bucket

    auto new_bucket  = this->Buckets.back();

    for (int i = 0; i < split_bucket->size();) {         // go through the split bucket

        const int new_bucket_idx = get_bucket_idx(split_bucket->at(i));      // get value new bucket

        if(new_bucket_idx != this->next_split) {                           // if it's in a new bucket, move it.
            std::swap(split_bucket->at(i), split_bucket->back());

            int rehashed_value = split_bucket->back();

            split_bucket->pop_back();

            new_bucket->push_back(rehashed_value);
        }
        else {
            i++;
        }
    }
    this->next_split++;
}


/*
 * A split occurs when an insertion to a bucket and that bucket
 * overflows [or is already overflowing] (as described by the slide)
 */
bool LinearHashing::split0(int bucket_idx) {
    auto curr_bucket = this->Buckets[bucket_idx];
    if (curr_bucket->size() > this->pageSize) {
        do_split();
    }
    return split_factor;
}


bool LinearHashing::split1(int bucket_idx) {
    return split_factor;
}

bool LinearHashing::split2(int bucket_idx) {
    return split_factor;
}

bool LinearHashing::split3(int bucket_idx) {
    return split_factor;
}