#include <iostream>
#include "../lib/LinearHashing/LinearHashing.h"

int main () {
        LinearHashing lh(5, 1);

        for(int i = 0; i < 16; i++) {
            lh.Insert(rand() % 1000000 + 1);
        }

        lh.Print(std::cout);

        std::cout << "This table has a total of " << lh.GetStats().OverflowBuckets() << " over Buckets" <<std::endl;
        std::cout << lh.Search(64) << std::endl;


}