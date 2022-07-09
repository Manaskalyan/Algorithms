#include "heap.h"

namespace mk{

    void MinHeap::display_heap() {

        int i;
        for (i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

    }

    void MinHeap::swap(int index1, int index2) {

        int tmp;
        tmp = vec[index1];
        vec[index1] = vec[index2];
        vec[index2] = tmp;
    }
    
    /* Assume index is start with 1. To access elemnt in vector, do a -1 */
    int MinHeap::heapify_upon_insert(int index) {

        if (index == 1) {
            return 0;
        }

        else {
            if (vec[ (index / 2) - 1] > vec [index - 1]) {
                swap( (index / 2) - 1, index - 1);
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
            // Nodes need to be addressed staring with 1 but access with 0 based index
            int index;
            vec.push_back(value);
            index = vec.size(); //size will give total num of elements

            if (vec[(index / 2) - 1] > value) {
                heapify_upon_insert(index);
            }
        }
        return 0;
    }

    int MinHeap::remove_min(){

        int index;
        index = vec.size();

        swap(0, index - 1);

        vec.pop_back(); //removes the min element

        heapify_upon_delete(1);




        return 0;

    }

    int MinHeap::heapify_upon_delete(int index) {

        int left_child_index, right_child_index;
        left_child_index = 2 * index;
        right_child_index = 2 * index + 1;

        /*No leaves for this node */
        if (left_child_index > vec.size()) {
            return 0;
        }

        /*Because it's a complete binary tree. If left child exists and right doesn't it means left_child is last*/
        if (left_child_index == vec.size()) {

            if (vec[left_child_index - 1] < vec[index - 1]) {
                swap(index - 1, left_child_index - 1);
               
                
            }
             return 0;

        }


        if (vec[index -1] < vec[left_child_index - 1] && vec[index - 1] < vec[right_child_index - 1]) {
            return 0;
        }
        else {
            //swap index with min of left child and right child and continue this process till you hit end
            if (vec[left_child_index - 1] < vec[right_child_index - 1]) {
                swap(index - 1, left_child_index - 1);
                heapify_upon_delete(left_child_index);
            }
            else {
                swap(index - 1, right_child_index - 1);
                heapify_upon_delete(right_child_index);
            }

            return 0;

            
        }
        return 0;
    }
}