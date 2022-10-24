/**
 * @file BST.cpp
 * @author Manas Kalyan (manaskalyan98@gmail.com)
 * @brief  Implements integer Binary Search Tree Functionality
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "BST.h"

namespace mk
{

//Given a tree how many times a function call will be made to traverse all nodes?
//I have kept root as a member of class BST. I have kept it as a variable too here in a member function.
//There is ambiguity here. How is that gonna be resolved?
  int32_t BST::_traverse_descending_order(Node* root) const
  {
    //std::cout << "entered traverse descending" <<std::endl;
    if (root == nullptr) {
      //std:: cout << "tree empty" << std::endl;
      return 0;
    }

    if (root->is_leaf()) {
      //std:: cout << "only 1 value" << std::endl;
      root->print_node();
      return 0;
    }
    
    /*The following produces data in asscending order*/
    //BST::traverse (root->Left_child);
    //root->print_node();
    //BST::traverse (root->Right_child);
    
    /*The following prints data in ascending order*/
    BST::_traverse_descending_order (root->Right_child);    
    root->print_node();
    BST::_traverse_descending_order (root->Left_child);

    return 0;  

  }

  int32_t BST::_traverse_ascending_order(Node* root) const
  {
    if (root == nullptr) {
      //std:: cout << "tree empty" << std::endl;
      return 0;
    }

    /*I think this is not needed also*/
    if (root->is_leaf()) {
      root->print_node();
      return 0;
    }
    
    /*The following produces data in asscending order*/
    BST::_traverse_ascending_order (root->Left_child);
    root->print_node();
    BST::_traverse_ascending_order (root->Right_child);    

    return 0;
  }

  parent_child BST:: _find_IOP (Node* root) {
    parent_child pc;
    Node* curr = root->Left_child;
    while (curr->Right_child != nullptr) {
      pc.parent = curr;
      curr = curr->Right_child;
    }
    pc.node = curr;
    return pc;
  }

  bool BST:: _search(Node* root, int search_value) const{
    bool err;

    if (root == nullptr) {
      std:: cout << "tree empty" << std::endl;
      return false;     
    }

    if (root->data == search_value) {
      //std:: cout << "search found" << std::endl;
      return true; 

    }
    
    /* If root is leaf, above condition checks if root data == search value*/
    /* Even if this condition is not there, it will work out because bext node will be nullptr */
    /*This is correct*/
    if (root->is_leaf()) {
      std:: cout << "search not found" << std::endl;      
      return false;
    }

    if (search_value < root->data){
      err = BST:: _search(root->Left_child, search_value);   
    }

    else {
      err = BST:: _search(root->Right_child, search_value);
    }

    return err;

  }

  parent_child BST:: _search(Node* root, Node* parent, int left_child, int search_value) const{

     parent_child pc;
     parent_child *pc_ptr = &pc;
          
     if (root == nullptr) {
        std:: cout << "tree empty" << std::endl;
        pc_ptr->parent = nullptr;
        pc_ptr->node = nullptr;
        pc_ptr->left_child = left_child;
        
        return pc;   
     }

     if (root->data == search_value) {
        //std:: cout << "search found" << std::endl;
        pc_ptr->parent = parent;
        pc_ptr->node = root;
        pc_ptr->left_child = left_child;
        return pc;

     }

    if (root->is_leaf() == 1) {
      std:: cout << "search not found" << std::endl; 

        pc_ptr->parent = nullptr;
        pc_ptr->node = nullptr;
        pc_ptr->left_child = left_child;     
      return pc;
    }

    if (search_value < root->data){
      pc = BST:: _search(root->Left_child, root, 1, search_value);
    }

    else {
      pc = BST:: _search(root->Right_child, root, 0,  search_value);
    }

    return pc;
  }

  int32_t BST::_insert(Node * root, int data)
  {
    
    if (root == nullptr){

      //root = (Node*)malloc(sizeof(Node));
      root = _create_node_on_heap(data);

      root_node_ = root;
      return 0;
    }

    if (data <= root->data){
        
      /* If root doesn't have right child */
      if (!root->has_left_child()) {

        root->Left_child = _create_node_on_heap(data);    /*I think I can clean this up with a constructor */
                                                          /* Will a constructor be invoked when created on heap? */
        //std::cout << "Data : " << data <<" "<< root->Left_child->data << std::endl;
        return 0;
      }
      else {
        BST::_insert(root->Left_child, data);
        return 0;
      }

    }

    else {

      /* If root doesn't have right child */
      if (!root->has_right_child()) {

        root->Right_child = _create_node_on_heap(data);
        return 0;        
      }
      else {
        BST::_insert(root->Right_child, data);
        return 0;
      }

    }

  }

  int32_t BST::_delete_leaf(parent_child pc) {

    delete(pc.node);

    if (pc.left_child == 1)
      pc.parent->Left_child = nullptr;
    else
      pc.parent->Right_child = nullptr;

    return 0;

  }

  int32_t BST::_delete_one_child_node (parent_child pc) {

    if (pc.node->Left_child != nullptr) {
      if (pc.left_child == 1) {
        pc.parent->Left_child = pc.node->Left_child;
      }
      else {
        pc.parent->Right_child = pc.node->Left_child;
      }   

    }

    else {
      if (pc.left_child == 1) {
        pc.parent->Left_child = pc.node->Right_child;
      }
      else {
        pc.parent->Right_child = pc.node->Right_child;
      }    

    }
    delete(pc.node);

    return 0;

  
  }

  int32_t BST::_delete_node(Node *root, int value)
  {
    parent_child pc, iop;
    parent_child *pc_ptr = &pc;

    pc = _search(root, nullptr, 1, value);

    /*only now you need to do anything*/
    if (pc_ptr->node != nullptr) {

      /* If the node to delete is a leaf */
      /* Delete the node and nullptr the pointer of parent based on if it's left child or right child */
      if (pc.node->is_leaf() == 1) {
        _delete_leaf(pc);          
      }

      /* If the node to delete has one child */
      else if (pc.node->has_one_child() == 1) {
        _delete_one_child_node(pc);     

      }

      /*it has both child*/
      /* Find the IOP. swap it with IOP and delete the swapped IOP */
      else {
          iop = _find_IOP(pc.node);

          int tmp;
          tmp = iop.node->data;
          iop.node->data = pc.node->data;
          pc.node->data  = tmp;

          if (pc.node->is_leaf() == 1) {
            _delete_leaf(pc);              
          }
          
          else  {
            _delete_one_child_node(pc);
          }
      }


    }

    return 0;


     // search the node. Ask the search function to return a pointer for the node
     // If the search is a leaf then you just need to delete it simple
     // If not get a value very close to the node.
     // If the value is very close to node is a leaf node then just swap the value with node and remove leaf node
     // If the value very close is not a leaf, then you need to delete intermediate node
     //  


  }

  int Node::print_node()
  {
    std::cout << this->data << " ";
    return 0;
  }

  bool Node::is_leaf()
  {
     if(this->Left_child == nullptr && this->Right_child == nullptr) {
       //std::cout << "For the leaf, data value is : " << this->data << std::endl;
       return true;
     }
     else {
       return false;
     }
  }

  bool Node::has_one_child()
  {
     int i = 0, j = 0;
     i = (this->Left_child == nullptr) ? 1 : 0;
     j = (this->Right_child == nullptr) ? 1 : 0;
     if ( i + j == 1)
       return true;
     else
       return false;
  }

  bool Node::has_left_child()
  {
    return (this->Left_child != nullptr) ? true : false;
  }

  bool Node::has_right_child()
  {
    return (this->Right_child != nullptr) ? true : false;
  }

  Node::Node(int data)
  {
    data = data;
    Left_child = nullptr;
    Right_child = nullptr;
  }

  Node::Node()
  {

  }

  Node* BST:: _create_node_on_heap(int data){

    Node* ptr = new Node();

    ptr->data = data;
    ptr->Left_child = nullptr;
    ptr->Right_child = nullptr;

    return ptr;
  }




  
}

namespace mk{


  bool BST::search(int search_value) const
    { 

      /* If you see that root_node_ is not declated in this function member */
      /* Becaue it is class data member, it is available to it */
      /* However is it a good style? */
      return ( BST::_search(root_node_, search_value) );

    }
  
  int32_t BST::insert(int data)
  {
    int32_t err;

    err = BST::_insert(root_node_, data);
    
    return err;
  }

  int32_t BST::traverse_ascending_order() const
  {
    int32_t err;

    err = BST::_traverse_ascending_order(root_node_);

    return err;
  }

  int32_t BST::traverse_descending_order() const
  {
    int32_t err;

    err = BST::_traverse_descending_order(root_node_);

    return err;
  }

  int32_t BST::delete_data_node(int data)
  {
    int32_t err;

    err = BST::_delete_node(root_node_, data);

    return err;

  }

  BST::BST()
  {
    root_node_ = nullptr;
  }


  

}







