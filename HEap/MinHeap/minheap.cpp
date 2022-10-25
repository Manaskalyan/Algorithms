#include "minheap.h"

namespace mk{

    int32_t MinHeap::display_heap() {

        int i;
        for (i = 0; i < vec_.size(); i++) {
            cout << vec_[i] << " ";
        }
        cout << endl;

        return NO_EXEC_ISSUES;

    }

    int32_t MinHeap::_swap(int index1, int index2) {

        int tmp;
        tmp = vec_[index1];
        vec_[index1] = vec_[index2];
        vec_[index2] = tmp;

        return NO_EXEC_ISSUES;
    }
    
    /* Assume index is start with 1. To access elemnt in vector, do a -1 */
    int32_t MinHeap::_heapify_upon_insert(int index)
    {

        if (index == 1) {
            return 0;
        }

        else {
            /* If parent value is  > child */
            if (vec_[ (index / 2) - 1] > vec_ [index - 1]) {
                _swap( (index / 2) - 1, index - 1);
                _heapify_upon_insert(index / 2);
                return 0;
            }
            else {
                return 0;
            }
        }


    }

    int32_t MinHeap::insert(int value)
    {

        if(vec_.empty()) {
            vec_.push_back(value);
            return 0;
        }
        else {
            // Nodes need to be addressed staring with 1 but access with 0 based index
            int index;
            vec_.push_back(value);
            index = vec_.size(); //size will give total num of elements

            if (vec_[(index / 2) - 1] > value) {
                _heapify_upon_insert(index);
            }
        }
        return 0;
    }

    int32_t MinHeap::remove_min(){

        int index;
        index = vec_.size();

        _swap(0, index - 1);

        vec_.pop_back(); //removes the min element

        _heapify_upon_delete(1);

        return NO_EXEC_ISSUES;

    }

    int MinHeap::_heapify_upon_delete(int index) {

        int left_child_index, right_child_index;
        left_child_index = 2 * index;
        right_child_index = 2 * index + 1;

        /*No leaves for this node */
        if (left_child_index > vec_.size()) {
            return 0;
        }

        /*Because it's a complete binary tree. If left child exists and right doesn't it means left_child is last*/
        if (left_child_index == vec_.size()) {

            if (vec_[left_child_index - 1] < vec_[index - 1]) {
                _swap(index - 1, left_child_index - 1);
               
                
            }
             return 0;

        }


        if (vec_[index -1] < vec_[left_child_index - 1] && vec_[index - 1] < vec_[right_child_index - 1]) {
            return 0;
        }
        else {
            //swap index with min of left child and right child and continue this process till you hit end
            if (vec_[left_child_index - 1] < vec_[right_child_index - 1]) {
                _swap(index - 1, left_child_index - 1);
                _heapify_upon_delete(left_child_index);
            }
            else {
                _swap(index - 1, right_child_index - 1);
                _heapify_upon_delete(right_child_index);
            }

            return 0;

            
        }
        return NO_EXEC_ISSUES;
    }
}