/**
 * @file main.cpp
 * @author Manas <manaskalyan98@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "BST.h"

int main() {

  bool search;

  mk::BST mk_tree;

  mk_tree.insert(5);
  mk_tree.insert(8);
  mk_tree.insert(1);
  mk_tree.insert(6);
  mk_tree.insert(2);
  mk_tree.insert(20);
  mk_tree.insert(200);
  mk_tree.insert(10);
  mk_tree.insert(3);

  std::cout << "printing in ascending order : " << std::endl;
  mk_tree.traverse_ascending_order();
  std::cout << " " << std::endl;
  std::cout << "printing in descending order : " << std::endl;
  mk_tree.traverse_descending_order();
  std::cout << " " << std::endl;

  search = mk_tree.search(200);
  std::cout << "Searched for 200 and "<<((search==true) ? "found in tree" : "not found in tree") << std::endl; 

  search = mk_tree.search(20);
  std::cout << "Searched for 20 and "<<((search==true) ? "found in tree" : "not found in tree") << std::endl;

  search = mk_tree.search(101);
  std::cout << "Searched for 101 and "<<((search==true) ? "found in tree" : "not found in tree") << std::endl; 




  mk_tree.delete_data_node(200);
  mk_tree.delete_data_node(10);

  std::cout << "printing in ascending order : " << std::endl;
  mk_tree.traverse_ascending_order();
  std::cout << " " << std::endl;

  std::cout << "printing in descending order : " << std::endl;
  mk_tree.traverse_descending_order();
  std::cout << " " << std::endl;

  return 0;
}
