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

  int selection;
  bool in_progress = true;

  while (in_progress)
  {
    cout << "Type in a number to search for!" << endl;
    cin >> selection;
    Node<int> *found = tree.search(selection);
    cout << found->data << endl;
  }

  return 0;
}
