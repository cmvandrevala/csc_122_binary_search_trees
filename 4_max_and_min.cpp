#include <array>
#include <iostream>

#include "binary_search_tree.hpp"

using namespace std;

int main()
{
  BinarySearchTree<int> tree;

  array<int, 10> values = {8, 14, 150, 0, 30, 2, 4, 7, 1, 9};
  for (int i = 0; i < 10; i++)
  {
    tree.insert(values[i]);
  }

  Node<int> *min = tree.min();
  cout << "The minimum of this list is " << min->data << endl;

  Node<int> *max = tree.max();
  cout << "The maximum of this list is " << max->data << endl;

  return 0;
}
