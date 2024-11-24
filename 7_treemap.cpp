#include <iostream>

#include "binary_search_tree.hpp"

using namespace std;

class TreeMap
{
private:
  class KeyValuePair
  {
  public:
    string key;
    int value;
    KeyValuePair(string k, int v) : key(k), value(v) {}
    KeyValuePair(string k) : key(k), value(-1) {}
    KeyValuePair() : key(""), value(-1) {}

    bool operator<(const KeyValuePair &kvp)
    {
      return (key < kvp.key);
    }

    bool operator>(const KeyValuePair &kvp)
    {
      return (key > kvp.key);
    }

    bool operator!=(const KeyValuePair &kvp)
    {
      return (key != kvp.key);
    }
  };
  BinarySearchTree<KeyValuePair> tree;

public:
  void insert(string key, int value)
  {
    KeyValuePair pair(key, value);
    tree.insert(pair);
  }

  int get(string key)
  {
    KeyValuePair temp(key);
    Node<KeyValuePair> *node = tree.search(temp);
    return node->data.value;
  }
};

int main()
{

  TreeMap tm;

  tm.insert("a", 5);
  tm.insert("b", 15);
  tm.insert("c", 35);
  tm.insert("d", -1);
  tm.insert("e", 2);

  cout << "The value for key e is " << tm.get("e") << endl;
  cout << "The value for key c is " << tm.get("c") << endl;
  cout << "The value for key a is " << tm.get("a") << endl;
  cout << "The value for key d is " << tm.get("d") << endl;
  cout << "The value for key b is " << tm.get("b") << endl;

  // Oh no! What is happening here? :(
  cout << "The value for key f is " << tm.get("f") << endl;

  return 0;
}
