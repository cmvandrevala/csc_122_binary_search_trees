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

  int e = tm.get("e");
  cout << "The value for key e is " << e << endl
       << endl;

  int c = tm.get("c");
  cout << "The value for key c is " << c << endl
       << endl;

  int a = tm.get("a");
  cout << "The value for key a is " << a << endl
       << endl;

  int d = tm.get("d");
  cout << "The value for key d is " << d << endl
       << endl;

  int b = tm.get("b");
  cout << "The value for key b is " << b << endl
       << endl;

  // Oh no! What is happening here? :(
  int f = tm.get("f");
  cout << "The value for key f is " << f << endl
       << endl;

  return 0;
}
