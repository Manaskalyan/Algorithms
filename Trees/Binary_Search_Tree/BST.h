/**
 * @file BST.h
 * @author Manas <manaskalyan98@gmail.com>
 * @brief Interface for the Integer Binary Search Tree
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define SUCCESS 0

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

    /**
     * @brief Checks if node is a leaf or not
     * 
     * @return true  node is a leaf
     * @return false node is not a leaf
     */
    bool is_leaf();

    /**
     * @brief prints value of node
     * 
     * @return SUCCESS if everything goes well
     */
    int print_node();

    /**
     * @brief Checks if node has only 1 child
     * 
     * @return true   node has only 1 child
     * @return false  node migt have 0 / 2 child
     */
    bool has_one_child();


    /**
     * @brief Checks if node has left child or not
     * 
     * @return true   if node has left child
     * @return false  if node doesn't have left child
     */
    bool has_left_child();

    /**
     * @brief Checks if node has right child or not
     * 
     * @return true   if node has right child
     * @return false  if node doesn't have right child
     */
    bool has_right_child();

    /**
     * @brief Construct a new Node object
     * 
     * Assigns data to node data value
     * Sets left child and right child pointers to nullptr
     * 
     */
    Node(int data);

    /**
     * @brief Construct a new Node object
     * 
     */
    Node();


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
  /**
   * @brief Binary Search Tree Class Interface
   * 
   */
  class BST {

    private:
      int32_t _delete_leaf(parent_child);           /* You can't call this from client */
      int32_t _delete_one_child_node(parent_child); /* You can't call this from client */

      Node *root_node_; // pointer to root node

      int32_t _insert(Node * root, int data);
      parent_child _search(Node* root, Node* parent, int left_child, int search_value) const; /*Can i overload this function ?*/
      /* User might not want to know the parent / pointer for this node. He might just want to know if a search exists or not */
      bool _search(Node* root, int search_value) const; //Change this implementation to bool MK.
      parent_child _find_IOP (Node* root);
      int32_t _traverse_ascending_order(Node * root) const;
      int32_t _traverse_descending_order(Node * root) const;
      int32_t _delete_node(Node *root, int value);
      Node* _create_node_on_heap(int data);

    public:


      /*From a user perspective Why user wants to pass root node as parameter for all of these functions? */
      /* The below should be what user should use MK */

      /**
       * @brief Search the BST for the search value
       * 
       * @param  search_value  valued to be searched in the BST
       * @return true          if search is found in BST
       *         false         if search is not found in BST
       */
      bool search(int search_value) const;

      /**
       * @brief Insert data into BST
       * 
       * @param  data          data to inserted into BST
       * @return SUCCESS       if everything worked properly 
       */
      int32_t insert(int data);


      /**
       * @brief Traverse BST in ascending order
       * 
       * @return SUCCESS       if everything worked properly 
       */
      int32_t traverse_ascending_order() const;

      /**
       * @brief Traverse BST in descending order
       * 
       * @return SUCCESS       if everything worked properly
       */
      int32_t traverse_descending_order() const;

      /**
       * @brief delete node with value data from BST
       * 
       * @param  data  value to be deleted from BST
       * @return SUCCESS       if everything worked properly
       */
      int32_t delete_data_node(int data);

      //TODO: Think of copy constructor and assignment operator Manas.
      //TODO: Think of destructor too MK.

      //TODO: Look if you can bring level order traversal as well here.
      //TODO: Look how to do traverse_ascending_order non-recursively..
      //TODO: Catch framework?? 

      BST(); //Custom default constructor


  };

}