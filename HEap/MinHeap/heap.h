#pragma once

#include <vector>
#include <iostream>

using namespace std;

namespace mk {
    class MinHeap {
        private:
            std::vector<int> vec;
            int heapify_upon_insert(int index);
            int heapify_upon_delete(int index);
            void swap(int index1, int index2);
        public:
            int insert(int value);
            int remove_min();
            void display_heap();
    };
}