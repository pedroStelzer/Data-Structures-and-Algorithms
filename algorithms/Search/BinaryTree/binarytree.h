#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

template <typename E> struct Node
{
    E data;
    Node<E>* right;
    Node<E>* left;

    Node(E value) : data(value), right(nullptr), left(nullptr) {};
};

template <typename E> class BinaryTree
{
    private:

        Node<E>* root;

        Node<E>* insert_helper(Node<E>* current, E value);
        bool search_helper(Node<E>* current, E value);

        void preorder(Node<E>* node);
        void inorder(Node<E>* node);
        void postorder(Node<E>* node);

    public:

        BinaryTree();
        void insert(E value);
        void print_tree();
        void search(E value);
};

template<typename E>
BinaryTree<E>::BinaryTree() {this->root = nullptr;};

template<typename E>
Node<E>* BinaryTree<E>::insert_helper(Node<E>* current, E value)
{
    if(current == nullptr) return new Node(value);

    if(current->left == nullptr)
    {
        current->left = insert_helper(current->left, value);
    }
    else if(current->right == nullptr)
    {
        current->right = insert_helper(current->right, value);
    }
    else
    {
        current->left = insert_helper(current->left, value);
    }

    return current;
};

template<typename E>
void BinaryTree<E>::insert(E value)
{
    root = insert_helper(this->root, value);
};

template<typename E>
void BinaryTree<E>::print_tree()
{
    int n;

    cout << "Choose which traversal order to display the tree: " << endl << endl;
    cout << "(1) Pre-order" << endl;
    cout << "(2) In-order" << endl;
    cout << "(3) Post-order" << endl << endl;

    cin >> n;

    switch(n)
    {
        case 1:
            preorder(this->root);
            break;
        
        case 2:
            inorder(this->root);
            break;
        
        case 3:
            postorder(this->root);
            break;
        
        default:
            break;
    }
};

template<typename E>
void BinaryTree<E>::preorder(Node<E>* node)
{
    if(node == nullptr) return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
};

template<typename E>
void BinaryTree<E>::inorder(Node<E>* node)
{
    if(node == nullptr) return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
};

template<typename E>
void BinaryTree<E>::postorder(Node<E>* node)
{
    if(node == nullptr) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
};

template<typename E>
bool BinaryTree<E>::search_helper(Node<E>* current, E value)
{
    if(current == nullptr) return false;

    if(current->data == value) return true;

    return search_helper(current->left, value) || search_helper(current->right, value);
}

template<typename E>
void BinaryTree<E>::search(E value)
{
    if(search_helper(this->root, value))
    {
        cout << "Element " << value << " is in the tree." << endl; 
    }
    else
    {
        cout << "Element " << value << " is not in the tree." << endl;
    }
}

#endif //BINARYTREE_H