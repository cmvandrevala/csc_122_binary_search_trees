#include <iostream>

#include "binary_search_tree.hpp"

using namespace std;

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

  Node<int> *min = tree.min();
  cout << min->data << endl;

  Node<int> *max = tree.max();
  cout << max->data << endl;

  return 0;
}
