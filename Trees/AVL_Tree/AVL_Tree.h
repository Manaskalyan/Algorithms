#pragma once

#include <iostream>
#include "BTree.h"

namespace mk{
    
    /* Wanna extend BST tree to AVL tree */
    class AVL_Tree:public BST { 
        private:
            int if_node_out_of_balance(Node *node);
            /*Fix me : Left child as a param is redundant */
            int balance_subtree(Node* node, Node* parent, int left_child);
            int set_height(Node* node);
            
        public:
            AVL_Tree(); //Default custom constructor
            /* For an AVL tree object, this insert overrides BST insert */
            int insert(Node * root, Node *parent, int data);

    };
}
