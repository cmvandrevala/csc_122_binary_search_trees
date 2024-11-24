#include "binary_search_tree.hpp"

int main()
{
  BinarySearchTree<int> tree;

  tree.insert(8);
  tree.insert(14);
  tree.insert(150);
  tree.insert(-10);
  tree.insert(30);
  tree.insert(2);
  tree.insert(4);
  tree.insert(7);
  tree.insert(1);
  tree.insert(32);
  tree.insert(5);

  tree.postorder();

  return 0;
}
