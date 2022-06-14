/**
 * An empty BinaryTree.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "BTree.h"

int main() {

  mk::BST mk_tree;

//  mk::Node node1, node2, node3, node4, node5, node6, node7, node8, node9;


  mk_tree.root_node = NULL;

  /*
  node1.data = 5;
  node1.Left_child = NULL;
  node1.Right_child = NULL;

//  mk_tree.root_node = &node1;


  node2.data = 8;
  node2.Left_child = NULL;
  node2.Right_child = NULL;

  node3.data = 1;
  node3.Left_child = NULL;
  node3.Right_child = NULL;

  node4.data = 6;
  node4.Left_child = NULL;
  node4.Right_child = NULL;

  node5.data = 2;
  node5.Left_child = NULL;
  node5.Right_child = NULL;

  node6.data = 20;
  node6.Left_child = NULL;
  node6.Right_child = NULL;

  node7.data = 200;
  node7.Left_child = NULL;
  node7.Right_child = NULL;

  node8.data = 10;
  node8.Left_child = NULL;
  node8.Right_child = NULL;

  node9.data = 3;
  node9.Left_child = NULL;
  node9.Right_child = NULL;

  */


  mk_tree.root_node = NULL;

  mk_tree.insert(mk_tree.root_node, 5);

  

  //mk_tree.root_node = &node1;

  mk_tree.insert(mk_tree.root_node, 8);

  mk_tree.insert(mk_tree.root_node, 1);

  mk_tree.insert(mk_tree.root_node, 6);

  mk_tree.insert(mk_tree.root_node, 2);

  mk_tree.insert(mk_tree.root_node, 20);

  mk_tree.insert(mk_tree.root_node, 200);

  mk_tree.insert(mk_tree.root_node, 10);

  mk_tree.insert(mk_tree.root_node, 3);

  std::cout << "atleast this should print" << std::endl;


  mk_tree.traverse(mk_tree.root_node);

  mk_tree.search(mk_tree.root_node, NULL, 1, 200);

  mk_tree.delete_node(mk_tree.root_node, 200);

  mk_tree.delete_node(mk_tree.root_node, 10);

  mk_tree.traverse(mk_tree.root_node);  

  return 0;
}