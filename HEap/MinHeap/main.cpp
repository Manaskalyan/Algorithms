#include <iostream>
#include "heap.h"

using namespace mk;

int main() {

    MinHeap heap_obj;

    heap_obj.insert(45);
    heap_obj.insert(32);
    heap_obj.display_heap();

    heap_obj.insert(26);
    heap_obj.display_heap();

    heap_obj.insert(39);
    heap_obj.display_heap();

    heap_obj.remove_min();
    heap_obj.display_heap();

    heap_obj.insert(28);
    heap_obj.display_heap();

    heap_obj.insert(31);
    heap_obj.display_heap();

    heap_obj.remove_min();
    heap_obj.display_heap();

    





    
  return 0;
}