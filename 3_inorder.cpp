#include <array>

#include "binary_search_tree.hpp"

int main()
{
  BinarySearchTree<int> tree;

  array<int, 10> values = {8, 14, 150, -10, 30, 2, 4, 7, 1, 32};
  for (int i = 0; i < 10; i++)
  {
    tree.insert(values[i]);
  }

  tree.inorder();

  return 0;
}
