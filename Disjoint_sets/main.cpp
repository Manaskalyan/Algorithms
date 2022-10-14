#include <iostream>
#include "disjoint_set.h"



int main() {

    Disjoint_set set1(10);

    for (int i = 0; i < 10; i++){
        std::cout << set1.vec[i] << " " ;
    }
    std::cout << std::endl;

    set1.union_sets(0,1);
    set1.union_sets(1,2);
    set1.union_sets(2,3);
    set1.union_sets(3,4);
    set1.union_sets(4,5);
    set1.union_sets(5,6);
    set1.union_sets(6,7);
    set1.union_sets(7,8);
    set1.union_sets(8,9);
    
    for (int i = 0; i < 10; i++){
        std::cout << set1.vec[i] << " " ;
    }

    for (int i = 0; i < 10; i++){
        std::cout << set1.size_vec[i] << " " ;
    }
    std::cout<<std::endl;

    set1.find(1);

    for (int i = 0; i < 10; i++){
        std::cout << set1.vec[i] << " " ;
    }

    for (int i = 0; i < 10; i++){
        std::cout << set1.size_vec[i] << " " ;
    }
    std::cout<<std::endl;
    

    return 0;
}