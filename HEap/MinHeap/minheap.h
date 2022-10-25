/**
 * @file minheap.h
 * @author Manas <manaskalyan98@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 * TODO : Think of Heap Sort using this
 * 
 */
#pragma once
#define NO_EXEC_ISSUES 0

#include <vector>
#include <iostream>

using namespace std;

namespace mk {
    class MinHeap {
        private:
            std::vector<int> vec_;

            /**
             * @brief Heapify upon insert
             *        Upon insertion of a data Heap property can get disturbed
             *        For every node, vlaue < RST, LST for a min Heap.
             *        Correct it. 
             * 
             * @param  index 
             * @return NO_EXEC_ISSUES   if everything goes well
             */
            int32_t _heapify_upon_insert(int index);

            /**
             * @brief Heapify upon delete
             *        Upon deletion of minimum node, (first node) it will become two trees.
             *        This will fix it.
             * 
             * @param  index     
             * @return NO_EXEC_ISSUES   if everything goes well 
             */
            int32_t _heapify_upon_delete(int index);

            /**
             * @brief Swap two elements of vector
             * 
             * @param index1 
             * @param index2 
             * @return * int32_t 
             */
            int32_t _swap(int index1, int index2);

        public:
            /**
             * @brief Insert a integer data into heap
             * 
             * it takes logn time
             * 
             * @param value     Data value to be inserted
             * @return NO_EXEC_ISSUES  if insertion was proper
             */
            int32_t insert(int value);
            /**
             * @brief Removes the minimum value from the heap
             * 
             * @return NO_EXEC_ISSUES if deletion was proper
             */
            int32_t remove_min();

            /**
             * @brief Displays values of heap
             * 
             * @return NO_EXEC_ISSUES if everything is fine 
             */
            int32_t display_heap();

            //TODO: Think of a constructor
            //TODO: Think of copy constructor
            //TODO: Destructor
            //TODO: Assignment operator
            //TODO : Heap Sort using this
    };
}