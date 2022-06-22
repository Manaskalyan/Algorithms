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
  int BST::traverse_descending_order (Node* root)
  {
    std::cout << "entered traverse descending" <<std::endl;
    if (root == nullptr) {
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
    BST::traverse_descending_order (root->Right_child);    
    root->print_node();
    BST::traverse_descending_order (root->Left_child);

    return 0;  

  }

   int BST::traverse_ascending_order (Node* root)
  {
    std::cout << "entered traverse ascending" <<std::endl;
    if (root == nullptr) {
      //std:: cout << "tree empty" << std::endl;
      return 0;
    }

    if (root->is_leaf() == 1) {
      std:: cout << "entered leaf" << std::endl;
      root->print_node();
      return 0;
    }
    
    /*The following produces data in asscending order*/
     BST::traverse_ascending_order (root->Left_child);
     root->print_node();
     BST::traverse_ascending_order (root->Right_child);
    

    return 0;  

  }

  parent_child BST:: find_IOP (Node* root) {
    parent_child pc;
    Node* curr = root->Left_child;
    while (curr->Right_child != nullptr) {
      pc.parent = curr;
      curr = curr->Right_child;
    }
    pc.node = curr;
    return pc;
  }

    int BST:: search(Node* root, int search_value) {
     if (root == nullptr) {
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

  parent_child BST:: search(Node* root, Node* parent, int left_child, int search_value) {

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
        std:: cout << "search found" << std::endl;
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
      pc = BST:: search(root->Left_child, root, 1, search_value);
    }

    else {
      pc = BST:: search(root->Right_child, root, 0,  search_value);
    }

    return pc;
  }

  int BST::insert(Node * root, int data)
  {
    
    if (root == nullptr){

      //root = (Node*)malloc(sizeof(Node));
      root = new(Node);
      root->data = data;
      root->Left_child = nullptr;
      root->Right_child = nullptr;
      root->height = 1;

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
        
      if (root->Left_child == nullptr){

        //Create a node and assign left and right childs to nullptr
        //root->Left_child = (Node*)malloc(sizeof(Node));
        root->Left_child = new(Node);

        root->Left_child->data = data;
        root->Left_child->Left_child = nullptr;
        root->Left_child->Right_child = nullptr;
        root->Left_child->height = 1;
        if (root->height <= 1) {
          root->height = 2;
        }
        return 0;
      }
      else {
        insert(root->Left_child, data);
        if (root->Right_child == nullptr) {
          root->height = root->Left_child->height + 1;
        }
        else {
          root->height = std::max(root->Left_child->height, root->Right_child->height) + 1;
        }
        
        return 0;
      }

    }

    else {

      if (root->Right_child == nullptr) {

        //create a node and assign left and right childs to nullptr
        //root->Right_child = (Node*)malloc(sizeof(Node));
        root->Right_child = new(Node);
        root->Right_child->data = data;
        root->Right_child->Left_child = nullptr;
        root->Right_child->Right_child = nullptr;
        root->Right_child->height = 1;

        if (root->height <= 1) {
          root->height = 2;
        }

        /*if root height <= 1, root -> height = 2*/

        return 0;        
      }
      else {
        insert(root->Right_child, data);
        if (root->Left_child == nullptr) {
          root->height = root->Right_child->height + 1;
        }
        else {
          root->height = std::max(root->Left_child->height, root->Right_child->height) + 1;          
        }
        
        return 0;
      }

    }

  }

  int BST::delete_leaf(parent_child pc) {

    delete(pc.node);

    if (pc.left_child == 1)
      pc.parent->Left_child = nullptr;
    else
      pc.parent->Right_child = nullptr;

    return 0;

  }

  int BST::delete_one_child_node (parent_child pc) {

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

  int BST::delete_node(Node *root, int value)
  {
    parent_child pc, iop;
    parent_child *pc_ptr = &pc;

    pc = search(root, nullptr, 1, value);

    /*only now you need to do anything*/
    if (pc_ptr->node != nullptr) {

      /* If the node to delete is a leaf */
      /* Delete the node and nullptr the pointer of parent based on if it's left child or right child */
      if (pc.node->is_leaf() == 1) {
        delete_leaf(pc);          
      }

      /* If the node to delete has one child */
      else if (pc.node->has_one_child() == 1) {
        delete_one_child_node(pc);     

      }

      /*it has both child*/
      /* Find the IOP. swap it with IOP and delete the swapped IOP */
      else {
          iop = find_IOP(pc.node);

          int tmp;
          tmp = iop.node->data;
          iop.node->data = pc.node->data;
          pc.node->data  = tmp;

          if (pc.node->is_leaf() == 1) {
            delete_leaf(pc);              
          }
          
          else  {
            delete_one_child_node(pc);
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
    //std::cout << this->data << " ";
    std::cout << this->data << " " << this->height << std::endl;
    return 0;
  }

  int Node::is_leaf()
  {
     if(this->Left_child == nullptr && this->Right_child == nullptr) {
       //std::cout << "For the leaf, data value is : " << this->data << std::endl;
       return 1;
     }
     else {
       return 0;
     }
  }

  int Node::has_one_child()
  {
     int i = 0, j = 0;
     i = (this->Left_child == nullptr) ? 1 : 0;
     j = (this->Right_child == nullptr) ? 1 : 0;
     if ( i + j == 1)
       return 1;
     else
       return 0;
  }


  
}





