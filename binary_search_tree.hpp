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

  Node<T> *clear(Node<T> *node)
  {
    if (node == nullptr)
      return nullptr;
    {
      // This is postorder traversal! So cool!
      clear(node->left);
      clear(node->right);
      delete node;
    }
    return nullptr;
  }

  Node<T> *insert(T data, Node<T> *node)
  {
    if (node == nullptr)
    {
      node = new Node<T>;
      node->data = data;
      node->left = nullptr;
      node->right = nullptr;
    }
    else if (data < node->data)
    {
      node->left = insert(data, node->left);
    }
    else if (data > node->data)
    {
      node->right = insert(data, node->right);
    }
    return node;
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

  Node<T> *search(Node<T> *node, T data)
  {
    if (node == nullptr)
    {
      return nullptr;
    }
    else if (data < node->data && node->left != nullptr)
    {
      cout << "Going left to " << node->left->data << "!" << endl;
      return search(node->left, data);
    }
    else if (data > node->data && node->right != nullptr)
    {
      cout << "Going right to " << node->right->data << "!" << endl;
      return search(node->right, data);
    }
    else if (node->data != data)
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
    clear(root);
  }

  Node<T> *min()
  {
    return min(root);
  }

  Node<T> *max()
  {
    return max(root);
  }

  Node<T> *search(T data)
  {
    return search(root, data);
  }

  void insert(T data)
  {
    root = insert(data, root);
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
