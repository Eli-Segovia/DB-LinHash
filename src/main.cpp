#include <iostream>
#include "../lib/LinearHashing/LinearHashing.h"
#include <gtest/gtest.h>

int main () {
        LinearHashing lh(3, 2, 1,.75f);

        for(int i = 0; i < 10; i++) {
            lh.Insert(rand() % 1000000 + 1);
        }

        lh.Print(std::cout);

        std::cout << "This table has a total o" << lh.GetStats().Buckets() << " Buckets" <<std::endl;
        std::cout << lh.Search(64) << std::endl;


}