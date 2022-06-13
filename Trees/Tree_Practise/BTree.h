/**
 * BTree class outline.
 * 
 * @author
 *   Manas <manaskalyan98@gmail.com>
 */

#pragma once

#include <iostream>


namespace mk{

  class Node {

    public:

    int data;

    // pointers to Left child and right child
    Node * Left_child;  // Not sure if this syntax will work or not.
    Node * Right_child;

    int is_leaf();
    int print_node();   

  };

  //What my brain says is I don't know how to deal with private variables of this object yet
  //So don't worry about this stuff Manas.

  class BST {

    public:

    Node *root_node; // pointer to root node

    int insert(Node * root, int data);
    int search (Node * node, int search_value);
    int traverse (Node * root);

  };

}

