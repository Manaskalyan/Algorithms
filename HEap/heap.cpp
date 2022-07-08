#include "heap.h"

namespace mk{

    void MinHeap::swap(int index1, int index2) {

        int tmp;
        tmp = vec[index1];
        vec[index1] = vec[index2];
        vec[index2] = tmp;
    }
    
    int MinHeap::heapify_upon_insert(int index) {

        if (index == 1) {
            return 0;
        }

        else {
            if (vec[index / 2] > vec [index]) {
                swap(index / 2, index);
                heapify_upon_insert(index / 2);
                return 0;
            }
            else {
                return 0;
            }
        }


    }
    int MinHeap::insert(int value){

        if(vec.empty()) {
            vec.push_back(value);
            return 0;
        }
        else {
            int index;
            vec.push_back(value);
            index = vec.size();

            if (vec[index / 2] > value) {
                heapify_upon_insert(index);
            }
        }
        return 0;
    }

    int MinHeap::remove_min(){

        int index;
        index = vec.size(); //My idea is to get last element index with this function

        swap(0, index); //Swap root and the last element

        vec.pop_back(); //removes the min element

        heapify_upon_delete(0);




        return 0;

    }

    int MinHeap::heapify_upon_delete(int index) {

        int left_child_index, right_child_index;

        if (vec[index] < vec[left_child_index] && vec[index] < vec[right_child_index]) {
            return 0;
        }
        else {
            //swap index with min of left child and right child and continue this process till you hit end 
        }
        return 0;
    }
}