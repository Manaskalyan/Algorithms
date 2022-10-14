#pragma once

#include <iostream>
#include <vector>


class Disjoint_set {

//private:

public:

    std::vector<int> vec;
    std::vector<int> size_vec;

    
    /*
     *  Finds the disjoint sets containing x and y, unions them
     */
    int union_sets(int x, int y);

    /*
     * Finds the element x and returns the representative element
     */
    int find(int x);

    /*
     * How do you think you should make sets?
     * Is it to start of with individual elemnets Manas and make them as representative elements?
     * It is to create n - elemets with representative elemets as -1. 
     */
    int make_set(int n);

    int add_element();

    Disjoint_set(int);

};