#include <array>
#include <iostream>

#include "binary_search_tree.hpp"

using namespace std;

class TodoItem
{
public:
  int priority;
  TodoItem(int p) : priority(p) {}
  TodoItem() : priority(0) {}

  bool operator<(const TodoItem &todo)
  {
    return (priority < todo.priority);
  }

  bool operator>(const TodoItem &todo)
  {
    return (priority > todo.priority);
  }
};

int main()
{
  BinarySearchTree<TodoItem> tree;

  array<int, 10> values = {8, 14, 150, -10, 30, 2, 4, 7, 1, 32};
  for (int i = 0; i < 10; i++)
  {
    TodoItem item(values[i]);
    tree.insert(item);
  }

  Node<TodoItem> *max = tree.max();
  cout << max->data.priority << endl;

  Node<TodoItem> *min = tree.min();
  cout << min->data.priority << endl;

  return 0;
}
