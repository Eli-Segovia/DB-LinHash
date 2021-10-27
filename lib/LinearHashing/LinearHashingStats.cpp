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

unsigned int LinearHashingStats::Count(){
    return this->_Count;
}

unsigned int LinearHashingStats::Buckets(){
    return this->_Buckets;
}

unsigned int LinearHashingStats::Pages(){
    return this->_Pages;
}

unsigned int LinearHashingStats::OverflowBuckets(){
    return this->_OverflowBuckets;
}

unsigned int LinearHashingStats::Access(){
    return this->_Access;
}

unsigned int LinearHashingStats::AccessInsertOnly(){
    return this->_AccessInsertOnly;
}

unsigned int LinearHashingStats::SplitCount(){
    return this->_SplitCount;
}