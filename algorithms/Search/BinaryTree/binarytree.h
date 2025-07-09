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
        Node<E>* search_helper(Node<E>* current, E value);
        int depth_helper(Node<E>* root, Node<E>* target, int currentDepth = 0);
        int height_helper(Node<E>* target);

        void preorder(Node<E>* node);
        void inorder(Node<E>* node);
        void postorder(Node<E>* node);

    public:

        BinaryTree();
        void insert(E value);
        void print_tree();
        void search(E value);
        int height(E value);
        int depth(E value);
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
Node<E>* BinaryTree<E>::search_helper(Node<E>* current, E value)
{
    if(current == nullptr) return nullptr;

    if(current->data == value) return current;

    Node<E>* found = search_helper(current->left, value);
    if (found != nullptr) return found;

    return search_helper(current->right, value);
}

template<typename E>
void BinaryTree<E>::search(E value)
{
    if(search_helper(this->root, value) != nullptr)
    {
        cout << "Element " << value << " is in the tree." << endl; 
    }
    else
    {
        cout << "Element " << value << " is not in the tree." << endl;
    }
}

template<typename E>
int BinaryTree<E>::height_helper(Node<E>* target)
{
    if(target == nullptr) return -1;

    int leftHeight = height_helper(target->left);
    int rightHeight = height_helper(target->right);

    if(leftHeight >= rightHeight)
    {
        return 1+leftHeight;
    }
    else
    {
        return 1+rightHeight;
    }
};

template<typename E>
int BinaryTree<E>::height(E value)
{
    Node<E>* target = search_helper(this->root, value);

    if(target != nullptr)
    {
        return height_helper(target);
    }
    else
    {
        return -1;
    }
};

template<typename E>
int BinaryTree<E>::depth_helper(Node<E>* root, Node<E>* target, int currentDepth)
{
    if(root == nullptr) return -1;

    if(root == target) return currentDepth;

    int left = depth_helper(root->left, target, currentDepth+1);
    if(left != -1) return left;

    int right = depth_helper(root->right, target, currentDepth+1);
    return right;
};

template<typename E>
int BinaryTree<E>::depth(E value)
{
    Node<E>* target = search_helper(this->root, value);

    if(target != nullptr)
    {
        return depth_helper(this->root, target);
    }
    else
    {
        return -1;
    }
};

#endif //BINARYTREE_H