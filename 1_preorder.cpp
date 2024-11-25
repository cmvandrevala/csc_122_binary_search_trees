#include <array>
#include <iostream>

#include "binary_search_tree.hpp"

int main()
{
  BinarySearchTree<int> tree;

  array<int, 10> values = {8, 14, 150, 0, 30, 2, 4, 7, 1, 9};
  for (int i = 0; i < 10; i++)
  {
    tree.insert(values[i]);
  }

  cout << "The numbers sorted by preorder traversal:" << endl;
  tree.preorder();

  return 0;
}
