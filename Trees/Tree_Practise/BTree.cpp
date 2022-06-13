/**
 * An empty BTree.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */
#include "BTree.h"

namespace mk
{

//Given a tree how many times a function call wiil be made to traverse all nodes?
//I have kept root as a member of class BST. I have kept it as a variable too here in a member function.
//There is ambiguity here. How is that gonna be resolved?
  int BST::traverse (Node* root)
  {
    //std::cout << "entered traverse" <<std::endl;
    if (root == NULL) {
      //std:: cout << "tree empty" << std::endl;
      return 0;
    }

    if (root->is_leaf() == 1) {
      //std:: cout << "only 1 value" << std::endl;
      root->print_node();
      return 0;
    }
    
    /*The following produces data in asscending order*/
    //BST::traverse (root->Left_child);
    //root->print_node();
    //BST::traverse (root->Right_child);
    
    /*The following prints data in ascending order*/
    BST::traverse (root->Right_child);    
    root->print_node();
    BST::traverse (root->Left_child);

    return 0;  

  }

  int BST:: search(Node* root, int search_value) {
     if (root == NULL) {
        std:: cout << "tree empty" << std::endl;
        return 0;     
     }

     if (root->data == search_value) {
        std:: cout << "search found" << std::endl;
        return 0; 

     }

    if (root->is_leaf() == 1) {
      std:: cout << "search not found" << std::endl;      
      return 0;
    }

    if (search_value < root->data){
      BST:: search(root->Left_child, search_value);   
    }

    else {
      BST:: search(root->Right_child, search_value);
    }

    return 0;
  }

  int BST::insert(Node * root, int data)
  {
    
    if (root == NULL){

      root = (Node*)malloc(sizeof(Node));
      root->data = data;
      root->Left_child = NULL;
      root->Right_child = NULL;

      root_node = root;
      //std::cout << "inserted value : " << root->data << std::endl;
      return 0;
    }

    /*
    if (root->is_leaf() == 1) {
      if (node->data <= root->data) {
         root->Left_child = node;
         return 0;
      }
      else{
        root->Right_child = node;
        return 0;
      }
    }
    */

    if (data <= root->data){
        
      if (root->Left_child == NULL){

        //Create a node and assign left and right childs to NULL
        root->Left_child = (Node*)malloc(sizeof(Node));
        root->Left_child->data = data;
        root->Left_child->Left_child = NULL;
        root->Left_child->Left_child = NULL;
        return 0;
      }
      else {
        insert(root->Left_child, data);
        return 0;
      }

    }

    else {

      if (root->Right_child == NULL) {

        //create a node and assign left and right childs to NULL
        root->Right_child = (Node*)malloc(sizeof(Node));
        root->Right_child->data = data;
        root->Right_child->Left_child = NULL;
        root->Right_child->Right_child = NULL;

        return 0;        
      }
      else {
        insert(root->Right_child, data);
        return 0;
      }

    }

  }

  int Node::print_node()
  {
    std::cout << this->data << " ";
    return 0;
  }

  int Node::is_leaf()
  {
     if(this->Left_child == NULL && this->Right_child == NULL) {
       //std::cout << "For the leaf, data value is : " << this->data << std::endl;
       return 1;
     }
     else {
       return 0;
     }
  }


  
}





