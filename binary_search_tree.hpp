/*
** Binary Search Tree implementation in C++
** Harish R
*/
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
  T data;
  Node<T> *left;
  Node<T> *right;
};

template <typename T>
class BinarySearchTree
{
  Node<T> *root;

  Node<T> *makeEmpty(Node<T> *t)
  {
    if (t == nullptr)
      return nullptr;
    {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
    }
    return nullptr;
  }

  Node<T> *insert(int x, Node<T> *t)
  {
    if (t == nullptr)
    {
      t = new Node<T>;
      t->data = x;
      t->left = t->right = nullptr;
    }
    else if (x < t->data)
      t->left = insert(x, t->left);
    else if (x > t->data)
      t->right = insert(x, t->right);
    return t;
  }

  Node<T> *min(Node<T> *node)
  {
    if (node == nullptr)
    {
      return nullptr;
    }
    else if (node->left == nullptr)
    {
      return node;
    }
    else
    {
      return min(node->left);
    }
  }

  Node<T> *max(Node<T> *node)
  {
    if (node == nullptr)
    {
      return nullptr;
    }
    else if (node->right == nullptr)
    {
      return node;
    }
    else
    {
      return max(node->right);
    }
  }

  Node<T> *remove(int x, Node<T> *t)
  {
    Node<T> *temp;
    if (t == nullptr)
      return nullptr;
    else if (x < t->data)
      t->left = remove(x, t->left);
    else if (x > t->data)
      t->right = remove(x, t->right);
    else if (t->left && t->right)
    {
      temp = min(t->right);
      t->data = temp->data;
      t->right = remove(t->data, t->right);
    }
    else
    {
      temp = t;
      if (t->left == nullptr)
        t = t->right;
      else if (t->right == nullptr)
        t = t->left;
      delete temp;
    }

    return t;
  }

  void inorder(Node<T> *node)
  {
    if (node == nullptr)
    {
      return;
    }
    inorder(node->left);
    cout << node->data << ", ";
    inorder(node->right);
  }

  void preorder(Node<T> *node)
  {
    if (node == nullptr)
    {
      return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }

  void postorder(Node<T> *node)
  {
    if (node == nullptr)
    {

      return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << ", ";
  }

  Node<T> *search(Node<T> *node, T x)
  {
    if (node == nullptr)
    {
      return nullptr;
    }
    else if (x < node->data && node->left != nullptr)
    {
      cout << "Going left to " << node->left->data << "!" << endl;
      return search(node->left, x);
    }
    else if (x > node->data && node->right != nullptr)
    {
      cout << "Going right to " << node->right->data << "!" << endl;
      return search(node->right, x);
    }

    else if (node->data != x)
    {
      cout << "This element does not exist in the list! Here is the node that we got to..." << endl;
      return node;
    }
    else
    {
      cout << "Arrived at the correct node!" << endl;
      return node;
    }
  }

public:
  BinarySearchTree()
  {
    root = nullptr;
  }

  ~BinarySearchTree()
  {
    root = makeEmpty(root);
  }

  Node<T> *min()
  {
    return min(root);
  }

  Node<T> *max()
  {
    return max(root);
  }

  Node<T> *search(T x)
  {
    return search(root, x);
  }

  void insert(int x)
  {
    root = insert(x, root);
  }

  void remove(int x)
  {
    root = remove(x, root);
  }

  void inorder()
  {
    inorder(root);
    cout << endl;
  }

  void preorder()
  {
    preorder(root);
    cout << endl;
  }

  void postorder()
  {
    postorder(root);
    cout << endl;
  }
};
