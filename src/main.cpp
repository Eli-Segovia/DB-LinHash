#include <iostream>
#include "../lib/LinearHashing/lh.h"

int main () {
    LinearHashing lh(3, 1,4);

    lh.Insert(0);
    lh.Insert(8);
    lh.Insert(16);

    lh.Insert(48);
    lh.Insert(8);

    lh.Insert(1);
    lh.Insert(9);
    lh.Insert(33);

    lh.Insert(5);
    lh.Insert(5);
    lh.Insert(13);

    lh.Insert(5);

    lh.Insert(8);
    lh.Insert(16);

    lh.Insert(32);

    lh.Insert(5);
    lh.Insert(5);

    lh.Insert(2);



    lh.Print(std::cout);

    std::cout << "This table has a total of " << lh.GetStats().OverflowBuckets() << " over Buckets" <<std::endl;
    std::cout << lh.Search(2) << std::endl;


}