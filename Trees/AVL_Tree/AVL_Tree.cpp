#include "AVL_Tree.h"


namespace mk{

    AVL_Tree :: AVL_Tree(){
        root_node = nullptr;
    }
    
    int AVL_Tree::insert(Node * root, Node *parent, int data){

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
                insert(root->Left_child, root, data);
                if (root->Right_child == nullptr) {
                    root->height = root->Left_child->height + 1;
                    //check if this node is out of balance or not
                    if (if_node_out_of_balance(root) == 1) {
                        // do balance the tree starting with this node MK
                        std::cout << "node " << root->data << " is out of balance" << std::endl;
                        balance_subtree(root, parent, 1);
                    } 
                }
                else {
                    root->height = std::max(root->Left_child->height, root->Right_child->height) + 1;
                    //check if this node is out of balance or not
                    if (if_node_out_of_balance(root) == 1) {
                        // do balance the tree starting with this node MK
                        std::cout << "node " << root->data << " is out of balance" << std::endl;
                        balance_subtree(root, parent, 1);
                    } 
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


                return 0;        
            }
            else {
                insert(root->Right_child, root, data);
                if (root->Left_child == nullptr) {
                    root->height = root->Right_child->height + 1;
                    //check if this node is out of balance or not
                    if (if_node_out_of_balance(root) == 1) {
                        // do balance the tree starting with this node MK
                        std::cout << "node " << root->data << " is out of balance" << std::endl;
                        balance_subtree(root, parent, 0);
                    }
                }
                else {
                    root->height = std::max(root->Left_child->height, root->Right_child->height) + 1;
                    //check if this node is out of balance or not
                    if (if_node_out_of_balance(root) == 1) {
                        // do balance the tree starting with this node MK
                        std::cout << "node " << root->data << " is out of balance" << std::endl;
                        balance_subtree(root, parent, 1);
                    }       
                }
                
                return 0;
            }

        }

    }

    int AVL_Tree::balance_subtree(Node* node, Node* parent, int left_child) {

        int right_heavy = 0, left_heavy = 0;

        int height_LST, height_RST, child_LST_height, child_RST_height;
        int stick = 0, elbow = 0;
        Node  *b1, *b2, *b3;

        height_LST = (node->Left_child == nullptr) ? 0 : node->Left_child->height;
        height_RST = (node->Right_child == nullptr) ? 0 : node->Right_child->height;
        
        if (parent != nullptr) {
            left_child = (parent->Left_child == node) ? 1 : 0;

        }
        

        std ::cout << "entered balance subtree " << height_RST << " " << height_LST <<std::endl;
        //std::cout << "arent's data : " << parent->data <<std::endl;

        if (height_RST - height_LST >= 2) {
            right_heavy = 1;
        }
        else {
            left_heavy = 1;
        }

        if (right_heavy) {

            b1 = node;
            b2 = b1->Right_child;

            child_LST_height = (b2->Left_child == nullptr) ? 0 : b2->Left_child->height;
            child_RST_height = (b2->Right_child == nullptr) ? 0 : b2->Right_child->height;      

            std::cout << "could be the error" << std::endl;
            if (child_LST_height > child_RST_height ) {
                
                elbow = 1;
            }
            else {
                std::cout << "stick transformation" << std::endl;
                stick = 1;
            }


            if (elbow) {

                b1 = node;
                b2 = node->Right_child;
                b3 = b2->Left_child;

                b1->Right_child = b3->Left_child;
                b3->Left_child = b1; // left side sorted

                b2->Left_child = b3->Right_child;
                b3->Right_child = b2;

                set_height(b2);
                set_height(b1);
                set_height(b3);

                

                if (parent != nullptr){

                    if (left_child) {
                        parent->Left_child = b3;
                    }
                    else {
                        parent->Right_child = b3;
                    }

                    set_height(parent);

                }
                else {
                root_node = b3;
                }


            }

            if (stick) {
                b1 = node;
                b2 = node->Right_child;
                b3 = b2->Right_child;

                b1->Right_child = b2->Left_child;
                b2->Left_child = b1;

                set_height(b1);
                set_height(b3);
                set_height(b2);

                std::cout << "did seg fault happened : " << std::endl;

                if (parent != nullptr){
                    if (left_child) {
                        std::cout << "check on Left Child : " << std::endl;
                        parent->Left_child = b2;
                    }
                    else {
                        parent->Right_child = b2;
                    }
                }
                else {
                    root_node = b2;
                }
                
            }


        }

        else { //Left heavy

            b1 = node;
            b2 = b1->Left_child;

            child_LST_height = (b2->Left_child == nullptr) ? 0 : b2->Left_child->height;
            child_RST_height = (b2->Right_child == nullptr) ? 0 : b2->Right_child->height;

            if (child_RST_height > child_LST_height ) {
                elbow = 1;
            }
            else {
                stick = 1;
            }

            if (elbow) {

                b1 = node;
                b2 = node->Left_child;
                b3 = b2->Right_child;

                b1->Left_child = b3->Right_child;
                b3->Right_child = b1;

                b2->Right_child = b3->Left_child;
                b3->Left_child = b2;

                set_height(b1);
                set_height(b2);
                set_height(b3);

                if (parent != nullptr){ 
                    if (left_child) {
                        parent->Left_child = b3;
                    }
                    else {
                        parent->Right_child = b3;
                    }
                }
                else {
                    root_node = b3;
                }

            }

            if (stick) {
                b1= node;
                b2 = node->Left_child;
                b3 = b2->Left_child;

                b1->Left_child = b2->Right_child;
                b2->Right_child = b1;

                set_height(b1);
                set_height(b3);
                set_height(b2);

                if (parent != nullptr){ 
                    if (left_child) {
                        parent->Left_child = b2;
                    }
                    else {
                        parent->Right_child = b2;
                    }
                }
                else {
                    root_node = b2;
                }
            }
        }

        //std::cout << "parent's data : " << parent->data << std::endl;
        //std::cout << "parent'sleft child data : " << parent->Left_child->data << std::endl;
        //std::cout << "parent's right child data :" << parent->Right_child->data << std::endl;
    

        return 0;
    }

    int AVL_Tree::if_node_out_of_balance(Node *node) {

        int height_LST, height_RST;

        height_LST = (node->Left_child == nullptr) ? 0 : node->Left_child->height;
        height_RST = (node->Right_child == nullptr) ? 0 : node->Right_child->height;

        if (std::abs(height_RST - height_LST) >= 2 ) {
            return 1;
        }
        else {
            return 0;
        }   
    
    }

    int AVL_Tree::set_height(Node* node) {
        int height_LST, height_RST;

        height_LST = (node->Left_child == nullptr) ? 0 : node->Left_child->height;
        height_RST = (node->Right_child == nullptr) ? 0 : node->Right_child->height;

        node->height = std::max(height_LST, height_RST) + 1;

        return 0;
    }
}

