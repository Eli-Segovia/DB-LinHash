//
// Created by Eli Segovia on 10/25/21.
//

#include "LinearHashingStats.hpp"

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