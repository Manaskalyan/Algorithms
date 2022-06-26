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
    int height;

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

  /* See this class has only one data member / root node pointer */
  /* A lot of functionality to be performed on the object */
  class BST {

    private:
    int delete_leaf(parent_child);           /* You can't call this from client */
    int delete_one_child_node(parent_child); /* You can't call this from client */

    public:
    Node *root_node; // pointer to root node

    int insert(Node * root, int data);
    parent_child search(Node* root, Node* parent, int left_child, int search_value); /*Can i overload this function ?*/
    /* User might not want to know the parent / pointer for this node. He might just want to know if a search exists or not */
    int search(Node* root, int search_value);
    parent_child find_IOP (Node* root);
    int traverse_ascending_order (Node * root);
    int traverse_descending_order (Node * root);
    int delete_node(Node *root, int value);

  };

}