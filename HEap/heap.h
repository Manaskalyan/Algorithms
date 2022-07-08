#pragma once

#include <vector>

namespace mk {
    class MinHeap {
        private:
            vector<int> vec;
            int heapify_upon_insert(int index);
            int heapify_upon_delete(int index);
            void swap(int index1, int index2);
        public:
            int insert(int value);
            int remove_min();
    };
}