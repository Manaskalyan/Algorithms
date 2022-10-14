#include <iostream>
#include "Btree.h"
#include "AVL_Tree.h"

int main(){

    mk::AVL_Tree mk_tree;

    mk_tree.root_node = nullptr;


    /* Left elbow */
    mk_tree.insert(mk_tree.root_node, nullptr, 3);
    mk_tree.insert(mk_tree.root_node, nullptr, 1);
    mk_tree.insert(mk_tree.root_node, nullptr, 2);

    mk_tree.traverse_ascending_order(mk_tree.root_node);




    return 0;
}