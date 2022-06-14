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
    int has_one_child();   

  };

  typedef struct {
    Node * node;
    Node * parent;
    int left_child; //if 1 node is a left child of parent

  } parent_child;

  //What my brain says is I don't know how to deal with private variables of this object yet
  //So don't worry about this stuff Manas.

  class BST {

    public:

    Node *root_node; // pointer to root node

    int insert(Node * root, int data);
    parent_child search(Node* root, Node* parent, int left_child, int search_value);
    parent_child find_IOP (Node* root);
    int delete_leaf(parent_child);
    int delete_one_child_node(parent_child);
    int traverse (Node * root);
    int delete_node(Node *root, int value);

  };

}